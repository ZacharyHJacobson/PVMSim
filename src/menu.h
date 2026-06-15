#ifndef MENU
#define MENU

#include <map>
#include <string>
#include <vector>

struct MenuOption
{
    std::string text;
    std::string menu_name;

    MenuOption(std::string t, std::string mn) : text(t), menu_name(mn) {}
};

class Menu
{
    private:
        std::map<std::string, std::vector<MenuOption>> menus;
        std::string menu_name;
    protected:
        std::vector<MenuOption> current_options;
    public:
        virtual void Navigate() = 0;
        void DisplayMenu();
        std::string SelectOption(int);
};

#endif