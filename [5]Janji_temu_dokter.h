#include <iostream>
#include <string>

using namespace std;

class JanjiTemuPasien
{
private:
    string nama;
    int usia;
    float tinggi;
    float berat;
    string alamat;
    string riwayatPenyakit;
    string keluhan;

public:
    JanjiTemuPasien() {}

    void setInfoJanjiTemuPasien(const string &nama, int usia, float tinggi, float berat, const string &alamat,
                                const string &riwayatPenyakit, const string &keluhan)
    {
        this->nama = nama;
        this->usia = usia;
        this->tinggi = tinggi;
        this->berat = berat;
        this->alamat = alamat;
        this->riwayatPenyakit = riwayatPenyakit;
        this->keluhan = keluhan;
    }

    void tampilkanInfoJanjiTemuPasien()
    {
        cout << "\nIdentitas JanjiTemuPasien:\n";
        cout << "Nama: " << nama << endl;
        cout << "Usia: " << usia << " tahun" << endl;
        cout << "Tinggi: " << tinggi << " cm" << endl;
        cout << "Berat: " << berat << " kg" << endl;
        cout << "Alamat: " << alamat << endl;
        cout << "Riwayat Penyakit: " << riwayatPenyakit << endl;
        cout << "Keluhan: " << keluhan << endl;
    }
};
struct Waktu
{
    int jam;
    int menit;
};

class JanjiTemu
{
private:
    string namaDokter;
    string spesialis;
    Waktu waktuJanji;

public:
    JanjiTemu() {}

    void setNamaDokter(const string &nama)
    {
        namaDokter = nama;
    }

    void setSpesialis(const string &spesialis)
    {
        this->spesialis = spesialis;
    }

    void setWaktuJanji(int jam, int menit)
    {
        waktuJanji.jam = jam;
        waktuJanji.menit = menit;
    }

    void tampilkanJanji()
    {
        cout << "Janji temu dengan Dokter " << namaDokter << " (" << spesialis << ") pada jam "
             << waktuJanji.jam << ":" << waktuJanji.menit << endl;
    }
    void menuJanjiTemu()
    {
        string namaJanjiTemuPasien, alamatJanjiTemuPasien, riwayatPenyakit, keluhanJanjiTemuPasien;
        int usiaJanjiTemuPasien;
        float tinggiJanjiTemuPasien, beratJanjiTemuPasien;

        cout << "Masukkan nama JanjiTemuPasien: ";
        getline(cin, namaJanjiTemuPasien);

        cout << "Masukkan usia JanjiTemuPasien: ";
        cin >> usiaJanjiTemuPasien;
        cin.ignore();

        cout << "Masukkan tinggi JanjiTemuPasien (cm): ";
        cin >> tinggiJanjiTemuPasien;
        cin.ignore();

        cout << "Masukkan berat JanjiTemuPasien (kg): ";
        cin >> beratJanjiTemuPasien;
        cin.ignore();

        cout << "Masukkan alamat JanjiTemuPasien: ";
        getline(cin, alamatJanjiTemuPasien);

        cout << "Masukkan riwayat penyakit JanjiTemuPasien: ";
        getline(cin, riwayatPenyakit);

        cout << "Masukkan keluhan JanjiTemuPasien: ";
        getline(cin, keluhanJanjiTemuPasien);

        JanjiTemuPasien JanjiTemuPasien;
        JanjiTemuPasien.setInfoJanjiTemuPasien(namaJanjiTemuPasien, usiaJanjiTemuPasien, tinggiJanjiTemuPasien, beratJanjiTemuPasien, alamatJanjiTemuPasien, riwayatPenyakit, keluhanJanjiTemuPasien);
        JanjiTemuPasien.tampilkanInfoJanjiTemuPasien();

        JanjiTemu janji1, janji2;
        janji1.setNamaDokter("Dr. Smith");
        janji1.setSpesialis("Dokter Umum");
        janji1.setWaktuJanji(10, 30);

        janji2.setNamaDokter("Dr. Johnson");
        janji2.setSpesialis("Dokter Gigi");
        janji2.setWaktuJanji(14, 15);

        cout << "\nPilihan Dokter Spesialis:\n";
        cout << "1. ";
        janji1.tampilkanJanji();
        cout << "2. ";
        janji2.tampilkanJanji();

        int pilihan;
        cout << "\nPilih dokter spesialis (1-2): ";
        cin >> pilihan;

        if (pilihan == 1)
        {
            cout << "\nAnda telah memilih dokter spesialis:\n";
            janji1.tampilkanJanji();
        }
        else if (pilihan == 2)
        {
            cout << "\nAnda telah memilih dokter spesialis:\n";
            janji2.tampilkanJanji();
        }
        else
        {
            cout << "Pilihan tidak valid.\n";
        }
    }
};

// int main()
// {
//     string namaJanjiTemuPasien, alamatJanjiTemuPasien, riwayatPenyakit, keluhanJanjiTemuPasien;
//     int usiaJanjiTemuPasien;
//     float tinggiJanjiTemuPasien, beratJanjiTemuPasien;

//     cout << "Masukkan nama JanjiTemuPasien: ";
//     getline(cin, namaJanjiTemuPasien);

//     cout << "Masukkan usia JanjiTemuPasien: ";
//     cin >> usiaJanjiTemuPasien;
//     cin.ignore();

//     cout << "Masukkan tinggi JanjiTemuPasien (cm): ";
//     cin >> tinggiJanjiTemuPasien;
//     cin.ignore();

//     cout << "Masukkan berat JanjiTemuPasien (kg): ";
//     cin >> beratJanjiTemuPasien;
//     cin.ignore();

//     cout << "Masukkan alamat JanjiTemuPasien: ";
//     getline(cin, alamatJanjiTemuPasien);

//     cout << "Masukkan riwayat penyakit JanjiTemuPasien: ";
//     getline(cin, riwayatPenyakit);

//     cout << "Masukkan keluhan JanjiTemuPasien: ";
//     getline(cin, keluhanJanjiTemuPasien);

//     JanjiTemuPasien JanjiTemuPasien;
//     JanjiTemuPasien.setInfoJanjiTemuPasien(namaJanjiTemuPasien, usiaJanjiTemuPasien, tinggiJanjiTemuPasien, beratJanjiTemuPasien, alamatJanjiTemuPasien, riwayatPenyakit, keluhanJanjiTemuPasien);
//     JanjiTemuPasien.tampilkanInfoJanjiTemuPasien();

//     JanjiTemu janji1, janji2;
//     janji1.setNamaDokter("Dr. Smith");
//     janji1.setSpesialis("Dokter Umum");
//     janji1.setWaktuJanji(10, 30);

//     janji2.setNamaDokter("Dr. Johnson");
//     janji2.setSpesialis("Dokter Gigi");
//     janji2.setWaktuJanji(14, 15);

//     cout << "\nPilihan Dokter Spesialis:\n";
//     cout << "1. ";
//     janji1.tampilkanJanji();
//     cout << "2. ";
//     janji2.tampilkanJanji();

//     int pilihan;
//     cout << "\nPilih dokter spesialis (1-2): ";
//     cin >> pilihan;

//     if (pilihan == 1)
//     {
//         cout << "\nAnda telah memilih dokter spesialis:\n";
//         janji1.tampilkanJanji();
//     }
//     else if (pilihan == 2)
//     {
//         cout << "\nAnda telah memilih dokter spesialis:\n";
//         janji2.tampilkanJanji();
//     }
//     else
//     {
//         cout << "Pilihan tidak valid.\n";
//     }

//     return 0;
// }
