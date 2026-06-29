#include <iostream>
#include <cstdlib>
#include <string>
#include <iomanip>
#include <fstream>
#include "menu.h"
#include "globals.h"

using namespace std;

// ========================================================
// MATERI 4: STACK (LIFO) - Log Aktivitas Selesai
// ========================================================
void pushRiwayat(string log) {
    if (riwayatSelesai.top < 99) {
        riwayatSelesai.top++;
        riwayatSelesai.logAktivitas[riwayatSelesai.top] = log;
    }
}

void cetakStackRiwayat() {
    cout << "--- LOG AKTIVITAS TERBARU (STACK) ---\n";
    if (riwayatSelesai.top == -1) {
        cout << "Belum ada aktivitas.\n";
    }
    else {
        for (int i = riwayatSelesai.top; i >= 0; i--) {
            cout << ">> " << riwayatSelesai.logAktivitas[i] << "\n";
        }
    }
}

// ========================================================
// MATERI 5: QUEUE (FIFO) - Antrean Pekerjaan
// ========================================================
void enqueueOrder(int id) {
    if (antreanOrder.depan == -1) antreanOrder.depan = 0;
    antreanOrder.belakang++;
    antreanOrder.idPesananMasuk[antreanOrder.belakang] = id;
}

int dequeueOrder() {
    if (antreanOrder.depan == -1 || antreanOrder.depan > antreanOrder.belakang) return -1;
    int idDiambil = antreanOrder.idPesananMasuk[antreanOrder.depan];
    antreanOrder.depan++;
    return idDiambil;
}

bool isQueueEmpty() {
    return (antreanOrder.depan == -1 || antreanOrder.depan > antreanOrder.belakang);
}

// ========================================================
// MATERI 6: SORTING (Selection Sort) - Urut Durasi
// ========================================================
void selectionSortDurasi() {
    for (int i = 0; i < jumlahPesanan - 1; i++) {
        int min_idx = i;
        for (int j = i + 1; j < jumlahPesanan; j++) {
            if (daftarPesanan[j].durasi < daftarPesanan[min_idx].durasi) {
                min_idx = j;
            }
        }
        Pesanan temp = daftarPesanan[i];
        daftarPesanan[i] = daftarPesanan[min_idx];
        daftarPesanan[min_idx] = temp;
    }
    cout << "Tabel berhasil diurutkan berdasarkan Durasi terpendek!\n";
}

// ========================================================
// MATERI 1 & 3: ARRAY & STRUCT - Tampilkan Tabel Pesanan
// ========================================================
void tampilkanTabelPesanan(string filterUsername, bool untukCleaner) {
    int wID = 6, wPel = 15, wLay = 12, wDur = 12, wAlm = 40, wStat = 25;
    string garisCleaner(wID + wPel + wLay + wDur + wAlm + wStat, '-');
    string garisPelanggan(wID + wLay + wDur + wAlm + wStat, '-');

    if (untukCleaner) {
        cout << garisCleaner << "\n";
        cout << left << setw(wID) << "ID" << setw(wPel) << "Pelanggan"
            << setw(wLay) << "Layanan" << setw(wDur) << "Durasi"
            << setw(wAlm) << "Alamat" << setw(wStat) << "Status" << "\n";
        cout << garisCleaner << "\n";

        for (int i = 0; i < jumlahPesanan; i++) {
            string textDurasi = to_string(daftarPesanan[i].durasi) + " jam";
            cout << left << setw(wID) << daftarPesanan[i].id
                << setw(wPel) << daftarPesanan[i].usernamePelanggan
                << setw(wLay) << daftarPesanan[i].layanan
                << setw(wDur) << textDurasi
                << setw(wAlm) << daftarPesanan[i].alamat
                << setw(wStat) << daftarPesanan[i].status << "\n";
        }
        cout << garisCleaner << "\n";
    }
    else {
        cout << garisPelanggan << "\n";
        cout << left << setw(wID) << "ID" << setw(wLay) << "Layanan"
            << setw(wDur) << "Durasi" << setw(wAlm) << "Alamat"
            << setw(wStat) << "Status" << "\n";
        cout << garisPelanggan << "\n";

        for (int i = 0; i < jumlahPesanan; i++) {
            if (daftarPesanan[i].usernamePelanggan == filterUsername) {
                string textDurasi = to_string(daftarPesanan[i].durasi) + " jam";
                cout << left << setw(wID) << daftarPesanan[i].id
                    << setw(wLay) << daftarPesanan[i].layanan
                    << setw(wDur) << textDurasi
                    << setw(wAlm) << daftarPesanan[i].alamat
                    << setw(wStat) << daftarPesanan[i].status << "\n";
            }
        }
        cout << garisPelanggan << "\n";
    }
}

