#include <fstream>
#include <iostream>
#include <string>
using namespace std;

class AkunManager {
public:
  AkunManager() {}

  void tampilkanMenuKategori() {
    cout << "|============================================================================|"<< endl;
    cout << "|                            Pilih kategori Fashion:                          |"<< endl;
    cout << "|============================================================================|"<< endl;
    cout << "|1. Baju Pria                                                                |"<< endl;
    cout << "|2. Baju Wanita                                                              |"<< endl;
    cout << "|3. Aksesoris                                                                |"<< endl;
    cout << "|4. Sepatu pria                                                              |"<< endl;
    cout << "|5. Sepatu wanita                                                            |"<< endl;
    cout << "|6. Skincare                                                                 |"<< endl;
    cout << "|============================================================================|"<< endl;
  }

  //////////////////////////////////PEMBELI////////PEMBELI////PEMBELI////PEMBELI////////////////////////////////////////
  void pilihKategori() {
    tampilkanMenuKategori();
    int pilKategori;
    cout << "Masukkan pilihan kategori (1/2/......): ";
    cin >> pilKategori;

    switch (pilKategori) {
    case 1:
      pilihBajupria();
      break;
    case 2:
      pilihBajuwanita();
      break;
    case 3:
      pilihAksesoris();
      break;
    case 4:
      pilihSepatupria();
      break;
    case 5:
      pilihSepatuwanita();
      break;
    case 6:
      pilihSkincare();
      break;
      
    default:
      cout << "Pilihan kategori tidak valid." << endl;
    }
  }

  void pilihBajupria() {
    system("clear");
    cout << "Pilih subkategori Elektronik:" << endl;
    cout << "1. Peralatan listrik rumah tangga" << endl;
    cout << "2. Komputer" << endl;
    cout << "3. Handphone" << endl;
    cout << "4. Lampu" << endl;
    cout << "5. Kipas" << endl;
    cout << "6. AC" << endl;
    cout << "7. timbangan(LCD) " << endl;
    cout << " 8. Setrika" << endl;
    cout << " 9.Aksesoris Handphone" << endl;

    int pilSubKategori;
    cout << "Masukkan pilihan subkategori (1/2/3/4/5/6/7/8/9): ";
    cin >> pilSubKategori;

    if (pilSubKategori >= 1 && pilSubKategori <= 10) {
      string kategori = "Elektronik";
      string subKategori;

      switch (pilSubKategori) {
      case 1:
        subKategori = "Peralatan listrik rumah tangga";
        break;
      case 2:
        subKategori = "Komputer";
        break;
      case 3:
        subKategori = "Handphone";
        break;
      case 4:
        subKategori = "Lampu";
        break;
      case 5:
        subKategori = "Kipas";
        break;
      case 6:
        subKategori = "AC";
        break;
      case 7:
        subKategori = "Timbangan(LCD)";
        break;
      case 8:
        subKategori = "Setrika";
        break;
      case 9:
        subKategori = "Aksesoris Handphone";
        break;
      default:
        cout << "Pilihan subkategori tidak valid." << endl;
        return;
      }

      simpanKontenKeFile(kategori, subKategori);
    } else {
      cout << "Pilihan subkategori tidak valid." << endl;
    }
  }

