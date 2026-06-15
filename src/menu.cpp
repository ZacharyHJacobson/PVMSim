#include "menu.h"
#include <iostream>

void Menu::DisplayMenu()
{
    for (int option = 0; option < current_options.size(); option++)
    {
        std::cout << option + 1 << ". " << current_options[option].text << std::endl;
    }
}

std::string Menu::SelectOption(int choice)
{
    choice -= 1;
    if (choice < 0 || choice >= current_options.size()) return {};
    return current_options[choice].menu_name;
}
