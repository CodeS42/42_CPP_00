#ifndef PHONEBOOK_HPP
# define PHONEBOOK_HPP

# include <sstream>
# include "Contact.hpp"

class PhoneBook
{
    private:
        Contact tab_contacts[8];
        int count_c;

    public:
        PhoneBook();
        ~PhoneBook();
        void add_contact(void);
        void search(void);
        int is_valid_number(std::string input);
        void display_phonebook(void);
        void display_phonebook2(std::string var);
};

#endif