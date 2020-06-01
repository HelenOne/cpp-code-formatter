#include <Windows.h>
#include <stdlib.h>
#include <iostream>
#include <fstream>

#include "../format/format.h"
#include "../fileExist/fileExist.h"

void GUI()
{

  setlocale(LC_ALL, "rus");

  char filename[256] = "1test.txt";
  while (!fileExist(filename))
  {
    std::wcout << std::endl
               << L"Введите путь к файлу, который хотите отформатировать"
               << L" (или перетащите с помощью drag&drop) и нажмите enter:"
               << std::endl;

    std::cin.getline(filename, 256, '\n');
    std::cout << std::endl;
    // system("cls");

    if (!fileExist(filename))
    {
      std::wcout << L"Не удалось открыть файл ("
                 << filename
                 << L")! \n"
                 << L"Попробуйте ввести название снова \n";
    }
  }

  // std::wcout
  //     << L"Введите путь к файлу, в котором вы хотите сохранить отформатированный код"
  //     << L" (или нажмите enter и код автоматически сохранится в "
  //     << filename
  //     << "):"
  //     << std::endl;

  char filenameToSave[256] = "f.txt";
  // std::cin.getline(filenameToSave, 256, '\n');

  if (filenameToSave[0] == '\0')
  {
    strcpy(filenameToSave, filename);
  }

  format(filename, filenameToSave);

  // system("cls");

  std::wcout << std::endl
             << L"Файл \""
             << filename
             << L"\" успешно отформатирован и сохранен!"
             << std::endl;
}
