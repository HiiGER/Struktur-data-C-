#ifndef DINAMIS_H
#define DINAMIS_H
#include <iostream>  
#include "ARTTEXT.h"
#include "admin.h"
#include <fstream>
#include <stdexcept>
#include <string>
#include <vector>
#include <iomanip>


#define MAX_ITEMS 9999

using namespace std;

Keranjang kranjang;
CHEKOUTT cek;
tampilan hias;

template <class T, int N> class Array1Dstatis {
public:
  Array1Dstatis();

  T &operator[](int index);
  const T &operator[](int index) const;

private:
  T data[N];
};

template <class T, int N> Array1Dstatis<T, N>::Array1Dstatis() {}

template <class T, int N> T &Array1Dstatis<T, N>::operator[](int index) {
  if (index >= 0 && index < N) {
    return data[index];
  } else {
    throw out_of_range("Index out of range");
  }
}

template <class T, int N>
const T &Array1Dstatis<T, N>::operator[](int index) const {
  if (index >= 0 && index < N) {
    return data[index];
  } else {
    throw out_of_range("Index out of range");
  }
}

template <class T>

class Array1Ddinamis {
public:
  Array1Ddinamis(int sz);

  ~Array1Ddinamis();

  Array1Ddinamis<T> &ReSize(int sz);

  T &operator[](int index);
  const T &operator[](int index) const;

  int Size() const;

private:
  T *elements_;
  int size_;
};

template <class T> Array1Ddinamis<T>::Array1Ddinamis(int sz) : size_(sz) {
  elements_ = new T[size_];
}

template <class T> Array1Ddinamis<T>::~Array1Ddinamis() { delete[] elements_; }

template <class T> Array1Ddinamis<T> &Array1Ddinamis<T>::ReSize(int sz) {
  delete[] elements_;
  size_ = sz;
  elements_ = new T[size_];
  return *this;
}

template <class T> T &Array1Ddinamis<T>::operator[](int index) {
  if (index < 0 || index >= size_) {
    throw out_of_range("Index out of range");
  }
  return elements_[index];
}

template <class T> const T &Array1Ddinamis<T>::operator[](int index) const {
  if (index < 0 || index >= size_) {
    throw out_of_range("Index out of range");
  }
  return elements_[index];
}

struct Item {
  string nama;
  string kategori;
  string lokasi;
  string warna;
  int status;
  double avarage;
  Array1Dstatis<int, 10> harga;
  Array1Dstatis<int, 10> stok;
};

class program {


public:
  Item items[MAX_ITEMS]; 
  vector<Item> item;

  void tampilkan() {
    system("clear");
    for (int i = 0; i < MAX_ITEMS; i++) {
      if (!items[i].nama.empty()) {
        cout << "=============================================================="
                "============"
             << endl;
        cout << "Nama Barang :            " << items[i].nama << endl;
        cout << "kategori :               " << items[i].kategori << endl;
        cout << "=============================================================="
                "============"
             << endl
             << endl;

        cout << "Harga S (SMALL): " << items[i].harga[0]
             << "Stok : " << items[i].stok[0] << endl;
        cout << "--------------------------------------------------------------"
                "------------"
             << endl;

        cout << "Harga M (MEDIUM): " << items[i].harga[1]
             << "Stok : " << items[i].stok[1] << endl;
        cout << "--------------------------------------------------------------"
                "------------"
             << endl;

        cout << "Harga L (LARGE): " << items[i].harga[2]
             << "Stok : " << items[i].stok[2] << endl;
        cout << "--------------------------------------------------------------"
                "------------"
             << endl;

        cout << "Harga XL (EXTRA LARGE): " << items[i].harga[3]
             << "Stok : " << items[i].stok[3] << endl;
        cout << "--------------------------------------------------------------"
                "------------"
             << endl;

        cout << "Harga XXL (DOUBEL EXTRA LARGE): " << items[i].harga[4]
             << "Stok : " << items[i].stok[4] << endl;

        cout << "=============================================================="
                "============="
             << endl<<endl;
        // cout<< items[i].avarage<<endl;
        cout<<items[i].status<<endl;
      }
    }
  }
////////////////////////////////////////////////////////////////////
  void searchKategori() {
    system("clear");
    tampilkanMenuKategori();
    string pencarian;
    int choice;
    cout << "Pilih nomor kategori (1-21)  : ";
    cin >> choice;

    if (choice == 1) {
      pencarian = "Baju Pria";

    } else if (choice == 2) {
      pencarian = "Baju Wanita";

    } else if (choice == 3) {
      pencarian = "Aksesoris";

    } else if (choice == 4) {
      pencarian = "Sepatu pria";

    } else if (choice == 5) {
      pencarian = "Sepatu wanita";

    } else if (choice == 6) {
      pencarian = "Skincare";

    } else if (choice == 7) {
      pencarian = "Baju Anak Pria";

    } else if (choice == 8) {
      pencarian = "Baju Anak Wanita";

    } else if (choice == 9) {
      pencarian = "Outerwear";

    } else if (choice == 10) {
      pencarian = "Pakaian Muslim Pria";

    } else if (choice == 11) {
      pencarian = "Hijab";

    } else if (choice == 12) {
      pencarian = "Atasan Muslim Wanita";

    } else if (choice == 13) {
      pencarian = "Bawahan Muslim Wanita";

    } else if (choice == 14) {
      pencarian = "Jam Tangan Pria";

    } else if (choice == 15) {
      pencarian = "Jam Tangan Wanita";

    } else if (choice == 16) {
      pencarian = "Jam Tangan Couple";

    } else if (choice == 17) {
      pencarian = "Tas Pria";

    } else if (choice == 18) {
      pencarian = "Tas Wanita";

    } else if (choice == 19) {
      pencarian = "Pakaian Olahraga Pria";

    } else if (choice == 20) {
      pencarian = "Pakaian Olahraga Wanita";

    } else if (choice == 21) {
      pencarian = "Pakaian Dalam";

    } else {
      cout << "Nomor kategori tidak valid" << endl;
      // Lakukan apa yang diperlukan jika pilihan tidak sesuai
    }
    for (int i = 0; i < MAX_ITEMS; i++) {
      if (pencarian == items[i].kategori) {
        if (!items[i].nama.empty()) {
          cout << "============================================================"
                  "=============="
               << endl;
          cout << "Nama Barang :            " << items[i].nama << endl;
          cout << "kategori :               " << items[i].kategori << endl;
          cout << "============================================================"
                  "=============="
               << endl
               << endl;

          cout << "Harga S (SMALL): " << items[i].harga[0]
               << "Stok : " << items[i].stok[0] << endl;
          cout << "------------------------------------------------------------"
                  "--------------"
               << endl;

          cout << "Harga M (MEDIUM): " << items[i].harga[1]
               << "Stok : " << items[i].stok[1] << endl;
          cout << "------------------------------------------------------------"
                  "--------------"
               << endl;

          cout << "Harga L (LARGE): " << items[i].harga[2]
               << "Stok : " << items[i].stok[2] << endl;
          cout << "------------------------------------------------------------"
                  "--------------"
               << endl;

          cout << "Harga XL (EXTRA LARGE): " << items[i].harga[3]
               << "Stok : " << items[i].stok[3] << endl;
          cout << "------------------------------------------------------------"
                  "--------------"
               << endl;

          cout << "Harga XXL (DOUBEL EXTRA LARGE): " << items[i].harga[4]
               << "Stok : " << items[i].stok[4] << endl;

          cout << "============================================================"
                  "==============="
               << endl;

                  ofstream file("Kategorisearching.txt",ios::app); 
                  if (file.is_open()) {
                    file << "=============================================================="
                            "============"
                         << endl;
                    file << "Nama Barang :            " << items[i].nama << endl;
                    file << "kategori :               " << items[i].kategori << endl;
                    file << "=============================================================="
                            "============"
                         << endl
                         << endl;

                    file << "Harga S (SMALL): " << items[i].harga[0]
                         << "Stok : " << items[i].stok[0] << endl;
                    file << "--------------------------------------------------------------"
                            "------------"
                         << endl;

                    file << "Harga M (MEDIUM): " << items[i].harga[1]
                         << "Stok : " << items[i].stok[1] << endl;
                    file << "--------------------------------------------------------------"
                            "------------"
                         << endl;

                    file << "Harga L (LARGE): " << items[i].harga[2]
                         << "Stok : " << items[i].stok[2] << endl;
                    file << "--------------------------------------------------------------"
                            "------------"
                         << endl;

                    file << "Harga XL (EXTRA LARGE): " << items[i].harga[3]
                         << "Stok : " << items[i].stok[3] << endl;
                    file << "--------------------------------------------------------------"
                            "------------"
                         << endl;

                    file << "Harga XXL (DOUBEL EXTRA LARGE): " << items[i].harga[4]
                         << "Stok : " << items[i].stok[4] << endl;

                    file << "=============================================================="
                            "============="
                         << endl<<endl;
                    // file<< items[i].avarage<<endl;
                    //file<<items[i].status<<endl;
                      file.close();
                      file << "Konten berhasil disimpan!" << endl;
                    } else {
                      file << "Gagal membuka file konten." << endl;
                    }
        }
      }
    }
  }
////////////////////////////////////////////////////////////////////
  void searchNamaBarang(const std::string &keyword) {
    bool found = false;
    system("clear");
    std::cout << "======================================================="
              << std::endl;
    std::cout << "Hasil pencarian untuk  " << keyword << "  :" << std::endl;
    for (const auto &item : items) {
      if (item.nama.find(keyword) != std::string::npos) {
        found = true;
        std::cout << "======================================================="<< std::endl;
        
        std::cout << item.nama << " - Kategori barang : " << item.kategori<< std::endl;

        
          ofstream file("PencarianNama.txt",ios::app); 
          if (file.is_open()) {
                file << "hasil pencarian dengan nama : "<<keyword<<endl;
                file << "Nama     : "<<item.nama<<endl;
                file << "kategori : "<<item.kategori<<endl;

            file.close();
            cout << "Konten berhasil disimpan!" << endl;

          } else {
            cout << "Gagal membuka file konten." << endl;
          }

        
        std::cout << "======================================================="<< std::endl<< std::endl;
        
      }
    }
    if (!found) {
      std::cout << "======================================================="<< std::endl;
      std::cout << "Barang dengan kata kunci " << keyword << " tidak ditemukan."<< std::endl;
      std::cout << "======================================================="<< std::endl<< std::endl<< std::endl<< std::endl;
    }
  }
////////////////////////////////////////////////////////////////////
  void sortirharga() {
      string nama;
      string kategori;
      string lokasi;
      int status;
      double average;
      int harga[5];
      int stok[5];

      cout << " 1.termahal" << endl;
      cout << " 2.termurah" << endl;
      char pilihan;
      cout << "masukan pilihan : ";
      cin >> pilihan;

      if (pilihan == '1') {
          for (int i = 0; i < MAX_ITEMS - 1; i++) {
              for (int j = 0; j < MAX_ITEMS - i - 1; j++) {
                  if (items[j].avarage < items[j + 1].avarage) {
                      // Melakukan pertukaran data
                      swap(items[j], items[j + 1]);
                  }
              } 
          }
          
      } else if (pilihan == '2') {
          for (int i = 0; i < MAX_ITEMS - 1; i++) {
              for (int j = 0; j < MAX_ITEMS - i - 1; j++) {
                  if (items[j].avarage > items[j + 1].avarage) {
                      // Melakukan pertukaran data
                      swap(items[j], items[j + 1]);
                  }
              }
          }
      }
      tampilkan();
      tulisHarga();
  }

  void tulisHarga(){  
    for (int i = 0; i < MAX_ITEMS; i++) {
      if (!items[i].nama.empty()) {
        ofstream file("Harga.txt",ios::app); 
        if (file.is_open()) {
          file << "=============================================================="
                  "============"
               << endl;
          file << "Nama Barang :            " << items[i].nama << endl;
          file << "kategori :               " << items[i].kategori << endl;
          file << "=============================================================="
                  "============"
               << endl
               << endl;

          file << "Harga S (SMALL): " << items[i].harga[0]
               << "Stok : " << items[i].stok[0] << endl;
          file << "--------------------------------------------------------------"
                  "------------"
               << endl;

          file << "Harga M (MEDIUM): " << items[i].harga[1]
               << "Stok : " << items[i].stok[1] << endl;
          file << "--------------------------------------------------------------"
                  "------------"
               << endl;

          file << "Harga L (LARGE): " << items[i].harga[2]
               << "Stok : " << items[i].stok[2] << endl;
          file << "--------------------------------------------------------------"
                  "------------"
               << endl;

          file << "Harga XL (EXTRA LARGE): " << items[i].harga[3]
               << "Stok : " << items[i].stok[3] << endl;
          file << "--------------------------------------------------------------"
                  "------------"
               << endl;

          file << "Harga XXL (DOUBEL EXTRA LARGE): " << items[i].harga[4]
               << "Stok : " << items[i].stok[4] << endl;

          file << "=============================================================="
                  "============="
               << endl<<endl;
          // file<< items[i].avarage<<endl;
          //file<<items[i].status<<endl;
            file.close();
            file << "Konten berhasil disimpan!" << endl;
          } else {
            file << "Gagal membuka file konten." << endl;
          }
      }
    }
  }
////////////////////////////////////////////////////////////////////
  void daftar_kota() {
      std::vector<std::string>daftarKota = {
          "Jawa", "Lampung", "Batam", "Madiun", "Surabaya",
          "Bandung", "Jatinangor", "Madura", "Jakarta", "Tangerang",
          "Depok", "Cianjur", "Cirebon", "Cimahi", "Aceh",
          "Padang", "Bogor", "Purworejo", "Palangkaraya", "Banjarmasin",
          "Pontianak", "Solo", "Semarang", "Yogyakarta", "Cilacap",
          "Temanggung", "Sidoarjo", "Jambi", "Sleman", "Manado",
          "Bantul", "Gunung Kidul", "Cilegon", "Majalengka", "Sumedang",
          "Banjar", "Sukabumi", "Cibinong", "Tasikmalaya", "Boyolali",
          "Purwodadi", "Jepara", "Klaten", "Kudus", "Pati",
          "Kebumen", "Kendal", "Kendari", "Karanganyar", "Pemalang",
          "Purbalingga", "Sragen", "Wonogiri", "Salatiga", "Tegal",
          "Wates", "Malang"
      };

      // Header tabel
      std::cout << std::setw(5) << "No." << std::setw(20) << "Nama Kota" << std::endl;
      std::cout << "-----------------------------------" << std::endl;

      // Isi tabel
      for (size_t i = 0; i < daftarKota.size(); ++i) {
          std::cout << std::setw(5) << i + 1 << std::setw(20) << daftarKota[i] << std::endl;
      }

  }

