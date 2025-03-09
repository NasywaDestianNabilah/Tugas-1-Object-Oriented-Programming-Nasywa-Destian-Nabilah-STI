// Tugas OOP University Course System Nasywa Destian Nabilah STI.cpp : This file contains the 'main' function. Program execution begins and ends there.
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