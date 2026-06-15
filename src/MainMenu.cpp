#include "mainmenu.h"
#include "maxhitmenu.h"
#include <iostream>

MaxHitMenu max_hit_menu;

enum Choices
{
    TOP_MENU,
    MAX_HIT,
    ABOUT,
    EXIT
};

void MainMenu::Navigate()
{
    enum Choices choice = TOP_MENU;
    while(choice != EXIT)
    {
        switch(choice)
        {
            case TOP_MENU:
                TopMenu();
                break;
            case MAX_HIT:
                max_hit_menu.Navigate();
                TopMenu();
                break;
            case ABOUT:
                AboutMenu();
                break;
            default:
                throw std::runtime_error("unhandled choice");
                break;
        }
        choice = (Choices)ProcessMenu();
    }
}

void MainMenu::TopMenu()
{
    AddOption("Max Hit calc", (int)MAX_HIT);
    AddOption("About", (int)ABOUT);
    AddOption("Exit", (int)EXIT);
}

void MainMenu::AboutMenu()
{
    std::cout << "v0.1" << std::endl;
    AddOption("Back", (int)TOP_MENU);
}