  void pilihBajuwanita() {
    system("clear");
    cout << "Pilih subkategori Fashion:" << endl;
    cout << "1. Pakaian pria" << endl;
    cout << "2. Pakaian wanita" << endl;
    cout << "3. Sepatu pria" << endl;
    cout << "4. Sepatu wanita" << endl;
    cout << "5. Jam tangan" << endl;
    cout << "6. Gelang&cincin" << endl;
    cout << "7. Kalung" << endl;
    cout << "8. Tas pria" << endl;
    cout << "9. Tas wanita" << endl;
    cout << "10. Aksesoris & lainnya" << endl;

    int pilSubKategori;
    cout << "Masukkan pilihan subkategori (1/2/3..): ";
    cin >> pilSubKategori;

    if (pilSubKategori >= 1 && pilSubKategori <= 3) {
      string kategori = "Fashion";
      string subKategori;

      switch (pilSubKategori) {
      case 1:
        subKategori = "Pakaian pria";
        break;
      case 2:
        subKategori = "Pakaian wanita";
        break;
      case 3:
        subKategori = "Sepatu pria";
        break;
      case 4:
        subKategori = "sepatu wanita";
        break;
      case 5:
        subKategori = "Jam tangan";
        break;
      case 6:
        subKategori = "Gelang & cincin";
        break;
      case 7:
        subKategori = "Kalung";
        break;
      case 8:
        subKategori = "Tas Pria";
        break;
      case 9:
        subKategori = "Tas Wanita";
        break;
      case 10:
        subKategori = "Aksesoris & lainnya";
        break;
      default:
        cout << "Pilihan subkategori tidak valid." << endl;
        return;
      }

      simpanKontenKeFile(kategori, subKategori);
    } else {
      cout << "Pilihan subkategori tidak valid." << endl;
    }
  }

  void pilihAksesoris() {
    system("clear");
    cout << "Pilih subkategori Hobi:" << endl;
    cout << "1. Mainan" << endl;
    cout << "2. Olahraga" << endl;
    cout << "3. Makanan" << endl;
    cout << "4. Peralatan PETS" << endl;
    cout << "5. Lainnya" << endl;

    int pilSubKategori;
    cout << "Masukkan pilihan subkategori (1/2/3/4/5): ";
    cin >> pilSubKategori;

    if (pilSubKategori >= 1 && pilSubKategori <= 5) {
      string kategori = "Hobi";
      string subKategori;

      switch (pilSubKategori) {
      case 1:
        subKategori = "Mainan";
        break;
      case 2:
        subKategori = "olahraga";
        break;
      case 3:
        subKategori = "Makanan";
        break;
      case 4:
        subKategori = "Peralatan PETS";
        break;
      case 5:
        subKategori = "Lainnya";
      default:
        cout << "Pilihan subkategori tidak valid." << endl;
        return;
      }

      simpanKontenKeFile(kategori, subKategori);
    } else {
      cout << "Pilihan subkategori tidak valid." << endl;
    }
  }

  void pilihSepatupria() {
    system("clear");
    cout << "Pilih subkategori Kecantikan:" << endl;
    cout << "1. Alat Makeup" << endl;
    cout << "2. Skincare" << endl;
    cout << "3. Lainnya" << endl;

    int pilSubKategori;
    cout << "Masukkan pilihan subkategori (1/2/3/4): ";
    cin >> pilSubKategori;

    if (pilSubKategori >= 1 && pilSubKategori <= 4) {
      string kategori = "Kecantikan";
      string subKategori;

      switch (pilSubKategori) {
      case 1:
        subKategori = "Alat Makeup";
        break;
      case 2:
        subKategori = "Skincare";
        break;
      case 3:
        subKategori = "Lainnya";
        break;
      default:
        cout << "Pilihan subkategori tidak valid." << endl;
        return;
      }

      simpanKontenKeFile(kategori, subKategori);
    } else {
      cout << "Pilihan subkategori tidak valid." << endl;
    }
  }

