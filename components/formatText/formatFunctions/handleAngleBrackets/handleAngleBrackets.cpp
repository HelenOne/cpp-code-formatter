#include "../../../../String.h"
#include "../isInComment/isInComment.h"
#include "../isInString/isInString.h"

String handleAngleBrackets(String codeHandlingString)
{
  bool isInclude = false;
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
      if (codeHandlingString[i] == '#')
      {
        if (codeHandlingString[i + 1] == 'i')
        {
          if (codeHandlingString[i + 2] == 'n')
          {
            if (codeHandlingString[i + 3] == 'c')
            {
              if (codeHandlingString[i + 4] == 'l')
              {
                if (codeHandlingString[i + 5] == 'u')
                {
                  if (codeHandlingString[i + 6] == 'd')
                  {
                    if (codeHandlingString[i + 7] == 'e')
                    {
                      isInclude = true;
                    }
                  }
                }
              }
            }
          }
        }
      }
      if (isInclude)
      {
        if (codeHandlingString[i] == '<')
        {
          if (codeHandlingString[i - 1] != ' ')
          {
            result += " ";
          }
          result += "<";
        }
        else if (codeHandlingString[i] == '>')
        {
          isInclude = false;
          result += ">";
          if (codeHandlingString[i + 1] != '\n')
          {
            result += "\n";
          }
        }
        else
        {
          char buffer[2] = {codeHandlingString[i], '\0'};
          result += buffer;
        }
      }
      else
      {
        if ((codeHandlingString[i] == '<') && (codeHandlingString[i - 1] != '<') && codeHandlingString[i + 1] != '<')
        {
          result += " < ";
        }
        else if ((codeHandlingString[i] == '>') && (codeHandlingString[i - 1] != '>') && codeHandlingString[i + 1] != '>')
        {
          result += " > ";
        }
        else
        {
          char buffer[2] = {codeHandlingString[i], '\0'};
          result += buffer;
        }
      }
    }
  }
  return result;
}