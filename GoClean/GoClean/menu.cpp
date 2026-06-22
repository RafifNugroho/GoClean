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
        cout << "1. Buat Pesanan\n";
        cout << "2. Lihat Pesanan Saya\n";
        cout << "3. Ubah Layanan Pesanan \n";
        cout << "4. Batalkan Pesanan\n";
        cout << "5. Lihat Informasi Transaksi / Kuitansi \n";
        cout << "6. Logout\n";
        cout << "Pilih menu: ";
        cin >> pilihan;

        if (pilihan == 1) {
            system("cls");
            cout << "--- Pilihan Layanan CLEANUP ---\n";
            cout << "- Sapu    (Rp 50.000 / jam)\n";
            cout << "- Pel     (Rp 60.000 / jam)\n";

            cout << "Masukkan jenis layanan (Sapu/Pel): ";
            string layanan;
            cin >> layanan;

            cout << "Msukkan durasi kerja (dalam jam): ";
            int durasiKerja;
            cin >> durasiKerja;

            // 1. Simpan ke data Pesanan
            daftarPesanan[jumlahPesanan].id = idPesananBerikutnya;
            daftarPesanan[jumlahPesanan].usernamePelanggan = username;
            daftarPesanan[jumlahPesanan].layanan = layanan;
            daftarPesanan[jumlahPesanan].durasi = durasiKerja;
            daftarPesanan[jumlahPesanan].status = "Menunggu";

            // 2. Tentukan Harga Otomatis & Simpan ke Informasi Transaksi
            int hargaLayanan = 0;
            if (layanan == "Sapu" || layanan == "sapu") hargaLayanan = 50000;
            else if (layanan == "Pel" || layanan == "pel") hargaLayanan = 60000;
            else hargaLayanan = 45000; // Default jika input salah

            int totalHarga = hargaLayanan * durasiKerja;

            daftarTransaksi[jumlahTransaksi].idTransaksi = idTransaksiBerikutnya;
            daftarTransaksi[jumlahTransaksi].idPesanan = idPesananBerikutnya;
            daftarTransaksi[jumlahTransaksi].usernamePelanggan = username;
            daftarTransaksi[jumlahTransaksi].layanan = layanan;
            daftarTransaksi[jumlahTransaksi].durasi = durasiKerja;
            daftarTransaksi[jumlahTransaksi].harga = totalHarga;
            daftarTransaksi[jumlahTransaksi].statusBayar = "Belum Lunas";

            jumlahPesanan++;
            idPesananBerikutnya++;
            jumlahTransaksi++;
            idTransaksiBerikutnya++;

            cout << "\nPesanan & Nota Transaksi berhasil dibuat!\n";
            system("pause");

        }
        else if (pilihan == 2) 
        {
            system("cls");
            cout << "--- Daftar Pesanan Saya ---\n";
            bool adaPesanan = false;
            for (int i = 0; i < jumlahPesanan; i++) {
                if (daftarPesanan[i].usernamePelanggan == username) 
                {
                    cout << "ID     : " << daftarPesanan[i].id << "\n";
                    cout << "Layanan: " << daftarPesanan[i].layanan << "\n";
                    cout << "Durasi : " << daftarPesanan[i].durasi << "jam\n";
                    cout << "Status : " << daftarPesanan[i].status << "\n";
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
                    cout << "Masukkan layanan baru (Sapu/Pel): ";
                    cin >> daftarPesanan[i].layanan;

                    cout << "Masukkan durasi baru (jam): ";
                    cin >> daftarPesanan[i].durasi;

                    // Update layanan, durasi, dan total harga di transaksi
                    for (int j = 0; j < jumlahTransaksi; j++) {
                        if (daftarTransaksi[j].idPesanan == idUbah) 
                        {
                            daftarTransaksi[j].layanan = daftarPesanan[i].layanan;
                            daftarTransaksi[j].durasi = daftarPesanan[i].durasi;

                            int hargaBaru = 0;
                            if (daftarTransaksi[j].layanan == "Sapu" || daftarTransaksi[j].layanan == "sapu") hargaBaru = 50000;
                            else if (daftarTransaksi[j].layanan == "Pel" || daftarTransaksi[j].layanan == "pel") hargaBaru = 60000;
                            else hargaBaru = 45000;

                            daftarTransaksi[j].harga = hargaBaru * daftarTransaksi[j].durasi;
                        }
                    }
                    cout << "Layanan, Durasi, & Harga Transaksi berhasil diubah!\n";
                    ditemukan = true;
                    break;
                }
            }
            if (!ditemukan) cout << "ID Pesanan tidak ditemukan atau bukan milikmu.\n";
            system("pause");
        }
        else if (pilihan == 4) 
        {
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

                    for (int j = 0; j < jumlahTransaksi; j++) {
                        if (daftarTransaksi[j].idPesanan == idHapus) {
                            daftarTransaksi[j].statusBayar = "Dibatalkan";
                        }
                    }

                    ditemukan = true;
                    cout << "Pesanan berhasil dibatalkan!\n";
                    break;
                }
            }
            if (!ditemukan) cout << "ID Pesanan tidak ditemukan.\n";
            system("pause");

        }
        else if (pilihan == 5) {
            system("cls");
            cout << "--- INFORMASI TRANSAKSI & KUITANSI SAYA ---\n";
            bool adaTransaksi = false;
            for (int i = 0; i < jumlahTransaksi; i++) {
                if (daftarTransaksi[i].usernamePelanggan == username) {
                    cout << "ID Transaksi : TRX" << daftarTransaksi[i].idTransaksi << "\n";
                    cout << "ID Pesanan   : " << daftarTransaksi[i].idPesanan << "\n";
                    cout << "Layanan      : " << daftarTransaksi[i].layanan << "\n";
                    cout << "Durasi Kerja : " << daftarTransaksi[i].durasi << " jam\n";
                    cout << "Total Biaya  : Rp " << daftarTransaksi[i].harga << "\n";
                    cout << "Status Bayar : " << daftarTransaksi[i].statusBayar << "\n";
                    cout << "-------------------------------------------\n";
                    adaTransaksi = true;
                }
            }
            if (!adaTransaksi) cout << "Belum ada riwayat transaksi pembayaran.\n";
            system("pause");
            }
    } while (pilihan != 6);
}

