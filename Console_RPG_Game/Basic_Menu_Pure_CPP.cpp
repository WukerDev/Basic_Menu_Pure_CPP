#include <iostream>
#include <conio.h>
#include <windows.h> 
#include "Main Menu.hpp"
#define KEY_UP 87
#define KEY_UP2 72
#define KEY_DOWN 83
#define KEY_DOWN2 80
#define KEY_ENTER 13
int selected = 1;
int pressed;
std::string menu_base[5] = { "Play", "Help", "Exit", "Credits", "Github" };

void text_def(std::string text) { HANDLE h = GetStdHandle(STD_OUTPUT_HANDLE);  SetConsoleTextAttribute(h, 15); std::cout << text << std::endl;
};
void text_sel(std::string text) {
    HANDLE h = GetStdHandle(STD_OUTPUT_HANDLE);  SetConsoleTextAttribute(h, 240); std::cout << text << std::endl; SetConsoleTextAttribute(h, 15);
};

void menu() {
    if (selected == 0) {
        selected = sizeof(menu_base) / sizeof(menu_base[0]);
    };
    for (int i = 1; i <= sizeof(menu_base) / sizeof(menu_base[0]); i++) {
        if (i == selected) { text_sel(menu_base[i-1]); };
        if (i != selected) { text_def(menu_base[i-1]); };

    }
};

void selection() {
    while (true) {
        pressed = _getch();
        pressed = toupper(pressed);
        if (pressed == KEY_UP || pressed == KEY_UP2) { selected--; };
        if (pressed == KEY_DOWN  || pressed == KEY_DOWN2) { selected++; };
        system("CLS");
        menu();
    }
};

int main()
{
    menu();
    selection();
    std::cout << pressed;
}
