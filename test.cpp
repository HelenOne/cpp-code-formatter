#include <iostream>
#include <fstream>
#include "./format/format.cpp"
#include <stdio.h>
#include <windows.h>

int main()
{
  HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
  CONSOLE_SCREEN_BUFFER_INFO consoleInfo;
  WORD saved_attributes;

  /* Save current attributes */
  GetConsoleScreenBufferInfo(hConsole, &consoleInfo);
  saved_attributes = consoleInfo.wAttributes;

  for (int i = 1; i <= 1; i++)
  {

    char filename[18] = "./tests/test";
    filename[12] = i + '0';
    filename[13] = '.';
    filename[14] = 'c';
    filename[15] = 'p';
    filename[16] = 'p';

    char filenameFormatted[28] = "./tests/test_formatted";
    filenameFormatted[22] = i + '0';
    filenameFormatted[23] = '.';
    filenameFormatted[24] = 'c';
    filenameFormatted[25] = 'p';
    filenameFormatted[26] = 'p';

    format(filename, filenameFormatted);

    char stubfile[23] = "./tests/test_stub";
    stubfile[17] = i + '0';
    stubfile[18] = '.';
    stubfile[19] = 'c';
    stubfile[20] = 'p';
    stubfile[21] = 'p';

    std::ifstream readStubFile;
    readStubFile.open(stubfile);
    if (!readStubFile.is_open())
    {
      std::cout << "Error with opening ("
                << stubfile
                << ")! \n";
      return 0;
    }

    char currentRowInStub[256];

    std::ifstream readFormattedFile;
    readFormattedFile.open(filenameFormatted);
    if (!readFormattedFile.is_open())
    {
      std::cout << "Error with opening ("
                << filenameFormatted
                << ")! \n";
      return 0;
    }
    char currentRowInFormatted[256];

    bool filesAreDifferent = false;
    int lastChar = 1;
    int lastRow = 1;
    while ((!readStubFile.eof()) && (!filesAreDifferent))
    {
      readStubFile.getline(currentRowInStub, 256, '\0');
      readFormattedFile.getline(currentRowInFormatted, 256, '\0');

      int currentChar = 0;
      while ((currentRowInStub[currentChar] != '\0') && (!filesAreDifferent))
      {

        if (currentRowInFormatted[currentChar] != currentRowInStub[currentChar])
        {
          lastChar = currentChar;
          lastRow++;

          filesAreDifferent = true;
        }

        currentChar++;
      }
      lastRow++;

      std::cout << std::endl;
      readStubFile.close();
    }

    if (filesAreDifferent)
    {
      SetConsoleTextAttribute(hConsole, FOREGROUND_RED);
      std::cout << "The test \""
                << filename
                << "\" is not passed! \n";
      std::cout << "(" << lastRow << ":" << lastChar << ") \n";
      SetConsoleTextAttribute(hConsole, saved_attributes);
    }
    else
    {
      SetConsoleTextAttribute(hConsole, FOREGROUND_GREEN);
      std::cout << "The test \""
                << filename
                << "\" is passed! \n";
      SetConsoleTextAttribute(hConsole, saved_attributes);
    }
  }

  return 0;
}