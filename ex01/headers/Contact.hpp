#ifndef CONTACT_HPP
# define CONTACT_HPP

# include <string>
# include <cstring>
# include <iostream>

class Contact
{
    private:
        std::string first_name;
        std::string last_name;
        std::string nickname;
        std::string phone_number;
        std::string darkest_secret;

    public:
        Contact();
        ~Contact();
        void set_infos(std::string tab_input[]);
        bool verify_form(std::string tab_input[]);
        bool fill_form(void);
        void display_contact(void);
        std::string get_first_name(void) const;
        std::string get_last_name(void) const;
        std::string get_nickname(void) const;
        std::string get_phone_number(void) const;
        std::string get_darkest_secret(void) const;
};

bool    numbers_only(std::string s);
bool    white_spaces_only(std::string s);
void    ctrld_pressed(void);

#endif
