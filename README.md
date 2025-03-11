// Tugas 2 OOP E-commerce Product Catalog Nasywa Destian Nabilah STI.cpp : This file contains the 'main' function. Program execution begins and ends there.
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


// Tugas 3 OOP University Course System Nasywa Destian Nabilah STI.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <string>
#include <vector>

using namespace std;

class MataKuliah; 

class Mahasiswa {
private:
    int id;
    string nama;
    vector<MataKuliah*> mataKuliahTerdaftar; 

public:
    Mahasiswa(int mhs_id, string mhs_nama) : id(mhs_id), nama(mhs_nama) {}

    void daftarMataKuliah(MataKuliah* mataKuliah);
    void batalMataKuliah(MataKuliah* mataKuliah);
    string getNama() const { return nama; }
};

class MataKuliah {
private:
    int kode;
    string nama;
    int kapasitasMaksimal;
    vector<Mahasiswa*> daftarMahasiswa; 

public:
    MataKuliah(int mk_kode, string mk_nama, int mk_kapasitas)
        : kode(mk_kode), nama(mk_nama), kapasitasMaksimal(mk_kapasitas) {}

    bool daftar(Mahasiswa* mahasiswa) {
        if (daftarMahasiswa.size() < kapasitasMaksimal) {
            daftarMahasiswa.push_back(mahasiswa);
            return true;
        }
        return false;
    }

    void batal(Mahasiswa* mahasiswa) {
        for (auto it = daftarMahasiswa.begin(); it != daftarMahasiswa.end(); ++it) {
            if (*it == mahasiswa) {
                daftarMahasiswa.erase(it);
                return;
            }
        }
    }

    void tampilkanMahasiswa() const {
        cout << "Mahasiswa yang terdaftar di " << nama << ":\n";
        if (daftarMahasiswa.empty()) {
            cout << "- Tidak ada mahasiswa terdaftar.\n";
            return;
        }
        for (const Mahasiswa* mahasiswa : daftarMahasiswa) {
            cout << "- " << mahasiswa->getNama() << endl;
        }
    }

    string getNama() const { return nama; }
    int getJumlahMahasiswa() const { return daftarMahasiswa.size(); }  
    int getKapasitasMaksimal() const { return kapasitasMaksimal; }      
};

void Mahasiswa::daftarMataKuliah(MataKuliah* mataKuliah) {
    if (mataKuliah->daftar(this)) {
        mataKuliahTerdaftar.push_back(mataKuliah);
        cout << nama << " berhasil mendaftar ke " << mataKuliah->getNama() << "!\n";
    }
    else {
        cout << "Pendaftaran gagal: " << mataKuliah->getNama()
            << " sudah penuh (" << mataKuliah->getJumlahMahasiswa()
            << "/" << mataKuliah->getKapasitasMaksimal() << ").\n";
    }
}

void Mahasiswa::batalMataKuliah(MataKuliah* mataKuliah) {
    mataKuliah->batal(this);
    for (auto it = mataKuliahTerdaftar.begin(); it != mataKuliahTerdaftar.end(); ++it) {
        if (*it == mataKuliah) {
            mataKuliahTerdaftar.erase(it);
            cout << nama << " berhasil membatalkan pendaftaran dari " << mataKuliah->getNama() << "!\n";
            return;
        }
    }
}

int main() {
    MataKuliah mk1(101, "Object-Oriented Programming", 2);
    MataKuliah mk2(102, "User Experience Design", 3);

    Mahasiswa mhs1(1, "Nasywa");
    Mahasiswa mhs2(2, "Reva");
    Mahasiswa mhs3(3, "Alya");

    mhs1.daftarMataKuliah(&mk1);
    mhs2.daftarMataKuliah(&mk1);
    mhs3.daftarMataKuliah(&mk1); 

    mhs1.daftarMataKuliah(&mk2);
    mhs3.daftarMataKuliah(&mk2);

    cout << "\n--- Daftar Mahasiswa di Object-Oriented Programming ---\n";
    mk1.tampilkanMahasiswa();

    cout << "\n--- Daftar Mahasiswa di User Experience Design ---\n";
    mk2.tampilkanMahasiswa();

    return 0;
}
