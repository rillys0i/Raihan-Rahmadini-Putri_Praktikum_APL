#include <iostream>
#include <iomanip>
using namespace std;

double konversiRupiah(double jumlah_mata_uang) {
    double dollar = jumlah_mata_uang * 0.000064;
    double euro = jumlah_mata_uang * 0.000059;
    double yen = jumlah_mata_uang * 0.0096;

    cout << fixed << setprecision(4);
    cout << "Dollar: " << dollar << endl;
    cout << "Euro: " << euro << endl;
    cout << "Yen: " << yen << endl;
    
    return dollar;
}

double konversiDollar(double jumlah_mata_uang) {    
    double rupiah = jumlah_mata_uang * 15728.00;
    double euro = jumlah_mata_uang * 0.92;
    double yen = jumlah_mata_uang * 150.40;

    cout << fixed << setprecision(4);
    cout << "Rupiah: Rp " << rupiah << endl;
    cout << "Euro: " << euro << endl;
    cout << "Yen: " << yen << endl;

    return yen;
}

double konversiEuro(double jumlah_mata_uang) {
    double rupiah = jumlah_mata_uang * 17061.36;
    double dollar = jumlah_mata_uang * 1.08;
    double yen = jumlah_mata_uang * 163.17;

    cout << fixed << setprecision(4);
    cout << "Rupiah: Rp " << rupiah << endl;
    cout << "Dollar: " << dollar << endl;
    cout << "Yen: " << yen << endl;

    return rupiah;
}

double konversiYen(double jumlah_mata_uang) {
    double rupiah = jumlah_mata_uang * 104.56;
    double dollar = jumlah_mata_uang * 0.0066;
    double euro = jumlah_mata_uang * 0.0061;

    cout << fixed << setprecision(4);
    cout << "Rupiah: Rp " << rupiah << endl;
    cout << "Dollar: " << dollar << endl;
    cout << "Euro: " << euro << endl;

    return dollar;
}

int main() {
    string username = "Putri";
    string password = "2309106008";
    string inputUsername, inputPassword;
    int loginAttempt = 0;
    bool loggedIn = false;
    string choice;

    do {
        cout << "=== LOGIN ===" << endl;
        cout << "Username: ";
        cin >> inputUsername;
        cout << "Password: ";
        cin >> inputPassword;

        if (inputUsername == username && inputPassword == password) {
            loggedIn = true;
        } else {
            loginAttempt++;
            if (loginAttempt == 3) {
                cout << "Sudah 3x login. Program akan berakhir." << endl;
                return 0;
            }
            cout << "username atau password salah. silahkan coba lagi." << endl;
        }
    } while (loggedIn != true);

    do {
        cout << "=== MENU ===" << endl;
        cout << "1. Konversi Rupiah" << endl;
        cout << "2. Konversi Dollar" << endl;
        cout << "3. Konversi Euro" << endl;
        cout << "4. Konversi Yen" << endl;
        cout << "5. Keluar" << endl;
        cout << "Pilih menu: ";
        cin >> choice;

        if (choice == "1") {
            double jumlah_mata_uang;
            cout << "Masukkan jumlah Rupiah: Rp ";
            cin >> jumlah_mata_uang;
            konversiRupiah(jumlah_mata_uang);
        } else if (choice == "2") {
            double jumlah_mata_uang;
            cout << "Masukkan jumlah Dollar: ";
            cin >> jumlah_mata_uang;
            konversiDollar(jumlah_mata_uang);
        } else if (choice == "3") {
            double jumlah_mata_uang;
            cout << "Masukkan jumlah Euro: ";
            cin >> jumlah_mata_uang;
            konversiEuro(jumlah_mata_uang);
        } else if (choice == "4") {
            double jumlah_mata_uang;
            cout << "Masukkan jumlah Yen: ";
            cin >> jumlah_mata_uang;
            konversiYen(jumlah_mata_uang);
        } else if (choice == "5") {
            cout << "Terima kasih! Program telah selesai." << endl;
            break;
        } else {
            cout << "Pilihan tidak valid. Silakan coba lagi." << endl;
        }
    } while (true);

    return 0;
}
