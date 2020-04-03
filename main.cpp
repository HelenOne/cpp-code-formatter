#include <iostream>
#include <fstream>
int main()
{
    std::ifstream readFile;
    readFile.open("test.txt");
    if (!readFile.is_open())
    {
        std::cout << "Error with opening! \n";
        return 0;
    }

    char currentRow[256];
    char codeArray[100]; //Не знаю реальный необходимый размер! Динамическая память?
    int row = 0;
    while (!readFile.eof())
    {
        readFile.getline(currentRow, 256, ';');
        std::cout << currentRow;
        int currentChar = 0;
        while (currentRow[currentChar] != '\0')
        {
            if (currentRow[currentChar + 1] == '!')
            {
                codeArray[row] = currentRow[currentChar];
                codeArray[row + 1] = ' ';

                row++;
            }
            else
            {
                if (currentRow[currentChar] == '\0')
                {
                    codeArray[row] = ';';
                }
                else
                {
                    codeArray[row] = currentRow[currentChar];
                }
            }

            currentChar++;
            row++; //Это и есть длина массива не так ли?
        }
    }
    std::cout << std::endl;
    readFile.close();

    for (int i = 0; i < row; i++) //Нужно как-то узнавать длину массива/файла. Вроде есть функции для этого (см конспект Воронова)
    {
        std::cout << codeArray[i]; //Здесь на самом деле нужно добавлять исправленный текст в новый файл
    }

    // system("pause");
    return 0;
}
