#include "./formatFunctions/addSpacesAroundOperators/addSpacesAroundOperators.h"
#include "./formatFunctions/deleteExtraSpaces/deleteExtraSpaces.h"
#include "./formatFunctions/handleSemicolon/handleSemicolon.h"
#include "./formatFunctions/nesting/nesting.h"
#include "../../String.h"

String formatText(String codeHandling)
{
  codeHandling = addSpacesAroundOperators(codeHandling);
  codeHandling = deleteExtraSpaces(codeHandling);
  codeHandling = handleSemicolon(codeHandling);
  codeHandling = nesting(codeHandling);

  return codeHandling;
}