  void lokasi() {
      int pilihan;
      std::string kota;

      std::cout << "Masukkan pilihan (1-57): ";
      std::cin >> pilihan;

      if (pilihan == 1) {
          kota = "Jawa";
      } else if (pilihan == 2) {
          kota = "Lampung";
      } else if (pilihan == 3) {
          kota = "Batam";
      } else if (pilihan == 4) {
          kota = "Madiun";
      } else if (pilihan == 5) {
          kota = "Surabaya";
      } else if (pilihan == 6) {
          kota = "Bandung";
      } else if (pilihan == 7) {
          kota = "Jatinangor";
      } else if (pilihan == 8) {
          kota = "Madura";
      } else if (pilihan == 9) {
          kota = "Jakarta";
      } else if (pilihan == 10) {
          kota = "Tangerang";
      } else if (pilihan == 11) {
          kota = "Depok";
      } else if (pilihan == 12) {
          kota = "Cianjur";
      } else if (pilihan == 13) {
          kota = "Cirebon";
      } else if (pilihan == 14) {
          kota = "Cimahi";
      } else if (pilihan == 15) {
          kota = "Aceh";
      } else if (pilihan == 16) {
          kota = "Padang";
      } else if (pilihan == 17) {
          kota = "Bogor";
      } else if (pilihan == 18) {
          kota = "Purworejo";
      } else if (pilihan == 19) {
          kota = "Palangkaraya";
      } else if (pilihan == 20) {
          kota = "Banjarmasin";
      } else if (pilihan == 21) {
          kota = "Pontianak";
      } else if (pilihan == 22) {
          kota = "Solo";
      } else if (pilihan == 23) {
          kota = "Semarang";
      } else if (pilihan == 24) {
          kota = "Yogyakarta";
      } else if (pilihan == 25) {
          kota = "Cilacap";
      } else if (pilihan == 26) {
          kota = "Temanggung";
      } else if (pilihan == 27) {
          kota = "Sidoarjo";
      } else if (pilihan == 28) {
          kota = "Jambi";
      } else if (pilihan == 29) {
          kota = "Sleman";
      } else if (pilihan == 30) {
          kota = "Manado";
      } else if (pilihan == 31) {
          kota = "Bantul";
      } else if (pilihan == 32) {
          kota = "Gunung Kidul";
      } else if (pilihan == 33) {
          kota = "Cilegon";
      } else if (pilihan == 34) {
          kota = "Majalengka";
      } else if (pilihan == 35) {
          kota = "Sumedang";
      } else if (pilihan == 36) {
          kota = "Banjar";
      } else if (pilihan == 37) {
          kota = "Sukabumi";
      } else if (pilihan == 38) {
          kota = "Cibinong";
      } else if (pilihan == 39) {
          kota = "Tasikmalaya";
      } else if (pilihan == 40) {
          kota = "Boyolali";
      } else if (pilihan == 41) {
          kota = "Purwodadi";
      } else if (pilihan == 42) {
          kota = "Jepara";
      } else if (pilihan == 43) {
          kota = "Klaten";
      } else if (pilihan == 44) {
          kota = "Kudus";
      } else if (pilihan == 45) {
          kota = "Pati";
      } else if (pilihan == 46) {
          kota = "Kebumen";
      } else if (pilihan == 47) {
          kota = "Kendal";
      } else if (pilihan == 48) {
          kota = "Kendari";
      } else if (pilihan == 49) {
          kota = "Karanganyar";
      } else if (pilihan == 50) {
          kota = "Pemalang";
      } else if (pilihan == 51) {
          kota = "Purbalingga";
      } else if (pilihan == 52) {
          kota = "Sragen";
      } else if (pilihan == 53) {
          kota = "Wonogiri";
      } else if (pilihan == 54) {
          kota = "Salatiga";
      } else if (pilihan == 55) {
          kota = "Tegal";
      } else if (pilihan == 56) {
          kota = "Wates";
      } else if (pilihan == 57) {
          kota = "Malang";
      } else {
          std::cout << "Pilihan tidak valid." << std::endl;
          return ;
      }

      std::cout << "Kota yang dipilih: " << kota << std::endl;

      searchLokasi(kota);
  }

  void searchLokasi(const std::string &keyword) {
    bool found = false;
    system("clear");
    std::cout << "======================================================="
              << std::endl;
    std::cout << "Hasil pencarian untuk  " << keyword << "  :" << std::endl;
    for (const auto &item : items) {
      if (item.lokasi.find(keyword) != std::string::npos) {
        found = true;
        std::cout << "======================================================="
                  << std::endl;
        std::cout << item.nama << " - Kategori barang : " << item.kategori
                  << std::endl;
        // Tampilkan atribut lainnya jika diperlukan
        std::cout << "======================================================="
                  << std::endl
                  << std::endl
                  << std::endl
                  << std::endl;
                              ofstream file("Pencarianlokasi.txt",ios::app); 
                              if (file.is_open()) {
                                    file << "Nama            : "<<item.nama<<endl;
                                    file << "kategori        : "<<item.kategori<<endl;
                                    file << "lokasi penjual  : "<<items->lokasi<<endl;
                      
                                file.close();
                                cout << "Konten berhasil disimpan!" << endl;
                      
                              } else {
                                cout << "Gagal membuka file konten." << endl;
                              }
        
      }
    }
    if (!found) {
      std::cout << "======================================================="
                << std::endl;
      std::cout << "Barang dengan kata kunci " << keyword << " tidak ditemukan."
                << std::endl;
      std::cout << "======================================================="
                << std::endl
                << std::endl
                << std::endl
                << std::endl;
    }
  }
////////////////////////////////////////////////////////////////////
  void searchWarna(const std::string &keyword) {
    bool found = false;
    system("clear");
    std::cout << "======================================================="
              << std::endl;
    std::cout << "Hasil pencarian untuk  warna " << keyword << "  :" << std::endl;
    for (const auto &item : items) {
      if (item.warna.find(keyword) != std::string::npos) {
        found = true;
        std::cout << "======================================================="
                  << std::endl;
        std::cout << item.nama << " - Kategori barang : " << item.kategori
                  << std::endl;
        // Tampilkan atribut lainnya jika diperlukan
        std::cout << "======================================================="
                  << std::endl
                  << std::endl
                  << std::endl
                  << std::endl;
                              ofstream file("Pencarianwarna.txt",ios::app); 
                              if (file.is_open()) {
                                    file << "Nama            : "<<item.nama<<endl;
                                    file << "kategori        : "<<item.kategori<<endl;

                                file.close();
                                cout << "Konten berhasil disimpan!" << endl;

                              } else {
                                cout << "Gagal membuka file konten." << endl;
                              }
      }
    }
    if (!found) {
      std::cout << "======================================================="
                << std::endl;
      std::cout << "Barang dengan warna : " << keyword << " tidak ditemukan."
                << std::endl;
      std::cout << "======================================================="
                << std::endl
                << std::endl
                << std::endl
                << std::endl;
    }
  }

  void tampilkanMenuWarna(){
    cout << "1.Merah "<<endl;
    cout << "2.Biru "<<endl;
    cout << "3.Putih "<<endl;
    cout << "4.Hitam "<<endl;
    int warna;
    string color;
    cout << "Masukkan pilihan : ";cin>>warna;
    if(warna == 1){
      color = "Merah";
    }
    if(warna == 2){
      color = "Biru";
    }
    if(warna == 3){
      color = "Putih";
    }
    if(warna == 4){
      color = "Hitam";
    }
    searchWarna(color);
  }
////////////////////////////////////////////////////////////////////
  void searchStatus(){
    system("clear");
    for (int i = 0; i < MAX_ITEMS; i++) {
      if(items[i].status == 1||items[i].status > 1 ){
          if (!items[i].nama.empty()) {
            cout << "=========================================================================="<< endl;
            cout << "Nama Barang :            " << items[i].nama << endl;
            cout << "kategori :               " << items[i].kategori << endl;
            cout << "dibeli sebanyak          " << items[i].status<<endl;
            cout << "=========================================================================="<< endl<< endl;

            ofstream file("Pencarianstatus.txt",ios::app); 
            if (file.is_open()) {
                  file << "Nama            : "<<item[i].nama<<endl;
                  file << "kategori        : "<<item[i].kategori<<endl;
                  file << "dibeli sebanyak : "<<items[i].status<<endl;

              file.close();
              cout << "Konten berhasil disimpan!" << endl;

            } else {
              cout << "Gagal membuka file konten." << endl;
            }
          }
      }
      
    }
  }
////////////////////////////////////////////////////////////////////

  void tampilkanMenuKategori() {
    cout << "|================================================================="
            "===========|"
         << endl;
    cout << "|                            Pilih kategori Fashion:              "
            "           |"
         << endl;
    cout << "|================================================================="
            "===========|"
         << endl;
    cout << "|1. Baju Pria                                                     "
            "           |"
         << endl;
    cout << "|2. Baju Wanita                                                   "
            "           |"
         << endl;
    cout << "|3. Aksesoris                                                     "
            "           |"
         << endl;
    cout << "|4. Sepatu pria                                                   "
            "           |"
         << endl;
    cout << "|5. Sepatu wanita                                                 "
            "           |"
         << endl;
    cout << "|6. Skincare                                                      "
            "           |"
         << endl;
    cout << "|7. Baju Anak Pria                                                "
            "           |"
         << endl;
    cout << "|8. Baju Anak Wanita                                              "
            "           |"
         << endl;
    cout << "|9. Outerwear                                                     "
            "           |"
         << endl;
    cout << "|10. Pakaian Muslim Pria                                          "
            "           |"
         << endl;
    cout << "|11. Hijab                                                        "
            "           |"
         << endl;
    cout << "|12. Atasan Muslim Wanita                                         "
            "           |"
         << endl;
    cout << "|13. Bawahan Muslim Wanita                                        "
            "           |"
         << endl;
    cout << "|14. Jam Tangan Pria                                              "
            "           |"
         << endl;
    cout << "|15. Jam Tangan Wanita                                            "
            "           |"
         << endl;
    cout << "|16. Jam Tangan Couple                                            "
            "           |"
         << endl;
    cout << "|17. Tas Pria                                                     "
            "           |"
         << endl;
    cout << "|18. Tas Wanita                                                   "
            "           |"
         << endl;
    cout << "|19. Pakaian Olahraga Pria                                        "
            "           |"
         << endl;
    cout << "|20. Pakaian Olahraga Wanita                                      "
            "           |"
         << endl;
    cout << "|21. Pakaian Dalam                                                "
            "           |"
         << endl;
    cout << "|================================================================="
            "===========|"
         << endl;
  }

