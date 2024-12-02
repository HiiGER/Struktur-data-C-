void tambahKeStack(const string &nama, double harga, int jumlah) {
    Itemkranjang *newItemkranjang = new Itemkranjang(nama, harga, jumlah);
    tempStack.push(newItemkranjang);
}
void cetakIsiStack() {
  if (tempStack.empty()) {
    cout << "Stack kosong." << endl;
    return;
  }

  stack<Itemkranjang *> temp = tempStack;

  cout << "Isi Stack:" << endl;
  int count = 1;
  while (!temp.empty()) {
    Itemkranjang *item = temp.top();
    cout << count << ". Nama: " << item->nama << ", Harga: " << item->harga
         << ", Jumlah: " << item->jumlah << endl;
    temp.pop();
    count++;
  }
}