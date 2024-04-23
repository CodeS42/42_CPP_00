#include "../headers/PhoneBook.hpp"

PhoneBook::PhoneBook() : count_c(0)
{
    // std::cout << "PhoneBook has been created" << std::endl;
}

PhoneBook::~PhoneBook()
{
    // std::cout << "PhoneBook has been destroyed" << std::endl;
}

void PhoneBook::add_contact(void)
{
    int i = count_c;

    if (count_c > 7)
        i = count_c % 8;
    if (tab_contacts[i].fill_form())
        count_c++;
}

void PhoneBook::display_phonebook2(std::string var)
{
    int spaces;

    spaces = 10 - var.length();
    if (spaces < 0)
        std::cout << var.substr(0, 9) << ".|";
    else
    {
        while (spaces-- > 0)
            std::cout << " ";
        std::cout << var << "|";
    }
}

void PhoneBook::display_phonebook(void)
{
    int i = 0;

    std::cout << "---------------------------------------------" << std::endl;
    std::cout << "|     INDEX|FIRST NAME| LAST NAME|  NICKNAME|" << std::endl;
    std::cout << "---------------------------------------------" << std::endl;
    while (i < 8)
    {
        if (!tab_contacts[i].get_first_name().empty())
        {
            std::cout << "|         " << i << "|";
            display_phonebook2(tab_contacts[i].get_first_name());
            display_phonebook2(tab_contacts[i].get_last_name());
            display_phonebook2(tab_contacts[i].get_nickname());
        }
        else 
            std::cout << "|..........|..........|..........|..........|";
        std::cout << std::endl;
        i++;
    }
    std::cout << "---------------------------------------------" << std::endl;
}

int PhoneBook::is_valid_number(std::string input)
{
    int index = -1;

    if (input.empty() || input.length() > 1)
        return (index);
    else if (input[0] >= '0' && input[0] <= '7')
    {
        std::stringstream conv(input);
        conv >> index;
    }
    return (index);
}

void PhoneBook::search(void)
{
    std::string input;
    int i;

    display_phonebook();
    std::cout << "Enter the contact index you wish to display (0 to 7):" << std::endl;
    std::getline(std::cin, input);
    ctrld_pressed();
    i = is_valid_number(input);
    if (i != -1)
    {
        if (!tab_contacts[i].get_first_name().empty())
            tab_contacts[i].display_contact();
        else
            std::cout << "No contact registered at this index." << std::endl;
    }
    else
        std::cout << "Invalid input." << std::endl;
}
