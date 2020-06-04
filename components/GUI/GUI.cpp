#include <Windows.h>
#include <stdlib.h>
#include <iostream>
#include <fstream>

#include "../format/format.h"
#include "../fileExist/fileExist.h"

void GUI()
{

  setlocale(LC_ALL, "rus");

  char filename[256];
  while (!fileExist(filename))
  {
    std::wcout << std::endl
               << L"Введите путь к файлу, который хотите отформатировать"
               << L" (или перетащите с помощью drag&drop) и нажмите enter:"
               << std::endl;

    std::cin.getline(filename, 256, '\n');
    std::cout << std::endl;

    if (!fileExist(filename))
    {
      std::wcout << L"Не удалось открыть файл ("
                 << filename
                 << L")! \n"
                 << L"Попробуйте ввести название снова \n";
    }
  }
  system("cls");

  char filenameToSave[256];

  std::wcout
      << L"Введите путь к файлу, в котором вы хотите сохранить отформатированный код"
      << L" (или нажмите enter и код автоматически сохранится в "
      << filename
      << "):"
      << std::endl;

  std::cin.getline(filenameToSave, 256, '\n');
  std::cout << std::endl;

  system("cls");

  if (filenameToSave[0] == '\0')
  {
    strcpy(filenameToSave, filename);
  }

  format(filename, filenameToSave);

  system("cls");

  std::wcout << std::endl
             << L"Файл \""
             << filename
             << L"\" успешно отформатирован и сохранен в "
             << filenameToSave
             << std::endl;
}
