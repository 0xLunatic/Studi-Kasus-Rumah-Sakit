#include "[1]dataPenyakitPasien.h"
#include "[2]pendataanObat.h"
#include "[4]wifi.h"
#include "[6]pasien_daftar.h"
#include "[7]BPJS_Gratis.h"
#include "[8]Presensi.h"
#include "[9]Penebusan_Obat.h"
#include "[10]Pembayaran.h"
#include "[11]Antrian.h"
#include "[12]Parkir.h"
#include "[13]CS.h"
#include <iostream>
using namespace std;

int main()
{
    int pilihan;
    ManajemenPasien dataPenyakit;
    Pembayaran pembayaran;
    RumahSakitWiFi rumahsakitWifi;
    ManajemenObat pendataanObat;
    AntrianRumahSakit antrianRs;
    ParkirRumahSakit parkirRs;
    Cstmr_srvc Cs;
    BPJS bpjs;
    Employee presensi;
    Resep resep;
    RumahSakit rumahSakit;

    cout << "Rumah Sakit Sejahtera" << endl;
    cout << endl;
    // UNTUK PILIHAN MENU TOLONG SAMAKAN DENGAN NOMOR KELOMPOK
    cout << "Silahkan pilih menu!" << endl;
    cout << "1. Data Penyakit Pasien" << endl;
    cout << "2. Pendataan Obat" << endl;
    cout << "4. Fasilitas Wifi RS" << endl;
    cout << "6. Daftar Pasien" << endl;
    cout << "7. BPJS Gratis" << endl;
    cout << "8. Presensi Karyawan" << endl;
    cout << "9. Penebusan Obat" << endl;
    cout << "10. Pembayaran" << endl;
    cout << "11. Antrian" << endl;
    cout << "12. Parkir" << endl;
    cout << "13. Customer Service" << endl;
    cout << endl;
    cout << "Pilihan Menu : ";
    cin >> pilihan;

    switch (pilihan)
    {
    case 1:
        dataPenyakit.tampilkanPengisianDataPenyakit();
        break;
    case 2:
        pendataanObat.pilihanObat();
        break;
    case 4:
        rumahsakitWifi.dataWifi();
        break;
    case 6:
        rumahSakit.input();
        break;
    case 7:
        bpjs.inputBJPS();
        break;
    case 8:
        presensi.presensi();
        break;
    case 9:
        resep.HandleResep();
        break;
    case 10:
        pembayaran.menuPembayaran();
        break;
    case 11:
        antrianRs.inputAntrian();
    case 12:
        parkirRs.output();
        break;
    case 13:
        Cs.pilih();
        break;
    }
}