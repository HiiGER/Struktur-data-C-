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
public:
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

// Method untuk menginput data KTP
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
}

// Method untuk menampilkan data KTP ke file output.h
void tampilkanData() {
  ofstream outputFile("dataUser.txt");
  outputFile << "Provinsi             : " << provinsi << endl;
  outputFile << "Kabupaten            : " << kabupaten << endl;
  outputFile << "NIK                  : " << nik << endl;
  outputFile << "Nama                 : " << nama << endl;
  outputFile << "Tempat Lahir         : " << tempatLahir << endl;
  outputFile << "Tanggal Lahir        : " << tanggallahir.hari << "/" << tanggallahir.bulan << "/" << tanggallahir.tahun << endl;
  outputFile << "Jenis Kelamin        : "<< (jenisKelamin == 'L' ? "Laki-laki" : "Perempuan") << endl;
  outputFile << "Golongan Darah       : " << golonganDarah << endl;
  outputFile << "Alamat               : " << alamat.jalan << endl;
  outputFile << "RT/RW                : " << alamat.RTRW << endl;
  outputFile << "Desa                 : " << alamat.desa << endl;
  outputFile << "RT/RW                : " << alamat.kecamatan << endl<<endl;
  outputFile << "Agama                : " << agama << endl;
  outputFile << "Status               : " << status << endl;
  outputFile << "Pekerjaan            : " << pekerjaan << endl;
  outputFile << "Tanggal Pembuatan KTP: " << tanggalPembuatanKTP.hari << "/"<< tanggalPembuatanKTP.bulan << "/" << tanggalPembuatanKTP.tahun<< endl;

  outputFile.close();
  cout << "Data KTP telah disimpan dalam file output.h" << endl;
}


};
int main() {
    KTP ktp;

    cout << "=== Pembuatan KTP ===" << endl;
    ktp.inputData();
    ktp.tampilkanData();
    ktp.tampiloutput();

    return 0;
}
