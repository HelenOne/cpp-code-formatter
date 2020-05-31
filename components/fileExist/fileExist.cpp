#include <Windows.h>
#include <stdlib.h>
#include <iostream>
#include <fstream>

bool fileExist(char filename[])
{
  std::ifstream readFile;
  readFile.open(filename);
  if (!readFile.is_open())
  {
    return false;
  }
  else
    return true;
}