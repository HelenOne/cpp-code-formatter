#include <Windows.h>
#include <stdlib.h>
#include <iostream>
#include <fstream>

void addMoreSpaceTo(char array[], int *length, int increase)
{
  char *p = array;
  char *newArray = new char[*length + increase];
  strcpy(newArray, array);
  array = newArray;
  delete p;
  *length += increase;
}