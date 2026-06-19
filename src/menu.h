#pragma once

#include <map>
#include <string>
#include <vector>

struct MenuOption
{
    std::string text;
    int action;

    MenuOption(std::string t, int a) : text(t), action(a) {}
};

class Menu
{
    private:
        int GetAction();
        void DisplayMenu();
        std::map<std::string, std::vector<MenuOption>> menus;
        std::string menu_name;
        std::vector<MenuOption> current_options;
        MenuOption* mo;
    protected:
        int ProcessMenu();
        virtual void TopMenu() = 0;
        void AddOption(std::string, int);
    public:
        virtual void Navigate() = 0;
};