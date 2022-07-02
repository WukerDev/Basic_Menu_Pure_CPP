#include <iostream>
#include <conio.h>
#include <windows.h> 
int selected = 1;
int pressed;
//do not touch

//MAIN CONFIG
// Key binding
#define KEY_UP 87
#define KEY_UP2 72
#define KEY_DOWN 83
#define KEY_DOWN2 80
#define KEY_ENTER 13
//Header text
std::string header_text = "Simple Selection Menu In C++ by Wiktor Kozakowski";

//Change colors here
int main_text_color=14;
int main_text_select_color=240;
int main_warning_color = 4; // header color too

//Menu options
std::string menu_base[] = { "Run", "Help", "Credits", "Github", "Exit" };
//To add more options just type name of the option here, and add it's function in selection
//Menu will dynamicly grow, you need to only add a function for every new menu option eg. if(selection==8){} for the 8th option

//END OF CONFIG

//Edit the color values at the color config above
void text_def(std::string text) { HANDLE h = GetStdHandle(STD_OUTPUT_HANDLE);  SetConsoleTextAttribute(h, main_text_color); std::cout << text << std::endl;
};
void text_sel(std::string text) {
    HANDLE h = GetStdHandle(STD_OUTPUT_HANDLE);  SetConsoleTextAttribute(h, main_text_select_color); std::cout << text << std::endl; SetConsoleTextAttribute(h, 15);
};
void text_warning(std::string text) {
    HANDLE h = GetStdHandle(STD_OUTPUT_HANDLE);  SetConsoleTextAttribute(h, main_warning_color); std::cout << text << std::endl; SetConsoleTextAttribute(h, 15);
};
void header() { text_warning(header_text); }


void menu() {
    header();
    if (selected == 0) {
        selected = sizeof(menu_base) / sizeof(menu_base[0]);
    };
    if (selected > sizeof(menu_base) / sizeof(menu_base[0])) {
        selected = 1;
    };
    for (int i = 1; i <= sizeof(menu_base) / sizeof(menu_base[0]); i++) {
        if (i == selected) { text_sel(menu_base[i - 1]); };
        if (i != selected) { text_def(menu_base[i-1]); };
        // selection
    }
};




void selection() {
    while (true) {
        //main menu selection, another selection can be added to each select option
        pressed = _getch();
        pressed = toupper(pressed);
        if (pressed == KEY_UP || pressed == KEY_UP2) { selected--; };
        if (pressed == KEY_DOWN  || pressed == KEY_DOWN2) { selected++; };
        if (pressed == KEY_ENTER) { 
            if(selected == 1){
                system("CLS");
                std::cout << "Nothing to see here, it's just a concept";
                pressed = _getch();
            }
            if (selected == 2) {
                system("CLS");
                std::cout << "To navigate the menu use W and S or ArrowUp and ArrowDown, use Enter to accept.";
                pressed = _getch();
            }
            if (selected == 3) {
                system("CLS");
                std::cout << "I used these sides to inspire myself on making this:\nhttps://stackoverflow.com/questions/4053837/colorizing-text-in-the-console-with-c \nhttps://www.youtube.com/watch?v=VXLtdJgl4PA\nThese codes were only an inspiration, all work and logic was done by me.\nWiktor Kozakowski 2022 ";
                pressed = _getch();

            }
            if (selected == 4) { system("start /max https://github.com/WukerDev"); }
            if (selected == 5) { system("CLS");  break;  }
        };
        system("CLS");
        menu();
        // do not touch, it is used to refresh the menu
    }
};

int main()
{
    
    menu();
    selection();

}
