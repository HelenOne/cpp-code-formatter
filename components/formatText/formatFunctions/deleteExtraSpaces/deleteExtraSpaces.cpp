#include "../../../../String.h"

String deleteExtraSpaces(String codeHandlingString)
{
  String result;
  bool thereIsOneSpaceAlredy = false;  // проверка на повторяющиеся пробелы
  bool thereIsTwoWrapsAlready = false; // проверка на то, что переносов строк больше 2 подряд
  int wrapsNumber = 0;
  for (int i = 0; i < codeHandlingString.length(); i++)
  {
    // не забыть учесть режим комментария и строки!!!
    //Убрать все пробелы после переноса и до переноса!!!
    if (wrapsNumber == 2)
    {
      thereIsTwoWrapsAlready = true;
    }
    if (((codeHandlingString[i] == ' ') || (codeHandlingString[i] == '\t')) && (!thereIsOneSpaceAlredy))
    {
      if ((codeHandlingString[i - 1] != '\n') && (codeHandlingString[i + 1] != '\n')) // Не учитывать все пробелы после переноса и до переноса
      {
        result += " ";
        thereIsOneSpaceAlredy = true;
      }
    }
    else if ((codeHandlingString[i] == ' ') || (codeHandlingString[i] == '\t') && ((thereIsOneSpaceAlredy) || (codeHandlingString[i - 1] != '\n') || (codeHandlingString[i + 1] != '\n')))
    {
      // ignore symbols
    }
    else if ((codeHandlingString[i] == '\n') && (!thereIsTwoWrapsAlready))
    {
      result += "\n";
      wrapsNumber++;
    }
    else if ((codeHandlingString[i] == '\n') && (thereIsTwoWrapsAlready))
    {
      // ignore symbols
    }
    else
    {
      if (thereIsOneSpaceAlredy)
      {
        thereIsOneSpaceAlredy = false;
      }
      if ((thereIsTwoWrapsAlready))
      {
        wrapsNumber = 0;
        thereIsTwoWrapsAlready = false;
      }
      char buffer[2] = {codeHandlingString[i], '\0'};
      result += buffer;
    }
  }
  return result;
}