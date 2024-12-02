#include <fstream>
#include <iostream>
#include <string>
using namespace std;
struct Tanggal {
  int hari;
  int bulan;
  int tahun;
};

// Struct untuk alamat
struct Alamat {
  string jalan;
  string RTRW;
  string desa;
  string kecamatan;
};

class KTP {
private:
  string provinsi;
  string kabupaten;
  string nik;
  string nama;
  char jenisKelamin;
  string golonganDarah;
  string tempatLahir;
  Alamat alamat;
  string agama;
  string status;
  string pekerjaan;
  Tanggal tanggallahir;
  Tanggal tanggalPembuatanKTP;

  int pill;

public:
  void inputData() {
    cout << "Masukkan provinsi: ";
    cin.ignore();
    getline(cin, provinsi);

    cout << "Masukkan kabupaten: ";
    getline(cin, kabupaten);

    cout << "Masukkan NIK: ";
    cin >> nik;

    cout << "Masukkan Nama: ";
    cin.ignore();
    getline(cin, nama);

    cout << "Tempat Lahir: ";
    getline(cin, tempatLahir);

    cout << "Tanggal Lahir (DD MM YYYY): ";
    cin >> tanggallahir.hari >> tanggallahir.bulan >> tanggallahir.tahun;

    cout << "1. Laki-Laki" << endl;
    cout << "2. Perempuan" << endl;
    cout << "Masukkan Jenis Kelamin (1/2): ";
    cin >> pill;
    if (pill == 1) {
      jenisKelamin = 'L';
    } else if (pill == 2) {
      jenisKelamin = 'P';
    } else {
      cout << "Pilihan tidak valid." << endl;
      return;
    }

    cout << "1. O" << endl;
    cout << "2. A" << endl;
    cout << "3. B" << endl;
    cout << "4. AB" << endl;
    cout << "Masukkan Golongan Darah (1/2/3/4): ";
    cin >> pill;
    switch (pill) {
    case 1:
      golonganDarah = "O";
      break;
    case 2:
      golonganDarah = "A";
      break;
    case 3:
      golonganDarah = "B";
      break;
    case 4:
      golonganDarah = "AB";
      break;
    default:
      cout << "Pilihan tidak valid." << endl;
      return;
    }

    cout << "Alamat: " << endl;
    cout << "Masukkan Jalan: ";
    cin.ignore();
    getline(cin, alamat.jalan);
    cout << "RT/RW: ";
    getline(cin, alamat.RTRW);
    cout << "Desa/Kelurahan: ";
    getline(cin, alamat.desa);
    cout << "Kecamatan: ";
    getline(cin, alamat.kecamatan);

    cout << "1. Islam" << endl;
    cout << "2. Kristen" << endl;
    cout << "3. Katolik" << endl;
    cout << "4. Hindu" << endl;
    cout << "5. Budha" << endl;
    cout << "6. Konghuchu" << endl;
    cout << "Masukkan Agama (1-6): ";
    cin >> pill;
    switch (pill) {
    case 1:
      agama = "Islam";
      break;
    case 2:
      agama = "Kristen";
      break;
    case 3:
      agama = "Katolik";
      break;
    case 4:
      agama = "Hindu";
      break;
    case 5:
      agama = "Budha";
      break;
    case 6:
      agama = "Konghuchu";
      break;
    default:
      cout << "Pilihan tidak valid." << endl;
      return;
    }

    cout << "1. Kawin" << endl;
    cout << "2. Belum Kawin" << endl;
    cout << "Masukkan Status (1/2): ";
    cin >> pill;
    if (pill == 1) {
      status = "Kawin";
    } else if (pill == 2) {
      status = "Belum Kawin";
    } else {
      cout << "Pilihan tidak valid." << endl;
      return;
    }

    cout << "Masukkan Pekerjaan: ";
    cin.ignore();
    getline(cin, pekerjaan);

    cout << "Tanggal Pembuatan KTP (DD MM YYYY): ";
    cin >> tanggalPembuatanKTP.hari >> tanggalPembuatanKTP.bulan >>
        tanggalPembuatanKTP.tahun;
    simpanData();
  }

