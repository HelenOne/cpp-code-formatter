#include <iostream>
#include <fstream>

int format(char filename[], char filenameToSave[])
{

  std::ifstream readFile;
  readFile.open(filename);
  if (!readFile.is_open())
  {
    std::cout << "Error with opening! \n";
    return 0;
  }

  char currentRowInReadFile[256];

  char codeHandlingArray[100]; //Сделать динамическим! //Сюда записываю код, чтобы обработать и записать в новый файл
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

    if (filenameToSave[0] == '\0')
    {
      writeFile.open(filename);
    }
    else
    {
      writeFile.open(filenameToSave);
    }

    // далее работа с записью в файл и обработка массива

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
  std::cout << std::endl
            << "File \""
            << filename
            << "\" is succesfully formatted!"
            << std::endl;
  return 0;
}