  void pilihKategori() {
    tampilkanMenuKategori();
    int pilKategori;
    cout << "Masukkan pilihan kategori barang yang ingin di jual : ";
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
    case 7:
      pilihBajuAnakPria();
      break;
    case 8:
      pilihBajuAnakWanita();
      break;
    case 9:
      pilihOuterwear();
      break;
    case 10:
      pilihPakaianMuslimPria();
      break;
    case 11:
      pilihHijab();
      break;
    case 12:
      pilihAtasanMuslimWanita();
      break;
    case 13:
      pilihBawahanMuslimWanita();
      break;
    case 14:
      pilihJamTanganPria();
      break;
    case 15:
      pilihJamTanganWanita();
      break;
    case 16:
      pilihJamTanganCouple();
      break;
    case 17:
      pilihTasPria();
      break;
    case 18:
      pilihTasWanita();
      break;
    case 19:
      pilihPakaianOlahragaPriaa();
      break;
    case 20:
      pilihPakaianOlahragaWanita();
      break;
    case 21:
      pilihPakaianDalam();
      break;
    }
  }
  //=======================================================================================================
  void pilihBajupria() {
    system("clear");

    string kategori = "baju pria";

    tambah(kategori);

    ofstream file("kat_baju pria.txt",
                  ios::app); // Membuka file dalam mode append
    if (file.is_open()) {
      for (int i = 0; i < MAX_ITEMS; i++) {
        if (!items[i].nama.empty()) {
          file << "============================================================"
                  "=============="
               << endl;
          file << "Nama Barang :            " << items[i].nama << endl;
          file << "kategori :               " << items[i].kategori << endl;
          file << "============================================================"
                  "=============="
               << endl
               << endl;

          file << "Harga S (SMALL): " << items[i].harga[0]
               << "Stok : " << items[i].stok[0] << endl;
          file << "------------------------------------------------------------"
                  "--------------"
               << endl;

          file << "Harga M (MEDIUM): " << items[i].harga[1]
               << "Stok : " << items[i].stok[1] << endl;
          file << "------------------------------------------------------------"
                  "--------------"
               << endl;

          file << "Harga L (LARGE): " << items[i].harga[2]
               << "Stok : " << items[i].stok[2] << endl;
          file << "------------------------------------------------------------"
                  "--------------"
               << endl;

          file << "Harga XL (EXTRA LARGE): " << items[i].harga[3]
               << "Stok : " << items[i].stok[3] << endl;
          file << "------------------------------------------------------------"
                  "--------------"
               << endl;

          file << "Harga XXL (DOUBEL EXTRA LARGE): " << items[i].harga[4]
               << "Stok : " << items[i].stok[4] << endl;

          file << "============================================================"
                  "==============="
               << endl;
        }
      }
      file.close();
      cout << "Konten berhasil disimpan!" << endl;

    } else {
      cout << "Gagal membuka file konten." << endl;
    }
  }

  void pilihBajuwanita() {
    system("clear");

    string kategori = "Baju wanita";

    tambah(kategori);

    ofstream file("kat_Baju wanita.txt",
                  ios::app); // Membuka file dalam mode append
    if (file.is_open()) {
      for (int i = 0; i < MAX_ITEMS; i++) {
        if (!items[i].nama.empty()) {
          file << "============================================================"
                  "=============="
               << endl;
          file << "Nama Barang :            " << items[i].nama << endl;
          file << "kategori :               " << items[i].kategori << endl;
          file << "============================================================"
                  "=============="
               << endl
               << endl;

          file << "Harga S (SMALL): " << items[i].harga[0]
               << "Stok : " << items[i].stok[0] << endl;
          file << "------------------------------------------------------------"
                  "--------------"
               << endl;

          file << "Harga M (MEDIUM): " << items[i].harga[1]
               << "Stok : " << items[i].stok[1] << endl;
          file << "------------------------------------------------------------"
                  "--------------"
               << endl;

          file << "Harga L (LARGE): " << items[i].harga[2]
               << "Stok : " << items[i].stok[2] << endl;
          file << "------------------------------------------------------------"
                  "--------------"
               << endl;

          file << "Harga XL (EXTRA LARGE): " << items[i].harga[3]
               << "Stok : " << items[i].stok[3] << endl;
          file << "------------------------------------------------------------"
                  "--------------"
               << endl;

          file << "Harga XXL (DOUBEL EXTRA LARGE): " << items[i].harga[4]
               << "Stok : " << items[i].stok[4] << endl;

          file << "============================================================"
                  "==============="
               << endl;
        }
      }
      file.close();
      cout << "Konten berhasil disimpan!" << endl;

    } else {
      cout << "Gagal membuka file konten." << endl;
    }
  }

  void pilihAksesoris() {
    system("clear");

    string kategori = "Aksesoris";

    tambah(kategori);

    ofstream file("kat_Aksesoris.txt",
                  ios::app); // Membuka file dalam mode append
    if (file.is_open()) {
      for (int i = 0; i < MAX_ITEMS; i++) {
        if (!items[i].nama.empty()) {
          file << "============================================================"
                  "=============="
               << endl;
          file << "Nama Barang :            " << items[i].nama << endl;
          file << "kategori :               " << items[i].kategori << endl;
          file << "============================================================"
                  "=============="
               << endl
               << endl;

          file << "Harga S (SMALL): " << items[i].harga[0]
               << "Stok : " << items[i].stok[0] << endl;
          file << "------------------------------------------------------------"
                  "--------------"
               << endl;

          file << "Harga M (MEDIUM): " << items[i].harga[1]
               << "Stok : " << items[i].stok[1] << endl;
          file << "------------------------------------------------------------"
                  "--------------"
               << endl;

          file << "Harga L (LARGE): " << items[i].harga[2]
               << "Stok : " << items[i].stok[2] << endl;
          file << "------------------------------------------------------------"
                  "--------------"
               << endl;

          file << "Harga XL (EXTRA LARGE): " << items[i].harga[3]
               << "Stok : " << items[i].stok[3] << endl;
          file << "------------------------------------------------------------"
                  "--------------"
               << endl;

          file << "Harga XXL (DOUBEL EXTRA LARGE): " << items[i].harga[4]
               << "Stok : " << items[i].stok[4] << endl;

          file << "============================================================"
                  "==============="
               << endl;
        }
      }
      file.close();
      cout << "Konten berhasil disimpan!" << endl;

    } else {
      cout << "Gagal membuka file konten." << endl;
    }
  }

  void pilihSepatupria() {
    system("clear");

    string kategori = "Sepatu pria";

    tambah(kategori);

    ofstream file("kat_Sepatu pria",
                  ios::app); // Membuka file dalam mode append
    if (file.is_open()) {
      for (int i = 0; i < MAX_ITEMS; i++) {
        if (!items[i].nama.empty()) {
          file << "============================================================"
                  "=============="
               << endl;
          file << "Nama Barang :            " << items[i].nama << endl;
          file << "kategori :               " << items[i].kategori << endl;
          file << "============================================================"
                  "=============="
               << endl
               << endl;

          file << "Harga S (SMALL): " << items[i].harga[0]
               << "Stok : " << items[i].stok[0] << endl;
          file << "------------------------------------------------------------"
                  "--------------"
               << endl;

          file << "Harga M (MEDIUM): " << items[i].harga[1]
               << "Stok : " << items[i].stok[1] << endl;
          file << "------------------------------------------------------------"
                  "--------------"
               << endl;

          file << "Harga L (LARGE): " << items[i].harga[2]
               << "Stok : " << items[i].stok[2] << endl;
          file << "------------------------------------------------------------"
                  "--------------"
               << endl;

          file << "Harga XL (EXTRA LARGE): " << items[i].harga[3]
               << "Stok : " << items[i].stok[3] << endl;
          file << "------------------------------------------------------------"
                  "--------------"
               << endl;

          file << "Harga XXL (DOUBEL EXTRA LARGE): " << items[i].harga[4]
               << "Stok : " << items[i].stok[4] << endl;

          file << "============================================================"
                  "==============="
               << endl;
        }
      }
      file.close();
      cout << "Konten berhasil disimpan!" << endl;

    } else {
      cout << "Gagal membuka file konten." << endl;
    }
  }

  void pilihSepatuwanita() {
    system("clear");

    string kategori = "Sepatu Wanita";

    tambah(kategori);

    ofstream file("kat_Sepatu Wanita.txt",
                  ios::app); // Membuka file dalam mode append
    if (file.is_open()) {
      for (int i = 0; i < MAX_ITEMS; i++) {
        if (!items[i].nama.empty()) {
          file << "============================================================"
                  "=============="
               << endl;
          file << "Nama Barang :            " << items[i].nama << endl;
          file << "kategori :               " << items[i].kategori << endl;
          file << "============================================================"
                  "=============="
               << endl
               << endl;

          file << "Harga S (SMALL): " << items[i].harga[0]
               << "Stok : " << items[i].stok[0] << endl;
          file << "------------------------------------------------------------"
                  "--------------"
               << endl;

          file << "Harga M (MEDIUM): " << items[i].harga[1]
               << "Stok : " << items[i].stok[1] << endl;
          file << "------------------------------------------------------------"
                  "--------------"
               << endl;

          file << "Harga L (LARGE): " << items[i].harga[2]
               << "Stok : " << items[i].stok[2] << endl;
          file << "------------------------------------------------------------"
                  "--------------"
               << endl;

          file << "Harga XL (EXTRA LARGE): " << items[i].harga[3]
               << "Stok : " << items[i].stok[3] << endl;
          file << "------------------------------------------------------------"
                  "--------------"
               << endl;

          file << "Harga XXL (DOUBEL EXTRA LARGE): " << items[i].harga[4]
               << "Stok : " << items[i].stok[4] << endl;

          file << "============================================================"
                  "==============="
               << endl;
        }
      }
      file.close();
      cout << "Konten berhasil disimpan!" << endl;

    } else {
      cout << "Gagal membuka file konten." << endl;
    }
  }

  void pilihSkincare() {
    system("clear");

    string kategori = "Skin care";

    tambah(kategori);

    ofstream file("kat_Skin care.txt",
                  ios::app); // Membuka file dalam mode append
    if (file.is_open()) {
      for (int i = 0; i < MAX_ITEMS; i++) {
        if (!items[i].nama.empty()) {
          file << "============================================================"
                  "=============="
               << endl;
          file << "Nama Barang :            " << items[i].nama << endl;
          file << "kategori :               " << items[i].kategori << endl;
          file << "============================================================"
                  "=============="
               << endl
               << endl;

          file << "Harga S (SMALL): " << items[i].harga[0]
               << "Stok : " << items[i].stok[0] << endl;
          file << "------------------------------------------------------------"
                  "--------------"
               << endl;

          file << "Harga M (MEDIUM): " << items[i].harga[1]
               << "Stok : " << items[i].stok[1] << endl;
          file << "------------------------------------------------------------"
                  "--------------"
               << endl;

          file << "Harga L (LARGE): " << items[i].harga[2]
               << "Stok : " << items[i].stok[2] << endl;
          file << "------------------------------------------------------------"
                  "--------------"
               << endl;

          file << "Harga XL (EXTRA LARGE): " << items[i].harga[3]
               << "Stok : " << items[i].stok[3] << endl;
          file << "------------------------------------------------------------"
                  "--------------"
               << endl;

          file << "Harga XXL (DOUBEL EXTRA LARGE): " << items[i].harga[4]
               << "Stok : " << items[i].stok[4] << endl;

          file << "============================================================"
                  "==============="
               << endl;
        }
      }
      file.close();
      cout << "Konten berhasil disimpan!" << endl;

    } else {
      cout << "Gagal membuka file konten." << endl;
    }
  }

  void pilihBajuAnakPria() {
    system("clear");

    string kategori = "Baju Anak Pria";

    tambah(kategori);

    ofstream file("kat_Baju Anak Pria.txt",
                  ios::app); // Membuka file dalam mode append
    if (file.is_open()) {
      for (int i = 0; i < MAX_ITEMS; i++) {
        if (!items[i].nama.empty()) {
          file << "============================================================"
                  "=============="
               << endl;
          file << "Nama Barang :            " << items[i].nama << endl;
          file << "kategori :               " << items[i].kategori << endl;
          file << "============================================================"
                  "=============="
               << endl
               << endl;

          file << "Harga S (SMALL): " << items[i].harga[0]
               << "Stok : " << items[i].stok[0] << endl;
          file << "------------------------------------------------------------"
                  "--------------"
               << endl;

          file << "Harga M (MEDIUM): " << items[i].harga[1]
               << "Stok : " << items[i].stok[1] << endl;
          file << "------------------------------------------------------------"
                  "--------------"
               << endl;

          file << "Harga L (LARGE): " << items[i].harga[2]
               << "Stok : " << items[i].stok[2] << endl;
          file << "------------------------------------------------------------"
                  "--------------"
               << endl;

          file << "Harga XL (EXTRA LARGE): " << items[i].harga[3]
               << "Stok : " << items[i].stok[3] << endl;
          file << "------------------------------------------------------------"
                  "--------------"
               << endl;

          file << "Harga XXL (DOUBEL EXTRA LARGE): " << items[i].harga[4]
               << "Stok : " << items[i].stok[4] << endl;

          file << "============================================================"
                  "==============="
               << endl;
        }
      }
      file.close();
      cout << "Konten berhasil disimpan!" << endl;

    } else {
      cout << "Gagal membuka file konten." << endl;
    }
  }

  void pilihBajuAnakWanita() {
    system("clear");

    string kategori = "Baju Anak Wanita";

    tambah(kategori);

    ofstream file("kat_Baju Anak Wanita.txt",
                  ios::app); // Membuka file dalam mode append
    if (file.is_open()) {
      for (int i = 0; i < MAX_ITEMS; i++) {
        if (!items[i].nama.empty()) {
          file << "============================================================"
                  "=============="
               << endl;
          file << "Nama Barang :            " << items[i].nama << endl;
          file << "kategori :               " << items[i].kategori << endl;
          file << "============================================================"
                  "=============="
               << endl
               << endl;

          file << "Harga S (SMALL): " << items[i].harga[0]
               << "Stok : " << items[i].stok[0] << endl;
          file << "------------------------------------------------------------"
                  "--------------"
               << endl;

          file << "Harga M (MEDIUM): " << items[i].harga[1]
               << "Stok : " << items[i].stok[1] << endl;
          file << "------------------------------------------------------------"
                  "--------------"
               << endl;

          file << "Harga L (LARGE): " << items[i].harga[2]
               << "Stok : " << items[i].stok[2] << endl;
          file << "------------------------------------------------------------"
                  "--------------"
               << endl;

          file << "Harga XL (EXTRA LARGE): " << items[i].harga[3]
               << "Stok : " << items[i].stok[3] << endl;
          file << "------------------------------------------------------------"
                  "--------------"
               << endl;

          file << "Harga XXL (DOUBEL EXTRA LARGE): " << items[i].harga[4]
               << "Stok : " << items[i].stok[4] << endl;

          file << "============================================================"
                  "==============="
               << endl;
        }
      }
      file.close();
      cout << "Konten berhasil disimpan!" << endl;

    } else {
      cout << "Gagal membuka file konten." << endl;
    }
  }

  void pilihOuterwear() {
    system("clear");

    string kategori = "Outerwear";

    tambah(kategori);

    ofstream file("kat_Outerwear.txt",
                  ios::app); // Membuka file dalam mode append
    if (file.is_open()) {
      for (int i = 0; i < MAX_ITEMS; i++) {
        if (!items[i].nama.empty()) {
          file << "============================================================"
                  "=============="
               << endl;
          file << "Nama Barang :            " << items[i].nama << endl;
          file << "kategori :               " << items[i].kategori << endl;
          file << "============================================================"
                  "=============="
               << endl
               << endl;

          file << "Harga S (SMALL): " << items[i].harga[0]
               << "Stok : " << items[i].stok[0] << endl;
          file << "------------------------------------------------------------"
                  "--------------"
               << endl;

          file << "Harga M (MEDIUM): " << items[i].harga[1]
               << "Stok : " << items[i].stok[1] << endl;
          file << "------------------------------------------------------------"
                  "--------------"
               << endl;

          file << "Harga L (LARGE): " << items[i].harga[2]
               << "Stok : " << items[i].stok[2] << endl;
          file << "------------------------------------------------------------"
                  "--------------"
               << endl;

          file << "Harga XL (EXTRA LARGE): " << items[i].harga[3]
               << "Stok : " << items[i].stok[3] << endl;
          file << "------------------------------------------------------------"
                  "--------------"
               << endl;

          file << "Harga XXL (DOUBEL EXTRA LARGE): " << items[i].harga[4]
               << "Stok : " << items[i].stok[4] << endl;

          file << "============================================================"
                  "==============="
               << endl;
        }
      }
      file.close();
      cout << "Konten berhasil disimpan!" << endl;

    } else {
      cout << "Gagal membuka file konten." << endl;
    }
  }

  void pilihPakaianMuslimPria() {
    system("clear");

    string kategori = "Pakaian Muslim Pria";

    tambah(kategori);

    ofstream file("kat_Pakaian Muslim Pria.txt",
                  ios::app); // Membuka file dalam mode append
    if (file.is_open()) {
      for (int i = 0; i < MAX_ITEMS; i++) {
        if (!items[i].nama.empty()) {
          file << "============================================================"
                  "=============="
               << endl;
          file << "Nama Barang :            " << items[i].nama << endl;
          file << "kategori :               " << items[i].kategori << endl;
          file << "============================================================"
                  "=============="
               << endl
               << endl;

          file << "Harga S (SMALL): " << items[i].harga[0]
               << "Stok : " << items[i].stok[0] << endl;
          file << "------------------------------------------------------------"
                  "--------------"
               << endl;

          file << "Harga M (MEDIUM): " << items[i].harga[1]
               << "Stok : " << items[i].stok[1] << endl;
          file << "------------------------------------------------------------"
                  "--------------"
               << endl;

          file << "Harga L (LARGE): " << items[i].harga[2]
               << "Stok : " << items[i].stok[2] << endl;
          file << "------------------------------------------------------------"
                  "--------------"
               << endl;

          file << "Harga XL (EXTRA LARGE): " << items[i].harga[3]
               << "Stok : " << items[i].stok[3] << endl;
          file << "------------------------------------------------------------"
                  "--------------"
               << endl;

          file << "Harga XXL (DOUBEL EXTRA LARGE): " << items[i].harga[4]
               << "Stok : " << items[i].stok[4] << endl;

          file << "============================================================"
                  "==============="
               << endl;
        }
      }
      file.close();
      cout << "Konten berhasil disimpan!" << endl;

    } else {
      cout << "Gagal membuka file konten." << endl;
    }
  }

  void pilihHijab() {
    system("clear");

    string kategori = "Hijab";

    tambah(kategori);

    ofstream file("kat_Hijab.txt", ios::app); // Membuka file dalam mode append
    if (file.is_open()) {
      for (int i = 0; i < MAX_ITEMS; i++) {
        if (!items[i].nama.empty()) {
          file << "============================================================"
                  "=============="
               << endl;
          file << "Nama Barang :            " << items[i].nama << endl;
          file << "kategori :               " << items[i].kategori << endl;
          file << "============================================================"
                  "=============="
               << endl
               << endl;

          file << "Harga S (SMALL): " << items[i].harga[0]
               << "Stok : " << items[i].stok[0] << endl;
          file << "------------------------------------------------------------"
                  "--------------"
               << endl;

          file << "Harga M (MEDIUM): " << items[i].harga[1]
               << "Stok : " << items[i].stok[1] << endl;
          file << "------------------------------------------------------------"
                  "--------------"
               << endl;

          file << "Harga L (LARGE): " << items[i].harga[2]
               << "Stok : " << items[i].stok[2] << endl;
          file << "------------------------------------------------------------"
                  "--------------"
               << endl;

          file << "Harga XL (EXTRA LARGE): " << items[i].harga[3]
               << "Stok : " << items[i].stok[3] << endl;
          file << "------------------------------------------------------------"
                  "--------------"
               << endl;

          file << "Harga XXL (DOUBEL EXTRA LARGE): " << items[i].harga[4]
               << "Stok : " << items[i].stok[4] << endl;

          file << "============================================================"
                  "==============="
               << endl;
        }
      }
      file.close();
      cout << "Konten berhasil disimpan!" << endl;

    } else {
      cout << "Gagal membuka file konten." << endl;
    }
  }

  void pilihAtasanMuslimWanita() {
    system("clear");

    string kategori = "Atasan Muslim Wanita";

    tambah(kategori);

    ofstream file("kat_Atasan Muslim Wanita.txt",
                  ios::app); // Membuka file dalam mode append
    if (file.is_open()) {
      for (int i = 0; i < MAX_ITEMS; i++) {
        if (!items[i].nama.empty()) {
          file << "============================================================"
                  "=============="
               << endl;
          file << "Nama Barang :            " << items[i].nama << endl;
          file << "kategori :               " << items[i].kategori << endl;
          file << "============================================================"
                  "=============="
               << endl
               << endl;

          file << "Harga S (SMALL): " << items[i].harga[0]
               << "Stok : " << items[i].stok[0] << endl;
          file << "------------------------------------------------------------"
                  "--------------"
               << endl;

          file << "Harga M (MEDIUM): " << items[i].harga[1]
               << "Stok : " << items[i].stok[1] << endl;
          file << "------------------------------------------------------------"
                  "--------------"
               << endl;

          file << "Harga L (LARGE): " << items[i].harga[2]
               << "Stok : " << items[i].stok[2] << endl;
          file << "------------------------------------------------------------"
                  "--------------"
               << endl;

          file << "Harga XL (EXTRA LARGE): " << items[i].harga[3]
               << "Stok : " << items[i].stok[3] << endl;
          file << "------------------------------------------------------------"
                  "--------------"
               << endl;

          file << "Harga XXL (DOUBEL EXTRA LARGE): " << items[i].harga[4]
               << "Stok : " << items[i].stok[4] << endl;

          file << "============================================================"
                  "==============="
               << endl;
        }
      }
      file.close();
      cout << "Konten berhasil disimpan!" << endl;

    } else {
      cout << "Gagal membuka file konten." << endl;
    }
  }

  void pilihBawahanMuslimWanita() {
    system("clear");

    string kategori = "Bawahan Muslim Wanita";

    tambah(kategori);

    ofstream file("kat_Bawahan Muslim Wanita.txt",
                  ios::app); // Membuka file dalam mode append
    if (file.is_open()) {
      for (int i = 0; i < MAX_ITEMS; i++) {
        if (!items[i].nama.empty()) {
          file << "============================================================"
                  "=============="
               << endl;
          file << "Nama Barang :            " << items[i].nama << endl;
          file << "kategori :               " << items[i].kategori << endl;
          file << "============================================================"
                  "=============="
               << endl
               << endl;

          file << "Harga S (SMALL): " << items[i].harga[0]
               << "Stok : " << items[i].stok[0] << endl;
          file << "------------------------------------------------------------"
                  "--------------"
               << endl;

          file << "Harga M (MEDIUM): " << items[i].harga[1]
               << "Stok : " << items[i].stok[1] << endl;
          file << "------------------------------------------------------------"
                  "--------------"
               << endl;

          file << "Harga L (LARGE): " << items[i].harga[2]
               << "Stok : " << items[i].stok[2] << endl;
          file << "------------------------------------------------------------"
                  "--------------"
               << endl;

          file << "Harga XL (EXTRA LARGE): " << items[i].harga[3]
               << "Stok : " << items[i].stok[3] << endl;
          file << "------------------------------------------------------------"
                  "--------------"
               << endl;

          file << "Harga XXL (DOUBEL EXTRA LARGE): " << items[i].harga[4]
               << "Stok : " << items[i].stok[4] << endl;

          file << "============================================================"
                  "==============="
               << endl;
        }
      }
      file.close();
      cout << "Konten berhasil disimpan!" << endl;

    } else {
      cout << "Gagal membuka file konten." << endl;
    }
  }

  void pilihJamTanganPria() {
    system("clear");

    string kategori = "Jam Tangan Pria";

    tambah(kategori);

    ofstream file("kat_Jam Tangan Pria.txt",
                  ios::app); // Membuka file dalam mode append
    if (file.is_open()) {
      for (int i = 0; i < MAX_ITEMS; i++) {
        if (!items[i].nama.empty()) {
          file << "============================================================"
                  "=============="
               << endl;
          file << "Nama Barang :            " << items[i].nama << endl;
          file << "kategori :               " << items[i].kategori << endl;
          file << "============================================================"
                  "=============="
               << endl
               << endl;

          file << "Harga S (SMALL): " << items[i].harga[0]
               << "Stok : " << items[i].stok[0] << endl;
          file << "------------------------------------------------------------"
                  "--------------"
               << endl;

          file << "Harga M (MEDIUM): " << items[i].harga[1]
               << "Stok : " << items[i].stok[1] << endl;
          file << "------------------------------------------------------------"
                  "--------------"
               << endl;

          file << "Harga L (LARGE): " << items[i].harga[2]
               << "Stok : " << items[i].stok[2] << endl;
          file << "------------------------------------------------------------"
                  "--------------"
               << endl;

          file << "Harga XL (EXTRA LARGE): " << items[i].harga[3]
               << "Stok : " << items[i].stok[3] << endl;
          file << "------------------------------------------------------------"
                  "--------------"
               << endl;

          file << "Harga XXL (DOUBEL EXTRA LARGE): " << items[i].harga[4]
               << "Stok : " << items[i].stok[4] << endl;

          file << "============================================================"
                  "==============="
               << endl;
        }
      }
      file.close();
      cout << "Konten berhasil disimpan!" << endl;

    } else {
      cout << "Gagal membuka file konten." << endl;
    }
  }

  void pilihJamTanganWanita() {
    system("clear");

    string kategori = "Jam Tangan Wanita";

    tambah(kategori);

    ofstream file("kat_Jam Tangan Wanita.txt",
                  ios::app); // Membuka file dalam mode append
    if (file.is_open()) {
      for (int i = 0; i < MAX_ITEMS; i++) {
        if (!items[i].nama.empty()) {
          file << "============================================================"
                  "=============="
               << endl;
          file << "Nama Barang :            " << items[i].nama << endl;
          file << "kategori :               " << items[i].kategori << endl;
          file << "============================================================"
                  "=============="
               << endl
               << endl;

          file << "Harga S (SMALL): " << items[i].harga[0]
               << "Stok : " << items[i].stok[0] << endl;
          file << "------------------------------------------------------------"
                  "--------------"
               << endl;

          file << "Harga M (MEDIUM): " << items[i].harga[1]
               << "Stok : " << items[i].stok[1] << endl;
          file << "------------------------------------------------------------"
                  "--------------"
               << endl;

          file << "Harga L (LARGE): " << items[i].harga[2]
               << "Stok : " << items[i].stok[2] << endl;
          file << "------------------------------------------------------------"
                  "--------------"
               << endl;

          file << "Harga XL (EXTRA LARGE): " << items[i].harga[3]
               << "Stok : " << items[i].stok[3] << endl;
          file << "------------------------------------------------------------"
                  "--------------"
               << endl;

          file << "Harga XXL (DOUBEL EXTRA LARGE): " << items[i].harga[4]
               << "Stok : " << items[i].stok[4] << endl;

          file << "============================================================"
                  "==============="
               << endl;
        }
      }
      file.close();
      cout << "Konten berhasil disimpan!" << endl;

    } else {
      cout << "Gagal membuka file konten." << endl;
    }
  }

  void pilihJamTanganCouple() {
    system("clear");

    string kategori = "Jam Tangan Couple";

    tambah(kategori);

    ofstream file("kat_Jam Tangan Couple.txt",
                  ios::app); // Membuka file dalam mode append
    if (file.is_open()) {
      for (int i = 0; i < MAX_ITEMS; i++) {
        if (!items[i].nama.empty()) {
          file << "============================================================"
                  "=============="
               << endl;
          file << "Nama Barang :            " << items[i].nama << endl;
          file << "kategori :               " << items[i].kategori << endl;
          file << "============================================================"
                  "=============="
               << endl
               << endl;

          file << "Harga S (SMALL): " << items[i].harga[0]
               << "Stok : " << items[i].stok[0] << endl;
          file << "------------------------------------------------------------"
                  "--------------"
               << endl;

          file << "Harga M (MEDIUM): " << items[i].harga[1]
               << "Stok : " << items[i].stok[1] << endl;
          file << "------------------------------------------------------------"
                  "--------------"
               << endl;

          file << "Harga L (LARGE): " << items[i].harga[2]
               << "Stok : " << items[i].stok[2] << endl;
          file << "------------------------------------------------------------"
                  "--------------"
               << endl;

          file << "Harga XL (EXTRA LARGE): " << items[i].harga[3]
               << "Stok : " << items[i].stok[3] << endl;
          file << "------------------------------------------------------------"
                  "--------------"
               << endl;

          file << "Harga XXL (DOUBEL EXTRA LARGE): " << items[i].harga[4]
               << "Stok : " << items[i].stok[4] << endl;

          file << "============================================================"
                  "==============="
               << endl;
        }
      }
      file.close();
      cout << "Konten berhasil disimpan!" << endl;

    } else {
      cout << "Gagal membuka file konten." << endl;
    }
  }

  void pilihTasPria() {
    system("clear");

    string kategori = "Tas Pria";

    tambah(kategori);

    ofstream file("kat_Tas Pria.txt",
                  ios::app); // Membuka file dalam mode append
    if (file.is_open()) {
      for (int i = 0; i < MAX_ITEMS; i++) {
        if (!items[i].nama.empty()) {
          file << "============================================================"
                  "=============="
               << endl;
          file << "Nama Barang :            " << items[i].nama << endl;
          file << "kategori :               " << items[i].kategori << endl;
          file << "============================================================"
                  "=============="
               << endl
               << endl;

          file << "Harga S (SMALL): " << items[i].harga[0]
               << "Stok : " << items[i].stok[0] << endl;
          file << "------------------------------------------------------------"
                  "--------------"
               << endl;

          file << "Harga M (MEDIUM): " << items[i].harga[1]
               << "Stok : " << items[i].stok[1] << endl;
          file << "------------------------------------------------------------"
                  "--------------"
               << endl;

          file << "Harga L (LARGE): " << items[i].harga[2]
               << "Stok : " << items[i].stok[2] << endl;
          file << "------------------------------------------------------------"
                  "--------------"
               << endl;

          file << "Harga XL (EXTRA LARGE): " << items[i].harga[3]
               << "Stok : " << items[i].stok[3] << endl;
          file << "------------------------------------------------------------"
                  "--------------"
               << endl;

          file << "Harga XXL (DOUBEL EXTRA LARGE): " << items[i].harga[4]
               << "Stok : " << items[i].stok[4] << endl;

          file << "============================================================"
                  "==============="
               << endl;
        }
      }
      file.close();
      cout << "Konten berhasil disimpan!" << endl;

    } else {
      cout << "Gagal membuka file konten." << endl;
    }
  }

  void pilihTasWanita() {
    system("clear");

    string kategori = "Tas Wanita";

    tambah(kategori);

    ofstream file("kat_Tas Wanita.txt",
                  ios::app); // Membuka file dalam mode append
    if (file.is_open()) {
      for (int i = 0; i < MAX_ITEMS; i++) {
        if (!items[i].nama.empty()) {
          file << "============================================================"
                  "=============="
               << endl;
          file << "Nama Barang :            " << items[i].nama << endl;
          file << "kategori :               " << items[i].kategori << endl;
          file << "============================================================"
                  "=============="
               << endl
               << endl;

          file << "Harga S (SMALL): " << items[i].harga[0]
               << "Stok : " << items[i].stok[0] << endl;
          file << "------------------------------------------------------------"
                  "--------------"
               << endl;

          file << "Harga M (MEDIUM): " << items[i].harga[1]
               << "Stok : " << items[i].stok[1] << endl;
          file << "------------------------------------------------------------"
                  "--------------"
               << endl;

          file << "Harga L (LARGE): " << items[i].harga[2]
               << "Stok : " << items[i].stok[2] << endl;
          file << "------------------------------------------------------------"
                  "--------------"
               << endl;

          file << "Harga XL (EXTRA LARGE): " << items[i].harga[3]
               << "Stok : " << items[i].stok[3] << endl;
          file << "------------------------------------------------------------"
                  "--------------"
               << endl;

          file << "Harga XXL (DOUBEL EXTRA LARGE): " << items[i].harga[4]
               << "Stok : " << items[i].stok[4] << endl;

          file << "============================================================"
                  "==============="
               << endl;
        }
      }
      file.close();
      cout << "Konten berhasil disimpan!" << endl;

    } else {
      cout << "Gagal membuka file konten." << endl;
    }
  }

  void pilihPakaianOlahragaPriaa() {
    system("clear");

    string kategori = "Pakaian Olahraga Pria";

    tambah(kategori);

    ofstream file("kat_Pakaian Olahraga Pria.txt",
                  ios::app); // Membuka file dalam mode append
    if (file.is_open()) {
      for (int i = 0; i < MAX_ITEMS; i++) {
        if (!items[i].nama.empty()) {
          file << "============================================================"
                  "=============="
               << endl;
          file << "Nama Barang :            " << items[i].nama << endl;
          file << "kategori :               " << items[i].kategori << endl;
          file << "============================================================"
                  "=============="
               << endl
               << endl;

          file << "Harga S (SMALL): " << items[i].harga[0]
               << "Stok : " << items[i].stok[0] << endl;
          file << "------------------------------------------------------------"
                  "--------------"
               << endl;

          file << "Harga M (MEDIUM): " << items[i].harga[1]
               << "Stok : " << items[i].stok[1] << endl;
          file << "------------------------------------------------------------"
                  "--------------"
               << endl;

          file << "Harga L (LARGE): " << items[i].harga[2]
               << "Stok : " << items[i].stok[2] << endl;
          file << "------------------------------------------------------------"
                  "--------------"
               << endl;

          file << "Harga XL (EXTRA LARGE): " << items[i].harga[3]
               << "Stok : " << items[i].stok[3] << endl;
          file << "------------------------------------------------------------"
                  "--------------"
               << endl;

          file << "Harga XXL (DOUBEL EXTRA LARGE): " << items[i].harga[4]
               << "Stok : " << items[i].stok[4] << endl;

          file << "============================================================"
                  "==============="
               << endl;
        }
      }
      file.close();
      cout << "Konten berhasil disimpan!" << endl;

    } else {
      cout << "Gagal membuka file konten." << endl;
    }
  }

  void pilihPakaianOlahragaWanita() {
    system("clear");

    string kategori = "Pakaian Olahraga Wanita";

    tambah(kategori);

    ofstream file("kat_Pakaian Olahraga Wanita.txt",
                  ios::app); // Membuka file dalam mode append
    if (file.is_open()) {
      for (int i = 0; i < MAX_ITEMS; i++) {
        if (!items[i].nama.empty()) {
          file << "============================================================"
                  "=============="
               << endl;
          file << "Nama Barang :            " << items[i].nama << endl;
          file << "kategori :               " << items[i].kategori << endl;
          file << "============================================================"
                  "=============="
               << endl
               << endl;

          file << "Harga S (SMALL): " << items[i].harga[0]
               << "Stok : " << items[i].stok[0] << endl;
          file << "------------------------------------------------------------"
                  "--------------"
               << endl;

          file << "Harga M (MEDIUM): " << items[i].harga[1]
               << "Stok : " << items[i].stok[1] << endl;
          file << "------------------------------------------------------------"
                  "--------------"
               << endl;

          file << "Harga L (LARGE): " << items[i].harga[2]
               << "Stok : " << items[i].stok[2] << endl;
          file << "------------------------------------------------------------"
                  "--------------"
               << endl;

          file << "Harga XL (EXTRA LARGE): " << items[i].harga[3]
               << "Stok : " << items[i].stok[3] << endl;
          file << "------------------------------------------------------------"
                  "--------------"
               << endl;

          file << "Harga XXL (DOUBEL EXTRA LARGE): " << items[i].harga[4]
               << "Stok : " << items[i].stok[4] << endl;

          file << "============================================================"
                  "==============="
               << endl;
        }
      }
      file.close();
      cout << "Konten berhasil disimpan!" << endl;

    } else {
      cout << "Gagal membuka file konten." << endl;
    }
  }

  void pilihPakaianDalam() {
    system("clear");

    string kategori = "Pakaian Dalam ";

    tambah(kategori);

    ofstream file("kat_Pakaian Dalam .txt",
                  ios::app); // Membuka file dalam mode append
    if (file.is_open()) {
      for (int i = 0; i < MAX_ITEMS; i++) {
        if (!items[i].nama.empty()) {
          file << "============================================================"
                  "=============="
               << endl;
          file << "Nama Barang :            " << items[i].nama << endl;
          file << "kategori :               " << items[i].kategori << endl;
          file << "============================================================"
                  "=============="
               << endl
               << endl;

          file << "Harga S (SMALL): " << items[i].harga[0]
               << "Stok : " << items[i].stok[0] << endl;
          file << "------------------------------------------------------------"
                  "--------------"
               << endl;

          file << "Harga M (MEDIUM): " << items[i].harga[1]
               << "Stok : " << items[i].stok[1] << endl;
          file << "------------------------------------------------------------"
                  "--------------"
               << endl;

          file << "Harga L (LARGE): " << items[i].harga[2]
               << "Stok : " << items[i].stok[2] << endl;
          file << "------------------------------------------------------------"
                  "--------------"
               << endl;

          file << "Harga XL (EXTRA LARGE): " << items[i].harga[3]
               << "Stok : " << items[i].stok[3] << endl;
          file << "------------------------------------------------------------"
                  "--------------"
               << endl;

          file << "Harga XXL (DOUBEL EXTRA LARGE): " << items[i].harga[4]
               << "Stok : " << items[i].stok[4] << endl;

          file << "============================================================"
                  "==============="
               << endl;
        }
      }
      file.close();
      cout << "Konten berhasil disimpan!" << endl;

    } else {
      cout << "Gagal membuka file konten." << endl;
    }
  }
  //================================================================================================
  void barang_statis() {
    items[0].nama = "UNICLO SUMMER EDITION";
    items[0].kategori = "Baju Pria";
    items[0].lokasi = "Jawa";
    items[0].status = 1;
    items[0].warna = "Merah";

    items[0].harga[0] = 50000;
    items[0].stok[0] = 40;

    items[0].harga[1] = 60000;
    items[0].stok[1] = 35;

    items[0].harga[2] = 70000;
    items[0].stok[2] = 25;

    items[0].harga[3] = 80000;
    items[0].stok[3] = 20;

    items[0].harga[4] = 90000;
    items[0].stok[4] = 15;

    items[0].avarage = 0;
    for (int i = 0; i < 5; ++i) {
        items[0].avarage+= items[0].harga[i];
    }

    items[0].avarage = items[0].avarage/5;
    //=====GANTI INDEKZ (ITEM[]) SETIAP MENAMBAH
    //BARANG=============================
    items[1].nama = "STARCROS GENTLE WILD";
    items[1].kategori = "Baju Pria";
    items[1].lokasi = "Lampung";
    items[1].status = 0;
    items[1].warna = "Biru";

    items[1].harga[0] = 150000;
    items[1].stok[0] = 40;

    items[1].harga[1] = 160000;
    items[1].stok[1] = 35;

    items[1].harga[2] = 170000;
    items[1].stok[2] = 25;

    items[1].harga[3] = 180000;
    items[1].stok[3] = 20;

    items[1].harga[4] = 190000;
    items[1].stok[4] = 15;

    items[1].avarage = 0;
    for (int i = 0; i < 5; ++i) {
        items[1].avarage+= items[1].harga[i];
    }

    items[1].avarage = items[1].avarage/5;
    //=====GANTI INDEKZ (ITEM[]) SETIAP MENAMBAH
    //BARANG=============================
    items[2].nama = "3 Seconds";
    items[2].kategori = "Baju Pria";
    items[2].lokasi = "Jawa";
    items[2].status = 0;
    items[2].warna = "Putih";

    items[2].harga[0] = 90000;
    items[2].stok[0] = 42;

    items[2].harga[1] = 12000;
    items[2].stok[1] = 76;

    items[2].harga[2] = 150000;
    items[2].stok[2] = 16;

    items[2].harga[3] = 170000;
    items[2].stok[3] = 67;

    items[2].harga[4] = 170000;
    items[2].stok[4] = 10;

    items[2].avarage = 0;
    for (int i = 0; i < 5; ++i) {
        items[2].avarage+= items[2].harga[i];
    }

    items[2].avarage = items[2].avarage/5;
    //=====GANTI INDEKZ (ITEM[]) SETIAP MENAMBAH
    //BARANG=============================
    items[3].nama = "Uniqlo Dress";
    items[3].kategori = "Baju Wanita";
    items[3].lokasi = "Batam";
    items[3].status = 0;
    items[3].warna = "Hitam";

    items[3].harga[0] = 230000;
    items[3].stok[0] = 22;

    items[3].harga[1] = 231000;
    items[3].stok[1] = 29;

    items[3].harga[2] = 232000;
    items[3].stok[2] = 16;

    items[3].harga[3] = 145000;
    items[3].stok[3] = 67;

    items[3].harga[4] = 255000;
    items[3].stok[4] = 10;

    items[3].avarage = 0;
    for (int i = 0; i < 5; ++i) {
        items[3].avarage+= items[3].harga[i];
    }

    items[3].avarage = items[3].avarage/5;
    //=====GANTI INDEKZ (ITEM[]) SETIAP MENAMBAH
    //BARANG=============================
    items[4].nama = "Miniso";
    items[4].kategori = "Baju Wanita";
    items[4].lokasi = "Madiun";
    items[4].status = 0;
    items[4].warna = "Merah";

    items[4].harga[0] = 250000;
    items[4].stok[0] = 30;

    items[4].harga[1] = 255000;
    items[4].stok[1] = 31;

    items[4].harga[2] = 260000;
    items[4].stok[2] = 19;

    items[4].harga[3] = 290000;
    items[4].stok[3] = 71;

    items[4].harga[4] = 310000;
    items[4].stok[4] = 8;

    items[4].avarage = 0;
    for (int i = 0; i < 5; ++i) {
        items[4].avarage+= items[4].harga[i];
    }

    items[4].avarage = items[4].avarage/5;
    //=====GANTI INDEKZ (ITEM[]) SETIAP MENAMBAH
    //BARANG=============================
    items[5].nama = "Colorbox";
    items[5].kategori = "Baju Wanita";
    items[5].lokasi = "Surabaya";
    items[5].status = 0;
    items[5].warna = "Biru";

    items[5].harga[0] = 130000;
    items[5].stok[0] = 27;

    items[5].harga[1] = 150000;
    items[5].stok[1] = 29;

    items[5].harga[2] = 200000;
    items[5].stok[2] = 16;

    items[5].harga[3] = 210000;
    items[5].stok[3] = 75;

    items[5].harga[4] = 240000;
    items[5].stok[4] = 10;

    items[5].avarage = 0;
    for (int i = 0; i < 5; ++i) {
        items[5].avarage+= items[5].harga[i];
    }

    items[5].avarage = items[5].avarage/5;
    //=====GANTI INDEKZ (ITEM[]) SETIAP MENAMBAH
    //BARANG=============================
    items[6].nama = "Jam Tangan";
    items[6].kategori = "Aksesoris";
    items[6].lokasi = "Bandung";
    items[6].status = 1;
    items[6].warna = "Putih";

    items[6].harga[0] = 90000;
    items[6].stok[0] = 20;

    items[6].harga[1] = 100000;
    items[6].stok[1] = 21;

    items[6].harga[2] = 130000;
    items[6].stok[2] = 25;

    items[6].harga[3] = 145000;
    items[6].stok[3] = 30;

    items[6].harga[4] = 160000;
    items[6].stok[4] = 35;

    items[6].avarage = 0;
    for (int i = 0; i < 5; ++i) {
        items[6].avarage+= items[6].harga[i];
    }

    items[6].avarage = items[6].avarage/5;
    //=====GANTI INDEKZ (ITEM[]) SETIAP MENAMBAH
    //BARANG=============================
    items[7].nama = "Cincin Akik";
    items[7].kategori = "Aksesoris";
    items[7].lokasi = "Jatinangor";
    items[7].status = 0;
    items[7].warna = "Hitam";

    items[7].harga[0] = 80000;
    items[7].stok[0] = 25;

    items[7].harga[1] = 90000;
    items[7].stok[1] = 30;

    items[7].harga[2] = 100000;
    items[7].stok[2] = 40;

    items[7].harga[3] = 110000;
    items[7].stok[3] = 36;

    items[7].harga[4] = 120000;
    items[7].stok[4] = 24;

    items[7].avarage = 0;
    for (int i = 0; i < 5; ++i) {
        items[7].avarage+= items[7].harga[i];
    }

    items[7].avarage = items[7].avarage/5;
    //=====GANTI INDEKZ (ITEM[]) SETIAP MENAMBAH
    //BARANG=============================
    items[8].nama = "Gelang Karet";
    items[8].kategori = "Aksesoris";
    items[8].lokasi = "Madura";
    items[8].status = 0;
    items[8].warna = "Merah";

    items[8].harga[0] = 70000;
    items[8].stok[0] = 25;

    items[8].harga[1] = 80000;
    items[8].stok[1] = 30;

    items[8].harga[2] = 90000;
    items[8].stok[2] = 35;

    items[8].harga[3] = 100000;
    items[8].stok[3] = 40;

    items[8].harga[4] = 110000;
    items[8].stok[4] = 45;

    items[8].avarage = 0;
    for (int i = 0; i < 5; ++i) {
        items[8].avarage+= items[8].harga[i];
    }

    items[8].avarage = items[8].avarage/5;
    //=====GANTI INDEKZ (ITEM[]) SETIAP MENAMBAH
    //BARANG=============================
    items[9].nama = "Docmart";
    items[9].kategori = "Sepatu pria";
    items[9].lokasi = "Jakarta";
    items[9].status = 0;
    items[9].warna = "Biru";

    items[9].harga[0] = 170000;
    items[9].stok[0] = 21;

    items[9].harga[1] = 190000;
    items[9].stok[1] = 50;

    items[9].harga[2] = 210000;
    items[9].stok[2] = 28;

    items[9].harga[3] = 245000;
    items[9].stok[3] = 40;

    items[9].harga[4] = 360000;
    items[9].stok[4] = 60;

    items[9].avarage = 0;
    for (int i = 0; i < 5; ++i) {
        items[9].avarage+= items[9].harga[i];
    }

    items[9].avarage = items[9].avarage/5;
    //=====GANTI INDEKZ (ITEM[]) SETIAP MENAMBAH
    //BARANG=============================
    items[10].nama = "Converse";
    items[10].kategori = "Sepatu pria";
    items[10].lokasi = "Jakarta";
    items[10].status = 0;
    items[10].warna = "Putih";

    items[10].harga[0] = 170000;
    items[10].stok[0] = 21;

    items[10].harga[1] = 190000;
    items[10].stok[1] = 50;

    items[10].harga[2] = 210000;
    items[10].stok[2] = 28;

    items[10].harga[3] = 245000;
    items[10].stok[3] = 40;

    items[10].harga[4] = 360000;
    items[10].stok[4] = 60;

    items[10].avarage = 0;
    for (int i = 0; i < 5; ++i) {
        items[10].avarage+= items[10].harga[i];
    }

    items[10].avarage = items[10].avarage/5;
    //=====GANTI INDEKZ (ITEM[]) SETIAP MENAMBAH
    //BARANG=============================
    items[11].nama = "Nike Airmax";
    items[11].kategori = "Sepatu pria";
    items[11].lokasi = "Tangerang";
    items[11].status = 0;
    items[11].warna = "Hitam";

    items[11].harga[0] = 210000;
    items[11].stok[0] = 25;

    items[11].harga[1] = 250000;
    items[11].stok[1] = 40;

    items[11].harga[2] = 270000;
    items[11].stok[2] = 27;

    items[11].harga[3] = 275000;
    items[11].stok[3] = 34;

    items[11].harga[4] = 340000;
    items[11].stok[4] = 65;

    items[11].avarage = 0;
    for (int i = 0; i < 5; ++i) {
        items[11].avarage+= items[11].harga[i];
    }

    items[11].avarage = items[11].avarage/5;
    //=====GANTI INDEKZ (ITEM[]) SETIAP MENAMBAH
    //BARANG=============================
    items[12].nama = "Reebook";
    items[12].kategori = "Sepatu wanita";
    items[12].lokasi = "Depok";
    items[12].status = 0;
    items[12].warna = "Merah";

    items[12].harga[0] = 150000;
    items[12].stok[0] = 18;

    items[12].harga[1] = 170000;
    items[12].stok[1] = 25;

    items[12].harga[2] = 190000;
    items[12].stok[2] = 28;

    items[12].harga[3] = 211000;
    items[12].stok[3] = 36;

    items[12].harga[4] = 213000;
    items[12].stok[4] = 45;

    items[12].avarage = 0;
    for (int i = 0; i < 5; ++i) {
        items[12].avarage+= items[12].harga[i];
    }
    //=====GANTI INDEKZ (ITEM[]) SETIAP MENAMBAH
    //BARANG=============================
    items[13].nama = "Adidas Yeezy";
    items[13].kategori = "Sepatu wanita";
    items[13].lokasi = "Cianjur";
    items[13].status = 0;
    items[13].warna = "Biru";

    items[13].harga[0] = 160000;
    items[13].stok[0] = 20;

    items[13].harga[1] = 180000;
    items[13].stok[1] = 25;

    items[13].harga[2] = 200000;
    items[13].stok[2] = 28;

    items[13].harga[3] = 202000;
    items[13].stok[3] = 36;

    items[13].harga[4] = 204000;
    items[13].stok[4] = 45;

    items[13].avarage = 0;
    for (int i = 0; i < 5; ++i) {
        items[13].avarage+= items[13].harga[i];
    }
    //=====GANTI INDEKZ (ITEM[]) SETIAP MENAMBAH
    //BARANG=============================
    items[14].nama = "Puma";
    items[14].kategori = "Sepatu wanita";
    items[14].lokasi = "Cirebon";
    items[14].status = 0;
    items[14].warna = "Putih";

    items[14].harga[0] = 200000;
    items[14].stok[0] = 30;

    items[14].harga[1] = 210000;
    items[14].stok[1] = 35;

    items[14].harga[2] = 220000;
    items[14].stok[2] = 38;

    items[14].harga[3] = 230000;
    items[14].stok[3] = 36;

    items[14].harga[4] = 240000;
    items[14].stok[4] = 32;

    items[14].avarage = 0;
    for (int i = 0; i < 5; ++i) {
        items[14].avarage+= items[14].harga[i];
    }
    //=====GANTI INDEKZ (ITEM[]) SETIAP MENAMBAH
    //BARANG=============================
    items[15].nama = "Ovale";
    items[15].kategori = "Skincare";
    items[15].lokasi = "Cimahi";
    items[15].status = 0;
    items[15].warna = "Hitam";

    items[15].harga[0] = 50000;
    items[15].stok[0] = 21;

    items[15].harga[1] = 60000;
    items[15].stok[1] = 25;

    items[15].harga[2] = 70000;
    items[15].stok[2] = 32;

    items[15].harga[3] = 80000;
    items[15].stok[3] = 45;

    items[15].harga[4] = 90000;
    items[15].stok[4] = 48;

    items[15].avarage = 0;
    for (int i = 0; i < 5; ++i) {
        items[15].avarage+= items[15].harga[i];
    }
    //=====GANTI INDEKZ (ITEM[]) SETIAP MENAMBAH
    //BARANG=============================
    items[16].nama = "Wardah";
    items[16].kategori = "Skincare";
    items[16].lokasi = "Aceh";
    items[16].status = 0;
    items[16].warna = "Merah";

    items[16].harga[0] = 60000;
    items[16].stok[0] = 21;

    items[16].harga[1] = 70000;
    items[16].stok[1] = 25;

    items[16].harga[2] = 80000;
    items[16].stok[2] = 32;

    items[16].harga[3] = 90000;
    items[16].stok[3] = 45;

    items[16].harga[4] = 100000;
    items[16].stok[4] = 48;

    items[16].avarage = 0;
    for (int i = 0; i < 5; ++i) {
        items[16].avarage+= items[16].harga[i];
    }
    //=====GANTI INDEKZ (ITEM[]) SETIAP MENAMBAH
    //BARANG=============================
    items[17].nama = "Garnier";
    items[17].kategori = "Skincare";
    items[17].lokasi = "Cimahi";
    items[17].status = 0;
    items[17].warna = "Biru";

    items[17].harga[0] = 40000;
    items[17].stok[0] = 31;

    items[17].harga[1] = 50000;
    items[17].stok[1] = 35;

    items[17].harga[2] = 60000;
    items[17].stok[2] = 32;

    items[17].harga[3] = 70000;
    items[17].stok[3] = 45;

    items[17].harga[4] = 80000;
    items[17].stok[4] = 38;

    items[17].avarage = 0;
    for (int i = 0; i < 5; ++i) {
        items[17].avarage+= items[17].harga[i];
    }
    //=====GANTI INDEKZ (ITEM[]) SETIAP MENAMBAH
    //BARANG=============================
    items[18].nama = "Little M";
    items[18].kategori = "Baju Anak Pria";
    items[18].lokasi = "Padang";
    items[18].status = 0;
    items[18].warna = "Putih";

    items[18].harga[0] = 100000;
    items[18].stok[0] = 25;

    items[18].harga[1] = 105000;
    items[18].stok[1] = 23;

    items[18].harga[2] = 110000;
    items[18].stok[2] = 26;

    items[18].harga[3] = 115000;
    items[18].stok[3] = 42;

    items[18].harga[4] = 120000;
    items[18].stok[4] = 45;

    items[18].avarage = 0;
    for (int i = 0; i < 5; ++i) {
        items[18].avarage+= items[18].harga[i];
    }
    //=====GANTI INDEKZ (ITEM[]) SETIAP MENAMBAH
    //BARANG=============================
    items[19].nama = "Mothercare";
    items[19].kategori = "Baju Anak Pria";
    items[19].lokasi = "Bogor";
    items[19].status = 0;
    items[19].warna = "Hitam";

    items[19].harga[0] = 150000;
    items[19].stok[0] = 25;

    items[19].harga[1] = 11000;
    items[19].stok[1] = 23;

    items[19].harga[2] = 115000;
    items[19].stok[2] = 26;

    items[19].harga[3] = 120000;
    items[19].stok[3] = 42;

    items[19].harga[4] = 125000;
    items[19].stok[4] = 45;

    items[19].avarage = 0;
    for (int i = 0; i < 5; ++i) {
        items[19].avarage+= items[19].harga[i];
    }
    //=====GANTI INDEKZ (ITEM[]) SETIAP MENAMBAH
    //BARANG=============================
    items[20].nama = "Cool Kids";
    items[20].kategori = "Baju Anak Pria";
    items[20].lokasi = "Purworejo";
    items[20].status = 0;
    items[20].warna = "Merah";

    items[20].harga[0] = 110000;
    items[20].stok[0] = 25;

    items[20].harga[1] = 115000;
    items[20].stok[1] = 23;

    items[20].harga[2] = 120000;
    items[20].stok[2] = 26;

    items[20].harga[3] = 125000;
    items[20].stok[3] = 42;

    items[20].harga[4] = 130000;
    items[20].stok[4] = 45;

    items[20].avarage = 0;
    for (int i = 0; i < 5; ++i) {
        items[20].avarage+= items[20].harga[i];
    }
    //=====GANTI INDEKZ (ITEM[]) SETIAP MENAMBAH
    //BARANG=============================
    items[21].nama = "Aero Kids";
    items[21].kategori = "Baju Anak Wanita";
    items[21].lokasi = "Palangkaraya";
    items[21].status = 1;
    items[21].warna = "Biru";

    items[21].harga[0] = 120000;
    items[21].stok[0] = 25;

    items[21].harga[1] = 125000;
    items[21].stok[1] = 23;

    items[21].harga[2] = 130000;
    items[21].stok[2] = 26;

    items[21].harga[3] = 135000;
    items[21].stok[3] = 42;

    items[21].harga[4] = 140000;
    items[21].stok[4] = 45;

    items[21].avarage = 0;
    for (int i = 0; i < 5; ++i) {
        items[21].avarage+= items[21].harga[i];
    }
    //=====GANTI INDEKZ (ITEM[]) SETIAP MENAMBAH
    //BARANG=============================
    items[22].nama = "Cool Kids";
    items[22].kategori = "Baju Anak Wanita";
    items[22].lokasi = "Banjarmasin";
    items[22].status = 0;
    items[22].warna = "Putih";

    items[22].harga[0] = 125000;
    items[22].stok[0] = 25;

    items[22].harga[1] = 130000;
    items[22].stok[1] = 23;

    items[22].harga[2] = 135000;
    items[22].stok[2] = 26;

    items[22].harga[3] = 140000;
    items[22].stok[3] = 42;

    items[22].harga[4] = 145000;
    items[22].stok[4] = 45;

    items[22].avarage = 0;
    for (int i = 0; i < 5; ++i) {
        items[22].avarage+= items[22].harga[i];
    }
    //=====GANTI INDEKZ (ITEM[]) SETIAP MENAMBAH
    //BARANG=============================
    items[23].nama = "Ethica";
    items[23].kategori = "Baju Anak Wanita";
    items[23].lokasi = "Pontianak";
    items[23].status = 0;
    items[23].warna = "Hitam";

    items[23].harga[0] = 150000;
    items[23].stok[0] = 25;

    items[23].harga[1] = 155000;
    items[23].stok[1] = 23;

    items[23].harga[2] = 160000;
    items[23].stok[2] = 26;

    items[23].harga[3] = 165000;
    items[23].stok[3] = 42;

    items[23].harga[4] = 170000;
    items[23].stok[4] = 35;

    items[23].avarage = 0;
    for (int i = 0; i < 5; ++i) {
        items[23].avarage+= items[23].harga[i];
    }
    //=====GANTI INDEKZ (ITEM[]) SETIAP MENAMBAH
    //BARANG=============================
    items[24].nama = "Hoodie LV";
    items[24].kategori = "Outerwear";
    items[24].lokasi = "Solo";
    items[24].status = 0;
    items[24].warna = "Merah";

    items[24].harga[0] = 350000;
    items[24].stok[0] = 28;

    items[24].harga[1] = 355000;
    items[24].stok[1] = 29;

    items[24].harga[2] = 360000;
    items[24].stok[2] = 16;

    items[24].harga[3] = 365000;
    items[24].stok[3] = 22;

    items[24].harga[4] = 370000;
    items[24].stok[4] = 35;

    items[24].avarage = 0;
    for (int i = 0; i < 5; ++i) {
        items[24].avarage+= items[24].harga[i];
    }
    //=====GANTI INDEKZ (ITEM[]) SETIAP MENAMBAH
    //BARANG=============================
    items[25].nama = "Blazers PNB";
    items[25].kategori = "Outerwear";
    items[25].lokasi = "Semarang";
    items[25].status = 0;
    items[25].warna = "Biru";

    items[25].harga[0] = 450000;
    items[25].stok[0] = 38;

    items[25].harga[1] = 455000;
    items[25].stok[1] = 19;

    items[25].harga[2] = 460000;
    items[25].stok[2] = 16;

    items[25].harga[3] = 465000;
    items[25].stok[3] = 22;

    items[25].harga[4] = 470000;
    items[25].stok[4] = 45;

    items[25].avarage = 0;
    for (int i = 0; i < 5; ++i) {
        items[25].avarage+= items[25].harga[i];
    }
    //=====GANTI INDEKZ (ITEM[]) SETIAP MENAMBAH
    //BARANG=============================
    items[26].nama = "Cardigan";
    items[26].kategori = "Outerwear";
    items[26].lokasi = "Yogyakarta";
    items[26].status = 0;
    items[25].warna = "Putih";

    items[26].harga[0] = 550000;
    items[26].stok[0] = 28;

    items[26].harga[1] = 555000;
    items[26].stok[1] = 29;

    items[26].harga[2] = 560000;
    items[26].stok[2] = 12;

    items[26].harga[3] = 565000;
    items[26].stok[3] = 21;

    items[26].harga[4] = 570000;
    items[26].stok[4] = 17;

    items[26].avarage = 0;
    for (int i = 0; i < 5; ++i) {
        items[26].avarage+= items[26].harga[i];
    }
    //=====GANTI INDEKZ (ITEM[]) SETIAP MENAMBAH
    //BARANG=============================
    items[27].nama = "Samase";
    items[27].kategori = "Pakaian Muslim Pria";
    items[27].lokasi = "Cilacap";
    items[27].status = 0;
    items[27].warna = "Hitam";

    items[27].harga[0] = 150000;
    items[27].stok[0] = 18;

    items[27].harga[1] = 155000;
    items[27].stok[1] = 19;

    items[27].harga[2] = 160000;
    items[27].stok[2] = 26;

    items[27].harga[3] = 165000;
    items[27].stok[3] = 12;

    items[27].harga[4] = 170000;
    items[27].stok[4] = 14;

    items[27].avarage = 0;
    for (int i = 0; i < 5; ++i) {
        items[27].avarage+= items[27].harga[i];
    }
    //=====GANTI INDEKZ (ITEM[]) SETIAP MENAMBAH
    //BARANG=============================
    items[28].nama = "Rabbani";
    items[28].kategori = "Pakaian Muslim Pria";
    items[28].lokasi = "Temanggung";
    items[28].status = 0;
    items[28].warna = "Merah";

    items[28].harga[0] = 160000;
    items[28].stok[0] = 18;

    items[28].harga[1] = 165000;
    items[28].stok[1] = 19;

    items[28].harga[2] = 170000;
    items[28].stok[2] = 56;

    items[28].harga[3] = 175000;
    items[28].stok[3] = 12;

    items[28].harga[4] = 180000;
    items[28].stok[4] = 10;

    items[28].avarage = 0;
    for (int i = 0; i < 5; ++i) {
        items[28].avarage+= items[28].harga[i];
    }
    //=====GANTI INDEKZ (ITEM[]) SETIAP MENAMBAH
    //BARANG=============================
    items[29].nama = "Elzata";
    items[29].kategori = "Pakaian Muslim Pria";
    items[29].lokasi = "Sidoarjo";
    items[29].status = 0;
    items[29].warna = "Biru";

    items[29].harga[0] = 180000;
    items[29].stok[0] = 38;

    items[29].harga[1] = 185000;
    items[29].stok[1] = 29;

    items[29].harga[2] = 190000;
    items[29].stok[2] = 16;

    items[29].harga[3] = 195000;
    items[29].stok[3] = 10;

    items[29].harga[4] = 200000;
    items[29].stok[4] = 14;

    items[29].avarage = 0;
    for (int i = 0; i < 5; ++i) {
        items[29].avarage+= items[29].harga[i];
    }
    //=====GANTI INDEKZ (ITEM[]) SETIAP MENAMBAH
    //BARANG=============================
    items[30].nama = "Segiempat";
    items[30].kategori = "Hijab";
    items[30].lokasi = "Jambi";
    items[30].status = 0;
    items[30].warna = "Putih";

    items[30].harga[0] = 150000;
    items[30].stok[0] = 28;

    items[30].harga[1] = 155000;
    items[30].stok[1] = 16;

    items[30].harga[2] = 160000;
    items[30].stok[2] = 18;

    items[30].harga[3] = 165000;
    items[30].stok[3] = 10;

    items[30].harga[4] = 170000;
    items[30].stok[4] = 19;

    items[30].avarage = 0;
    for (int i = 0; i < 5; ++i) {
        items[30].avarage+= items[30].harga[i];
    }
    //=====GANTI INDEKZ (ITEM[]) SETIAP MENAMBAH
    //BARANG=============================
    items[31].nama = "Pashmina";
    items[31].kategori = "Hijab";
    items[31].lokasi = "Sleman";
    items[31].status = 0;
    items[31].warna = "Hitam";

    items[31].harga[0] = 160000;
    items[31].stok[0] = 18;

    items[31].harga[1] = 165000;
    items[31].stok[1] = 17;

    items[31].harga[2] = 170000;
    items[31].stok[2] = 19;

    items[31].harga[3] = 175000;
    items[31].stok[3] = 30;

    items[31].harga[4] = 180000;
    items[31].stok[4] = 29;

    items[31].avarage = 0;
    for (int i = 0; i < 5; ++i) {
        items[31].avarage+= items[31].harga[i];
    }
    //=====GANTI INDEKZ (ITEM[]) SETIAP MENAMBAH
    //BARANG=============================
    items[32].nama = "Kulot";
    items[32].kategori = "Hijab";
    items[32].lokasi = "Madura";
    items[32].status = 0;
    items[32].warna = "Merah";

    items[32].harga[0] = 90000;
    items[32].stok[0] = 22;

    items[32].harga[1] = 100000;
    items[32].stok[1] = 19;

    items[32].harga[2] = 105000;
    items[32].stok[2] = 27;

    items[32].harga[3] = 110000;
    items[32].stok[3] = 17;

    items[32].harga[4] = 115000;
    items[32].stok[4] = 15;

    items[32].avarage = 0;
    for (int i = 0; i < 5; ++i) {
        items[32].avarage+= items[32].harga[i];
    }
    //=====GANTI INDEKZ (ITEM[]) SETIAP MENAMBAH
    //BARANG=============================
    items[33].nama = "Starla Blouse";
    items[33].kategori = "Atasan Muslim Wanita";
    items[33].lokasi = "Manado";
    items[33].status = 0;
    items[33].warna = "Biru";

    items[33].harga[0] = 53000;
    items[33].stok[0] = 18;

    items[33].harga[1] = 55000;
    items[33].stok[1] = 16;

    items[33].harga[2] = 56000;
    items[33].stok[2] = 19;

    items[33].harga[3] = 57000;
    items[33].stok[3] = 20;

    items[33].harga[4] = 58000;
    items[33].stok[4] = 39;

    items[33].avarage = 0;
    for (int i = 0; i < 5; ++i) {
        items[33].avarage+= items[33].harga[i];
    }
    //=====GANTI INDEKZ (ITEM[]) SETIAP MENAMBAH
    //BARANG=============================
    items[34].nama = "Zalfa";
    items[34].kategori = "Atasan Muslim Wanita";
    items[34].lokasi = "Bantul";
    items[34].status = 0;
    items[34].warna = "Putih";

    items[34].harga[0] = 61000;
    items[34].stok[0] = 16;

    items[34].harga[1] = 65000;
    items[34].stok[1] = 16;

    items[34].harga[2] = 66000;
    items[34].stok[2] = 19;

    items[34].harga[3] = 67000;
    items[34].stok[3] = 22;

    items[34].harga[4] = 68000;
    items[34].stok[4] = 29;

    items[34].avarage = 0;
    for (int i = 0; i < 5; ++i) {
        items[34].avarage+= items[34].harga[i];
    }
    //=====GANTI INDEKZ (ITEM[]) SETIAP MENAMBAH
    //BARANG=============================
    items[35].nama = "Vallina Outfit";
    items[35].kategori = "Atasan Muslim Wanita";
    items[35].lokasi = "Gunung Kidul";
    items[35].status = 0;
    items[35].warna = "Hitam";

    items[35].harga[0] = 34000;
    items[35].stok[0] = 18;

    items[35].harga[1] = 35000;
    items[35].stok[1] = 16;

    items[35].harga[2] = 36000;
    items[35].stok[2] = 19;

    items[35].harga[3] = 37000;
    items[35].stok[3] = 15;

    items[35].harga[4] = 38000;
    items[35].stok[4] = 29;

    items[35].avarage = 0;
    for (int i = 0; i < 5; ++i) {
        items[35].avarage+= items[35].harga[i];
    }
    //=====GANTI INDEKZ (ITEM[]) SETIAP MENAMBAH
    //BARANG=============================
    items[36].nama = "Carnia Tunik";
    items[36].kategori = "Bawahan Muslim Wanita";
    items[36].lokasi = "Cilegon";
    items[36].status = 0;
    items[36].warna = "Merah";

    items[36].harga[0] = 23000;
    items[36].stok[0] = 19;

    items[36].harga[1] = 25000;
    items[36].stok[1] = 17;

    items[36].harga[2] = 26000;
    items[36].stok[2] = 29;

    items[36].harga[3] = 27000;
    items[36].stok[3] = 20;

    items[36].harga[4] = 28000;
    items[36].stok[4] = 19;

    items[36].avarage = 0;
    for (int i = 0; i < 5; ++i) {
        items[36].avarage+= items[36].harga[i];
    }
    //=====GANTI INDEKZ (ITEM[]) SETIAP MENAMBAH
    //BARANG=============================
    items[37].nama = "Skirt";
    items[37].kategori = "Bawahan Muslim Wanita";
    items[37].lokasi = "Majalengka";
    items[37].status = 0;
    items[37].warna = "Biru";

    items[37].harga[0] = 79000;
    items[37].stok[0] = 18;

    items[37].harga[1] = 80000;
    items[37].stok[1] = 16;

    items[37].harga[2] = 85000;
    items[37].stok[2] = 19;

    items[37].harga[3] = 87000;
    items[37].stok[3] = 20;

    items[37].harga[4] = 88000;
    items[37].stok[4] = 39;

    items[37].avarage = 0;
    for (int i = 0; i < 5; ++i) {
        items[37].avarage+= items[37].harga[i];
    }
    //=====GANTI INDEKZ (ITEM[]) SETIAP MENAMBAH
    //BARANG=============================
    items[38].nama = "Bergo";
    items[38].kategori = "Bawahan Muslim Wanita";
    items[38].lokasi = "Sumedang";
    items[38].status = 0;
    items[38].warna = "Putih";

    items[38].harga[0] = 153000;
    items[38].stok[0] = 18;

    items[38].harga[1] = 155000;
    items[38].stok[1] = 16;

    items[38].harga[2] = 156000;
    items[38].stok[2] = 19;

    items[38].harga[3] = 157000;
    items[38].stok[3] = 20;

    items[38].harga[4] = 158000;
    items[38].stok[4] = 29;

    items[38].avarage = 0;
    for (int i = 0; i < 5; ++i) {
        items[38].avarage+= items[38].harga[i];
    }
    //=====GANTI INDEKZ (ITEM[]) SETIAP MENAMBAH
    //BARANG=============================
    items[39].nama = "Sunlifex";
    items[39].kategori = "Jam Tangan Pria";
    items[39].lokasi = "Banjar";
    items[39].status = 0;
    items[39].warna = "Hitam";

    items[39].harga[0] = 53000;
    items[39].stok[0] = 18;

    items[39].harga[1] = 55000;
    items[39].stok[1] = 16;

    items[39].harga[2] = 56000;
    items[39].stok[2] = 19;

    items[39].harga[3] = 57000;
    items[39].stok[3] = 20;

    items[39].harga[4] = 58000;
    items[39].stok[4] = 39;

    items[39].avarage = 0;
    for (int i = 0; i < 5; ++i) {
        items[39].avarage+= items[39].harga[i];
    }
    //=====GANTI INDEKZ (ITEM[]) SETIAP MENAMBAH
    //BARANG=============================
    items[40].nama = "Rolex";
    items[40].kategori = "Jam Tangan Pria";
    items[40].lokasi = "Sukabumi";
    items[40].status = 0;
    items[40].warna = "Merah";

    items[40].harga[0] = 553000;
    items[40].stok[0] = 15;

    items[40].harga[1] = 555000;
    items[40].stok[1] = 16;

    items[40].harga[2] = 556000;
    items[40].stok[2] = 19;

    items[40].harga[3] = 557000;
    items[40].stok[3] = 10;

    items[40].harga[4] = 558000;
    items[40].stok[4] = 19;

    items[40].avarage = 0;
    for (int i = 0; i < 5; ++i) {
        items[40].avarage+= items[40].harga[i];
    }
    //=====GANTI INDEKZ (ITEM[]) SETIAP MENAMBAH
    //BARANG=============================
    items[41].nama = "iWatch";
    items[41].kategori = "Jam Tangan Pria";
    items[41].lokasi = "Cibinong";
    items[41].status = 0;
    items[41].warna = "Biru";

    items[41].harga[0] = 953000;
    items[41].stok[0] = 18;

    items[41].harga[1] = 955000;
    items[41].stok[1] = 16;

    items[41].harga[2] = 956000;
    items[41].stok[2] = 19;

    items[41].harga[3] = 957000;
    items[41].stok[3] = 20;

    items[41].harga[4] = 958000;
    items[41].stok[4] = 39;

    items[41].avarage = 0;
    for (int i = 0; i < 5; ++i) {
        items[41].avarage+= items[41].harga[i];
    }
    //=====GANTI INDEKZ (ITEM[]) SETIAP MENAMBAH
    //BARANG=============================
    items[42].nama = "iWatch";
    items[42].kategori = "Jam Tangan Wanita";
    items[42].lokasi = "Cibinong";
    items[42].status = 0;
    items[42].warna = "Putih";

    items[42].harga[0] = 953000;
    items[42].stok[0] = 18;

    items[42].harga[1] = 955000;
    items[42].stok[1] = 16;

    items[42].harga[2] = 956000;
    items[42].stok[2] = 19;

    items[42].harga[3] = 957000;
    items[42].stok[3] = 20;

    items[42].harga[4] = 958000;
    items[42].stok[4] = 39;

    items[42].avarage = 0;
    for (int i = 0; i < 5; ++i) {
        items[42].avarage+= items[42].harga[i];
    }
    //=====GANTI INDEKZ (ITEM[]) SETIAP MENAMBAH
    //BARANG=============================
    items[43].nama = "Guess Watch";
    items[43].kategori = "Jam Tangan Wanita";
    items[43].lokasi = "Tasikmalaya";
    items[43].status = 0;
    items[43].warna = "Hitam";

    items[43].harga[0] = 953000;
    items[43].stok[0] = 18;

    items[43].harga[1] = 955000;
    items[43].stok[1] = 16;

    items[43].harga[2] = 956000;
    items[43].stok[2] = 19;

    items[43].harga[3] = 957000;
    items[43].stok[3] = 20;

    items[43].harga[4] = 958000;
    items[43].stok[4] = 39;

    items[43].avarage = 0;
    for (int i = 0; i < 5; ++i) {
        items[43].avarage+= items[43].harga[i];
    }
    //=====GANTI INDEKZ (ITEM[]) SETIAP MENAMBAH
    //BARANG=============================
    items[44].nama = "Gucci Watch";
    items[44].kategori = "Jam Tangan Wanita";
    items[44].lokasi = "Boyolali";
    items[44].status = 0;
    items[44].warna = "Merah";

    items[44].harga[0] = 950000;
    items[44].stok[0] = 18;

    items[44].harga[1] = 955000;
    items[44].stok[1] = 16;

    items[44].harga[2] = 1110000;
    items[44].stok[2] = 19;

    items[44].harga[3] = 1120000;
    items[44].stok[3] = 20;

    items[44].harga[4] = 1130000;
    items[44].stok[4] = 39;

    items[44].avarage = 0;
    for (int i = 0; i < 5; ++i) {
        items[44].avarage+= items[44].harga[i];
    }
    //=====GANTI INDEKZ (ITEM[]) SETIAP MENAMBAH
    //BARANG=============================
    items[45].nama = "Gozeal";
    items[45].kategori = "Jam Tangan Couple";
    items[45].lokasi = "Purwodadi";
    items[45].status = 0;
    items[45].warna = "Putih";

    items[45].harga[0] = 153000;
    items[45].stok[0] = 18;

    items[45].harga[1] = 155000;
    items[45].stok[1] = 16;

    items[45].harga[2] = 156000;
    items[45].stok[2] = 19;

    items[45].harga[3] = 157000;
    items[45].stok[3] = 20;

    items[45].harga[4] = 158000;
    items[45].stok[4] = 18;

    items[45].avarage = 0;
    for (int i = 0; i < 5; ++i) {
        items[45].avarage+= items[45].harga[i];
    }
    //=====GANTI INDEKZ (ITEM[]) SETIAP MENAMBAH
    //BARANG=============================
    items[46].nama = "Woodka";
    items[46].kategori = "Jam Tangan Couple";
    items[46].lokasi = "Jepara";
    items[46].status = 0;
    items[46].warna = "Hitam";

    items[46].harga[0] = 75000;
    items[46].stok[0] = 18;

    items[46].harga[1] = 80000;
    items[46].stok[1] = 16;

    items[46].harga[2] = 85000;
    items[46].stok[2] = 19;

    items[46].harga[3] = 90000;
    items[46].stok[3] = 20;

    items[46].harga[4] = 95000;
    items[46].stok[4] = 18;

    items[46].avarage = 0;
    for (int i = 0; i < 5; ++i) {
        items[46].avarage+= items[46].harga[i];
    }
    //=====GANTI INDEKZ (ITEM[]) SETIAP MENAMBAH
    //BARANG=============================
    items[47].nama = "Casio";
    items[47].kategori = "Jam Tangan Couple";
    items[47].lokasi = "Klaten";
    items[47].status = 0;
    items[47].warna = "Merah";

    items[47].harga[0] = 85000;
    items[47].stok[0] = 18;

    items[47].harga[1] = 90000;
    items[47].stok[1] = 16;

    items[47].harga[2] = 95000;
    items[47].stok[2] = 19;

    items[47].harga[3] = 100000;
    items[47].stok[3] = 20;

    items[47].harga[4] = 105000;
    items[47].stok[4] = 18;

    items[47].avarage = 0;
    for (int i = 0; i < 5; ++i) {
        items[47].avarage+= items[47].harga[i];
    }
    //=====GANTI INDEKZ (ITEM[]) SETIAP MENAMBAH
    //BARANG=============================
    items[48].nama = "Tas Ransel";
    items[48].kategori = "Tas Pria";
    items[48].lokasi = "Kudus";
    items[48].status = 0;
    items[48].warna = "Biru";

    items[48].harga[0] = 55000;
    items[48].stok[0] = 18;

    items[48].harga[1] = 60000;
    items[48].stok[1] = 16;

    items[48].harga[2] = 65000;
    items[48].stok[2] = 19;

    items[48].harga[3] = 70000;
    items[48].stok[3] = 20;

    items[48].harga[4] = 75000;
    items[48].stok[4] = 18;

    items[48].avarage = 0;
    for (int i = 0; i < 5; ++i) {
        items[48].avarage+= items[48].harga[i];
    }
    //=====GANTI INDEKZ (ITEM[]) SETIAP MENAMBAH
    //BARANG=============================
    items[49].nama = "Tas Selempang";
    items[49].kategori = "Tas Pria";
    items[49].lokasi = "Pati";
    items[49].status = 0;
    items[49].warna = "Putih";

    items[49].harga[0] = 55000;
    items[49].stok[0] = 18;

    items[49].harga[1] = 60000;
    items[49].stok[1] = 16;

    items[49].harga[2] = 65000;
    items[49].stok[2] = 19;

    items[49].harga[3] = 70000;
    items[49].stok[3] = 20;

    items[49].harga[4] = 75000;
    items[49].stok[4] = 18;

    items[49].avarage = 0;
    for (int i = 0; i < 5; ++i) {
        items[49].avarage+= items[49].harga[i];
    }
    //=====GANTI INDEKZ (ITEM[]) SETIAP MENAMBAH
    //BARANG=============================
    items[50].nama = "Tas Laptop";
    items[50].kategori = "Tas Pria";
    items[50].lokasi = "Kebumen";
    items[50].status = 0;
    items[50].warna = "Hitam";

    items[50].harga[0] = 155000;
    items[50].stok[0] = 18;

    items[50].harga[1] = 160000;
    items[50].stok[1] = 16;

    items[50].harga[2] = 165000;
    items[50].stok[2] = 19;

    items[50].harga[3] = 170000;
    items[50].stok[3] = 20;

    items[50].harga[4] = 175000;
    items[50].stok[4] = 18;

    items[50].avarage = 0;
    for (int i = 0; i < 5; ++i) {
        items[50].avarage+= items[50].harga[i];
    }
    //=====GANTI INDEKZ (ITEM[]) SETIAP MENAMBAH
    //BARANG=============================
    items[51].nama = "Stringbag";
    items[51].kategori = "Tas Wanita";
    items[51].lokasi = "Kendal";
    items[51].status = 0;
    items[41].warna = "Merah";

    items[51].harga[0] = 15000;
    items[51].stok[0] = 18;

    items[51].harga[1] = 16000;
    items[51].stok[1] = 16;

    items[51].harga[2] = 17000;
    items[51].stok[2] = 19;

    items[51].harga[3] = 18000;
    items[51].stok[3] = 20;

    items[51].harga[4] = 25000;
    items[51].stok[4] = 18;

    items[51].avarage = 0;
    for (int i = 0; i < 5; ++i) {
        items[51].avarage+= items[51].harga[i];
    }
    //=====GANTI INDEKZ (ITEM[]) SETIAP MENAMBAH
    //BARANG=============================
    items[52].nama = "Tas Pinggang";
    items[52].kategori = "Tas Wanita";
    items[52].lokasi = "Kendari";
    items[52].status = 0;
    items[52].warna = "Biru";

    items[52].harga[0] = 25000;
    items[52].stok[0] = 18;

    items[52].harga[1] = 30000;
    items[52].stok[1] = 16;

    items[52].harga[2] = 35000;
    items[52].stok[2] = 19;

    items[52].harga[3] = 40000;
    items[52].stok[3] = 20;

    items[52].harga[4] = 45000;
    items[52].stok[4] = 18;

    items[52].avarage = 0;
    for (int i = 0; i < 5; ++i) {
        items[52].avarage+= items[52].harga[i];
    }
    //=====GANTI INDEKZ (ITEM[]) SETIAP MENAMBAH
    //BARANG=============================
    items[53].nama = "Totebag";
    items[53].kategori = "Tas Wanita";
    items[53].lokasi = "Karanganyar";
    items[53].status = 0;
    items[53].warna = "Putih";

    items[53].harga[0] = 115000;
    items[53].stok[0] = 18;

    items[53].harga[1] = 116000;
    items[53].stok[1] = 16;

    items[53].harga[2] = 117000;
    items[53].stok[2] = 19;

    items[53].harga[3] = 118000;
    items[53].stok[3] = 20;

    items[53].harga[4] = 125000;
    items[53].stok[4] = 18;

    items[53].avarage = 0;
    for (int i = 0; i < 5; ++i) {
        items[53].avarage+= items[53].harga[i];
    }
    //=====GANTI INDEKZ (ITEM[]) SETIAP MENAMBAH
    //BARANG=============================
    items[54].nama = "Baju Futsal";
    items[54].kategori = "Pakaian Olahraga Pria";
    items[54].lokasi = "Pemalang";
    items[54].status = 0;
    items[54].warna = "Hitam";

    items[54].harga[0] = 220000;
    items[54].stok[0] = 18;

    items[54].harga[1] = 230000;
    items[54].stok[1] = 16;

    items[54].harga[2] = 240000;
    items[54].stok[2] = 19;

    items[54].harga[3] = 250000;
    items[54].stok[3] = 20;

    items[54].harga[4] = 260000;
    items[54].stok[4] = 18;

    items[54].avarage = 0;
    for (int i = 0; i < 5; ++i) {
        items[54].avarage+= items[54].harga[i];
    }
    //=====GANTI INDEKZ (ITEM[]) SETIAP MENAMBAH
    //BARANG=============================
    items[55].nama = "Baju Renang";
    items[55].kategori = "Pakaian Olahraga Pria";
    items[55].lokasi = "Purbalingga";
    items[55].status = 0;
    items[55].warna = "Merah";

    items[55].harga[0] = 230000;
    items[55].stok[0] = 18;

    items[55].harga[1] = 240000;
    items[55].stok[1] = 16;

    items[55].harga[2] = 250000;
    items[55].stok[2] = 19;

    items[55].harga[3] = 260000;
    items[55].stok[3] = 20;

    items[55].harga[4] = 270000;
    items[55].stok[4] = 18;

    items[55].avarage = 0;
    for (int i = 0; i < 5; ++i) {
        items[55].avarage+= items[55].harga[i];
    }
    //=====GANTI INDEKZ (ITEM[]) SETIAP MENAMBAH
    //BARANG=============================
    items[56].nama = "Jogger Pants";
    items[56].kategori = "Pakaian Olahraga Pria";
    items[56].lokasi = "Pemalang";
    items[56].status = 0;
    items[56].warna = "Biru";

    items[56].harga[0] = 120000;
    items[56].stok[0] = 18;

    items[56].harga[1] = 130000;
    items[56].stok[1] = 16;

    items[56].harga[2] = 140000;
    items[56].stok[2] = 19;

    items[56].harga[3] = 150000;
    items[56].stok[3] = 20;

    items[56].harga[4] = 160000;
    items[56].stok[4] = 18;

    items[56].avarage = 0;
    for (int i = 0; i < 5; ++i) {
        items[56].avarage+= items[56].harga[i];
    }
    //=====GANTI INDEKZ (ITEM[]) SETIAP MENAMBAH
    //BARANG=============================
    items[57].nama = "Legging Skirt";
    items[57].kategori = "Pakaian Olahraga Wanita";
    items[57].lokasi = "Sragen";
    items[57].status = 0;
    items[57].warna = "Putih";

    items[57].harga[0] = 20000;
    items[57].stok[0] = 18;

    items[57].harga[1] = 30000;
    items[57].stok[1] = 16;

    items[57].harga[2] = 40000;
    items[57].stok[2] = 19;

    items[57].harga[3] = 50000;
    items[57].stok[3] = 20;

    items[57].harga[4] = 60000;
    items[57].stok[4] = 18;

    items[57].avarage = 0;
    for (int i = 0; i < 5; ++i) {
        items[57].avarage+= items[57].harga[i];
    }
    //=====GANTI INDEKZ (ITEM[]) SETIAP MENAMBAH
    //BARANG=============================
    items[58].nama = "Baju Zumba";
    items[58].kategori = "Pakaian Olahraga Wanita";
    items[58].lokasi = "Wonogiri";
    items[58].status = 0;
    items[58].warna = "Hitam";

    items[58].harga[0] = 250000;
    items[58].stok[0] = 18;

    items[58].harga[1] = 350000;
    items[58].stok[1] = 16;

    items[58].harga[2] = 450000;
    items[58].stok[2] = 19;

    items[58].harga[3] = 550000;
    items[58].stok[3] = 20;

    items[58].harga[4] = 650000;
    items[58].stok[4] = 18;

    items[58].avarage = 0;
    for (int i = 0; i < 5; ++i) {
        items[58].avarage+= items[58].harga[i];
    }
    //=====GANTI INDEKZ (ITEM[]) SETIAP MENAMBAH
    //BARANG=============================
    items[59].nama = "Kaos Senam";
    items[59].kategori = "Pakaian Olahraga Wanita";
    items[59].lokasi = "Salatiga";
    items[59].status = 0;
    items[59].warna = "Merah";

    items[59].harga[0] = 20000;
    items[59].stok[0] = 18;

    items[59].harga[1] = 30000;
    items[59].stok[1] = 16;

    items[59].harga[2] = 40000;
    items[59].stok[2] = 19;

    items[59].harga[3] = 50000;
    items[59].stok[3] = 20;

    items[59].harga[4] = 60000;
    items[59].stok[4] = 18;

    items[59].avarage = 0;
    for (int i = 0; i < 5; ++i) {
        items[59].avarage+= items[59].harga[i];
    }
    //=====GANTI INDEKZ (ITEM[]) SETIAP MENAMBAH
    //BARANG=============================
    items[60].nama = "GT Man";
    items[60].kategori = "Pakaian Dalam";
    items[60].lokasi = "Tegal";
    items[60].status = 0;
    items[60].warna = "Biru";

    items[60].harga[0] = 200000;
    items[60].stok[0] = 18;

    items[60].harga[1] = 300000;
    items[60].stok[1] = 16;

    items[60].harga[2] = 400000;
    items[60].stok[2] = 19;

    items[60].harga[3] = 500000;
    items[60].stok[3] = 20;

    items[60].harga[4] = 600000;
    items[60].stok[4] = 18;

    items[60].avarage = 0;
    for (int i = 0; i < 5; ++i) {
        items[60].avarage+= items[60].harga[i];
    }
    //=====GANTI INDEKZ (ITEM[]) SETIAP MENAMBAH
    //BARANG=============================
    items[61].nama = "Crocodile";
    items[61].kategori = "Pakaian Dalam";
    items[61].lokasi = "Wates";
    items[61].status = 0;
    items[61].warna = "Putih";

    items[61].harga[0] = 250000;
    items[61].stok[0] = 18;

    items[61].harga[1] = 350000;
    items[61].stok[1] = 16;

    items[61].harga[2] = 450000;
    items[61].stok[2] = 19;

    items[61].harga[3] = 550000;
    items[61].stok[3] = 20;

    items[61].harga[4] = 650000;
    items[61].stok[4] = 18;

    items[61].avarage = 0;
    for (int i = 0; i < 5; ++i) {
        items[61].avarage+= items[61].harga[i];
    }
    //=====GANTI INDEKZ (ITEM[]) SETIAP MENAMBAH
    //BARANG=============================
    items[62].nama = "Calvin Klein";
    items[62].kategori = "Pakaian Dalam";
    items[62].lokasi = "Malang";
    items[62].status = 0;
    items[62].warna = "Hitam";

    items[62].harga[0] = 400000;
    items[62].stok[0] = 18;

    items[62].harga[1] = 500000;
    items[62].stok[1] = 16;

    items[62].harga[2] = 600000;
    items[62].stok[2] = 19;

    items[62].harga[3] = 700000;
    items[62].stok[3] = 20;

    items[62].harga[4] = 800000;
    items[62].stok[4] = 18;

    items[62].avarage = 0;
    for (int i = 0; i < 5; ++i) {
        items[62].avarage+= items[62].harga[i];
    }
  }
  //==============UBAH PERULANGAN FUNGSI VOID TAMBAH (i =  INDEK BARANG TERAHIR
  //+1 ) ===============
  //==================FUNGSI BELI DI BAWAH
  //PERSIS===================================================
  //!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!

  void tambah(const string &kategori) {
    for (int i = 61; i < MAX_ITEMS; i++) {
      if (items[i].nama.empty()) {
        cout << "Nama Barang: ";
        cin.ignore();
        getline(cin, items[i].nama);
        items[i].kategori = kategori;
        cout << "Lokasi : ";getline(cin, items[i].lokasi);
        cout << endl << endl;
        cout << "1.Merah "<<endl;
        cout << "2.Biru "<<endl;
        cout << "3.Putih "<<endl;
        cout << "4.Hitam "<<endl;
        int warna;
        cout << "Masukkan pilihan : ";cin>>warna;
        if(warna == 1){
          item[i].warna = "Merah ";
        }
        if(warna == 2){
          items[i].warna = "Merah ";
        }
        if(warna == 3){
          items[i].warna = "Merah ";
        }
        if(warna == 4){
          items[i].warna = "Merah ";
        }
        items[i].status = 0;
                
        cout << "Harga S(small) : ";
        cin >> items[i].harga[0];

        cout << "Stok S(small) : ";
        cin >> items[i].stok[0];

        cout << "Harga M(medium) : ";
        cin >> items[i].harga[1];

        cout << "Stok M(medium): ";
        cin >> items[i].stok[1];

        cout << "Harga L(Large) : ";
        cin >> items[i].harga[2];

        cout << "Stok L(Large) : ";
        cin >> items[i].stok[2];

        cout << "Harga XL(Extra Large ) : ";
        cin >> items[i].harga[3];

        cout << "Stok XL (Extra Large) : ";
        cin >> items[i].stok[3];

        cout << "Harga xXL(Doubel Extra Large ) : ";
        cin >> items[i].harga[4];

        cout << "Stok xXL (Doubel Extra Large) : ";
        cin >> items[i].stok[4];

          items[i].avarage = 0;
          for (int j = 0; i < 5; ++i) {
              items[i].avarage+= items[i].harga[j];
          }

          items[i].avarage = items[i].avarage/5;

          
        break;
      }
    }
  }

  int updatestatus(int i){
    items[i].status = items[i].status +1;
    return items[i].status;
  }

  void beli(const int &virhar) { // Tambahkan parameter untuk objek Keranjang
    int virtualmoney = virhar;
    string itemToBuy;
    int amount;
    cout << "Masukkan nama barang yang akan dibeli: ";
    cin.ignore();
    getline(cin, itemToBuy);
    bool barangTersedia = false; // Untuk memeriksa apakah barang ditemukan
    for (int i = 0; i < MAX_ITEMS; i++) {
      if (items[i].nama == itemToBuy) {
        barangTersedia = true;
        cout << "1.S" << endl;
        cout << "2.M" << endl;
        cout << "3.L" << endl;
        cout << "4.XL" << endl;
        cout << "5.XXL" << endl;
        int ltr;
        cout << "masukan pilihan : ";
        cin >> ltr;
        if (ltr >= 1 && ltr <= 5) {
          ltr--; // Kurangi 1 untuk sesuai dengan indeks
          cout << "Masukkan jumlah yang akan dibeli: ";
          cin >> amount;
          if (amount > 0) {
            if (items[i].stok[ltr] >= amount) {
              items[i].stok[ltr] = items[i].stok[ltr] - amount;
              int pilihanbeli;
              cout << "1.masukan kedalam keranjang" << endl;
              cout << "2.langsung checkout " << endl;
              cout << "pilihan  : ";
              cin >> pilihanbeli;
              if (pilihanbeli == 1) {
                int promo;
                cout << "apakah anda memiliki promo? "<<endl;
                cout << " (KETIK 1 UNTUK YA KETIK 0 UNTUK TIDAK)  : ";cin>>promo;
                items[i].status = items[i].status +1;
                kranjang.tambahKeKeranjang(itemToBuy, items[i].harga[ltr], amount,promo);


              } else if (pilihanbeli == 2) {
                if (virtualmoney >= (items[i].harga[ltr] * amount)) {
                  virtualmoney  -= (items[i].harga[ltr] * amount);
                  int promo;
                  cout << "apakah anda memiliki promo? "<<endl;
                  cout << " (KETIK 1 UNTUK YA KETIK 0 UNTUK TIDAK)  : ";cin>>promo;
                  items[i].status = items[i].status +1;
                  cek.tambahKeCHEKOUTT(itemToBuy, items[i].harga[ltr], amount,promo);
                } else {
                  cout << "saldo tidak mencukupi" << endl;
                }

              } else {
                cout << "Pilihan tidak valid!" << endl;
              }
            } else {
              cout << "Stok tidak mencukupi!" << endl;
            }
          } else {
            cout << "Jumlah pembelian tidak valid!" << endl;
          }
        } else {
          cout << "Pilihan tidak valid!" << endl;
        }
        break;
      }
    }

    if (!barangTersedia) {
      cout << "Nama barang tidak tersedia" << endl;
    }
      mainSTADIS(virtualmoney);
      return;
////////////////////////////////////
  }

  void mainSTADIS(int saldo){

    barang_statis();
    int virtualmoney = saldo;
    int choice;
    do {
      cout << "============================================" << endl;
      cout << "saldo Epaymen anda saat ini  : " << virtualmoney << endl;
      cout << "++++++++++++++++++++++++++++++++++++++++++++" << endl;
      hias.Menu();
      cout << "" << endl;
      cout << "============================================" << endl;
      cout << "  1. Smart fitur" << endl;
      cout << "  2. Beli" << endl;
      cout << "  3. lihat keranjang belanja" << endl;
      cout << "  4. cekout barang dalam keranjang" << endl;
      cout << "  5. Riwayat Pembelian" << endl;
      cout << "  6. Cek antrian pengiriman barang" << endl;
      cout << "  7. Riwayat pembayaran                        "<<endl;
      cout << "  8. keluar"<<endl;
      cout << "============================================" << endl;
      cout << "  Pilihan : ";
      cin >> choice;
      if (choice == 1) {
        system("clear");
        int pilihan_pencarian;

        do {
            cout << "+================================+" << endl;
            cout << "|  1. tampilkan semua            |" << endl;
            cout << "|  2. pencarian kategori         |" << endl;
            cout << "|  3. pencarian nama barang      |" << endl;
            cout << "|  4. Sorting Harga              |" << endl;
            cout << "|  5. Daftar kota                |" << endl;
            cout << "|  6. Terlaris                   |" << endl;
            cout << "|  7. Pilihan Warna Produk       |" << endl;
            cout << "|  8. Beli                       |" << endl;
            cout << "|  9. Kembali ke menu awal       |" << endl; // Added option 9
            cout << "+================================+" << endl;

            cout << "  masukan pilihan  : ";
            cin >> pilihan_pencarian;

            if (pilihan_pencarian == 1) {
                system("clear");
                tampilkan();
            } else if (pilihan_pencarian == 2) {
                system("clear");
                searchKategori();
            } else if (pilihan_pencarian == 3) {
                system("clear");
                string keyword;
                cout << endl << endl << "+================================+" << endl;
                cout << "masukan nama barang : ";
                cin >> keyword;
                system("clear");
                searchNamaBarang(keyword);
            } else if (pilihan_pencarian == 4) {
                system("clear");
                sortirharga();
            } else if (pilihan_pencarian == 5) {
                system("clear");
                daftar_kota();
                lokasi();
            } else if (pilihan_pencarian == 6) {
                system("clear");
                searchStatus();
            } else if (pilihan_pencarian == 7) {
                system("clear");
                tampilkanMenuWarna();
            } else if (pilihan_pencarian == 8) {
                
                beli(virtualmoney);
            } else if (pilihan_pencarian == 9) { // Added option 9 to return to the main menu
                // Do nothing, will exit the loop
            } else {
                cout << "Pilihan tidak valid. Silakan masukkan pilihan 1-9." << endl;
            }

        } while (pilihan_pencarian != 9);

      } else if (choice == 2) {
        beli(virtualmoney);
      } else if (choice == 3) {

        kranjang.tampilkanKeranjang();
      } else if (choice == 4) {
        kranjang.tampilkanKeranjang();

        int index;
        cout << "Masukkan indeks barang yang ingin cek out : ";

        cin >> index;

        kranjang.hapusDariKeranjang(index, virtualmoney);
      } else if (choice == 5) {
        kranjang.cetakIsiStack();
        cek.tampilkanRiwayatPembelianC();
        
      }
      else if (choice == 6) {
        kirim.cetakAntrean();
      }
      else if (choice == 7){
        pohon.cetakAntrean();
      }
    } while (choice != 8);
    cout << "program selesai" << endl;
    
  }

};

#endif // DINAMIS_H
