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
  
  void inputData();