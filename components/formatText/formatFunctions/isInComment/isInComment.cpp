#include "../../../../String.h"

bool isInComment(int orderNumber, String codeHandling)
{

  bool commentModeSingle = false; // Режим комментария, чтобы не учитывать закомментированные символы
  bool commentModeMulty = false;  // Режим многострочного, блочного комментария

  for (int i = 1; i < orderNumber; i++)
  {
    if (!commentModeSingle && !commentModeMulty) // Если мы не в комментарии сейчас
    {
      if ((codeHandling[i - 1] == '/') && (codeHandling[i] == '/'))
      {
        commentModeSingle = true;
      }
      else if ((codeHandling[i - 1] == '/') && (codeHandling[i] == '*'))
      {
        commentModeMulty = true;
      }
    }
    else // Если мы в комментарии
    {
      if (commentModeSingle && codeHandling[i + 1] == '\n')
      {
        commentModeSingle = false;
      }
      if (commentModeMulty && codeHandling[i - 1] == '*' && codeHandling[i] == '/')
      {
        commentModeMulty = false;
      }
    }
  }

  return (commentModeSingle || commentModeMulty);
}