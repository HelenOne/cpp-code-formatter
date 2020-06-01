#include "./formatFunctions/addSpacesAroundOperators/addSpacesAroundOperators.h"
#include "../../String.h"

String formatText(String codeHandling)
{
  codeHandling = addSpacesAroundOperators(codeHandling);
  return codeHandling;
}