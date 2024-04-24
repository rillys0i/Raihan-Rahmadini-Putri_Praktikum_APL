#include <iostream>
#include <limits> 
#include <cstring>

using namespace std;

const int MAX_BARANG = 100;
const int MAX_LOGIN_ATTEMPTS = 3;
const int MAX_NAMA_LENGTH = 100; 
const int MAX_JENIS_LENGTH = 100; 

struct Barang {
    int nomor;
    char nama[MAX_NAMA_LENGTH + 1];
    char jenis[MAX_JENIS_LENGTH + 1];
    int jumlah;
};

void tambahData(Barang*, int&);
void tampilkanData(const Barang*, int);
void hapusData(Barang*, int&);
void perbaruiData(Barang*, int);
int cariData(const Barang*, const char*, int);
void bubbleSortNamaDescending(Barang *daftarBarang, int jumlahData);
void insertionSortNomorAscending(Barang *daftarBarang, int jumlahData);
void selectionSortJumlahDescending(Barang *daftarBarang, int jumlahData);
void sequentialSearchAscendingMenu(const Barang *daftarBarang, int jumlahData);
void binarySearchDescendingMenu(const Barang *daftarBarang, int jumlahData);

bool cekLogin(const char username[], const char password[]) {
    return (strcmp(username, "putri") == 0 && strcmp(password, "008") == 0);
}

int main() {
    Barang daftarBarang[MAX_BARANG];
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

    system("cls");
    int pilihan;

    do {
        cout << "\t\t\t============================================" << endl;
        cout << "\t\t\tSELAMAT DATANG DI PENDATAAN PERIZINAN BARANG" <<  endl;
        cout << "\t\t\t============================================" << endl;
        cout << "Menu Utama:" << endl;
        cout << "1. Tambah Data Barang" << endl;
        cout << "2. Tampilkan Data Barang" << endl;
        cout << "3. Hapus Data Barang" << endl;
        cout << "4. Perbarui Data Barang" << endl;
        cout << "5. Cari Data Barang" << endl;
        cout << "6. mengurutkan Data Barang secara Descending" << endl;
        cout << "7. mengurutkan Data Barang secara Ascending" << endl;
        cout << "8. mengurutkan Data Barang secara Descending" << endl;
        cout << "9. cari data secara Ascending" << endl;
        cout << "10. cari data secara descending" << endl;
        cout << "11. Keluar" << endl;
        cout << "Masukkan pilihan: ";
        cin >> pilihan;

        switch (pilihan) {
            case 1:
                tambahData(daftarBarang, jumlahData);
                break;
            case 2:
                tampilkanData(daftarBarang, jumlahData);
                break;
            case 3:
                hapusData(daftarBarang, jumlahData);
                break;
            case 4:
                perbaruiData(daftarBarang, jumlahData);
                break;
            case 5:
                {
                    char namaCari[100];
                    cout << "Masukkan nama barang yang ingin dicari: ";
                    cin.ignore();
                    cin.getline(namaCari, 100);
                    int index = cariData(daftarBarang, namaCari, jumlahData);
                    if (index != -1) {
                        cout << "Barang ditemukan pada nomor: " << daftarBarang[index].nomor << endl;
                    } else {
                        cout << "Barang tidak ditemukan." << endl;
                    }
                    break;
                }
            case 6:
                bubbleSortNamaDescending(daftarBarang, jumlahData);
                cout << "Data barang berhasil diurutkan berdasarkan nama secara descending." << endl;
                break;
            case 7:
                insertionSortNomorAscending(daftarBarang, jumlahData);
                cout << "Data barang berhasil diurutkan berdasarkan nomor secara ascending." << endl;
                break;
            case 8:
                selectionSortJumlahDescending(daftarBarang, jumlahData);
                cout << "Data barang berhasil diurutkan berdasarkan jumlah secara descending." << endl;
                break;
            case 9:
                sequentialSearchAscendingMenu(daftarBarang, jumlahData);
                break;
            case 10:
                binarySearchDescendingMenu(daftarBarang, jumlahData);
                break;
            case 11:
                cout << "Terima kasih telah menggunakan program ini." << endl;
                break;
            default:
                cout << "Pilihan tidak valid. Silakan coba lagi." << endl;
        }
    } while (pilihan != 11);

    return 0;
}

