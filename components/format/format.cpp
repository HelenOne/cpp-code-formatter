#include <iostream>
#include <fstream>
#include <Windows.h>
#include <stdlib.h>

#include "../formatText/formatText.h"
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

  String codeHandling = ""; // строка в которую копируется файл

  while (!readFile.eof())
  {
    char buffer;
    readFile.get(buffer);
    char bufferArr[2] = {buffer, '\0'};
    codeHandling += bufferArr;
  }

  readFile.close(); // программа прочитала исходный файл, сохранила его в строку, закрыла поток

  // // здесь строка форматируется
  String resultString = formatText(codeHandling);

  std::ofstream writeFile; // поток для записи в новый файл отформатированного кода
  writeFile.open(filenameToSave);

  for (int i = 0; i < resultString.length(); i++)
  {
    writeFile << resultString[i];
  }
  writeFile.close();
}