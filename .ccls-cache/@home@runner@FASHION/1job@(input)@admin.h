#ifndef ADMIN_H

#define ADMIN_H

#include <iostream>

#include <fstream>

#include <stack>

#include "pengiriman.h"

#include "Riwayatpembayaran.h"

#include <cstdlib>

#include <ctime>

using namespace std;
Pengiriman kirim;
PohonPembayaran pohon;

  struct Itemkranjang {
  
    string nama;
  
    double harga;
  
    int jumlah;

    int pil;
    Itemkranjang *next;
  
    Itemkranjang(const string &_nama, double _harga, int _jumlah,int _pil)
        : nama(_nama), harga(_harga), jumlah(_jumlah),pil(_pil), next(nullptr) {}
  };
  class Keranjang {
  private:
    string namaPembeli;
    string alamatPembeli;
    string noTelpPembeli;
  
    stack<Itemkranjang *> tempStack;
  
  public:
    Itemkranjang *head;
    
  
    Keranjang() : head(nullptr) {}
  
    void tambahKeKeranjang(const string &nama, double harga, int jumlah,int pil) {
  
      Itemkranjang *newItemkranjang = new Itemkranjang(nama, harga, jumlah, pil);
  
      if (!head) {
  
        head = newItemkranjang;
  
      } else {
  
        Itemkranjang *current = head;
  
        while (current->next) {
  
          current = current->next;
        }
  
        current->next = newItemkranjang;
      }
    }
  
    void tampilkanKeranjang() {
  
      Itemkranjang *current = head;
  
      if (!head) {
        cout << "Keranjang kosong." << endl;
        return;
      }
  
      while (current) {
        cout << "================================================================"
                "====================="
             << endl;
  
        cout << "Nama: " << current->nama << ", Harga satuan : " << current->harga
             << ", Jumlah yang di beli: " << current->jumlah << endl
             << endl;
  
        cout << "================================================================"
                "====================="
             << endl;
        current = current->next;
      }
    }
  
    void hapusDariKeranjang(const int &idx, int &virtualmoney) {
      int index = idx - 1;
  
      if (!head) {
        cout << "Keranjang kosong." << endl;
        return;
      }
  
      if (index < 0) {
        cout << "Indeks tidak valid." << endl;
        return;
      }
  
      Itemkranjang *current = head;
      int i = 0;
  
      while (current && i < index) {
        current = current->next;
        i++;
      }
  
      if (!current) {
        cout << "Indeks tidak valid." << endl;
        return;
      }
  
      // Periksa apakah virtualmoney cukup
      if (virtualmoney < current->harga * current->jumlah) {
        cout << "Virtual money tidak mencukupi." << endl;
        return;
      }
  
      // Kurangi virtualmoney
      virtualmoney -= current->harga * current->jumlah;
  
      // Panggil fungsi buatInvoice
      buatInvoice(current);
  
      // Hapus item dari keranjang
      if (index == 0) {
        head = head->next;
      } else {
        Itemkranjang *prev = head;
        while (prev->next != current) {
          prev = prev->next;
        }
        prev->next = current->next;
      }
  
      delete current;
      
      return;
    }
  
    void buatInvoice(Itemkranjang *item) {
      cout << "Masukkan nama lengkap: ";
      cin.ignore();
      getline(cin, namaPembeli);
  
      cout << "Masukkan alamat: ";
      getline(cin, alamatPembeli);
  
      cout << "Masukkan nomor telepon: ";
      cin >> noTelpPembeli;
  
      system("clear");
      cout << "======================================================" << endl;
      cout << "                Invoice" << endl;
      cout << "======================================================" << endl;
      cout << "Nama Pembeli: " << namaPembeli << endl;
      cout << "Alamat: " << alamatPembeli << endl;
      cout << "Nomor Telepon: " << noTelpPembeli << endl;
      cout << "======================================================" << endl;
  
      cout << "Nama: " << item->nama << ", Harga satuan: " << item->harga
           << ", Jumlah yang dibeli: " << item->jumlah << endl;
  
      cout << "==========================================" << endl;
      tambahKeStack(item->nama,item->harga,item->jumlah,item->pil);
      kirim.tambahAntrian(item->nama,item->harga,item->jumlah,item->pil);
      srand(static_cast<unsigned int>(time(0)));

      // Menghasilkan angka acak antara 10000 dan 99999
      int randomNumber = rand() % 90000 + 10000;

      pohon.tambahPembayaran(item->nama, item->harga, item->jumlah, randomNumber);
      
    }
  
    // stacckk////////////////////////////////////////////////////////// c\sek sekk ini dulu
    void tambahKeStack(const string &nama, double harga, int jumlah,int pil) {
        Itemkranjang *newItemkranjang = new Itemkranjang(nama, harga, jumlah,pil);
        tempStack.push(newItemkranjang);
    }

    void cetakIsiStack() {
      if (tempStack.empty()) {
        return;
      }

      stack<Itemkranjang *> temp = tempStack;

      cout << "==========================================" << endl;
      cout << "         Riwayat Pembelian" << endl;
      cout << "==========================================" << endl;

      int count = 1;
      while (!temp.empty()) {
        Itemkranjang *item = temp.top();
        cout << count << ". Nama: " << item->nama << ", Harga: " << item->harga
             << ", Jumlah: " << item->jumlah << endl;
        temp.pop();
        count++;
      }
    }
  };