void tambahData(Barang *daftarBarang, int& jumlahData) {
    if (jumlahData == MAX_BARANG) {
        cout << "Data barang sudah penuh." << endl;
        return;
    }

    Barang baru;
    Barang *ptrBaru = &baru;

    cout << "Masukkan Nomor Barang: ";
    while (true) {
        cin >> ptrBaru->nomor;
        if (cin.fail() || ptrBaru->nomor <= 0) {
            cout << "Input tidak valid. Masukkan nomor barang yang valid: ";
            cin.clear(); 
            cin.ignore(numeric_limits<streamsize>::max(), '\n'); 
        } else {
            break; 
        }
    }

    cin.ignore(); 

    cout << "Masukkan Nama Barang: ";
    cin.getline(ptrBaru->nama, MAX_NAMA_LENGTH + 1); 
    if (strlen(ptrBaru->nama) > MAX_NAMA_LENGTH) {
        cout << "Panjang nama barang melebihi batas maksimum." << endl;
        return;
    }

    cout << "Masukkan Jenis Barang: ";
    cin.getline(ptrBaru->jenis, MAX_JENIS_LENGTH + 1); 
    if (strlen(ptrBaru->jenis) > MAX_JENIS_LENGTH) {
        cout << "Panjang jenis barang melebihi batas maksimum." << endl;
        return;
    }

    cout << "Masukkan Jumlah Barang: ";
    cin >> ptrBaru->jumlah;
    if (cin.fail() || ptrBaru->jumlah < 0) {
        cout << "Input tidak valid. Masukkan jumlah barang yang valid." << endl;
        cin.clear(); 
        cin.ignore(numeric_limits<streamsize>::max(), '\n'); 
        return;
    }

    daftarBarang[jumlahData] = baru;
    jumlahData++;
    cout << "Data barang berhasil ditambahkan." << endl;
}

void tampilkanData(const Barang *daftarBarang, int jumlahData) {
    if (jumlahData == 0) {
        cout << "Belum tersedia data barang." << endl;
        return;
    }
    cout << "Data Barang:" << endl;
    for (int i = 0; i < jumlahData; ++i) {
        cout << "Nomor: " << daftarBarang[i].nomor << ", Nama: " << daftarBarang[i].nama << ", Jenis: " << daftarBarang[i].jenis << ", Jumlah: " << daftarBarang[i].jumlah << endl;
    }
}

int cariData(const Barang *daftarBarang, const char *namaCari, int jumlahData) {
    for (int i = 0; i < jumlahData; ++i) {
        if (strcmp(daftarBarang[i].nama, namaCari) == 0)
            return i;
    }
    return -1;
}

void hapusData(Barang *daftarBarang, int& jumlahData) {
    if (jumlahData == 0) {
        cout << "Belum tersedia data barang." << endl;
        return;
    }
    tampilkanData(daftarBarang, jumlahData);
    int nomorHapus;
    cout << "Masukkan nomor barang yang ingin dihapus: ";
    cin >> nomorHapus;

    if (nomorHapus < 1 || nomorHapus > jumlahData) {
        cout << "Nomor barang tidak valid." << endl;
        return;
    }

    int index = -1;
    for (int i = 0; i < jumlahData; ++i) {
        if (daftarBarang[i].nomor == nomorHapus) {
            index = i;
            break;
        }
    }

    if (index != -1) {
        for (int i = index; i < jumlahData - 1; ++i) {
            daftarBarang[i] = daftarBarang[i + 1];
        }
        jumlahData--;
        cout << "Data barang berhasil dihapus." << endl;
    } else {
        cout << "Nomor barang tidak valid." << endl;
    }
}

