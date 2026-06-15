#include "menu.h"
#include <iostream>

void Menu::DisplayMenu()
{
    for (int option = 0; option < current_options.size(); option++)
    {
        std::cout << option + 1 << ". " << current_options[option].text << std::endl;
    }
}

int Menu::GetAction()
{
    int choice;
    while(!(std::cin >> choice) || choice < 1 || choice > current_options.size())
    {
        std::cin.clear();
        std::cin.ignore();
    }
    std::cout << std::endl;
    return current_options[choice-1].action;
}

void Menu::AddOption(std::string text, int action)
{
    mo = new MenuOption(text, action);
    current_options.push_back(*mo);
}

int Menu::ProcessMenu()
{
    DisplayMenu();
    int action = GetAction();
    current_options.clear();
    return action;
}
