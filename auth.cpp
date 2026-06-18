#include <iostream>
#include <cstdlib>
#include <cctype>

#include "auth.h"
#include "globals.h"
#include "menu.h"

using namespace std;

string toLowerCase(string text) {
    for (int i = 0; i < text.length(); i++) {
        text[i] = tolower(text[i]);
    }
    return text;
}

void layerRegister() {

    system("cls");

    if(jumlahAkun >= 100) {
    cout << "Kapasitas akun penuh!\n";
    system("pause");
    return;
}

    cout << "\n=== REGISTER ===\n";

    int pilihanRole;

    cout << "1. Pelanggan\n";
    cout << "2. Cleaner\n";
    cout << "Pilih Role : ";
    cin >> pilihanRole;

    string role;

    if (pilihanRole == 1)
        role = "Pelanggan";
    else if (pilihanRole == 2)
        role = "Cleaner";
    else {
        cout << "Role tidak valid!\n";
        system("pause");
        return;
    }

    string username;
string password;

cout << "\nUsername : ";
cin >> username;
username = toLowerCase(username);

for(int i = 0; i < jumlahAkun; i++) {
    if(daftarAkun[i].username == username) {
        cout << "Username sudah digunakan!\n";
        system("pause");
        return;
    }
}

cout << "Password : ";
cin >> password;

daftarAkun[jumlahAkun].username = username;
daftarAkun[jumlahAkun].password = password;
daftarAkun[jumlahAkun].role = role;

jumlahAkun++;

    cout << "\nRegister Berhasil\n";

    system("pause");
}

void layerLogin() {

    system("cls");

    string username;
    string password;

    cout << "\n=== LOGIN ===\n";

    cout << "Username : ";
    cin >> username;
    username = toLowerCase(username);

    cout << "Password : ";
    cin >> password;

    bool loginBerhasil = false;
    string roleLogin;

    for(int i = 0; i < jumlahAkun; i++) {

        if(daftarAkun[i].username == username &&
           daftarAkun[i].password == password) {

            loginBerhasil = true;
            roleLogin = daftarAkun[i].role;
            break;
        }
    }

    if(loginBerhasil) {

        cout << "\nLogin Berhasil\n";
        system("pause");

        layerMenuUtama(roleLogin, username);
    }
    else {

        cout << "\nLogin Gagal\n";
        system("pause");
    }
}