#include <iostream>
#include <fstream>
#include <string>
#include <limits>

// 让客户输入文件名称。如果文件不存在，则让客户重新输入文件名称，如果文件存在，则将文件内容全部输出

int main()
{
    std::string fileName;
    std::string fileContent;

    while (std::cin >> fileName, !std::cin.eof())
    {
        if (std::cin.bad())
        {
            throw std::runtime_error("cin is corrupted");
        }
        std::ifstream ifs(fileName);
        if (ifs.is_open())
        {
            while (std::getline(ifs, fileContent))
            {
                std::cout << fileContent << std::endl;
            }
            ifs.close();
        }
        else
        {
            ifs.clear();
            ifs.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            std::cout << "file not exist, please try again" << std::endl;
            continue;
        }
    }
    std::cout << "process complete" << std::endl;
    return 0;
}
