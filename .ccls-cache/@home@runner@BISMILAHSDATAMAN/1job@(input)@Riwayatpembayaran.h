#ifndef RIWAYATPEMBAYARAN_H

#define RIWAYATPEMBAYARAN_H

#include <iostream>
#include <string>

using namespace std;

struct Pembayaran {
    string nama;
    double harga;
    int jumlah;
    int kode;

    Pembayaran(const string &_nama, double _harga, int _jumlah, int _kode)
        : nama(_nama), harga(_harga), jumlah(_jumlah), kode(_kode) {}
};

struct Node {
    Pembayaran data;
    Node *kiri;
    Node *kanan;

    Node(const Pembayaran &item) : data(item), kiri(nullptr), kanan(nullptr) {}
};

class PohonPembayaran {
private:
    Node *akar;

    void tambahNode(Node *&node, const Pembayaran &item) {
        if (node == nullptr) {
            node = new Node(item);
        } else {
            if (item.kode < node->data.kode) {
                tambahNode(node->kiri, item);
            } else {
                tambahNode(node->kanan, item);
            }
        }
    }

    void cetakAntrean(Node *node) {
        if (node != nullptr) {
            cetakAntrean(node->kiri);
            cout << "Nama: " << node->data.nama << ", Harga: " << node->data.harga << ", Kode pembayaran: " << node->data.kode << endl;
            cetakAntrean(node->kanan);
        }
    }

public:
    PohonPembayaran() : akar(nullptr) {}

    void tambahPembayaran(const string &nama, double harga, int jumlah, int kode) {
        Pembayaran newItem(nama, harga, jumlah, kode);
        tambahNode(akar, newItem);
    }

    void cetakAntrean() {
        cout << "Pohon Pembayaran:\n";
        cetakAntrean(akar);
    }
};

#endif