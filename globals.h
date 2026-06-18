#ifndef GLOBALS_H
#define GLOBALS_H

#include <string>

using namespace std;

struct Akun {
    string username;
    string password;
    string role;
};

extern Akun daftarAkun[100];
extern int jumlahAkun;

#endif