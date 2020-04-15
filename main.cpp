// 9372 Громова "C++ code formatter"

#include <iostream>
#include <fstream>
#include "./format/format.cpp";

int main()
{
    std::ifstream readFile;
    std::cout << std::endl
              << "Write path to file you want to format and press enter:" << std::endl;
    char filename[256];
    std::cin.getline(filename, 256, '\n');
    readFile.open(filename);
    if (!readFile.is_open())
    {
        std::cout << "Error with opening! \n";
        return 0;
    }

    std::cout << std::endl;
    readFile.close();

    std::ofstream writeFile;

    std::cout << "Write path to file you want to save formatted code in and press enter (or press enter and code will be saved in " << filename << "):" << std::endl;
    char filenameToSave[256];
    std::cin.getline(filenameToSave, 256, '\n');
    if (filenameToSave[0] == '\0')
    {
        for (int i = 0; filename[i] != '\0'; i++)
        {
            filenameToSave[i] = filename[i];
        }
    }

    format(filename, filenameToSave);

    return 0;
}