struct cekout {

  string nama;

  double harga;

  int jumlah;

  int pil; 

  cekout *next;

  cekout(const string &_nama, double _harga, int _jumlah,int _pil)
      : nama(_nama), harga(_harga), jumlah(_jumlah), pil(_pil), next(nullptr) {}
};

class CHEKOUTT {
private:
  string namaPembeli;
  string alamatPembeli;
  string noTelpPembeli;

  stack<cekout *> riwayatPembelian;

public:
  cekout *head;

  CHEKOUTT() : head(nullptr) {}

  void tambahKeCHEKOUTT(const string &nama, double harga, int jumlah, int pil) {

    cekout *newcekout = new cekout(nama, harga, jumlah, pil);

    if (!head) {

      head = newcekout;

    } else {

      cekout *current = head;

      while (current->next) {

        current = current->next;
      }

      current->next = newcekout;
    }
    //simpanRiwayatPembelian(newcekout);
    tambahKeStack(nama, harga, jumlah,pil);
    kirim.tambahAntrian(nama,harga,jumlah,pil);
    
    srand(static_cast<unsigned int>(time(0)));
    // Menghasilkan angka acak antara 10000 dan 99999
    int randomNumber = rand() % 90000 + 10000;

    pohon.tambahPembayaran(nama,harga,jumlah,randomNumber);
    CHEKOUTInvoice(nama, harga, jumlah);

    hapusCHEKOUTT();
  }

  void hapusCHEKOUTT() {
    if (!head) {
      cout << "CHEKOUTT kosong." << endl;
      return;
    }
    cekout *temp = head;
    head = head->next;


    cout << "Item BERHASIL di CHEKOUTT" << endl;
    // simpanRiwayatPembelian(temp);
  }

  void CHEKOUTInvoice(const string &nama, double harga, int jumlah) {
    if (!head) {
      cout << "CHEKOUTT kosong. Tidak dapat membuat invoice." << endl;
      return;
    }

    cout << "Masukkan nama lengkap: ";
    cin.ignore();
    getline(cin, namaPembeli);

    cout << "Masukkan alamat: ";
    getline(cin, alamatPembeli);

    cout << "Masukkan nomor telepon: ";
    cin >> noTelpPembeli;

    system("clear");
    cout << "==========================================" << endl;
    cout << "                Invoice" << endl;
    cout << "==========================================" << endl;
    cout << "Nama Pembeli: " << namaPembeli << endl;
    cout << "Alamat: " << alamatPembeli << endl;
    cout << "Nomor Telepon: " << noTelpPembeli << endl;
    cout << "==========================================" << endl;

    cekout *current = head;
    while (current) {
      cout << "Nama: " << current->nama << ", Harga satuan: " << current->harga
           << ", Jumlah yang dibeli: " << current->jumlah << endl;
      current = current->next;
    }
    cout << "==========================================" << endl;

    cout << "Invoice telah dibuat." << endl;
    
  }

/////////////////////////////////////////////////////////////////////////////////
  void tambahKeStack(const string &nama, double harga, int jumlah,int pil) {
    cekout *newcekout = new cekout(nama, harga, jumlah,pil);
        riwayatPembelian.push(newcekout);
  }
  
  void tampilkanRiwayatPembelianC() {
   
    if (riwayatPembelian.empty()) {
      return;
    }

    stack<cekout *> tempStack = riwayatPembelian;
    while (!tempStack.empty()) {
      cekout *item = tempStack.top();
      cout << "Nama: " << item->nama << ", Harga satuan: " << item->harga
           << ", Jumlah: " << item->jumlah << endl;
      tempStack.pop();
    }

    cout << "==========================================" << endl;
  }
};
#endif
