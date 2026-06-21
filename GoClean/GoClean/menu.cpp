#include <iostream>
#include <cstdlib>
#include <string>
#include "menu.h"
#include "globals.h"

using namespace std;

void menuPelanggan(string username) {
    int pilihan;
    do {
        system("cls");
        cout << "\n=== MENU PELANGGAN: " << username << " ===\n";
        cout << "1. Buat Pesanan (Create)\n";
        cout << "2. Lihat Pesanan Saya (Read)\n";
        cout << "3. Ubah Layanan Pesanan (Update)\n";
        cout << "4. Batalkan Pesanan (Delete)\n";
        cout << "5. Logout\n";
        cout << "Pilih menu: ";
        cin >> pilihan;

        if (pilihan == 1) {
            system("cls");
            cout << "Masukkan jenis layanan (Sapu/Pel/Setrika): ";
            string layanan;
            cin >> layanan;

            daftarPesanan[jumlahPesanan].id = idPesananBerikutnya;
            daftarPesanan[jumlahPesanan].usernamePelanggan = username;
            daftarPesanan[jumlahPesanan].layanan = layanan;
            daftarPesanan[jumlahPesanan].status = "Menunggu";

            jumlahPesanan++;
            idPesananBerikutnya++;
            cout << "Pesanan berhasil dibuat!\n";
            system("pause");

        }
        else if (pilihan == 2) {
            system("cls");
            cout << "--- Daftar Pesanan Saya ---\n";
            bool adaPesanan = false;
            for (int i = 0; i < jumlahPesanan; i++) {
                if (daftarPesanan[i].usernamePelanggan == username) {
                    cout << "ID: " << daftarPesanan[i].id
                        << " | Layanan: " << daftarPesanan[i].layanan
                        << " | Status: " << daftarPesanan[i].status << "\n";
                    adaPesanan = true;
                }
            }
            if (!adaPesanan) cout << "Belum ada pesanan.\n";
            system("pause");

        }
        else if (pilihan == 3) {
            system("cls");
            cout << "Masukkan ID Pesanan yang ingin diubah: ";
            int idUbah;
            cin >> idUbah;
            bool ditemukan = false;

            for (int i = 0; i < jumlahPesanan; i++) {
                if (daftarPesanan[i].id == idUbah && daftarPesanan[i].usernamePelanggan == username) {
                    cout << "Masukkan layanan baru: ";
                    cin >> daftarPesanan[i].layanan;
                    cout << "Layanan berhasil diubah!\n";
                    ditemukan = true;
                    break;
                }
            }
            if (!ditemukan) cout << "ID Pesanan tidak ditemukan atau bukan milikmu.\n";
            system("pause");

        }
        else if (pilihan == 4) {
            system("cls");
            cout << "Masukkan ID Pesanan yang ingin dibatalkan: ";
            int idHapus;
            cin >> idHapus;
            bool ditemukan = false;

            for (int i = 0; i < jumlahPesanan; i++) {
                if (daftarPesanan[i].id == idHapus && daftarPesanan[i].usernamePelanggan == username) {
                    for (int j = i; j < jumlahPesanan - 1; j++) {
                        daftarPesanan[j] = daftarPesanan[j + 1];
                    }
                    jumlahPesanan--;
                    ditemukan = true;
                    cout << "Pesanan berhasil dibatalkan!\n";
                    break;
                }
            }
            if (!ditemukan) cout << "ID Pesanan tidak ditemukan.\n";
            system("pause");
        }
    } while (pilihan != 5);
}

void menuCleaner(string username) {
    int pilihan;
    do {
        system("cls");
        cout << "\n=== MENU CLEANER: " << username << " ===\n";
        cout << "1. Lihat Semua Pesanan Masuk (Read)\n";
        cout << "2. Ambil Pekerjaan (Update Status)\n";
        cout << "3. Logout\n";
        cout << "Pilih menu: ";
        cin >> pilihan;

        if (pilihan == 1) {
            system("cls");
            cout << "--- Daftar Semua Pesanan ---\n";
            if (jumlahPesanan == 0) cout << "Belum ada pesanan masuk.\n";
            for (int i = 0; i < jumlahPesanan; i++) {
                cout << "ID: " << daftarPesanan[i].id
                    << " | Pelanggan: " << daftarPesanan[i].usernamePelanggan
                    << " | Layanan: " << daftarPesanan[i].layanan
                    << " | Status: " << daftarPesanan[i].status << "\n";
            }
            system("pause");

        }
        else if (pilihan == 2) {
            system("cls");
            cout << "Masukkan ID Pesanan yang ingin dikerjakan: ";
            int idKerja;
            cin >> idKerja;
            bool ditemukan = false;

            for (int i = 0; i < jumlahPesanan; i++) {
                if (daftarPesanan[i].id == idKerja) {
                    daftarPesanan[i].status = "Dikerjakan oleh " + username;
                    cout << "Pekerjaan berhasil diambil!\n";
                    ditemukan = true;
                    break;
                }
            }
            if (!ditemukan) cout << "ID Pesanan tidak ditemukan.\n";
            system("pause");
        }
    } while (pilihan != 3);
}

void layerMenuUtama(string role, string username) {
    if (role == "Pelanggan") {
        menuPelanggan(username);
    }
    else if (role == "Cleaner") {
        menuCleaner(username);
    }
}