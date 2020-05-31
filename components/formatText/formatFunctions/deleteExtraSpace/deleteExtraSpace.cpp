#include <Windows.h>
#include <stdlib.h>
#include <iostream>
#include <fstream>

void deleteExtraSpace(char array[], int *length, int decrease)
{
  char *p = array;
  char *newArray = new char[*length - decrease];
  strcpy(newArray, array);
  array = newArray;
  delete p;
  *length -= decrease;
}