#ifndef DINAMIS_H
#define DINAMIS_H

#include <iostream>
#include <stdexcept>
#include <string>
#include <fstream>
#define MAX_ITEMS 10

using namespace std;

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
  Array1Dstatis<int, 10> harga;
  Array1Dstatis<int, 10> stok;
};

class program {
public:
  Item items[MAX_ITEMS]; // Item items menjadi anggota kelas program

  void tampilkan() {
    system("clear");
    for (int i = 0; i < MAX_ITEMS; i++) {
      if (!items[i].nama.empty()) {
        cout << "=========================================================================="<< endl;
        cout << "Nama Barang :            " << items[i].nama << endl;
        cout << "kategori :               " << items[i].kategori << endl;
        cout << "=========================================================================="<< endl<< endl;

        cout << "Harga S (SMALL): " << items[i].harga[0]
             << "Stok : " << items[i].stok[0] << endl;
        cout << "--------------------------------------------------------------------------"<< endl;

        cout << "Harga M (MEDIUM): " << items[i].harga[1]
             << "Stok : " << items[i].stok[1] << endl;
        cout << "--------------------------------------------------------------------------"<< endl;

        cout << "Harga L (LARGE): " << items[i].harga[2]
             << "Stok : " << items[i].stok[2] << endl;
        cout << "--------------------------------------------------------------------------"<< endl;

        cout << "Harga XL (EXTRA LARGE): " << items[i].harga[3]
             << "Stok : " << items[i].stok[3] << endl;
        cout << "--------------------------------------------------------------------------"<< endl;

        cout << "Harga XXL (DOUBEL EXTRA LARGE): " << items[i].harga[4]
             << "Stok : " << items[i].stok[4] << endl;

        cout << "==========================================================================="<<endl;
      }
    }
  }

  void tampilkanMenuKategori() {
    int pillJUAL;
    cout << "|============================================================================|"<< endl;
    cout << "|                            Pilih kategori Fashion:                         |"<< endl;
    cout << "|============================================================================|"<< endl;
    cout << "|1. Baju Pria                                                                |"<< endl;
    cout << "|2. Baju Wanita                                                              |"<< endl;
    cout << "|3. Aksesoris                                                                |"<< endl;
    cout << "|4. Sepatu pria                                                              |"<< endl;
    cout << "|5. Sepatu wanita                                                            |"<< endl;
    cout << "|6. Skincare                                                                 |"<< endl;
    cout << "|============================================================================|"<<endl;
  }

