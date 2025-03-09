// Tugas 1 OOP E-commerce Product Catalog Nasywa Destian Nabilah STI.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <iomanip>
using namespace std;

class Produk {
private:
    int id;
    string nama;
    double harga;
    int stok;
    string kategori;

public:
    Produk(int id, string nama, double harga, int stok, string kategori)
        : id(id), nama(nama), harga(harga), stok(stok), kategori(kategori) {}

    void perbaruiHarga(double harga_baru) {
        if (harga_baru >= 0) {
            harga = harga_baru;
        }
        else {
            cout << "Harga tidak boleh negatif." << endl;
        }
    }

    void perbaruiStok(int jumlah) {
        if (stok + jumlah >= 0) {
            stok += jumlah;
        }
        else {
            cout << "Stok tidak boleh negatif." << endl;
        }
    }

    double terapkanDiskon(double persentase_diskon) {
        if (persentase_diskon >= 0 && persentase_diskon <= 100) {
            return harga * (1 - persentase_diskon / 100);
        }
        else {
            cout << "Persentase diskon tidak valid." << endl;
            return harga;
        }
    }

    void tampilkanInfo() {
        cout << "ID Produk: " << id << endl;
        cout << "Nama: " << nama << endl;
        cout << fixed << setprecision(2);
        cout << "Harga: Rp" << harga << endl;
        cout << "Stok: " << stok << endl;
        cout << "Kategori: " << kategori << endl;
    }
};

int main() {
    Produk produk1(1, "Laptop", 13000000, 10, "Elektronik");
    produk1.tampilkanInfo();

    produk1.perbaruiHarga(12000000);
    cout << "\nSetelah memperbarui harga:" << endl;
    produk1.tampilkanInfo();

    double harga_diskon = produk1.terapkanDiskon(10);
    cout << "\nHarga setelah diskon 10%: Rp" << fixed << setprecision(2) << harga_diskon << endl;

    return 0;
}
