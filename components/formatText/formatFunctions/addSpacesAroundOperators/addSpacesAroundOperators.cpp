#include "../addMoreSpaceTo/addMoreSpaceTo.h"
#include "../deleteExtraSpace/deleteExtraSpace.h"
#include "../../../../String.h"

String addSpacesAroundOperators(String codeHandling)
{
  String result = "";
  int nowChar = 0;

  bool commentModeSingle = false; // Режим комментария, чтобы не учитывать закомментированные символы
  bool commentModeMulty = false;  // Режим многострочного, блочного комментария

  for (int i = 0; i < codeHandling.length(); i++)
  {

    if (commentModeSingle)
    {
      if ((codeHandling[i] == '\n'))
      {
        commentModeSingle = false;
        result += "\n";
      }
    }
    else if (commentModeMulty)
    {
      if ((codeHandling[i + 1] == '/') && (codeHandling[i] == '*'))
      {
        commentModeMulty = false;
        result += "*";
        result += "/";
      }
    }
    else // обрабатываем символы только если не режим комментария
    {
      if (codeHandling[i] == '/')
      {
        if ((codeHandling[i + 1] == '/'))
        {
          commentModeSingle = true;
          if (result[result.length() - 1] == '\n')
          {
            result += " //";
          }
          else
          {
            result += "//";
          }
        }
        else if ((codeHandling[i + 1] == '*'))
        {
          commentModeMulty = true;
          if (result[result.length() - 1] == '\n')
          {
            result += "/*";
          }
          else
          {
            result += " /*";
          }
        }
        else
        {
          result += " / ";
        }
      }
      else if (codeHandling[i] == '=')
      {
        result += " = ";
      }
      else if ((codeHandling[i] == '=') && (codeHandling[i + 1] == '='))
      {
        result += " == ";
        i++;
      }
      else if ((codeHandling[i] == '+') && (codeHandling[i + 1] != '+')) //если не инкрементирование
      {
        result += " + ";
      }
      else if ((codeHandling[i] == '-') && (codeHandling[i + 1] != '-')) // если не декрементирование
      {
        result += " - ";
      }
      else if (codeHandling[i] == '*')
      {
        result += " * ";
      }
      else if ((codeHandling[i] == '/'))
      {
        result += " / ";
      }
      else if ((codeHandling[i] == '<') && (codeHandling[i + 1] == '<'))
      {
        result += " << ";
        i++;
      }
      else if ((codeHandling[i] == '>') && (codeHandling[i + 1] == '>'))
      {
        result += " >> ";
        i++;
      }
      else if ((codeHandling[i] == '%'))
      {
        result += " % ";
      }
      else if ((codeHandling[i] == '!') && (codeHandling[i + 1] == '='))
      {
        result += " != ";
        i++;
      }
      else
      {
        char buffer[1];
        buffer[0] = codeHandling[i];
        result += buffer;
      }
    }
  }
  return result;
}
