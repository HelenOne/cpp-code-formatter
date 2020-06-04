#include "../../../../String.h"
#include "../isInComment/isInComment.h"
#include "../isInString/isInString.h"

String handleCycles(String codeHandlingString)
{
  String result;
  for (int i = 0; i < codeHandlingString.length(); i++)
  {
    if (isInComment(i, codeHandlingString) || isInString(i, codeHandlingString))
    {
      char buffer[2] = {codeHandlingString[i], '\0'};
      result += buffer;
    }
    else
    {
      if ((codeHandlingString[i] == 'f') && (codeHandlingString[i + 1] == 'o') && (codeHandlingString[i + 2] == 'r'))
      {
        if (codeHandlingString[i + 3] != ' ')
        {
          result += "for ";
        }
        else
        {
          result += "for";
        }
        i += 2;
      }

      else if ((codeHandlingString[i] == 's') && (codeHandlingString[i + 1] == 'w') && (codeHandlingString[i + 2] == 'i') && (codeHandlingString[i + 3] == 't') && (codeHandlingString[i + 4] == 'c') && (codeHandlingString[i + 5] == 'h'))
      {
        if (codeHandlingString[i + 6] != ' ')
        {
          result += "switch ";
        }
        else
        {
          result += "switch";
        }
        i += 5;
      }

      else if ((codeHandlingString[i] == 'w') && (codeHandlingString[i + 1] == 'h') && (codeHandlingString[i + 2] == 'i') && (codeHandlingString[i + 3] == 'l') && (codeHandlingString[i + 4] == 'e'))
      {
        if (codeHandlingString[i + 5] != ' ')
        {
          result += "while ";
        }
        else
        {
          result += "while";
        }
        i += 3;
      }

      else if ((codeHandlingString[i] == 'i') && (codeHandlingString[i + 1] == 'f'))
      {
        if (codeHandlingString[i + 3] != ' ')
        {
          result += "if ";
        }
        else
        {
          result += "if";
        }
        i += 1;
      }

      else
      {
        char buffer[2] = {codeHandlingString[i], '\0'};
        result += buffer;
      }
    }
  }

  return result;
}