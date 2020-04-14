#include <iostream>
#include <fstream>

int main()
{
    std::ifstream readFile;
    std::cout << "Write filename to format and press enter:" << std::endl;
    char filename[256];
    std::cin.getline(filename, 256, '\n');
    readFile.open(filename);
    if (!readFile.is_open())
    {
        std::cout << "Error with opening! \n";
        return 0;
    }
    char currentRowInReadFile[256];

    std::ofstream writeFile;

    char codeHandlingArray[100]; //Не знаю реальный необходимый размер! Динамическая память? //Сюда записываю код, чтобы обработать и записать в новый файл
    int codeHandlingArrayChar = 0;

    while (!readFile.eof())
    {
        readFile.getline(currentRowInReadFile, 256, '\0');

        int currentChar = 0;
        while (currentRowInReadFile[currentChar] != '\0')
        {

            codeHandlingArray[codeHandlingArrayChar] = currentRowInReadFile[currentChar];

            currentChar++;
            codeHandlingArrayChar++;
        }

        std::cout << std::endl;
        readFile.close();

        std::ofstream writeFile;

        std::cout << "Write filename to save formatted code and press enter (or press enter and code will be saved in " << filename << "):" << std::endl;
        char filenameToSave[256];
        std::cin.getline(filenameToSave, 256, '\n');
        if (filenameToSave[0] == '\0')
        {
            writeFile.open(filename);
        }
        else
        {
            writeFile.open(filenameToSave);
        }

        int nestingLevel = 0; //Уровень вложенности
        char previousChar = '\0';
        for (int i = 0; i < codeHandlingArrayChar; i++)
        {
            bool rowHasIndent = false;

            if ((nestingLevel != 0) && (rowHasIndent) && (previousChar == '\n') && (codeHandlingArray[i] != '}'))
            {
                for (int i = 0; i < nestingLevel; i++)
                {
                    writeFile << '\t';
                }
                rowHasIndent = true;
            }
            if (codeHandlingArray[i] == ';')
            {
                bool rowHasIndent = false;
            }

            if (codeHandlingArray[i] == '{')
            {
                if (previousChar != ' ')
                {
                    writeFile << ' ';
                }
                writeFile << codeHandlingArray[i] << '\n';
                previousChar = '\n';
                nestingLevel++;
            }
            else if (codeHandlingArray[i] == '}')
            {
                writeFile << '\n'
                          << codeHandlingArray[i] << '\n';
                previousChar = '\n';
                nestingLevel--;
            }
            else if (((previousChar == ' ') && (codeHandlingArray[i] == ' ')) || ((previousChar == '\n') && (codeHandlingArray[i] == '\n')) || ((previousChar == '\n') && (codeHandlingArray[i] == '}')) || ((codeHandlingArray[i] == '\t')))
            {
                // do nothing
            }
            else
            {
                writeFile << codeHandlingArray[i];
                previousChar = codeHandlingArray[i];
            }
        }
    }
    return 0;
}
