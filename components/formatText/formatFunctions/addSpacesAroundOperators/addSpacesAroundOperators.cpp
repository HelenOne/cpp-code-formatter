#include "../addMoreSpaceTo/addMoreSpaceTo.h"
#include "../deleteExtraSpace/deleteExtraSpace.h"
#include "../../../../String.h"
#include "../isInComment/isInComment.h"

String addSpacesAroundOperators(String codeHandling)
{
  String result = "";
  int nowChar = 0;

  for (int i = 0; i < codeHandling.length(); i++)
  {
    if (isInComment(i, codeHandling))
    // Проверка, что сейчас в комментарии
    {
      char buffer[2] = {codeHandling[i], '\0'};

      result += buffer;
    }
    else // обрабатываем символы только если не режим комментария
    {

      if ((codeHandling[i] == '=') && (codeHandling[i - 1] != '=') && (codeHandling[i + 1] != '=') && (codeHandling[i - 1] != '!') && (codeHandling[i - 1] != '-') && (codeHandling[i - 1] != '+'))
      {
        result += " = ";
      }
      else if ((codeHandling[i] == '=') && (codeHandling[i + 1] == '='))
      {
        result += " == ";
        i++;
      }
      else if ((codeHandling[i] == '+') && (codeHandling[i - 1] != '+') && (codeHandling[i + 1] != '+')) //если не инкрементирование
      {
        result += " + ";
      }
      else if ((codeHandling[i] == '-') && (codeHandling[i - 1] != '-') && (codeHandling[i + 1] != '-')) // если не декрементирование
      {
        result += " - ";
      }
      else if (codeHandling[i] == '*')
      {
        result += " * ";
      }
      // else if ((codeHandling[i] == '/'))
      // {
      //   result += " / ";
      // }
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
        i++;
      }
      else if ((codeHandling[i] == '-') && (codeHandling[i + 1] == '='))
      {
        result += " -= ";
        i++;
      }

      else
      {
        char buffer[2] = {codeHandling[i], '\0'};
        result += buffer;
      }
    }
  }
  return result;
}
