#include <iostream>
#include <cstdlib>

#include "menu.h"

using namespace std;

void layerMenuUtama(string role, string username) {

    int pilihan;

    do {

        system("cls");

        cout << "\n=========================\n";
        cout << "     MENU CLEANUP\n";
        cout << "=========================\n";

        cout << "Role : " << role << endl;
        cout << "User : " << username << endl;

        cout << "\n1. Input Order";
        cout << "\n2. Cari Cleaner";
        cout << "\n3. Logout";

        cout << "\nPilih : ";
        cin >> pilihan;

        switch(pilihan) {

            case 1:
                cout << "\nFitur Input Order";
                system("pause");
                break;

            case 2:
                cout << "\nFitur Cari Cleaner";
                system("pause");
                break;

            case 3:
                cout << "\nLogout...";
                break;

            default:
                cout << "\nMenu tidak valid";
                system("pause");
        }

    } while(pilihan != 3);
}