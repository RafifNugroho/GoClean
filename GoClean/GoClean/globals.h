#ifndef GLOBALS_H
#define GLOBALS_H

#include <string>

using namespace std;

struct Akun {
    string username;
    string email;
    string password;
    string role;
};

struct Pesanan {
    int id;
    string usernamePelanggan;
    string layanan;
    string status;
};

extern Akun daftarAkun[100];
extern int jumlahAkun;

extern Pesanan daftarPesanan[100];
extern int jumlahPesanan;
extern int idPesananBerikutnya;

#endif
