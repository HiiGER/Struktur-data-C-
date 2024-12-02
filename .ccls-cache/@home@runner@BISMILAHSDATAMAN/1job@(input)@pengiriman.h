#ifndef PENGIRIMAN_H

#define PENGIRIMAN_H

#include <iostream>
#include <queue>
#include <vector>

using namespace std;

struct ItemKeranjang {
    string nama;
    double harga;
    int jumlah;
    int pil;

    ItemKeranjang(const string &_nama, double _harga, int _jumlah, int _pil)
        : nama(_nama), harga(_harga), jumlah(_jumlah), pil(_pil) {}
};

class Pengiriman {
private:
    struct ItemCompare {
        bool operator()(const ItemKeranjang &item1, const ItemKeranjang &item2) {
            // Gunakan pil sebagai kriteria prioritas
            return item1.pil < item2.pil;
        }
    };

    priority_queue<ItemKeranjang, vector<ItemKeranjang>, ItemCompare> antrianPrioritas;

public:
    void tambahAntrian(const string &nama, double harga, int jumlah, int pil) {
      ItemKeranjang *newItemKeranjang = new ItemKeranjang(nama, harga, jumlah, pil);
      antrianPrioritas.push(*newItemKeranjang);
    }


    void cetakAntrean() {
      cout << "Antrian Prioritas Pengiriman:\n";

      // Salin antrianPrioritas ke antrianSementara agar dapat mencetak elemen-elemen antrianPrioritas tanpa menghapusnya.
      priority_queue<ItemKeranjang, vector<ItemKeranjang>, ItemCompare> antrianSementara = antrianPrioritas;

      while (!antrianSementara.empty()) {
          ItemKeranjang item = antrianSementara.top();
          cout << "Nama: " << item.nama << ", Harga: " << item.harga << ", Jumlah: " << item.jumlah << ", Promo: " << item.pil << "\n";
          antrianSementara.pop();
      }
    }

};
#endif