// ========================================================
// MENU UTAMA PELANGGAN
// ========================================================
void menuPelanggan(string username) {
    int pilihan;
    do {
        system("cls");
        cout << "\n=== MENU PELANGGAN: " << username << " ===\n";
        cout << "1. Buat Pesanan \n";
        cout << "2. Lihat Pesanan Saya \n";
        cout << "3. Ubah Pesanan \n";
        cout << "4. Batalkan Pesanan \n";
        cout << "5. Lihat & Cetak Kuitansi \n";
        cout << "6. Cari Cleaner Terdekat \n";
        cout << "7. Logout\n";
        cout << "Pilih menu: ";
        cin >> pilihan;

        if (pilihan == 1) {
            system("cls");
            cout << "--- Pilihan Layanan CLEANUP ---\n";
            cout << "- Sapu    (Rp 50.000 / jam)\n";
            cout << "- Pel     (Rp 60.000 / jam)\n";

            string layanan;
            cout << "Masukkan jenis layanan (Sapu/Pel): ";
            cin >> layanan;

            int durasiKerja;
            cout << "Masukkan durasi kerja (jam): ";
            while (!(cin >> durasiKerja)) {
                cout << "Harap masukkan ANGKA: ";
                cin.clear(); cin.ignore(10000, '\n');
            }

            string alamat;
            cout << "Masukkan alamat lengkap: ";
            getline(cin >> ws, alamat);

            daftarPesanan[jumlahPesanan].id = idPesananBerikutnya;
            daftarPesanan[jumlahPesanan].usernamePelanggan = username;
            daftarPesanan[jumlahPesanan].layanan = layanan;
            daftarPesanan[jumlahPesanan].durasi = durasiKerja;
            daftarPesanan[jumlahPesanan].alamat = alamat;
            daftarPesanan[jumlahPesanan].status = "Menunggu";

            int hargaLayanan = (layanan == "Pel" || layanan == "pel") ? 60000 : 50000;

            daftarTransaksi[jumlahTransaksi].idTransaksi = idTransaksiBerikutnya;
            daftarTransaksi[jumlahTransaksi].idPesanan = idPesananBerikutnya;
            daftarTransaksi[jumlahTransaksi].usernamePelanggan = username;
            daftarTransaksi[jumlahTransaksi].layanan = layanan;
            daftarTransaksi[jumlahTransaksi].durasi = durasiKerja;
            daftarTransaksi[jumlahTransaksi].harga = (hargaLayanan * durasiKerja);
            daftarTransaksi[jumlahTransaksi].uangBayar = 0;
            daftarTransaksi[jumlahTransaksi].kembalian = 0;
            daftarTransaksi[jumlahTransaksi].statusBayar = "Belum Lunas";

            enqueueOrder(idPesananBerikutnya);

            jumlahPesanan++; idPesananBerikutnya++;
            jumlahTransaksi++; idTransaksiBerikutnya++;

            cout << "\nPesanan dibuat dan masuk ke Antrean!\n";
            system("pause");

        }
        else if (pilihan == 2) {
            system("cls");
            cout << "--- DAFTAR PESANAN SAYA ---\n";
            tampilkanTabelPesanan(username, false);
            system("pause");

        }
        else if (pilihan == 3) {
            system("cls");
            cout << "--- UBAH PESANAN ---\n";
            tampilkanTabelPesanan(username, false);

            cout << "\nMasukkan ID Pesanan yang ingin diubah: ";
            int idUbah; cin >> idUbah;
            bool ditemukan = false;

            for (int i = 0; i < jumlahPesanan; i++) {
                if (daftarPesanan[i].id == idUbah && daftarPesanan[i].usernamePelanggan == username) {
                    if (daftarPesanan[i].status != "Menunggu") {
                        cout << "Pesanan sudah diproses oleh Cleaner, tidak bisa diubah!\n";
                        ditemukan = true; break;
                    }
                    cout << "Masukkan layanan baru (Sapu/Pel): ";
                    cin >> daftarPesanan[i].layanan;

                    cout << "Masukkan durasi baru (jam): ";
                    while (!(cin >> daftarPesanan[i].durasi)) {
                        cout << "Input tidak valid! Harap masukkan ANGKA saja: ";
                        cin.clear(); cin.ignore(10000, '\n');
                    }

                    for (int j = 0; j < jumlahTransaksi; j++) {
                        if (daftarTransaksi[j].idPesanan == idUbah) {
                            daftarTransaksi[j].layanan = daftarPesanan[i].layanan;
                            daftarTransaksi[j].durasi = daftarPesanan[i].durasi;
                            int hargaBaru = (daftarTransaksi[j].layanan == "Pel" || daftarTransaksi[j].layanan == "pel") ? 60000 : 50000;
                            daftarTransaksi[j].harga = hargaBaru * daftarTransaksi[j].durasi;
                        }
                    }
                    cout << "Layanan, Durasi, & Harga Transaksi berhasil diubah!\n";
                    ditemukan = true; break;
                }
            }
            if (!ditemukan) cout << "ID Pesanan tidak valid atau bukan milikmu.\n";
            system("pause");

        }
        else if (pilihan == 4) {
            system("cls");
            tampilkanTabelPesanan(username, false);

            cout << "\nMasukkan ID Pesanan yang dibatalkan: ";
            int idHapus; cin >> idHapus;
            bool ditemukan = false;

            for (int i = 0; i < jumlahPesanan; i++) {
                if (daftarPesanan[i].id == idHapus && daftarPesanan[i].usernamePelanggan == username) {
                    for (int j = i; j < jumlahPesanan - 1; j++) daftarPesanan[j] = daftarPesanan[j + 1];
                    jumlahPesanan--;

                    for (int j = 0; j < jumlahTransaksi; j++) {
                        if (daftarTransaksi[j].idPesanan == idHapus) daftarTransaksi[j].statusBayar = "Dibatalkan";
                    }
                    ditemukan = true; cout << "Pesanan dibatalkan!\n"; break;
                }
            }
            if (!ditemukan) cout << "ID tidak valid.\n";
            system("pause");

        }
        else if (pilihan == 5) {
            system("cls");
            cout << "--- KUITANSI PEMBAYARAN SAYA ---\n\n";

            bool adaTransaksi = false;
            for (int i = 0; i < jumlahTransaksi; i++) {
                if (daftarTransaksi[i].usernamePelanggan == username) {
                    cout << "========================================\n";
                    cout << "            KUITANSI CLEANUP            \n";
                    cout << "========================================\n";
                    cout << left << setw(15) << "ID Transaksi" << ": TRX" << daftarTransaksi[i].idTransaksi << "\n";
                    cout << left << setw(15) << "Layanan" << ": " << daftarTransaksi[i].layanan << "\n";
                    cout << left << setw(15) << "Durasi" << ": " << daftarTransaksi[i].durasi << " jam\n";
                    cout << "----------------------------------------\n";
                    cout << left << setw(15) << "Total Biaya" << ": Rp " << daftarTransaksi[i].harga << "\n";

                    if (daftarTransaksi[i].statusBayar == "Lunas") {
                        cout << left << setw(15) << "Uang Tunai" << ": Rp " << daftarTransaksi[i].uangBayar << "\n";
                        cout << left << setw(15) << "Kembalian" << ": Rp " << daftarTransaksi[i].kembalian << "\n";
                    }

                    cout << left << setw(15) << "Status" << ": " << daftarTransaksi[i].statusBayar << "\n";
                    cout << "========================================\n";
                    cout << " Terima kasih telah menggunakan layanan \n";
                    cout << "========================================\n\n";
                    adaTransaksi = true;
                }
            }
            if (adaTransaksi) {
                cout << "Cetak Kuitansi? (1. Ya, 2. Tidak): ";
                int cetak; cin >> cetak;
                if (cetak == 1) {
                    string namaFile = "Kuitansi_" + username + ".csv";
                    ofstream fileExcel(namaFile);
                    if (fileExcel.is_open()) {
                        fileExcel << "ID Transaksi,ID Pesanan,Layanan,Durasi (Jam),Total Biaya,Uang Bayar,Kembalian,Status Bayar\n";
                        for (int i = 0; i < jumlahTransaksi; i++) {
                            if (daftarTransaksi[i].usernamePelanggan == username) {
                                fileExcel << "TRX" << daftarTransaksi[i].idTransaksi << "," << daftarTransaksi[i].idPesanan << ","
                                    << daftarTransaksi[i].layanan << "," << daftarTransaksi[i].durasi << ","
                                    << daftarTransaksi[i].harga << "," << daftarTransaksi[i].uangBayar << ","
                                    << daftarTransaksi[i].kembalian << "," << daftarTransaksi[i].statusBayar << "\n";
                            }
                        }
                        fileExcel.close(); cout << "Berhasil dicetak!\n";
                    }
                }
            }
            else {
                cout << "Belum ada transaksi.\n";
            }
            system("pause");
        }
        else if (pilihan == 6) {
            system("cls");
            cout << "--- CARI CLEANER TERDEKAT ---\n";
            cout << "Daftar Area: Sleman, Bantul, Jogja, Gunungkidul, KulonProgo\n";
            cout << "Masukkan area lokasi Anda saat ini: ";
            string cariArea;
            cin >> cariArea;

            cout << "\n----------------------------------------\n";
            cout << "Daftar Cleaner beroperasi di " << cariArea << ":\n";
            cout << "----------------------------------------\n";
            bool adaCleaner = false;

            for (int i = 0; i < jumlahAkun; i++) {
                if (daftarAkun[i].role == "Cleaner" && daftarAkun[i].area == cariArea) {
                    cout << ">> " << daftarAkun[i].username << "\n";
                    adaCleaner = true;
                }
            }
            if (!adaCleaner) cout << "Maaf, belum ada Cleaner yang beroperasi di area " << cariArea << ".\n";
            cout << "----------------------------------------\n";
            system("pause");
        }
    } while (pilihan != 7);
}

