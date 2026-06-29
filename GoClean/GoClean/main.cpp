#include <iostream>
#include <cstdlib>
#include "auth.h"

using namespace std;

int main() {
    int pilihan;
    do {
        system("cls");
        cout << "\n================================\n";
        cout << "      CLEANUP / GOCLEAN\n";
        cout << "================================\n";
        cout << "1. Login\n";
        cout << "2. Daftar Akun\n";
        cout << "3. Keluar\n";
        cout << "Pilih menu: ";
        cin >> pilihan;

        switch (pilihan) {
        case 1:
            layerLogin();
            break;
        case 2:
            layerRegister();
            break;
        case 3:
            system("cls");
            cout << "Keluar dari sistem CLEANUP.\n";
            break;
        default:
            cout << "Pilihan tidak valid.\n";
            system("pause");
        }
    } while (pilihan != 3);

    return 0;
}