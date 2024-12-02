
#include <fstream>
#include <iostream>
#include <string>
#include "statis.h"


using namespace std;
class login {
public:
 program Program; 
  bool verifikasiLogin(string username, string password, int index = 0) {
    if (index >= sizeof(useradmin) / sizeof(useradmin[0])) {
      return false;
    }
    if (username == useradmin[index] && password == paswordadmin[index]) {
      return true;
    } else {
      return verifikasiLogin(username, password, index + 1);
    }
  }

  void opsilogin() {
    system("clear");
    int opsipengguna;
    cout << "1. User" << endl;
    cout << "2. Admin" << endl;
    cout << "Masukkan opsi: ";
    cin >> opsipengguna;

    if (opsipengguna == 1) {
      masuk();
    } else if (opsipengguna == 2) {
      string username, password;

      cout << "Masukkan username: ";
      cin >> username;
      cout << "Masukkan password: ";
      cin >> password;

      if (verifikasiLogin(username, password)) {
        cout << "Login berhasil!" << endl;
        int pilAdmin;
        do {
          cout << "1.tambah barang " << endl;
          cout << "2.keluar(logout) " << endl;
          cout << "masukan pilihan : ";
          cin >> pilAdmin;
          if (pilAdmin == 1) {
            Program.tambah();
          }
        } while (pilAdmin != 2);
        opsilogin();

      } else {
        cout << "Login gagal. Username atau password salah." << endl;
        opsilogin();
      }
    } else {
      cout << "Tidak valid, masukkan ulang opsi." << endl;
      opsilogin();
    }
  }

  bool masuk() {
    string username;
    string password;
    cout << "Masukkan username: ";
    cin >> username;
    cout << "Masukkan Password: ";
    cin >> password;
    ifstream inputFile("dataUserUP.txt");
    if (inputFile.is_open()) {
      string line;
      while (getline(inputFile, line)) {
        size_t pos = line.find(" ");
        if (pos != string::npos) {
          string savedUsername = line.substr(0, pos);
          string savedPassword = line.substr(pos + 1);
          if (username == savedUsername && password == savedPassword) {
            inputFile.close();
            cout << "Login berhasil!" << endl;
              Program.mainSTADIS();
            return true; // Login sukses
          }
        }
      }
      inputFile.close();
    } else {
      cout << "Gagal membuka file 'dataUserUP.txt'." << endl;
    }
    cout << "Login gagal. Username atau password salah." << endl;
    return false; // Login gagal
  }

private:
  string useradmin[2] = {"kelompok02D", "admin1"};
  string paswordadmin[2] = {"lancar", "234aman"};
};