// ========================================================
// MENU UTAMA CLEANER
// ========================================================
void menuCleaner(string username) {
    int pilihan;
    do {
        system("cls");
        cout << "\n=== MENU CLEANER: " << username << " ===\n";
        cout << "1. Lihat & Urutkan Semua Pesanan \n";
        cout << "2. Ambil Pekerjaan dari Antrean \n";
        cout << "3. Konfirmasi Pembayaran \n";
        cout << "4. Lihat Log Aktivitas \n";
        cout << "5. Logout\n";
        cout << "Pilih menu: ";
        cin >> pilihan;

        if (pilihan == 1) {
            system("cls");
            cout << "--- DAFTAR SEMUA PESANAN MASUK ---\n";
            tampilkanTabelPesanan("", true);

            cout << "\nLakukan Sorting berdasarkan Durasi Terpendek? (1. Ya, 2. Tidak): ";
            int sortPilih; cin >> sortPilih;
            if (sortPilih == 1) {
                selectionSortDurasi();
                tampilkanTabelPesanan("", true);
            }
            system("pause");

        }
        else if (pilihan == 2) {
            system("cls");
            cout << "--- PAPAN ANTREAN PEKERJAAN (FIFO) ---\n";

            if (isQueueEmpty()) {
                cout << "Hore! Tidak ada antrean pesanan saat ini.\n";
                system("pause");
                continue;
            }

            cout << "Urutan Antrean Saat Ini:\n";
            int nomorUrut = 1;
            for (int k = antreanOrder.depan; k <= antreanOrder.belakang; k++) {
                int idCek = antreanOrder.idPesananMasuk[k];
                for (int m = 0; m < jumlahPesanan; m++) {
                    if (daftarPesanan[m].id == idCek) {
                        cout << nomorUrut << ". ID: " << idCek << " | Layanan: " << daftarPesanan[m].layanan
                            << " (" << daftarPesanan[m].durasi << " jam) | Alamat: " << daftarPesanan[m].alamat << "\n";
                        nomorUrut++;
                    }
                }
            }

            cout << "\nBerapa banyak antrean terdepan yang ingin diambil? (Maksimal 3): ";
            int jumlahAmbil; cin >> jumlahAmbil;

            if (jumlahAmbil > 3) jumlahAmbil = 3;
            if (jumlahAmbil < 1) jumlahAmbil = 1;

            int berhasilDiambil = 0;
            cout << "\n--- PROSES PENGAMBILAN ---\n";

            for (int i = 0; i < jumlahAmbil; i++) {
                int idTerambil = dequeueOrder();
                if (idTerambil == -1) {
                    cout << "- Antrean sudah habis.\n";
                    break;
                }

                for (int j = 0; j < jumlahPesanan; j++) {
                    if (daftarPesanan[j].id == idTerambil) {
                        Pesanan* ptrPsn = &daftarPesanan[j];
                        ptrPsn->status = "Dikerjakan (" + username + ")";
                        cout << "- [SUKSES] Pesanan ID " << idTerambil << " milik " << ptrPsn->usernamePelanggan << " berhasil diambil!\n";
                        berhasilDiambil++;
                        break;
                    }
                }
            }

            cout << "\nTotal pekerjaan yang berhasil diambil: " << berhasilDiambil << "\n";
            system("pause");

        }
        else if (pilihan == 3) {
            system("cls");
            cout << "--- DAFTAR SEMUA TRANSAKSI MASUK ---\n";
            string garisTrxCleaner(90, '-');
            cout << garisTrxCleaner << "\n";
            cout << left << setw(10) << "ID Trx" << setw(15) << "Pelanggan"
                << setw(12) << "Layanan" << setw(12) << "Durasi"
                << setw(18) << "Total" << setw(20) << "Status" << "\n";
            cout << garisTrxCleaner << "\n";

            for (int i = 0; i < jumlahTransaksi; i++) {
                string textDurasi = to_string(daftarTransaksi[i].durasi) + " jam";
                string textHarga = "Rp " + to_string(daftarTransaksi[i].harga);
                cout << left << "TRX" << setw(7) << daftarTransaksi[i].idTransaksi
                    << setw(15) << daftarTransaksi[i].usernamePelanggan
                    << setw(12) << daftarTransaksi[i].layanan
                    << setw(12) << textDurasi
                    << setw(18) << textHarga
                    << setw(20) << daftarTransaksi[i].statusBayar << "\n";
            }
            cout << garisTrxCleaner << "\n";

            if (jumlahTransaksi > 0) {
                cout << "\n1. Konfirmasi Pembayaran Kasir\n2. Cetak Excel\n3. Kembali\nPilih: ";
                int aksi; cin >> aksi;

                if (aksi == 1) {
                    cout << "Masukkan ID Transaksi (Angka saja): TRX";
                    int idTrx; cin >> idTrx;
                    bool ditemukan = false;

                    for (int i = 0; i < jumlahTransaksi; i++) {
                        if (daftarTransaksi[i].idTransaksi == idTrx) {
                            if (daftarTransaksi[i].statusBayar == "Lunas") {
                                cout << "Transaksi ini sudah lunas sebelumnya!\n";
                                ditemukan = true; break;
                            }

                            Transaksi* ptrTrx = &daftarTransaksi[i];

                            cout << "\n--- PEMBAYARAN ---\n";
                            int uang;
                            do {
                                cout << "Total Tagihan    : Rp " << ptrTrx->harga << "\n";
                                cout << "Masukkan Uang    : Rp ";
                                while (!(cin >> uang)) {
                                    cout << "Harap masukkan ANGKA: Rp ";
                                    cin.clear(); cin.ignore(10000, '\n');
                                }
                                if (uang < ptrTrx->harga) {
                                    cout << "Maaf, uang kurang! Silakan input ulang.\n\n";
                                }
                            } while (uang < ptrTrx->harga);

                            ptrTrx->uangBayar = uang;
                            ptrTrx->kembalian = uang - ptrTrx->harga;
                            ptrTrx->statusBayar = "Lunas";

                            cout << "------------------------\n";
                            cout << "Kembalian        : Rp " << ptrTrx->kembalian << "\n";
                            cout << "Pembayaran Berhasil!\n";

                            string pesannya = "TRX" + to_string(idTrx) + " dikonfirmasi oleh " + username;
                            pushRiwayat(pesannya);

                            ditemukan = true; break;
                        }
                    }
                    if (!ditemukan) cout << "ID Transaksi tidak ditemukan.\n";

                }
                else if (aksi == 2) {
                    string namaFile = "Summary_Kerja_" + username + ".csv";
                    ofstream fileExcel(namaFile);
                    if (fileExcel.is_open()) {
                        fileExcel << "ID Transaksi,Pelanggan,Layanan,Total Biaya,Uang Bayar,Kembalian,Status Bayar\n";
                        for (int i = 0; i < jumlahTransaksi; i++) {
                            fileExcel << "TRX" << daftarTransaksi[i].idTransaksi << "," << daftarTransaksi[i].usernamePelanggan << ","
                                << daftarTransaksi[i].layanan << "," << daftarTransaksi[i].harga << ","
                                << daftarTransaksi[i].uangBayar << "," << daftarTransaksi[i].kembalian << "," << daftarTransaksi[i].statusBayar << "\n";
                        }
                        fileExcel.close(); cout << "Berhasil dicetak ke Excel!\n";
                    }
                }
            }
            system("pause");

        }
        else if (pilihan == 4) {
            system("cls");
            cetakStackRiwayat();
            system("pause");
        }
    } while (pilihan != 5);
}

void layerMenuUtama(string role, string username) {
    if (role == "Pelanggan") menuPelanggan(username);
    else if (role == "Cleaner") menuCleaner(username);
}