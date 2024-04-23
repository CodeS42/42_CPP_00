#include <iostream>
#include <cctype>
#include <string>

void    toupper_str(int argc, char *argv[])
{
    std::string str;
    int len;
    int j;
    int i = 0;

    while (++i < argc)
    {
        j = -1;
        str = argv[i];
        len = str.length();
        while (++j < len)
            argv[i][j] = toupper(argv[i][j]);
    }
}

int main(int argc, char *argv[])
{
    int i = 0;
    
    if (argc == 1)
    {
        std::cout << "* LOUD AND UNBEARABLE FEEDBACK NOISE *" << std::endl;
        return (0);
    }
    
    toupper_str(argc, argv);
    while (++i < argc)
        std::cout << argv[i];
    std::cout << std::endl;
    
    return (0);
}
