#include "../addMoreSpaceTo/addMoreSpaceTo.h"
#include "../deleteExtraSpace/deleteExtraSpace.h"

void addSpacesAroundOperators(char codeHandlingArray[], int *codeLength)
{
  char *buffer = new char[*codeLength]; // буфер для форматирования
  int nowChar = 0;
  int bufferLength = *codeLength;

  bool commentModeSingle = false; // Режим комментария, чтобы не учитывать закомментированные символы
  bool commentModeMulty = false;  // Режим многострочного, блочного комментария

  for (int i = 0; i < *codeLength; i++)
  {

    if (commentModeSingle)
    {
      if ((codeHandlingArray[i] == '\n'))
      {
        commentModeSingle = false;
        addMoreSpaceTo(&*buffer, &bufferLength, 1); // увеличиваем размер буфера
        buffer[nowChar] = '\n';
        nowChar++;
      }
    }
    else if (commentModeMulty)
    {
      if ((codeHandlingArray[i + 1] == '/') && (codeHandlingArray[i] == '*'))
      {
        commentModeMulty = false;
        addMoreSpaceTo(&*buffer, &bufferLength, 2); // увеличиваем размер буфера
        buffer[nowChar] = '*';
        nowChar++;
        buffer[nowChar] = '/';
        nowChar++;
      }
    }
    else // обрабатываем символы только если не режим комментария
    {
      if (codeHandlingArray[i] == '/')
      {
        if ((codeHandlingArray[i + 1] == '/'))
        {
          commentModeSingle = true;
          addMoreSpaceTo(&*buffer, &bufferLength, 3); // увеличиваем размер буфера
          buffer[nowChar] = ' ';                      // ЭТО ТОЛЬКО НЕ ПОСЛЕ ПЕРЕНОСА СТРОКИ
          nowChar++;
          buffer[nowChar] = '/';
          nowChar++;
          buffer[nowChar] = '/';
          nowChar++;
        }
        else if ((codeHandlingArray[i + 1] == '*'))
        {
          commentModeMulty = true;
          addMoreSpaceTo(&*buffer, &bufferLength, 3); // увеличиваем размер буфера
          buffer[nowChar] = ' ';
          nowChar++;
          buffer[nowChar] = '/';
          nowChar++;
          buffer[nowChar] = '*';
          nowChar++;
        }
        else
        {
          addMoreSpaceTo(&*buffer, &bufferLength, 3); // увеличиваем размер буфера
          buffer[nowChar] = ' ';
          nowChar++;
          buffer[nowChar] = '/';
          nowChar++;
          buffer[nowChar] = ' ';
          nowChar++;
        }
      }
      else if (codeHandlingArray[i] == '=')
      {
        buffer[nowChar] = ' ';
        nowChar++;
        buffer[nowChar] = '=';
        nowChar++;
        buffer[nowChar] = ' ';
        nowChar++;
      }
      else if ((codeHandlingArray[i] == '=') && (codeHandlingArray[i + 1] == '='))
      {
        buffer[nowChar] = ' ';
        nowChar++;
        buffer[nowChar] = '=';
        nowChar++;
        buffer[nowChar] = '=';
        nowChar++;
        buffer[nowChar] = ' ';
        nowChar++;
      }
      else if ((codeHandlingArray[i] == '+') && (codeHandlingArray[i + 1] != '+')) //если не инкрементирование
      {
        buffer[nowChar] = ' ';
        nowChar++;
        buffer[nowChar] = '+';
        nowChar++;
        buffer[nowChar] = ' ';
        nowChar++;
      }
      else if ((codeHandlingArray[i] == '-') && (codeHandlingArray[i + 1] != '-')) // если не декрементирование
      {
        buffer[nowChar] = ' ';
        nowChar++;
        buffer[nowChar] = '-';
        nowChar++;
        buffer[nowChar] = ' ';
        nowChar++;
      }
      else if (codeHandlingArray[i] == '*')
      {
        buffer[nowChar] = ' ';
        nowChar++;
        buffer[nowChar] = '*';
        nowChar++;
        buffer[nowChar] = ' ';
        nowChar++;
      }
      else if ((codeHandlingArray[i] == '/'))
      {
        buffer[nowChar] = ' ';
        nowChar++;
        buffer[nowChar] = '/';
        nowChar++;
        buffer[nowChar] = ' ';
        nowChar++;
      }
      else if ((codeHandlingArray[i] == '<') && (codeHandlingArray[i + 1] == '<'))
      {
        buffer[nowChar] = ' ';
        nowChar++;
        buffer[nowChar] = '<';
        nowChar++;
        buffer[nowChar] = '<';
        nowChar++;
        buffer[nowChar] = ' ';
        nowChar++;
      }
      else if ((codeHandlingArray[i] == '>') && (codeHandlingArray[i + 1] == '>'))
      {
        buffer[nowChar] = ' ';
        nowChar++;
        buffer[nowChar] = '>';
        nowChar++;
        buffer[nowChar] = '>';
        nowChar++;
        buffer[nowChar] = ' ';
        nowChar++;
      }
      else if ((codeHandlingArray[i] == '%'))
      {
        buffer[nowChar] = ' ';
        nowChar++;
        buffer[nowChar] = '%';
        nowChar++;
        buffer[nowChar] = ' ';
        nowChar++;
      }
      else if ((codeHandlingArray[i] == '!') && (codeHandlingArray[i + 1] == '='))
      {
        buffer[nowChar] = ' ';
        nowChar++;
        buffer[nowChar] = '!';
        nowChar++;
        buffer[nowChar] = '=';
        nowChar++;
        buffer[nowChar] = ' ';
        nowChar++;
      }
    }
  }
  if (*codeLength < bufferLength)
  {
    int difference = bufferLength - *codeLength;
    addMoreSpaceTo(&*codeHandlingArray, &*codeLength, difference);
  }
  else if (*codeLength > bufferLength)
  {
    int difference = *codeLength - bufferLength;
    deleteExtraSpace(&*codeHandlingArray, &*codeLength, difference);
  }
  strcpy(&*codeHandlingArray, buffer);
  delete buffer;
}
