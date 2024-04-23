#include "../headers/PhoneBook.hpp"
#include <cstdlib>
#include <cctype>

bool    numbers_only(std::string s)
{
    int i = 0;

    while (i < static_cast<int>(s.length()))
    {
        if (!std::isdigit(s[i++]))
            return (false);
    }
    return (true);    
}

bool    white_spaces_only(std::string s)
{
    int i = 0;

    while (i < static_cast<int>(s.length()))
    {
        if (!std::isspace(s[i++]))
            return (false);
    }
    return (true);
}

void    ctrld_pressed(void)
{
    if (std::cin.eof())
    {
        std::cout << "End Of File" << std::endl;
        std::exit(0);
    }  
}

void    manage_commands(std::string command, PhoneBook *phonebook)
{
    if (command == "ADD")
        phonebook->add_contact();
    else if (command == "SEARCH")
        phonebook->search();
    else if (command == "EXIT")
        std::exit(0);
    else
        std::cout << "The command you entered is invalid." << std::endl;
}

int main(int argc, char *argv[])
{
    std::string command;
    PhoneBook phonebook;

    (void)argv;
    if (argc > 1)
    {
        std::cerr << "Too much arguments" << std::endl;
        return (1);
    }
    while(1)
    {
        std::cout << "Enter a command (ADD, SEARCH, or EXIT):" << std::endl;
        std::getline(std::cin, command);
        ctrld_pressed();
        manage_commands(command, &phonebook);
    }
    return (0);
}
