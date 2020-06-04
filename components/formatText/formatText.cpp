#include "./formatFunctions/addSpacesAroundOperators/addSpacesAroundOperators.h"
#include "./formatFunctions/deleteExtraSpaces/deleteExtraSpaces.h"
#include "./formatFunctions/handleSemicolon/handleSemicolon.h"
#include "./formatFunctions/nesting/nesting.h"
#include "./formatFunctions/handleAngleBrackets/handleAngleBrackets.h"
#include "./formatFunctions/handleCycles/handleCycles.h"
#include "../../String.h"

String formatText(String codeHandling)
{
  codeHandling = deleteExtraSpaces(codeHandling);        // удаление лишних пробелов, табов и переносов строки
  codeHandling = addSpacesAroundOperators(codeHandling); // добавление пробелов вокруг операторов
  codeHandling = handleSemicolon(codeHandling);          // обработка точек с запятой
  codeHandling = nesting(codeHandling);                  // добавление вложенности (блоки кода, switch-case)
  codeHandling = handleAngleBrackets(codeHandling);      // обработка "<" и ">"
  codeHandling = handleCycles(codeHandling);             // обработка циклов

  return codeHandling;
}