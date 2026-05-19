#include <iostream>
using namespace std;

// Abstract Base Class
class RekeningBank {
protected:
    string namaNasabah;
    double saldo;

public:
    RekeningBank(string nama, double sld) {
        namaNasabah = nama;
        saldo = sld;
    }

    virtual void potongAdmin() = 0;

    void tampilkanSaldo() {
        cout << "Nama Nasabah : " << namaNasabah << endl;
        cout << "Saldo Akhir  : Rp " << saldo << endl;
        cout << "==============================" << endl;
    }
};

// Rekening Syariah
class RekeningSyariah : public RekeningBank {
public:
    RekeningSyariah(string nama, double sld)
        : RekeningBank(nama, sld) {}

    void potongAdmin() {
        cout << "Rekening Syariah bebas biaya admin" << endl;
    }
};

// Rekening Konvensional
class RekeningKonvensional : public RekeningBank {
public:
    RekeningKonvensional(string nama, double sld)
        : RekeningBank(nama, sld) {}

    void potongAdmin() {
        saldo -= 15000;
        cout << "Biaya admin Rp 15.000 dipotong" << endl;
    }
};

// Rekening Premium
class RekeningPremium : public RekeningBank {
public:
    RekeningPremium(string nama, double sld)
        : RekeningBank(nama, sld) {}

    void potongAdmin() {
        if (saldo > 10000000) {
            cout << "Saldo di atas Rp 10.000.000, bebas biaya admin" << endl;
        } else {
            saldo -= 50000;
            cout << "Biaya admin Rp 50.000 dipotong" << endl;
        }
    }
};

int main() {

    RekeningBank* rekening;

    RekeningSyariah syariah("Andi", 5000000);
    RekeningKonvensional konvensional("Budi", 3000000);
    RekeningPremium premium1("Citra", 15000000);
    RekeningPremium premium2("Dina", 7000000);

    rekening = &syariah;
    rekening->potongAdmin();
    rekening->tampilkanSaldo();

    rekening = &konvensional;
    rekening->potongAdmin();
    rekening->tampilkanSaldo();

    rekening = &premium1;
    rekening->potongAdmin();
    rekening->tampilkanSaldo();

    rekening = &premium2;
    rekening->potongAdmin();
    rekening->tampilkanSaldo();

    return 0;
}