  void cekSpasiUS(const string &str) {
    bool cek = false;
    for (char c : str) {
      if (c == ' ') {
        cek = true; // Jika ditemukan spasi, kembalikan true
      }
    }

    if (cek == true) {
      system("clear");
      cout << "============== PERINGATAN =================" << endl << endl;
      cout << "username tidak boleh mengandung (spasi) !!!" << endl;
      cout << "===========================================" << endl;
      up();
    }
  }

  void cekSpasiPS(const string &str) {
    bool cek = false;
    for (char c : str) {
      if (c == ' ') {
        cek = true; // Jika ditemukan spasi, kembalikan true
      }
    }

    if (cek == true) {
      system("clear");
      cout << "============== PERINGATAN =================" << endl << endl;
      cout << "password tidak boleh mengandung (spasi) !!!" << endl;
      cout << "===========================================" << endl;
      up();
    }
  }

  void up() {
    string username;
    string password;
    int saldo;

    cout << "Masukkan username     : ";
    cin.ignore();
    getline(cin, username);
    cekSpasiUS(username);

    cout << "Masukkan Password : ";
    cin.ignore();
    getline(cin, password);
    cekSpasiPS(password);

    cout << "Masukkan jumlah saldo  : ";
    cin >> saldo;

    // Memeriksa apakah terdapat spasi di username atau password

    ofstream outputFile("dataUserUP.txt", ios::app);

    if (outputFile.is_open()) {
      outputFile << username << " " << password << " " << saldo << endl;
      outputFile.close();
      cout << "Data telah ditambahkan ke dalam file dataUserUP.txt" << endl;
    } else {
      cout << "Gagal membuka file dataUserUP.txt untuk penulisan." << endl;
    }
  }

  void simpanData() {
    ofstream outputFile("dataUserKTP.txt", ios::app); // Gunakan mode ios::app

    if (outputFile.is_open()) {
      outputFile << "----------------------------------------------------------"
                    "------------------------------"
                 << endl;
      outputFile << "Provinsi             : " << provinsi << endl;
      outputFile << "Kabupaten            : " << kabupaten << endl;
      outputFile << "NIK                  : " << nik << endl;
      outputFile << "Nama                 : " << nama << endl;
      outputFile << "Tempat Lahir         : " << tempatLahir << endl;
      outputFile << "Tanggal Lahir        : " << tanggallahir.hari << "/"
                 << tanggallahir.bulan << "/" << tanggallahir.tahun << endl;
      outputFile << "Jenis Kelamin        : "
                 << (jenisKelamin == 'L' ? "Laki-laki" : "Perempuan") << endl;
      outputFile << "Golongan Darah       : " << golonganDarah << endl;
      outputFile << "Alamat               : " << alamat.jalan << endl;
      outputFile << "RT/RW                : " << alamat.RTRW << endl;
      outputFile << "Desa                 : " << alamat.desa << endl;
      outputFile << "RT/RW                : " << alamat.kecamatan << endl
                 << endl;
      outputFile << "Agama                : " << agama << endl;
      outputFile << "Status               : " << status << endl;
      outputFile << "Pekerjaan            : " << pekerjaan << endl;
      outputFile << "Tanggal Pembuatan KTP: " << tanggalPembuatanKTP.hari << "/"
                 << tanggalPembuatanKTP.bulan << "/"
                 << tanggalPembuatanKTP.tahun << endl;
      outputFile.close();
      system("clear");
      cout << "Data KTP telah di simpan" << endl;
    } else {
      cout << "Gagal membuka file dataUserKTP.txt untuk penulisan" << endl;
      inputData();
    }
  }

  void mainreg() {

    cout << "=== Registrasi Pembuatan Akun ===" << endl;
    KTP ktp;

    ktp.inputData();
    ktp.up();
  }
};