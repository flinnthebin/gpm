#include "../include/gpm.hpp"
#include <ncurses.h>
#include <iostream>

auto print_menu(int select, const std::vector<std::string>& opts) -> void {
    for (int i = 0; i < opts.size(); ++i) {
        if (select == i + 1) {
            attron(A_REVERSE);
            mvprintw(i + 1, 1, "%s", opts[i].c_str());
            attroff(A_REVERSE);
        } else {
            mvprintw(i + 1, 1, "%s", opts[i].c_str());
        }
    }
}

auto main() -> int {
    std::vector<std::string> opts = {"option1", "option2", "option3", "option4"};
    auto select = 1;
    auto opt = 0;
        int in;
    // TODO: make this happen without
    // removing the user from the terminal
    // ncurses isnt going to work. ANSI escape 
    // sequences may be an appropriate alternative
    // to create the menu
    initscr();
    clear();
    noecho();
    cbreak();
    keypad(stdscr, TRUE);

    while (true) {
        print_menu(select, opts);
        in = getch();
        switch (in) {
            case 'k':
                if (select == 1) {
                    select = opts.size();
                } else {
                    --select;
                }
                break;
            case 'j':
                if (select == opts.size()) {
                    select = 1;
                } else {
                    ++select;
                }
                break;
            case '\n':
                opt = select;
                break;
            case 'q':
                opt = opts.size();

                break;
        }
        if (opt != 0)
            break;
    }
    endwin();

    if (opt == opts.size()) {
        std::cout << "Thank you for using gpm!" << std::endl;
    } else {
        std::cout << opts[opt - 1] << " selected" << std::endl;
    }
    return 0;
}
