#include <iostream>
#include <fstream>

int format(char filename[], char filenameToSave[])
{

  // создание потока для чтения файла и открытие файла для дальнейшего форматирования
  std::ifstream readFile;
  readFile.open(filename);
  if (!readFile.is_open())
  {
    std::cout << "Error with opening ("
              << filename
              << ")! \n";
    return 0;
  }

  char currentRowInReadFile[256]; // для получения отдельных строк из исходного файла

  char codeHandlingArray[100]; //Сделать динамическим! //Сюда записываю код, чтобы обработать и записать отформатированный код в новый файл
  int codeHandlingArrayChar = 0;

  // цикл для записи исходного кода в массив символов, дальнейшей обработки массива и записи более красивого кода в новый файл
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
    writeFile.open(filenameToSave);

    // далее идет обработка массива с исходным кодом по правилам форматтирования кода

    int nestingLevel = 0; //Уровень вложенности
    char previousChar = '\0';
    for (int i = 0; i < codeHandlingArrayChar; i++)
    {
      bool rowHasIndent = false; // переменная для проверки наличия отступов в каждой строке

      if ((nestingLevel != 0) && (!rowHasIndent) && (previousChar == '\n') && (codeHandlingArray[i] != '}'))
      {
        for (int i = 0; i < nestingLevel; i++)
        {
          writeFile << '\t';
          previousChar = '\t';
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
      // Далее идут уословия при которых символ не записывается в новый файл, то есть игнорируются
      else if ((previousChar == ' ') && (codeHandlingArray[i] == ' ')) //удаление лишних пробелов
      {
        // do nothing
      }
      else if ((codeHandlingArray[i] == '\t')) //Удаление всех оттупов, которые были в изначальном файле
      {
        // do nothing
      }
      else if ((previousChar == '\n') && (codeHandlingArray[i] == '}')) //Удаление пустой строки перед закрывающей скобкой
      {
        // do nothing
      }
      else if ((previousChar == '\n') && (codeHandlingArray[i] == '\n')) //Удаление повторяющихся переносов строки
      {
        // do nothing
      }
      else if ((previousChar == '\t') && ((codeHandlingArray[i] == ' '))) //Удаление лишних пробелов
      {
        //do nothing
      }

      //все остальные символы (просто записываются):
      else
      {
        writeFile << codeHandlingArray[i];
        previousChar = codeHandlingArray[i];
      }
    }
  }
  // std::cout << std::endl
  //           << "File \""
  //           << filename
  //           << "\" is succesfully formatted!"
  //           << std::endl;
  return 0;
}