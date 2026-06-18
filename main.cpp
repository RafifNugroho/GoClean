#include <iostream>
#include <cstdlib>

#include "auth.h"
#include "globals.h"

using namespace std;

int main() {

    daftarAkun[0] = {"admin","123","Admin"};
    jumlahAkun = 1;

    int pilihan;

    do {

        system("cls");

        cout << "\n=========================\n";
        cout << "      CLEANUP APP\n";
        cout << "=========================\n";

        cout << "1. Login\n";
        cout << "2. Register\n";
        cout << "3. Keluar\n";

        cout << "Pilih : ";
        cin >> pilihan;

        switch(pilihan) {

            case 1:
                layerLogin();
                break;

            case 2:
                layerRegister();
                break;

            case 3:
                cout << "\nTerima kasih\n";
                break;

            default:
                cout << "\nPilihan salah\n";
                system("pause");
        }

    } while(pilihan != 3);

    return 0;
}