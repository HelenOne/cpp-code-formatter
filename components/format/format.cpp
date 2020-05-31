#include <iostream>
#include <fstream>
#include <Windows.h>
#include <stdlib.h>

#include "../formatText/formatText.h"
#include "../formatText/formatFunctions/addMoreSpaceTo/addMoreSpaceTo.h"

void format(char filename[], char filenameToSave[])
{

  setlocale(LC_ALL, "rus");

  // создание потока для чтения файла и открытие файла для дальнейшего форматирования
  std::ifstream readFile;
  readFile.open(filename);
  if (!readFile.is_open())
  {
    std::wcout << L"Не удалось открыть файл ("
               << filename
               << L")! \n";
  }

  std::wcout << L"Функция format.cpp запущена \n";

  int codeLength = 0;
  int maxStringLength = 100000;

  char *codeHandlingArray = new char[codeLength]; //Сюда записываю код, чтобы обработать и записать отформатированный код в новый файл
  char currentRowInReadFile[maxStringLength];     // массив для получения отдельных строк из исходного файла

  int codeHandlingArrayChar = 0;

  int codeRowNumber = 0; // номер обраатываемой строки

  // цикл для записи исходного кода в массив символов codeHandlingArray
  while (!readFile.eof())
  {
    // std::wcout << L"Цикл while (!readFile.eof()) \n";
    readFile.getline(currentRowInReadFile, maxStringLength, '\0');
    codeRowNumber++;

    int currentChar = 0;

    while (currentRowInReadFile[currentChar] != '\0')
    {
      // std::wcout << L"Цикл while (currentRowInReadFile[currentChar]) \n";
      // std::cout << codeLength << std::endl;
      addMoreSpaceTo(codeHandlingArray, &codeLength, 1);

      // std::cout << codeLength << std::endl;

      codeHandlingArray[codeHandlingArrayChar] = currentRowInReadFile[currentChar];
      // std::cout << codeHandlingArray[codeHandlingArrayChar] << std::endl;

      currentChar++;
      codeHandlingArrayChar++;
      // codeLength++;
      if (currentRowInReadFile[currentChar] == '\0')
      {
        std::wcout << L"Строка " << codeRowNumber << L" успешно обработана \n";
      }
    }

    std::cout << "Debug" << std::endl;

    if (readFile.eof())
    {
      std::wcout << L"Файл успешно обработан \n";
    }
  }

  // std::wcout << L"Цикл завершен";

  readFile.close(); // программа прочитала исходный файл, сохранила его в массив, закрыла поток

  // здесь маcсив форматируется
  formatText(codeHandlingArray, &codeLength);

  std::ofstream writeFile; // поток для записи в новый файл обработанного массива
  writeFile.open(filenameToSave);

  for (int i = 0; i < codeLength; i++)
  {
    writeFile << codeHandlingArray[i];
  }
}