void perbaruiData(Barang *daftarBarang, int jumlahData) {
    if (jumlahData == 0) {
        cout << "Belum tersedia data barang." << endl;
        return;
    }
    tampilkanData(daftarBarang, jumlahData);
    int nomorPerbarui;
    cout << "Masukkan nomor barang yang ingin diperbarui: ";
    cin >> nomorPerbarui;

    if (nomorPerbarui < 1 || nomorPerbarui > jumlahData) {
        cout << "Nomor barang tidak valid." << endl;
        return;
    }

    int index = -1;
    for (int i = 0; i < jumlahData; ++i) {
        if (daftarBarang[i].nomor == nomorPerbarui) {
            index = i;
            break;
        }
    }

    if (index != -1) {
        Barang baru;
        Barang *ptrBaru = &baru;

        cout << "Masukkan Nama Barang Baru: ";
        cin.ignore();
        cin.getline(ptrBaru->nama, MAX_NAMA_LENGTH + 1); 
        if (strlen(ptrBaru->nama) > MAX_NAMA_LENGTH) {
            cout << "Panjang nama barang melebihi batas maksimum." << endl;
            return;
        }

        cout << "Masukkan Jenis Barang Baru: ";
        cin.getline(ptrBaru->jenis, MAX_JENIS_LENGTH + 1); 
        if (strlen(ptrBaru->jenis) > MAX_JENIS_LENGTH) {
            cout << "Panjang jenis barang melebihi batas maksimum." << endl;
            return;
        }

        cout << "Masukkan Jumlah Barang Baru: ";
        cin >> ptrBaru->jumlah;

        daftarBarang[index] = baru;

        cout << "Data barang berhasil diperbarui." << endl;
    } else {
        cout << "Nomor barang tidak valid." << endl;
    }
}

void bubbleSortNamaDescending(Barang *daftarBarang, int jumlahData) {
    for (int i = 0; i < jumlahData - 1; ++i) {
        for (int j = 0; j < jumlahData - i - 1; ++j) {
            if (strcmp(daftarBarang[j].nama, daftarBarang[j + 1].nama) < 0) {
                swap(daftarBarang[j], daftarBarang[j + 1]);
            }
        }
    }
}

void insertionSortNomorAscending(Barang *daftarBarang, int jumlahData) {
    for (int i = 1; i < jumlahData; ++i) {
        Barang key = daftarBarang[i];
        int j = i - 1;
        while (j >= 0 && daftarBarang[j].nomor > key.nomor) {
            daftarBarang[j + 1] = daftarBarang[j];
            j = j - 1;
        }
        daftarBarang[j + 1] = key;
    }
}

void selectionSortJumlahDescending(Barang *daftarBarang, int jumlahData) {
    for (int i = 0; i < jumlahData - 1; ++i) {
        int max_idx = i;
        for (int j = i + 1; j < jumlahData; ++j) {
            if (daftarBarang[j].jumlah > daftarBarang[max_idx].jumlah) {
                max_idx = j;
            }
        }
        swap(daftarBarang[max_idx], daftarBarang[i]);
    }
}

int sequentialSearchAscending(const Barang *daftarBarang, int jumlahData, int nomorCari) {
    for (int i = 0; i < jumlahData; ++i) {
        if (daftarBarang[i].nomor == nomorCari) {
            return i;
        }
    }
    return -1;
}

int binarySearchDescending(const Barang *daftarBarang, int jumlahData, int nomorCari) {
    int low = 0, high = jumlahData - 1;
    while (low <= high) {
        int mid = low + (high - low) / 2;
        if (daftarBarang[mid].nomor == nomorCari) {
            return mid;
        } else if (daftarBarang[mid].nomor < nomorCari) {
            high = mid - 1;
        } else {
            low = mid + 1;
        }
    }
    return -1;
}

void sequentialSearchAscendingMenu(const Barang *daftarBarang, int jumlahData) {
    int nomorCari;
    cout << "Masukkan nomor barang yang ingin dicari: ";
    cin >> nomorCari;
    int index = sequentialSearchAscending(daftarBarang, jumlahData, nomorCari);
    if (index != -1) {
        cout << "Barang ditemukan pada indeks: " << index << endl;
    } else {
        cout << "Barang tidak ditemukan." << endl;
    }
}

void binarySearchDescendingMenu(const Barang *daftarBarang, int jumlahData) {
    int nomorCari;
    cout << "Masukkan nomor barang yang ingin dicari: ";
    cin >> nomorCari;
    int index = binarySearchDescending(daftarBarang, jumlahData, nomorCari);
    if (index != -1) {
        cout << "Barang ditemukan pada indeks: " << index << endl;
    } else {
        cout << "Barang tidak ditemukan." << endl;
    }
}

