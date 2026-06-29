#ifndef GLOBALS_H
#define GLOBALS_H

#include <string>

using namespace std;

struct Akun {
    string email;
    string username;
    string password;
    string role;
    string area; //Fitur Cari Cleaner Terdekat
};

struct Pesanan { int id; string usernamePelanggan; string layanan; int durasi; string alamat; string status; };

struct Transaksi {
    int idTransaksi;
    int idPesanan;
    string usernamePelanggan;
    string layanan;
    int durasi;
    int harga;
    int uangBayar;
    int kembalian;
    string statusBayar;
};

// --- MATERI 5: QUEUE (ANTREAN PESANAN MASUK) ---
struct QueueAntrean {
    int depan;
    int belakang;
    int idPesananMasuk[100];
};

// --- MATERI 4: STACK (LOG RIWAYAT TERBARU) ---
struct StackRiwayat {
    int top;
    string logAktivitas[100];
};

extern Akun daftarAkun[100]; extern int jumlahAkun;
extern Pesanan daftarPesanan[100]; extern int jumlahPesanan; extern int idPesananBerikutnya;
extern Transaksi daftarTransaksi[100]; extern int jumlahTransaksi; extern int idTransaksiBerikutnya;

extern QueueAntrean antreanOrder;
extern StackRiwayat riwayatSelesai;

#endif