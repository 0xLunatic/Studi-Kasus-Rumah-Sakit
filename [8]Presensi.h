#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Employee
{
public:
    string name;
    bool present;

    void presensi()
    {
        const int numEmployees = 10;
        vector<Employee> employees = createEmployees(numEmployees);

        while (true)
        {
            cout << "Menu Presensi Karyawan:" << endl;
            cout << "1. Cek Presensi Karyawan" << endl;
            cout << "2. Presensi" << endl;
            cout << "3. Keluar" << endl;

            int choice;
            cin >> choice;

            switch (choice)
            {
            case 1:
                cout << "Daftar Karyawan dan Presensi:" << endl;
                for (int i = 0; i < numEmployees; ++i)
                {
                    cout << employees[i].name << ": ";
                    if (employees[i].present)
                    {
                        cout << "Hadir" << endl;
                    }
                    else
                    {
                        cout << "Tidak Hadir" << endl;
                    }
                }
                break;

            case 2:
                cout << "Masukkan nomor karyawan (1-" << numEmployees << "): ";
                int employeeNumber;
                cin >> employeeNumber;

                if (employeeNumber >= 1 && employeeNumber <= numEmployees)
                {
                    employees[employeeNumber - 1].present = true;
                    cout << "Presensi berhasil dicatat." << endl;
                }
                else
                {
                    cout << "Nomor karyawan tidak valid." << endl;
                }
                break;

            case 3:
                cout << "Terima kasih! Sampai jumpa." << endl;
                return;

            default:
                cout << "Pilihan tidak valid. Silakan pilih lagi." << endl;
                break;
            }
        }
    }

private:
    static vector<Employee> createEmployees(int numEmployees)
    {
        vector<Employee> employees;

        employees.push_back(Employee{"Karyawan 1", false});
        employees.push_back(Employee{"Karyawan 2", false});
        employees.push_back(Employee{"Karyawan 3", false});
        employees.push_back(Employee{"Karyawan 4", false});
        employees.push_back(Employee{"Karyawan 5", false});
        employees.push_back(Employee{"Karyawan 6", false});
        employees.push_back(Employee{"Karyawan 7", false});
        employees.push_back(Employee{"Karyawan 8", false});
        employees.push_back(Employee{"Karyawan 9", false});
        employees.push_back(Employee{"Karyawan 10", false});

        return employees;
    }
};