void menuCleaner(string username) {
    int pilihan;
    do {
        system("cls");
        cout << "\n=== MENU CLEANER: " << username << " ===\n";
        cout << "1. Lihat Semua Pesanan Masuk \n";
        cout << "2. Ambil Pekerjaan\n";
        cout << "3. Lihat & Konfirmasi Pembayaran Transaksi \n";
        cout << "4. Logout\n";
        cout << "Pilih menu: ";
        cin >> pilihan;

        if (pilihan == 1) {
            system("cls");
            cout << "--- Daftar Semua Pesanan ---\n";
            if (jumlahPesanan == 0) cout << "Belum ada pesanan masuk.\n";
            for (int i = 0; i < jumlahPesanan; i++) {
                cout << "ID         : " << daftarPesanan[i].id << "\n";
                cout << "Pelanggan  : " << daftarPesanan[i].usernamePelanggan << "\n";
                cout << "Layanan    : " << daftarPesanan[i].layanan << "\n";
                cout << "Durasi     : " << daftarPesanan[i].durasi << " jam" << "\n";
                cout << "Status     : " << daftarPesanan[i].status << "\n";
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
        else if (pilihan == 3) {
            system("cls");
            cout << "--- DAFTAR SEMUA TRANSAKSI MASUK ---\n";
            if (jumlahTransaksi == 0) cout << "Belum ada transaksi pembayaran masuk.\n";

            for (int i = 0; i < jumlahTransaksi; i++) {
                cout << "ID Transaksi   : TRX" << daftarTransaksi[i].idTransaksi << "\n";
                cout << "Pelanggan      : " << daftarTransaksi[i].usernamePelanggan << "\n";
                cout << "Layanan        : " << daftarTransaksi[i].layanan << "\n";
                cout << "Durasi         : " << daftarTransaksi[i].durasi << " jam" << "\n";
                cout << "Total          : Rp " << daftarTransaksi[i].harga << "\n";
                cout << "Status         : " << daftarTransaksi[i].statusBayar << "\n";
            }

            cout << "\nApakah ingin konfirmasi pembayaran Lunas? (1. Ya, 2. Tidak): ";
            int konf;
            cin >> konf;
            if (konf == 1) {
                cout << "Masukkan ID Transaksi yang ingin dilunasi (Angka saja): TRX";
                int idTrx;
                cin >> idTrx;
                bool ditemukan = false;

                for (int i = 0; i < jumlahTransaksi; i++) {
                    if (daftarTransaksi[i].idTransaksi == idTrx) {
                        daftarTransaksi[i].statusBayar = "Lunas";
                        cout << "Transaksi TRX" << idTrx << " berhasil diubah menjadi Lunas!\n";
                        ditemukan = true;
                        break;
                    }
                }
                if (!ditemukan) cout << "ID Transaksi tidak ditemukan.\n";
            }
            system("pause");
        }
    } while (pilihan != 4);
}

void layerMenuUtama(string role, string username) {
    if (role == "Pelanggan") {
        menuPelanggan(username);
    }
    else if (role == "Cleaner") {
        menuCleaner(username);
    }
}