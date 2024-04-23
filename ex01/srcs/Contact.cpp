#include "../headers/Contact.hpp"

Contact::Contact()
{
    // std::cout << "Contact has been created" << std::endl;
}

Contact::~Contact()
{
    // std::cout << "Contact has been destroyed" << std::endl;
}

void Contact::set_infos(std::string tab_input[])
{
    first_name = tab_input[0];
    last_name = tab_input[1];
    nickname = tab_input[2];
    phone_number = tab_input[3];
    darkest_secret = tab_input[4];
}

bool Contact::verify_form(std::string tab_input[])
{
    int i = 0;
    
    if (!numbers_only(tab_input[3]))
    {
        std::cout << "Invalid form : the phone number must contain numbers only." << std::endl;
        return (false);
    }
    while (i < 5)
    {
        if (tab_input[i].empty() || white_spaces_only(tab_input[i]))
        {
            std::cout << "Invalid form : you have note filled in all the fields." << std::endl;
            return (false);
        }
        i++;
    }
    return (true);
}

bool Contact::fill_form(void)
{
    std::string input[5];

    std::cout << "First name:" << std::endl;
    std::getline(std::cin, input[0]);
    ctrld_pressed();
    std::cout << "Last name:" << std::endl;
    std::getline(std::cin, input[1]);
    ctrld_pressed();
    std::cout << "Nickname:" << std::endl;
    std::getline(std::cin, input[2]);
    ctrld_pressed();
    std::cout << "Phone number:" << std::endl;
    std::getline(std::cin, input[3]);
    ctrld_pressed();
    std::cout << "Darkest secret:" << std::endl;
    std::getline(std::cin, input[4]);
    ctrld_pressed();

    if (!verify_form(input))
        return (false);
    set_infos(input);
    return (true);
}

void Contact::display_contact(void)
{
    std::cout << "First name: " << first_name << std::endl;
    std::cout << "Last name: " << last_name << std::endl;
    std::cout << "Nickname: " << nickname << std::endl;
    std::cout << "Phone number: " << phone_number << std::endl;
    std::cout << "Darkest secret: " << darkest_secret << std::endl;
}

std::string Contact::get_first_name(void) const
{
    return (first_name);
}

std::string Contact::get_last_name(void) const
{
    return (last_name);
}

std::string Contact::get_nickname(void) const
{
    return (nickname);
}

std::string Contact::get_phone_number(void) const
{
    return (phone_number);
}

std::string Contact::get_darkest_secret(void) const
{
    return (darkest_secret);
}
