#ifndef GLOBALS_H
#define GLOBALS_H

#include <string>

using namespace std;

struct Akun {
    string email;
    string username;
    string password;
    string role;
};

struct Pesanan {
    int id;
    string usernamePelanggan;
    string layanan;
    int durasi;
    string status;
};

struct Transaksi {
    int idTransaksi;
    int idPesanan;
    string usernamePelanggan;
    string layanan;
    int durasi;
    int harga;
    string statusBayar;
};

extern Akun daftarAkun[100];
extern int jumlahAkun;

extern Pesanan daftarPesanan[100];
extern int jumlahPesanan;
extern int idPesananBerikutnya;

extern Transaksi daftarTransaksi[100];
extern int jumlahTransaksi;
extern int idTransaksiBerikutnya;

#endif