 #ifndef BELIKRANJANG_H
 #define BELIKRANJANG_H
#include "1job/(input)/din
 #include <iostream>

 using namespace std;
 struct Item {
     string nama;
     double harga;
     int jumlah;
     Item* next;

     Item(const string& _nama, double _harga, int _jumlah)
         : nama(_nama), harga(_harga), jumlah(_jumlah), next(nullptr) {}
 };

 class Keranjang {
 public:
     Item* head;

     Keranjang() : head(nullptr) {}

     void tambahKeKeranjang(const string& nama, double harga, int jumlah) {
         Item* newItem = new Item(nama, harga, jumlah);
         if (!head) {
             head = newItem;
         } else {
             Item* current = head;
             while (current->next) {
                 current = current->next;
             }
             current->next = newItem;
         }
       tampilkanKeranjang();
     }

     void tampilkanKeranjang() {
         Item* current = head;
         while (current) {
             cout << "Nama: " << current->nama << ", Harga: " << current->harga << ", Jumlah: " << current->jumlah << endl;
             current = current->next;
         }
     }
 };
 #endif  BELIKRANJANG_H
