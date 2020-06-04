#include "../../../../String.h"

String handleSemicolon(String codeHandlingString)
{
  bool isForCicle = false;
  int semicolonsNumberInForCicle = 0;
  String result;

  for (int i = 0; i < codeHandlingString.length(); i++)
  {
    if (codeHandlingString[i] == 'f' && codeHandlingString[i + 1] == 'o' && codeHandlingString[i + 2] == 'r')
    {
      isForCicle = true;
    }
    if (semicolonsNumberInForCicle == 2)
    {
      semicolonsNumberInForCicle = 0;
      isForCicle = false;
    }
    if ((codeHandlingString[i] == ';'))
    {
      if (isForCicle) // если ";" в цикле for (...)
      {
        if ((codeHandlingString[i + 1] != ' '))
        {
          result += "; ";
        }
        else
        {
          result += ";";
        }
        semicolonsNumberInForCicle++;
      }
      else // если не цикл for
      {
        if (codeHandlingString[i + 1] == ' ')
        {
          if (codeHandlingString[i + 2] == '/')
          {
            // do nothing
          }
          else
          {
            if (codeHandlingString[i + 1] != '\n')
            {
              result += ";\n";
            }
            else
            {
              result += ";";
            }
            i++; // Пропускаем пробел
          }
        }
        else
        {
          if (codeHandlingString[i + 1] == '/')
          {
            result += "; "; //  Добавляетсся пробел перед комментарием
          }
          else
          {
            if (codeHandlingString[i + 1] != '\n')
            {
              result += ";\n";
            }
            else
            {
              result += ";";
            }
          }
        }
        // result += ";\n"; // и тут проверить что переноса нет еще........
      }
    }
    else
    {
      char buffer[2] = {codeHandlingString[i], '\0'};
      result += buffer;
    }
  }
  return result;
}