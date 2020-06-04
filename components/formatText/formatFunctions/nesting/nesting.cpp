#include "../../../../String.h"

String nesting(String codeHandlingString)
{
  int nestingLevel = 0;
  String result;
  for (int i = 0; i < codeHandlingString.length(); i++)
  {
    if ((codeHandlingString[i] == ' ') && ((codeHandlingString[i - 1] == '{') || (codeHandlingString[i - 1] == '}')))
    {
      i++; // Игнорирование пробелов после "{" и "}"
    }
    if (codeHandlingString[i] == '{')
    {
      nestingLevel++;
      if (codeHandlingString[i - 1] != '\n')
      {
        result += "\n";
      }
      for (int tabs = 0; tabs < nestingLevel - 1; tabs++)
      {
        result += "\t";
      }
      result += "{";
      if (codeHandlingString[i + 1] != '\n')
      {
        result += "\n";
      }
      for (int tabs = 0; tabs < nestingLevel; tabs++)
      {
        result += "\t";
      }
    }
    else if (codeHandlingString[i] == '}')
    {
      nestingLevel--;
      if ((codeHandlingString[i - 1] != '\n'))
      {
        result += "\n";
      }
      for (int tabs = 0; tabs < nestingLevel; tabs++)
      {
        result += "\t";
      }
      result += "}";
      if ((codeHandlingString[i + 1] != '\n') && (codeHandlingString[i + 1] != '}'))
      {
        result += "\n";
      }
      for (int tabs = 0; tabs < nestingLevel; tabs++)
      {
        result += "\t";
      }
    }
    else if ((codeHandlingString[i] == '\n') && (codeHandlingString[i + 1] != '}') && (codeHandlingString[i + 1] != '{'))
    {
      result += "\n";
      for (int tabs = 0; tabs < nestingLevel; tabs++)
      {
        result += "\t";
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
