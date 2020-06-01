#include <iostream>
#include <fstream>
#include <Windows.h>
#include <stdlib.h>

#include "../formatText/formatText.h"
#include "../formatText/formatFunctions/addMoreSpaceTo/addMoreSpaceTo.h"
#include "../../String.h"

void format(char filename[], char filenameToSave[])
{

  setlocale(LC_ALL, "rus");

  // создание потока для чтения файла и открытие файла для дальнейшего форматирования
  std::ifstream readFile;
  readFile.open(filename);
  if (!readFile.is_open())
  {
    std::wcout << L"Не удалось открыть файл (";
    std::cout << filename
              << ")! \n";
  }

  String codeHandling = "";
  // String s;

  while (!readFile.eof())
  {
    char buffer;
    readFile.get(buffer);
    char bufferArr[2] = {buffer, '\0'};
    std::cout << bufferArr;
    codeHandling += bufferArr;
  }
  std::cout << "pushing completed\n";

  std::cout << codeHandling;
  // int codeLength = 0;
  // int maxStringLength = 100000;

  // char *codeHandlingArray = new char[codeLength]; //Сюда записываю код, чтобы обработать и записать отформатированный код в новый файл
  // char currentRowInReadFile[maxStringLength];     // массив для получения отдельных строк из исходного файла

  // int codeHandlingArrayChar = 0;

  // int codeRowNumber = 0; // номер обрабатываемой строки

  // // цикл для записи исходного кода в массив символов codeHandlingArray
  // while (!readFile.eof())
  // {
  //   // std::cout << "Debug" << std::endl;

  //   readFile.getline(currentRowInReadFile, maxStringLength, '\0');

  //   int currentChar = 0;
  //   while (currentRowInReadFile[currentChar] != '\0')
  //   {

  //     addMoreSpaceTo(codeHandlingArray, &codeLength, 1);
  //     if (codeHandlingArray[codeHandlingArrayChar])
  //     {
  //       codeHandlingArray[codeHandlingArrayChar] = currentRowInReadFile[currentChar];
  //       currentChar++;
  //       codeHandlingArrayChar++;
  //     }
  //     else
  //     {
  //       std::wcout << L"Ошибка! Элемент не найден";
  //     }
  //   }

  //   if (readFile.eof())
  //   {
  //     std::wcout << L"Файл успешно обработан \n";
  //   }
  // }
  // for (int i = 0; i < codeLength; i++)
  // {
  //   std::cout << codeHandlingArray[i];
  // }

  // readFile.close(); // программа прочитала исходный файл, сохранила его в массив, закрыла поток

  // // здесь маcсив форматируется

  // formatText(codeHandlingArray, &codeLength);

  // std::ofstream writeFile; // поток для записи в новый файл обработанного массива
  // writeFile.open(filenameToSave);

  // for (int i = 0; i < codeLength; i++)
  // {
  //   writeFile << codeHandlingArray[i];
  // }
}