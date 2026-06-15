#include "maxhitmenu.h"
#include <iostream>

enum Choices
{
    TOP_MENU,
    DEMO,
    EXIT
};

void MaxHitMenu::Navigate()
{
    enum Choices choice = TOP_MENU;
    while(choice != EXIT)
    {
        switch(choice)
        {
            case DEMO:
                std::cout << "Max hit demo goes here" << std::endl;
                TopMenu();
                break;
            case TOP_MENU:
                TopMenu();
                break;
            default:
                throw std::runtime_error("unhandled choice");
                break;
        }
        choice = (Choices)ProcessMenu();
    }
}

void MaxHitMenu::TopMenu()
{
    AddOption("Demo", (int)DEMO);
    AddOption("Back", (int)EXIT);
}
