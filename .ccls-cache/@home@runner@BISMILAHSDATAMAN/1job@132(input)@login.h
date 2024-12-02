#include <iostream>
#include <fstream>
#include <string>

using namespace std;

string loginUsername;
string loginPassword;

bool recursiveLogin(const string& filename) {
    ifstream inputFile(filename);
    if (!inputFile.is_open()) {
        cout << "Gagal membuka file " << filename << " untuk membaca." << endl;
        return false;
    }

    string storedUsername, storedPassword;
    if (inputFile >> storedUsername >> storedPassword) {
        if (storedUsername == loginUsername && storedPassword == loginPassword) {
            inputFile.close();
            return true;
        } else {
            // Panggil rekursi untuk mencari di sisa file
            return recursiveLogin(filename);
        }
    } else {
        inputFile.close();
        return false;
    }
}

void login() {
    cout << "=== Login ===" << endl;
    cout << "Masukkan username: ";
    cin >> loginUsername;
    cout << "Masukkan password: ";
    cin >> loginPassword;

    bool loginSuccessful = recursiveLogin("dataUserUP.txt");

    if (loginSuccessful) {
        cout << "Login berhasil!" << endl;
        // Tempatkan logika atau tindakan setelah login berhasil di sini.
    } else {
        cout << "Login gagal. Username atau password tidak valid." << endl;
    }
}

// Program ini tidak memiliki fungsi main.
// Program ini bisa diintegrasikan ke dalam program yang lebih besar atau
// dijalankan sebagai bagian dari modul lain.
