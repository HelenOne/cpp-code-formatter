#include "../../../../String.h"

bool isInString(int orderNumber, String codeHandlingString)
{
  String result;
  bool stringMode = false;
  bool symbolLiteralMode = false;
  for (int i = 0; i < orderNumber; i++)
  {
    if ((codeHandlingString[i] == '"') && (!stringMode))
    {
      stringMode = true;
    }
    else if ((codeHandlingString[i] == '\'') && (!symbolLiteralMode))
    {
      symbolLiteralMode = true;
    }
    else if ((codeHandlingString[i] == '"') && (stringMode))
    {
      stringMode = false;
    }
    else if ((codeHandlingString[i] == '\'') && (symbolLiteralMode))
    {
      symbolLiteralMode = false;
    }
  }
  return (stringMode || symbolLiteralMode);
}