#ifndef ALATLAB_H
#define ALATLAB_H

#include <string>
using std::string;

class AlatLaboratorium {
private:
    string nama;
    string kategori;
    int jumlah;

public:
    // Constructor
    AlatLaboratorium();
    AlatLaboratorium(const string &nama, const string &kategori, int jumlah);

    // Getter & Setter
    void setNama(const string &nama);
    string getNama() const;

    void setKategori(const string &kategori);
    string getKategori() const;

    void setJumlah(int jumlah);
    int getJumlah() const;

    // Method operasi
    void tampilkanInfo() const;
    void tambahJumlah(int n);
    bool kurangiJumlah(int n); // return false jika stok tidak cukup

    // Destructor
    ~AlatLaboratorium();
};

#endif // ALATLAB_H
