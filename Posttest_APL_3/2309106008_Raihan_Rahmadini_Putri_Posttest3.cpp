#include <iostream>
#include <cstring>

using namespace std;

const int MAX_BARANG = 100;
const int MAX_LOGIN_ATTEMPTS = 3;

void tambahData(char namaBarang[][100], char jenisBarang[][100], int jumlahBarang[], int nomorBarang [], int& jumlahData);
void tampilkanData(const char namaBarang[][100], const char jenisBarang[][100], const int jumlahBarang[], const int nomorBarang [], int jumlahData);
void hapusData(char namaBarang[][100], char jenisBarang[][100], int jumlahBarang[], int nomorBarang [], int& jumlahData);
void perbaruiData(char namaBarang[][100], char jenisBarang[][100], int jumlahBarang[], int nomorBarang [], int jumlahData);
int cariData(const char namaBarang[][100], const char namaCari[], int jumlahData, int index = 0);
bool cekLogin(const char username[], const char password[]) {
    return (strcmp(username, "putri") == 0 && strcmp(password, "008") == 0);
}


int main() {
    char namaBarang[MAX_BARANG][100];
    char jenisBarang[MAX_BARANG][100];
    int jumlahBarang[MAX_BARANG];
    int nomorBarang[MAX_BARANG];
    int jumlahData = 0;

    char Username[50], Password[10];
    int loginAttempt = 0;

    while (loginAttempt < MAX_LOGIN_ATTEMPTS) {
        cout << "Masukkan Username: ";
        cin >> Username;
        cout << "Masukkan Password: ";
        cin >> Password;

        if (cekLogin(Username, Password)) {
            cout << "Login berhasil!" << endl;
            break;
        } else {
            cout << "Login gagal. Silakan coba lagi." << endl;
            loginAttempt++;
        }
    }

    if (loginAttempt == MAX_LOGIN_ATTEMPTS) {
        cout << "Anda sudah login sebanyak " << MAX_LOGIN_ATTEMPTS << " kali. Program akan berhenti." << endl;
        return 0;
    }

    int pilihan;

    do {
        cout << "\nMenu Utama:" << endl;
        cout << "1. Tambah Data Barang" << endl;
        cout << "2. Tampilkan Data Barang" << endl;
        cout << "3. Hapus Data Barang" << endl;
        cout << "4. Perbarui Data Barang" << endl;
        cout << "5. Cari Data Barang" << endl;
        cout << "6. Keluar" << endl;
        cout << "Masukkan pilihan: ";
        cin >> pilihan;

        switch (pilihan) {
            case 1:
                tambahData(namaBarang, jenisBarang, jumlahBarang, nomorBarang, jumlahData);
                break;
            case 2:
                tampilkanData(namaBarang, jenisBarang, jumlahBarang, nomorBarang, jumlahData);
                break;
            case 3:
                hapusData(namaBarang, jenisBarang, jumlahBarang, nomorBarang, jumlahData);
                break;
            case 4:
                perbaruiData(namaBarang, jenisBarang, jumlahBarang, nomorBarang, jumlahData);
                break;
            case 5:
                {
                    char namaCari[100];
                    cout << "Masukkan nama barang yang ingin dicari: ";
                    cin.ignore();
                    cin.getline(namaCari, 100);
                    int index = cariData(namaBarang, namaCari, jumlahData);
                    if (index != -1) {
                        cout << "Barang ditemukan pada nomor: " << nomorBarang[index] << endl;
                    } else {
                        cout << "Barang tidak ditemukan." << endl;
                    }
                    break;
                }
            case 6:
                cout << "Terima kasih telah menggunakan program ini." << endl;
                break;
            default:
                cout << "Pilihan tidak valid. Silakan coba lagi." << endl;
        }
    } while (pilihan != 6);

    return 0;
}

