#include <iostream>
#include <string>
using namespace std;

class Resep
{
public:
    string namaPasien;
    struct Obat
    {
        string nama;
        int jumlah;
        float harga;

        Obat() : nama(""), jumlah(0), harga(0.0) {}
        Obat(string _nama, float _harga) : nama(_nama), jumlah(0), harga(_harga) {}

        void Tambah(int jumlah)
        {
            this->jumlah += jumlah;
        }
    } daftarObat[3];

    Resep()
    {
        namaPasien = "";
        daftarObat[0] = Obat("Paracetamol", 5000);
        daftarObat[1] = Obat("Amoxicillin", 8000);
        daftarObat[2] = Obat("Ibuprofen", 6000);
    }

    void TampilkanResep()
    {
        cout << "\nResep untuk " << namaPasien << ":\n";
        float totalHarga = 0;
        for (int i = 0; i < 3; ++i)
        {
            if (daftarObat[i].jumlah > 0)
            {
                cout << daftarObat[i].nama << " - " << daftarObat[i].jumlah << " tablet - Rp" << daftarObat[i].harga * daftarObat[i].jumlah << "\n";
                totalHarga += daftarObat[i].harga * daftarObat[i].jumlah;
            }
        }
        cout << "Total Harga: Rp" << totalHarga << "\n";
    }

    void HandleResep()
    {
        cout << "Masukkan nama pasien: ";
        cin >> namaPasien;

        for (int i = 0; i < 3; ++i)
        {
            cout << "1. Paracetamol" << endl;
            cout << "2. Amoxicillin" << endl;
            cout << "3. Ibuprofen" << endl;
            cout << "Pilih nomor obat (1 - 3) atau ketik 'selesai' untuk selesai: ";
            string input;
            cin >> input;

            if (input == "selesai")
            {
                break;
            }

            int nomorObat = stoi(input);
            if (nomorObat < 1 || nomorObat > 3)
            {
                cout << "Nomor obat tidak valid. Silakan pilih dari daftar yang tersedia.\n";
                continue;
            }

            cout << "Masukkan jumlah tablet: ";
            int jumlah;
            cin >> jumlah;

            daftarObat[nomorObat - 1].Tambah(jumlah);
        }

        TampilkanResep();
    }
};
