#define _XOPEN_SOURCE_EXTENDED 1
#include <iostream>
#include <ncurses.h>
#include <clocale>
#include <vector>
#include <string>
#include "Registrar.h"
#include "Professor.h"

void drawMenu(WINDOW* menuWin, int highlight, const std::vector<std::wstring>& choices) {
    wclear(menuWin);
    box(menuWin, 0, 0);

    mvwaddwstr(menuWin, 1, 2, L"=== ΓΡΑΜΜΑΤΕΙΑ ===");

    int x = 2;
    int y = 3;

    for(size_t i = 0; i < choices.size(); ++i) {
        if(highlight == static_cast<int>(i)) {
            wattron(menuWin, A_REVERSE); // Αντιστροφή χρωμάτων
            std::wstring selectedChoice = L"-> " + choices[i];
            mvwaddwstr(menuWin, y, x, selectedChoice.c_str());
            wattroff(menuWin, A_REVERSE);
        } else {
            std::wstring normalChoice = L"   " + choices[i];
            mvwaddwstr(menuWin, y, x, normalChoice.c_str());
        }
        y++;
    }
    wrefresh(menuWin);
}

int main() {
    std::setlocale(LC_ALL, "");

    initscr();
    clear();
    noecho();
    cbreak();
    curs_set(0);

    Registrar registrar;
    registrar.loadFromFile("university_data.csv");

    std::vector<std::wstring> choices = {
        L"Προβολή Μελών",
        L"Προβολή Μαθημάτων",
        L"Προσθήκη Δείγματος Καθηγητή",
        L"Αποθήκευση και Έξοδος"
    };

    int chooserWinHeight = 10;
    int chooserWinWidth = 45;
    int startY = 3;
    int startX = 5;

    WINDOW* menuWin = newwin(chooserWinHeight, chooserWinWidth, startY, startX);
    keypad(menuWin, TRUE);

    int highlight = 0;
    int choice = -1;

    while(true) {
        drawMenu(menuWin, highlight, choices);
        int c = wgetch(menuWin);

        switch(c) {
            case KEY_UP:
                if(highlight > 0) highlight--;
                break;
            case KEY_DOWN:
                if(highlight < static_cast<int>(choices.size()) - 1) highlight++;
                break;
            case 10: // Enter
                choice = highlight;
                break;
            default:
                break;
        }

        if(choice != -1) {
            break;
        }
    }

    wclear(menuWin);
    wrefresh(menuWin);
    delwin(menuWin);
    endwin();

    if (choice == 0) {
        registrar.printAllMembers();
        std::cout << "\nΠατήστε Enter για να κλείσει το πρόγραμμα...";
        std::cin.get();
    }
    else if (choice == 1) {
        registrar.printAllCourses();
        std::cout << "\nΠατήστε Enter για να κλείσει το πρόγραμμα...";
        std::cin.get();
    }
    else if (choice == 2) {
        registrar.addMember(new Professor("Νίκος Παπαδόπουλος", "Άνδρας", "Τμήμα Μηχανικών Πληροφορικής"));
        std::cout << "Προστέθηκε επιτυχώς ένας καθηγητής ως δείγμα!" << std::endl;

        registrar.saveToFile("university_data.csv");
        std::cout << "Τα δεδομένα αποθηκεύτηκαν στο αρχείο university_data.csv!" << std::endl;

        std::cout << "\nΠατήστε Enter για να κλείσει το πρόγραμμα...";
        std::cin.get();
    }
    else if (choice == 3) {
        registrar.saveToFile("university_data.csv");
        std::cout << "\nΠατήστε Enter για να κλείσει το πρόγραμμα...";
        std::cin.get();
    }

    return 0;
}