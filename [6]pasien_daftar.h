#include <iostream>
#include <string>
#include <fstream>

using namespace std;

struct pendaftarPasien
{
    string id;
    string nama;
    int umur;
    string diagnosis;
    pendaftarPasien *next;
};

class RumahSakit
{
private:
    pendaftarPasien *head;

    pendaftarPasien *caripendaftarPasien(pendaftarPasien *head, string id)
    {
        pendaftarPasien *current = head;
        while (current != nullptr)
        {
            if (current->id == id)
            {
                return current;
            }
            current = current->next;
        }
        return nullptr;
    }

    void hapuspendaftarPasien(pendaftarPasien *&head, string id)
    {
        pendaftarPasien *prev = nullptr;
        pendaftarPasien *current = head;

        while (current != nullptr)
        {
            if (current->id == id)
            {
                if (prev == nullptr)
                {
                    head = current->next;
                }
                else
                {
                    prev->next = current->next;
                }
                delete current;
                cout << "pendaftarPasien dengan ID " << id << " telah dihapus." << endl;
                return;
            }
            prev = current;
            current = current->next;
        }

        cout << "pendaftarPasien dengan ID " << id << " tidak ditemukan." << endl;
    }

    void simpanDaftarpendaftarPasien(pendaftarPasien *head)
    {
        ofstream file("daftar_pendaftarPasien.txt");

        if (!file.is_open())
        {
            cerr << "Gagal membuka file daftar_pendaftarPasien.txt." << endl;
            return;
        }

        pendaftarPasien *current = head;
        while (current != nullptr)
        {
            file << "ID: " << current->id << endl;
            file << "Nama: " << current->nama << endl;
            file << "Umur: " << current->umur << endl;
            file << "Diagnosis: " << current->diagnosis << endl;
            file << "====================" << endl;
            current = current->next;
        }

        file.close();
        cout << "Daftar pendaftarPasien berhasil disimpan ke dalam file daftar_pendaftarPasien.txt." << endl;
    }

public:
    RumahSakit() : head(nullptr) {}

    void input()
    {
        while (true)
        {
            cout << "Rumah Sakit Kelas B" << endl;
            cout << "1. Tambah pendaftarPasien" << endl;
            cout << "2. Tampilkan Daftar pendaftarPasien" << endl;
            cout << "3. Cari pendaftarPasien" << endl;
            cout << "4. Hapus pendaftarPasien" << endl;
            cout << "5. Simpan Daftar pendaftarPasien ke File" << endl;
            cout << "6. Keluar" << endl;
            cout << "Pilih menu: ";

            int pilihan;
            cin >> pilihan;

            switch (pilihan)
            {
            case 1:
            {
                // Case 1: Tambah pendaftarPasien
                string id, nama, diagnosis;
                int umur;
                cin.ignore();
                cout << "ID pendaftarPasien\t: ";
                getline(cin, id);
                cout << "Nama pendaftarPasien\t: ";
                getline(cin, nama);
                cout << "Umur pendaftarPasien\t: ";
                cin >> umur;
                cin.ignore();
                cout << "Diagnosis\t: ";
                getline(cin, diagnosis);

                pendaftarPasien *pendaftarPasienBaru = new pendaftarPasien{id, nama, umur, diagnosis, nullptr};

                if (head == nullptr)
                {
                    head = pendaftarPasienBaru;
                }
                else
                {
                    pendaftarPasien *current = head;
                    while (current->next != nullptr)
                    {
                        current = current->next;
                    }
                    current->next = pendaftarPasienBaru;
                }

                cout << "pendaftarPasien dengan ID " << id << " telah ditambahkan." << endl;
            }
            break;
            case 2:
                // Case 2: Tampilkan Daftar pendaftarPasien
                if (head == nullptr)
                {
                    cout << "Belum ada pendaftarPasien yang terdaftar." << endl;
                }
                else
                {
                    cout << "Daftar pendaftarPasien:" << endl;
                    pendaftarPasien *current = head;
                    int nomorpendaftarPasien = 1;
                    while (current != nullptr)
                    {
                        cout << "pendaftarPasien ke-" << nomorpendaftarPasien << endl;
                        cout << "ID: " << current->id << endl;
                        cout << "Nama: " << current->nama << endl;
                        cout << "Umur: " << current->umur << endl;
                        cout << "Diagnosis: " << current->diagnosis << endl;
                        cout << "====================" << endl;
                        current = current->next;
                        nomorpendaftarPasien++;
                    }
                }
                break;
            case 3:
            {
                // Case 3: Cari pendaftarPasien
                cin.ignore();
                cout << "Masukkan ID pendaftarPasien yang ingin dicari: ";
                string id;
                getline(cin, id);

                pendaftarPasien *hasilPencarian = caripendaftarPasien(head, id);
                if (hasilPencarian != nullptr)
                {
                    cout << "pendaftarPasien ditemukan:" << endl;
                    cout << "ID: " << hasilPencarian->id << endl;
                    cout << "Nama: " << hasilPencarian->nama << endl;
                    cout << "Umur: " << hasilPencarian->umur << endl;
                    cout << "Diagnosis: " << hasilPencarian->diagnosis << endl;
                    cout << "====================" << endl;
                }
                else
                {
                    cout << "pendaftarPasien dengan ID " << id << " tidak ditemukan." << endl;
                }
            }
            break;
            case 4:
            {
                // Case 4: Hapus pendaftarPasien
                cin.ignore();
                cout << "Masukkan ID pendaftarPasien yang ingin dihapus: ";
                string id;
                getline(cin, id);

                hapuspendaftarPasien(head, id);
            }
            break;
            case 5:
                // Case 5: Simpan Daftar pendaftarPasien ke File
                simpanDaftarpendaftarPasien(head);
                break;
            case 6:
                // Case 6: Keluar
                while (head != nullptr)
                {
                    pendaftarPasien *temp = head;
                    head = head->next;
                    delete temp;
                }
                cout << "Terima kasih telah berobat disini. Semoga cepat sembuh!" << endl;
                return;
            default:
                cout << "Pilihan tidak valid. Silakan coba lagi." << endl;
            }
        }
    }
};