void tambahData(char namaBarang[][100], char jenisBarang[][100], int jumlahBarang[], int nomorBarang[], int& jumlahData) {
    char nama[50], jenis[50];
    int jumlah, no;
    cout << "Masukkan Nomor Barang: ";
    cin >> no;
    cout << "Masukkan Nama Barang: ";
    cin.ignore();
    cin.getline(nama, 50);
    cout << "Masukkan Jenis Barang: ";
    cin.getline(jenis, 50);
    cout << "Masukkan Jumlah Barang: ";
    cin >> jumlah;
    nomorBarang[jumlahData] = no;
    strcpy(namaBarang[jumlahData], nama);
    strcpy(jenisBarang[jumlahData], jenis);
    jumlahBarang[jumlahData] = jumlah;
    jumlahData++;
    cout << "Data barang berhasil ditambahkan." << endl;
}

void tampilkanData(const char namaBarang[][100], const char jenisBarang[][100], const int jumlahBarang[], const int nomorBarang[], int jumlahData) {
    if (jumlahData == 0) {
        cout << "Belum tersedia data barang." << endl;
        return;
    }
    cout << "Data Barang:" << endl;
    for (int i = 0; i < jumlahData; ++i) {
        cout << "Nomor: " << nomorBarang[i] << ", Nama: " << namaBarang[i] << ", Jenis: " << jenisBarang[i] << ", Jumlah: " << jumlahBarang[i] << endl;
    }
}

int cariData(const char namaBarang[][100], const char namaCari[], int jumlahData, int index) {
    if (index == jumlahData) 
        return -1; 

    if (strcmp(namaBarang[index], namaCari) == 0) 
        return index;

    return cariData(namaBarang, namaCari, jumlahData, index + 1);
}

void hapusData(char namaBarang[][100], char jenisBarang[][100], int jumlahBarang[], int nomorBarang[], int& jumlahData) {
    if (jumlahData == 0) {
        cout << "Belum tersedia data barang." << endl;
        return;
    }
    tampilkanData(namaBarang, jenisBarang, jumlahBarang, nomorBarang, jumlahData);
    int nomorHapus;
    cout << "Masukkan nomor barang yang ingin dihapus: ";
    cin >> nomorHapus;

    int index = -1;
    for (int i = 0; i < jumlahData; ++i) {
        if (nomorBarang[i] == nomorHapus) {
            index = i;
            break;
        }
    }

    if (index != -1) {
        for (int i = index; i < jumlahData - 1; ++i) {
            nomorBarang[i] = nomorBarang[i + 1];
            strcpy(namaBarang[i], namaBarang[i + 1]);
            strcpy(jenisBarang[i], jenisBarang[i + 1]);
            jumlahBarang[i] = jumlahBarang[i + 1];
        }
        jumlahData--;
        cout << "Data barang berhasil dihapus." << endl;
    } else {
        cout << "Nomor barang tidak valid." << endl;
    }
}

void perbaruiData(char namaBarang[][100], char jenisBarang[][100], int jumlahBarang[], int nomorBarang[], int jumlahData) {
    if (jumlahData == 0) {
        cout << "Belum tersedia data barang." << endl;
        return;
    }
    tampilkanData(namaBarang, jenisBarang, jumlahBarang, nomorBarang, jumlahData);
    int nomorPerbarui;
    cout << "Masukkan nomor barang yang ingin diperbarui: ";
    cin >> nomorPerbarui;

    int index = -1;
    for (int i = 0; i < jumlahData; ++i) {
        if (nomorBarang[i] == nomorPerbarui) {
            index = i;
            break;
        }
    }

    if (index != -1) {
        char nama[100], jenis[100];
        int jumlah;
        cout << "Masukkan Nama Barang Baru: ";
        cin.ignore();
        cin.getline(nama, 100);
        cout << "Masukkan Jenis Barang Baru: ";
        cin.getline(jenis, 100);
        cout << "Masukkan Jumlah Barang Baru: ";
        cin >> jumlah;

        strcpy(namaBarang[index], nama);
        strcpy(jenisBarang[index], jenis);
        jumlahBarang[index] = jumlah;

        cout << "Data barang berhasil diperbarui." << endl;
    } else {
        cout << "Nomor barang tidak valid." << endl;
    }
}
