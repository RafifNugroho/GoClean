#include "globals.h"

Akun daftarAkun[100]; int jumlahAkun = 0;
Pesanan daftarPesanan[100]; int jumlahPesanan = 0; int idPesananBerikutnya = 1;
Transaksi daftarTransaksi[100]; int jumlahTransaksi = 0; int idTransaksiBerikutnya = 1;

// Menginisialisasi nilai awal Queue dan Stack menjadi kosong (-1)
QueueAntrean antreanOrder = { -1, -1 };
StackRiwayat riwayatSelesai = { -1 };