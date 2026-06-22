#include <iostream>
#include <cstdlib>
#include <string>
#include "auth.h"
#include "globals.h"
#include "menu.h"

using namespace std;

void layerRegister() {
    system("cls");
    cout << "\n--- Halaman Pendaftaran ---\n";
    cout << "Pilih Role (1. Pelanggan, 2. Cleaner): ";

    int pilihanRole;
    cin >> pilihanRole;

    string role;
    if (pilihanRole == 2) {
        role = "Cleaner";
    }
    else {
        role = "Pelanggan";
    }

    cout << "Masukkan Email: ";
    cin >> daftarAkun[jumlahAkun].email;
    cout << "Masukkan Username: ";
    cin >> daftarAkun[jumlahAkun].username;
    cout << "Masukkan Password: ";
    cin >> daftarAkun[jumlahAkun].password;
    daftarAkun[jumlahAkun].role = role;

    jumlahAkun++;
    cout << "\nPendaftaran berhasil! Silakan login.\n";
    system("pause");
}

void layerLogin() {
    system("cls");
    cout << "\n--- Halaman Login ---\n";
    cout << "Login sebagai (1. Pelanggan, 2. Cleaner): ";

    int pilihanRole;
    cin >> pilihanRole;
    string roleDicari = (pilihanRole == 2) ? "Cleaner" : "Pelanggan";

    // Meminta 3 input sekaligus sesuai permintaanmu
    string emailLogin, usernameLogin, passwordLogin;
    cout << "Masukkan Email: ";
    cin >> emailLogin;
    cout << "Masukkan Username: ";
    cin >> usernameLogin;
    cout << "Masukkan Password: ";
    cin >> passwordLogin;

    bool loginBerhasil = false;

    for (int i = 0; i < jumlahAkun; i++) {
        if (daftarAkun[i].email == emailLogin &&
            daftarAkun[i].username == usernameLogin &&
            daftarAkun[i].password == passwordLogin &&
            daftarAkun[i].role == roleDicari) {
            loginBerhasil = true;
            break;
        }
    }

    if (loginBerhasil) {
        cout << "\nLogin Berhasil!\n";
        system("pause");
        layerMenuUtama(roleDicari, usernameLogin);
    }
    else {
        cout << "\nEmail, Username, Password, atau Role salah!\n";
        system("pause");
    }
}