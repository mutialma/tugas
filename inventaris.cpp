#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <sstream>
using namespace std;

// ==========================
// Struktur Data Barang
// ==========================
struct Barang {
    string nama;
    string kategori;
    int jumlah;
};

// ==========================
// Fungsi Memisahkan String
// ==========================
vector<string> split(const string &line, char delimiter) {
    vector<string> parts;
    string part;
    stringstream ss(line);

    while (getline(ss, part, delimiter)) {
        parts.push_back(part);
    }
    return parts;
}

// ==========================
// Membaca Data dari File
// ==========================
void loadData(vector<Barang> &daftar) {
    ifstream file("barang.txt");
    if (!file.is_open()) return;

    string line;
    while (getline(file, line)) {
        vector<string> p = split(line, '|');
        if (p.size() == 3) {
            Barang b;
            b.nama = p[0];
            b.kategori = p[1];
            b.jumlah = stoi(p[2]);
            daftar.push_back(b);
        }
    }
    file.close();
}

// ==========================
// Menyimpan Data ke File
// ==========================
void saveData(const vector<Barang> &daftar) {
    ofstream file("barang.txt", ios::trunc);
    for (const auto &b : daftar) {
        file << b.nama << "|" << b.kategori << "|" << b.jumlah << "\n";
    }
    file.close();
}

// ==========================
// Menambah Barang
// ==========================
void tambahBarang(vector<Barang> &daftar) {
    Barang b;

    cout << "\nMasukkan nama barang   : ";
    cin >> ws;
    getline(cin, b.nama);

    cout << "Masukkan kategori       : ";
    getline(cin, b.kategori);

    cout << "Masukkan jumlah         : ";
    cin >> b.jumlah;

    daftar.push_back(b);
    saveData(daftar);

    cout << ">> Barang berhasil ditambahkan!\n";
}

// ==========================
// Menampilkan Data Barang
// ==========================
void tampilkanBarang(const vector<Barang> &daftar) {
    cout << "\n=== DAFTAR BARANG ===\n";
    if (daftar.empty()) {
        cout << "Tidak ada data.\n";
        return;
    }

    int no = 1;
    for (const auto &b : daftar) {
        cout << no++ << ". " << b.nama
             << " | Kategori: " << b.kategori
             << " | Jumlah: " << b.jumlah << "\n";
    }
}

// ==========================
// Update Jumlah Barang
// ==========================
void updateStok(vector<Barang> &daftar) {
    if (daftar.empty()) {
        cout << "\nData masih kosong!\n";
        return;
    }

    string nama;
    cout << "\nMasukkan nama barang yang dicari: ";
    cin >> ws;
    getline(cin, nama);

    for (auto &b : daftar) {
        if (b.nama == nama) {
            int pilih, jumlah;
            cout << "\n1. Tambah stok\n2. Kurangi stok\nPilih: ";
            cin >> pilih;

            cout << "Masukkan jumlah: ";
            cin >> jumlah;

            if (pilih == 1) {
                b.jumlah += jumlah;
                cout << ">> Stok berhasil ditambah!\n";
            } else if (pilih == 2) {
                if (jumlah > b.jumlah) {
                    cout << ">> Stok tidak cukup!\n";
                    return;
                }
                b.jumlah -= jumlah;
                cout << ">> Stok berhasil dikurangi!\n";
            }

            saveData(daftar);
            return;
        }
    }

    cout << ">> Barang tidak ditemukan!\n";
}

// ==========================
// MAIN PROGRAM
// ==========================
int main() {
    vector<Barang> daftar;
    loadData(daftar);

    int pilih;
    while (true) {
        cout << "\n=== SISTEM INVENTARIS BARANG ===\n";
        cout << "1. Tambah Barang\n";
        cout << "2. Tampilkan Barang\n";
        cout << "3. Update Stok Barang\n";
        cout << "4. Keluar\n";
        cout << "Pilih: ";
        cin >> pilih;

        switch (pilih) {
            case 1: tambahBarang(daftar); break;
            case 2: tampilkanBarang(daftar); break;
            case 3: updateStok(daftar); break;
            case 4: cout << "Keluar...\n"; return 0;
            default: cout << "Pilihan tidak valid!\n";
        }
    }

    return 0;
}
