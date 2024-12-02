
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
    
