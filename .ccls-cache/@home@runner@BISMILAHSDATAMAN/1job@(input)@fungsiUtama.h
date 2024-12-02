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
            cout << "Nama: " << node->data.nama << ", Harga: " << node->data.harga
                 << ", Jumlah: " << node->data.jumlah << ", Kode: " << node->data.kode << endl;
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

int main() {
    PohonPembayaran pohon;

    // Menambahkan beberapa data pembayaran
    pohon.tambahPembayaran("Produk A", 150.0, 2, 123);
    pohon.tambahPembayaran("Produk B", 200.0, 1, 456);
    pohon.tambahPembayaran("Produk C", 100.0, 3, 789);

    // Menampilkan pohon pembayaran
    pohon.cetakAntrean();

    return 0;
}