  void pilihKategori() {
    tampilkanMenuKategori();
    int pilKategori;
    cout << "Masukkan pilihan kategori barang yang ingin di jual : ";cin >> pilKategori;

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
    }
  }

  void pilihBajupria() {
    system("clear");

      string kategori = "baju pria";

      tambah(kategori);

      ofstream file("kat_baju pria.txt", ios::app); // Membuka file dalam mode append
        if (file.is_open()) {
          for (int i = 0; i < MAX_ITEMS; i++) {
            if (!items[i].nama.empty()) {
              file << "=========================================================================="<< endl;
              file << "Nama Barang :            " << items[i].nama << endl;
              file << "kategori :               " << items[i].kategori << endl;
              file << "=========================================================================="<< endl<< endl;

              file << "Harga S (SMALL): " << items[i].harga[0]
                   << "Stok : " << items[i].stok[0] << endl;
              file << "--------------------------------------------------------------------------"<< endl;

              file << "Harga M (MEDIUM): " << items[i].harga[1]
                   << "Stok : " << items[i].stok[1] << endl;
              file << "--------------------------------------------------------------------------"<< endl;

              file << "Harga L (LARGE): " << items[i].harga[2]
                   << "Stok : " << items[i].stok[2] << endl;
              file << "--------------------------------------------------------------------------"<< endl;

              file << "Harga XL (EXTRA LARGE): " << items[i].harga[3]
                   << "Stok : " << items[i].stok[3] << endl;
              file << "--------------------------------------------------------------------------"<< endl;

              file << "Harga XXL (DOUBEL EXTRA LARGE): " << items[i].harga[4]
                   << "Stok : " << items[i].stok[4] << endl;

              file << "==========================================================================="<<endl;
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

      ofstream file("kat_Baju wanita.txt", ios::app); // Membuka file dalam mode append
        if (file.is_open()) {
          for (int i = 0; i < MAX_ITEMS; i++) {
            if (!items[i].nama.empty()) {
              file << "=========================================================================="<< endl;
              file << "Nama Barang :            " << items[i].nama << endl;
              file << "kategori :               " << items[i].kategori << endl;
              file << "=========================================================================="<< endl<< endl;

              file << "Harga S (SMALL): " << items[i].harga[0]
                   << "Stok : " << items[i].stok[0] << endl;
              file << "--------------------------------------------------------------------------"<< endl;

              file << "Harga M (MEDIUM): " << items[i].harga[1]
                   << "Stok : " << items[i].stok[1] << endl;
              file << "--------------------------------------------------------------------------"<< endl;

              file << "Harga L (LARGE): " << items[i].harga[2]
                   << "Stok : " << items[i].stok[2] << endl;
              file << "--------------------------------------------------------------------------"<< endl;

              file << "Harga XL (EXTRA LARGE): " << items[i].harga[3]
                   << "Stok : " << items[i].stok[3] << endl;
              file << "--------------------------------------------------------------------------"<< endl;

              file << "Harga XXL (DOUBEL EXTRA LARGE): " << items[i].harga[4]
                   << "Stok : " << items[i].stok[4] << endl;

              file << "==========================================================================="<<endl;
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

      ofstream file("kat_Aksesoris.txt", ios::app); // Membuka file dalam mode append
        if (file.is_open()) {
          for (int i = 0; i < MAX_ITEMS; i++) {
            if (!items[i].nama.empty()) {
              file << "=========================================================================="<< endl;
              file << "Nama Barang :            " << items[i].nama << endl;
              file << "kategori :               " << items[i].kategori << endl;
              file << "=========================================================================="<< endl<< endl;

              file << "Harga S (SMALL): " << items[i].harga[0]
                   << "Stok : " << items[i].stok[0] << endl;
              file << "--------------------------------------------------------------------------"<< endl;

              file << "Harga M (MEDIUM): " << items[i].harga[1]
                   << "Stok : " << items[i].stok[1] << endl;
              file << "--------------------------------------------------------------------------"<< endl;

              file << "Harga L (LARGE): " << items[i].harga[2]
                   << "Stok : " << items[i].stok[2] << endl;
              file << "--------------------------------------------------------------------------"<< endl;

              file << "Harga XL (EXTRA LARGE): " << items[i].harga[3]
                   << "Stok : " << items[i].stok[3] << endl;
              file << "--------------------------------------------------------------------------"<< endl;

              file << "Harga XXL (DOUBEL EXTRA LARGE): " << items[i].harga[4]
                   << "Stok : " << items[i].stok[4] << endl;

              file << "==========================================================================="<<endl;
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

      ofstream file("kat_Sepatu pria", ios::app); // Membuka file dalam mode append
        if (file.is_open()) {
            for (int i = 0; i < MAX_ITEMS; i++) {
              if (!items[i].nama.empty()) {
                file << "=========================================================================="<< endl;
                file << "Nama Barang :            " << items[i].nama << endl;
                file << "kategori :               " << items[i].kategori << endl;
                file << "=========================================================================="<< endl<< endl;

                file << "Harga S (SMALL): " << items[i].harga[0]
                     << "Stok : " << items[i].stok[0] << endl;
                file << "--------------------------------------------------------------------------"<< endl;

                file << "Harga M (MEDIUM): " << items[i].harga[1]
                     << "Stok : " << items[i].stok[1] << endl;
                file << "--------------------------------------------------------------------------"<< endl;

                file << "Harga L (LARGE): " << items[i].harga[2]
                     << "Stok : " << items[i].stok[2] << endl;
                file << "--------------------------------------------------------------------------"<< endl;

                file << "Harga XL (EXTRA LARGE): " << items[i].harga[3]
                     << "Stok : " << items[i].stok[3] << endl;
                file << "--------------------------------------------------------------------------"<< endl;

                file << "Harga XXL (DOUBEL EXTRA LARGE): " << items[i].harga[4]
                     << "Stok : " << items[i].stok[4] << endl;

                file << "==========================================================================="<<endl;
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

      ofstream file("kat_Sepatu Wanita.txt", ios::app); // Membuka file dalam mode append
        if (file.is_open()) {
            for (int i = 0; i < MAX_ITEMS; i++) {
              if (!items[i].nama.empty()) {
                file << "=========================================================================="<< endl;
                file << "Nama Barang :            " << items[i].nama << endl;
                file << "kategori :               " << items[i].kategori << endl;
                file << "=========================================================================="<< endl<< endl;

                file << "Harga S (SMALL): " << items[i].harga[0]
                     << "Stok : " << items[i].stok[0] << endl;
                file << "--------------------------------------------------------------------------"<< endl;

                file << "Harga M (MEDIUM): " << items[i].harga[1]
                     << "Stok : " << items[i].stok[1] << endl;
                file << "--------------------------------------------------------------------------"<< endl;

                file << "Harga L (LARGE): " << items[i].harga[2]
                     << "Stok : " << items[i].stok[2] << endl;
                file << "--------------------------------------------------------------------------"<< endl;

                file << "Harga XL (EXTRA LARGE): " << items[i].harga[3]
                     << "Stok : " << items[i].stok[3] << endl;
                file << "--------------------------------------------------------------------------"<< endl;

                file << "Harga XXL (DOUBEL EXTRA LARGE): " << items[i].harga[4]
                     << "Stok : " << items[i].stok[4] << endl;

                file << "==========================================================================="<<endl;
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

      ofstream file("kat_Skin care.txt", ios::app); // Membuka file dalam mode append
        if (file.is_open()) {
            for (int i = 0; i < MAX_ITEMS; i++) {
              if (!items[i].nama.empty()) {
                file << "=========================================================================="<< endl;
                file << "Nama Barang :            " << items[i].nama << endl;
                file << "kategori :               " << items[i].kategori << endl;
                file << "=========================================================================="<< endl<< endl;

                file << "Harga S (SMALL): " << items[i].harga[0]
                     << "Stok : " << items[i].stok[0] << endl;
                file << "--------------------------------------------------------------------------"<< endl;

                file << "Harga M (MEDIUM): " << items[i].harga[1]
                     << "Stok : " << items[i].stok[1] << endl;
                file << "--------------------------------------------------------------------------"<< endl;

                file << "Harga L (LARGE): " << items[i].harga[2]
                     << "Stok : " << items[i].stok[2] << endl;
                file << "--------------------------------------------------------------------------"<< endl;

                file << "Harga XL (EXTRA LARGE): " << items[i].harga[3]
                     << "Stok : " << items[i].stok[3] << endl;
                file << "--------------------------------------------------------------------------"<< endl;

                file << "Harga XXL (DOUBEL EXTRA LARGE): " << items[i].harga[4]
                     << "Stok : " << items[i].stok[4] << endl;

                file << "==========================================================================="<<endl;
              }
            }
          file.close();
          cout << "Konten berhasil disimpan!" << endl;

        } else {
          cout << "Gagal membuka file konten." << endl;
        }
  }




  void tambah(const string &kategori) {
    for (int i = 0; i < MAX_ITEMS; i++) {
      if (items[i].nama.empty()) {
        cout << "Nama Barang: ";cin.ignore();
        getline(cin, items[i].nama);
        items[i].kategori = kategori;

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
        break;
      }
    }
  }

  void beli() {
    system("clear");
    tampilkan();
    string itemToBuy;
    int amount;
    cout << "Masukkan nama barang yang akan dibeli: ";
    cin.ignore();
    getline(cin, itemToBuy);
    for (int i = 0; i < MAX_ITEMS; i++) {
      if (items[i].nama == itemToBuy) {
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
              cout << "Pembelian berhasil!" << endl;
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
      }else{
        cout << "nama barang tidak tersedia"<<endl;
        beli();
      }
    }
  }

  void mainSTADIS() {
    int choice;
    do {
      cout << "Menu:" << endl;
      cout << "1. Perlihatkan Stok" << endl;
      cout << "2. Beli" << endl;
      cout << "3. logout" << endl;
      cout << "Pilihan: ";
      cin >> choice;
      if (choice == 1) {
        tampilkan();
      } else if (choice == 2) {
        beli();
      }
    } while (choice != 3);
    cout << "program selesai" << endl;
  }
};
#endif // DINAMIS_H
