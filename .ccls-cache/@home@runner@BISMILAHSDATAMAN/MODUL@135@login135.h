#ifndef CLOGIN_H

#define CLOGIN_H

#include "dinamis.h"

#include <fstream>

#include <iostream>

#include <string>

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
    string opsipengguna;
    cout << "==================================" << endl;
    cout << "|1. User                          |" << endl;
    cout << "==================================" << endl;
    cout << "|2. Admin                         |" << endl;
    cout << "==================================" << endl;
    cout << "Masukkan opsi: ";
    cin >> opsipengguna;

    system("clear");
    if (opsipengguna == "1") {
      masuk();
    } else if (opsipengguna == "2") {
      string username, password;

      cout << "=====================" << endl;
      cout << "Masukkan username: ";
      cin >> username;

      cout << "=====================" << endl;
      cout << "Masukkan password: ";
      cin >> password;

      if (verifikasiLogin(username, password)) {
        cout << "Selamat Login Anda Berhasil!" << endl;
        int pilAdmin;
        do {
          cout << "1.tambah barang " << endl;
          cout << "2.keluar(logout) " << endl;
          cout << "masukan pilihan : ";
          cin >> pilAdmin;
          if (pilAdmin == 1) {

            Program.pilihKategori();
          }
        } while (pilAdmin != 2);
        system("clear");
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
    int savedSaldo;
    cout << "=======================" << endl;
    cout << "Masukkan username: ";
    cin >> username;

    cout << "=======================" << endl;
    cout << "Masukkan Password: ";
    cin >> password;

    ifstream inputFile("dataUserUP.txt");
    if (inputFile.is_open()) {
      string line;
      while (getline(inputFile, line)) {
        size_t posFirstSpace = line.find(" ");
        if (posFirstSpace != string::npos) {
          string savedUsername = line.substr(0, posFirstSpace);
          size_t posSecondSpace = line.find(" ", posFirstSpace + 1);
          if (posSecondSpace != string::npos) {
            string savedPassword = line.substr(
                posFirstSpace + 1, posSecondSpace - posFirstSpace - 1);
            string saldoStr = line.substr(posSecondSpace + 1);
            if (username == savedUsername && password == savedPassword) {
              savedSaldo = stoi(saldoStr);

              inputFile.close();
              system("clear");
              cout << "+========================+" << endl;
              cout << "|YEAY!! Login Berhasil!  |" << endl;
              cout << "+========================+" << endl << endl << endl;

              Program.mainSTADIS(savedSaldo);
              opsilogin();
              return true;
            }
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

#endif // CLOGIN_H