  void pilihSepatuwanita() {
    system("clear");
    cout << "Pilih subkategori Homedekor:" << endl;
    cout << "1. Meubel" << endl;
    cout << "2. Kitchen Set" << endl;
    cout << "3. Bathroom" << endl;
    cout << "4. Bedroom" << endl;
    cout << "5. Living Room" << endl;
    cout << "6. Teras" << endl;
    cout << "7. Patung Dan Lukisan" << endl;
    cout << "8. Lampu" << endl;
    cout << "9. Lainnya" << endl;

    int pilSubKategori;
    cout << "Masukkan pilihan subkategori (1/2/3/4/5/6/7/8/9/): ";
    cin >> pilSubKategori;

    if (pilSubKategori >= 1 && pilSubKategori <= 9) {
      string kategori = "Home Dekor";
      string subKategori;

      switch (pilSubKategori) {
      case 1:
        subKategori = "Meubel";
        break;
      case 2:
        subKategori = "Kitchen Set";
        break;
      case 3:
        subKategori = "Bathroom";
        break;
      case 4:
        subKategori = "Bedroom";
        break;
      case 5:
        subKategori = "Living Room";
        break;
      case 6:
        subKategori = "Teras";
        break;
      case 7:
        subKategori = "Patung Dan Lukisan";
        break;
      case 8:
        subKategori = "Lampu";
        break;
      case 9:
        subKategori = "Lainnya";
        break;
      default:
        cout << "Pilihan subkategori tidak valid." << endl;
        return;
      }

      simpanKontenKeFile(kategori, subKategori);
    } else {
      cout << "Pilihan subkategori tidak valid." << endl;
    }
  }

  void pilihSkincare() {
    system("clear");
    cout << "Pilih subkategori Kesehatan:" << endl;
    cout << "1. Obat-obatan " << endl;
    cout << "2. Alat kesehatan" << endl;
    cout << "3. obat-obatan herbal" << endl;
    cout << "4. Alat terapi" << endl;
    cout << "5. Lainnya" << endl;

    int pilSubKategori;
    cout << "Masukkan pilihan subkategori (1/2/3/4/5): ";
    cin >> pilSubKategori;

    if (pilSubKategori >= 1 && pilSubKategori <= 5) {
      string kategori = "Kesehatan";
      string subKategori;

      switch (pilSubKategori) {
      case 1:
        subKategori = "Obat-obatan";
        break;
      case 2:
        subKategori = "Alat Kesehatan";
        break;
      case 3:
        subKategori = "Obat-obatan herbal";
        break;
      case 4:
        subKategori = "Alat terapi";
        break;
      case 5:
        subKategori = "Lainnya";
      default:
        cout << "Pilihan subkategori tidak valid." << endl;
        return;
      }

      simpanKontenKeFile(kategori, subKategori);
    } else {
      cout << "Pilihan subkategori tidak valid." << endl;
    }
  }

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
  void simpanKontenKeFile(const string &kategori, const string &subKategori) {
    ofstream file("konten.txt", ios::app); // Membuka file dalam mode append
    if (file.is_open()) {
      file << "Kategori: " << kategori << ", Subkategori: " << subKategori
           << endl;
      file.close();
      cout << "Konten berhasil disimpan!" << endl;
      homepage();
    } else {
      cout << "Gagal membuka file konten." << endl;
    }
  }
  ///////////////////////PEMBELI////PEMBELI////PEMBELI/////PEMBLI///PEMBELI//////////////////////////////////////////////////////////////
  void homepage() { cout << "INI ADALAH HOME PAGE" << endl; }
private:
  struct Akun {
    string nama;
    string password;
    string nik;
    string notelp;
    string alamat;
  } pengguna;
  string storedNama;
  string storedPassword;
  string storedNik;
  string storedNotelp;
  string storedAlamat;
};
int main() {
  AkunManager manager;
  char pil;
  bool loginSukses = false;
  do {
    manager.tampilkanMenuUtama();
    cin >> pil;
    if (pil == '+') {
      manager.daftarAkun();
    } 
    else if (pil == '-') {
      loginSukses = manager.login();
          if (loginSukses) {
            system("clear");
            cout << "YEAYYY!!! Login berhasil!" << endl << endl;
            int menu;
            cout << "1. "
            manager.pilihKategori();
          } 
          else {
            cout << "Login gagal. Cek kembali nama dan password Anda." << endl;
          }
    } 
    else {
      cout << "Pilihan tidak valid." << endl;
    }
    cout << "Apakah Anda ingin kembali ke halaman awal? (y/n): ";
    cin >> pil;
  } while (pil == 'y' || pil == 'Y');
  return 0;
}
