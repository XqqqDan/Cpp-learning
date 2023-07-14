#include <iostream>
#include <sstream>
#include <string>
#include <limits>

// string和其他类型的转换

int String_To_Int() // string转化成int
{
    std::string str;
    int i = 0;
    std::cout << "请输入具体内容:" << std::endl;
    while (1)
    {
        std::cin >> str;
        std::stringstream strStream(str);
        strStream >> i;
        if (strStream.bad())
        {
            throw std::runtime_error("strStream is corrupted");
        }
        if (strStream.fail())
        {
            strStream.clear();
            strStream.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            std::cout << "string format error, please try again" << std::endl;
            continue;
        }
        std::cout << "转化完成" << std::endl;
        return i;
    }
}

std::string Int_To_String() // int转化成string
{
    int srcI = 0;
    std::stringstream strStream;
    std::cout << "请输入具体内容:" << std::endl;
    while (1)
    {

        std::cin >> srcI;
        // std::cout << srcI << std::endl;
        strStream << srcI << std::endl;
        if (strStream.bad())
        {
            throw std::runtime_error("strStream is corrupted");
        }
        if (strStream.fail()) //?????????????
        {
            strStream.clear();
            strStream.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            std::cout << "int format error, please try again" << std::endl;
            continue;
        }

        std::cout << "转化完成" << std::endl;
        return strStream.str();
    }
}

void String_To_Words()
{
    std::string srcString("hello world hello");
    std::string destString;
    // std::cin >> srcString;??????????
    std::stringstream strStream(srcString);
    while (strStream >> destString)
    {
        std::cout << destString << std::endl;
    }
    if (strStream.bad())
    {
        throw std::runtime_error("strStream is corrupted");
    }
}

int main()
{
    int input = 0;
    std::string str;
    std::cout << "请选择模式:" << std::endl;
    std::cout << "1: string 转 int" << std::endl;
    std::cout << "2: int 转 string" << std::endl;
    std::cout << "3: 字符串去空格" << std::endl;
    std::cout << "请输入[1/2/3]:" << std::endl;

    while (std::cin >> input, !std::cin.eof())
    {
        if (std::cin.bad())
        {
            throw std::runtime_error("cin is corrupted");
        }
        if (std::cin.fail())
        {
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            std::cout << "请输入[1/2/3]:" << std::endl;
            continue;
        }
        if ((input != 1) && (input != 2) && (input != 3))
        {
            std::cout << "请输入[1/2/3]:" << std::endl;
            continue;
        }
        break;
    }

    if (input == 1)
    {
        std::cout << String_To_Int() << std::endl;
    }
    else if (input == 2)
    {
        std::cout << Int_To_String() << std::endl;
    }
    else
    {
        std::cout << "请输入文本:" << std::endl;
        String_To_Words();
    }
    return 0;
}
