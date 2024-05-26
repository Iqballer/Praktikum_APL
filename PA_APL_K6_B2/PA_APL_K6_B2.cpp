#include <iostream>
#include <string>
#include <fstream>
#include <sstream>
#include <iomanip>
#include <limits>  

using namespace std;

struct Barang {
    int id;
    string nama;
    string merk;
    int harga;
    int jumlah;
};

Barang* barang = nullptr;
int jumlahBarang = 0; 
int kapasitas = 0; 

void tambahKapasitas() {
    int kapasitasBaru = kapasitas == 0 ? 10 : kapasitas * 2;
    Barang* barangBaru = new Barang[kapasitasBaru];

    for (int i = 0; i < jumlahBarang; ++i) {
        barangBaru[i] = barang[i];
    }

    delete[] barang;
    barang = barangBaru;
    kapasitas = kapasitasBaru;
}

void bacaCSV(const string& data) {
    ifstream file(data);
    if (!file.is_open()) {
        cout << "Gagal membuka file." << endl;
        return;
    }
    
    jumlahBarang = 0; 

    string line;
    while (getline(file, line)) {
        if (jumlahBarang >= kapasitas) {
            tambahKapasitas();
        }

        stringstream ss(line);
        string idStr, nama, merk, hargaStr, jumlahStr;

        getline(ss, idStr, ',');
        getline(ss, nama, ',');
        getline(ss, merk, ',');
        getline(ss, hargaStr, ',');
        getline(ss, jumlahStr, ',');

        barang[jumlahBarang].id = stoi(idStr);
        barang[jumlahBarang].nama = nama;
        barang[jumlahBarang].merk = merk;
        barang[jumlahBarang].harga = stoi(hargaStr);
        barang[jumlahBarang].jumlah = stoi(jumlahStr);
        jumlahBarang++;
    }
    file.close();
}

void tampilkanBarangDariCSV(const string& data) {
    ifstream file(data);
    if (!file.is_open()) {
        cout << "Gagal membuka file." << endl;
        return;
    }

    string line;
    cout << "Daftar Barang:\n";
    cout << "ID"<< setw(30) <<"Nama"<< setw(30) <<"Merk"<< setw(30) <<"Harga"<< setw(30) <<"Jumlah\n";
    while (getline(file, line)) {
        stringstream ss(line);
        string idStr, nama, merk, hargaStr, jumlahStr;

        getline(ss, idStr, ',');
        getline(ss, nama, ',');
        getline(ss, merk, ',');
        getline(ss, hargaStr, ',');
        getline(ss, jumlahStr, ',');

        cout << idStr << setw(30) << nama << setw(30) << merk << setw(30) << hargaStr << setw(30) << jumlahStr << endl;
    }
    file.close();
}

void tambahBarangKeCSV(const string& data) {
    ofstream file(data, ios::app); 
    if (!file.is_open()) {
        cerr << "Gagal membuka file: " << data << endl;
        return;
    }

    int id = jumlahBarang + 1; 
    string nama, merk;
    int harga, jumlah;

    cout << "Masukkan nama Barang: ";
    cin >> ws; 
    if (!getline(cin, nama) || nama.empty()) {
        cerr << "Input tidak valid untuk nama." << endl;
        return;
    }

    cout << "Masukkan merk Barang: ";
    if (!getline(cin, merk) || merk.empty()) {
        cerr << "Input tidak valid untuk merk." << endl;
        return;
    }

    cout << "Masukkan harga Barang: ";
    if (!(cin >> harga) || harga < 0) {
        cerr << "Input tidak valid untuk harga." << endl;
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n'); 
        return;
    }

    cout << "Masukkan jumlah Barang: ";
    if (!(cin >> jumlah) || jumlah < 0) {
        cerr << "Input tidak valid untuk jumlah." << endl;
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n'); 
        return;
    }

    file << id << "," << nama << "," << merk << "," << harga << "," << jumlah << endl;
    if (file.fail()) {
        cerr << "Gagal menulis ke file." << endl;
        return;
    }

    file.close();
    if (file.fail()) {
        cerr << "Gagal menutup file." << endl;
        return;
    }

    cout << "----------------------------------" << endl;
    cout << "Barang telah ditambahkan ke file." << endl;
    cout << "----------------------------------" << endl;

    try {
        if (jumlahBarang >= kapasitas) {
            tambahKapasitas();
        }

        barang[jumlahBarang].id = id;
        barang[jumlahBarang].nama = nama;
        barang[jumlahBarang].merk = merk;
        barang[jumlahBarang].harga = harga;
        barang[jumlahBarang].jumlah = jumlah;
        jumlahBarang++;
    } catch (const exception& e) {
        cerr << "Error: " << e.what() << endl;
    }
}


void ubahBarang(const string& data) {
    int cariID;
    cout << "Masukkan ID Barang yang ingin diubah: ";
    if (!(cin >> cariID)) {
        cerr << "Input tidak valid untuk ID." << endl;
        cin.clear();
        cin.ignore(10000, '\n'); 
        return;
    }
    cin.ignore(); 

    ifstream file(data);
    if (!file.is_open()) {
        cerr << "Gagal membuka file: " << data << endl;
        return;
    }

    bool ditemukan = false;

    while (!file.eof()) {
        string line;
        getline(file, line);
        if (line.empty()) break;

        stringstream ss(line);
        string idStr, nama, merk, hargaStr, jumlahStr;

        getline(ss, idStr, ',');
        getline(ss, nama, ',');
        getline(ss, merk, ',');
        getline(ss, hargaStr, ',');
        getline(ss, jumlahStr, ',');

        int id = stoi(idStr);
        if (id == cariID) {
            cout << "Masukkan nama Barang baru: ";
            if (!getline(cin, nama) || nama.empty()) {
                cerr << "Input tidak valid untuk nama." << endl;
                return;
            }
            cout << "Masukkan merk Barang baru: ";
            if (!getline(cin, merk) || merk.empty()) {
                cerr << "Input tidak valid untuk merk." << endl;
                return;
            }
            cout << "Masukkan harga Barang baru: ";
            if (!(cin >> hargaStr)) {
                cerr << "Input tidak valid untuk harga." << endl;
                cin.clear();
                cin.ignore(10000, '\n'); 
                return;
            }
            cout << "Masukkan jumlah Barang baru: ";
            if (!(cin >> jumlahStr)) {
                cerr << "Input tidak valid untuk jumlah." << endl;
                cin.clear();
                cin.ignore(10000, '\n'); 
                return;
            }
            cin.ignore(); 

            int harga = stoi(hargaStr);
            int jumlah = stoi(jumlahStr);

            for (int i = 0; i < jumlahBarang; ++i) {
                if (barang[i].id == id) {
                    barang[i].nama = nama;
                    barang[i].merk = merk;
                    barang[i].harga = harga;
                    barang[i].jumlah = jumlah;
                    ditemukan = true;
                    break;
                }
            }
        }
    }
    file.close();

    if (!ditemukan) {
        system("cls");
        cout << "Barang dengan ID tersebut tidak ditemukan." << endl;
        return;
    }

    ofstream outFile(data);
    if (!outFile.is_open()) {
        cerr << "Gagal membuka file: " << data << endl;
        return;
    }

    for (int i = 0; i < jumlahBarang; ++i) {
        outFile << barang[i].id << "," << barang[i].nama << "," << barang[i].merk << "," << barang[i].harga << "," << barang[i].jumlah << endl;
        if (outFile.fail()) {
            cerr << "Gagal menulis data barang ke file." << endl;
            outFile.close();
            return;
        }
    }
    outFile.close();
    if (outFile.fail()) {
        cerr << "Gagal menutup file." << endl;
        return;
    }
    system("cls");
    cout << "Barang dengan ID tersebut telah diubah." << endl;
  
}


void hapusBarang(const string& data) {
    int cariID;
    cout << "Masukkan ID Barang yang ingin dihapus: ";
    if (!(cin >> cariID)) {
        cerr << "Input tidak valid untuk ID." << endl;
        cin.clear();
        cin.ignore(10000, '\n'); 
        return;
    }

    bool ditemukan = false;
    int indexHapus = -1;

    
    for (int i = 0; i < jumlahBarang; ++i) {
        if (barang[i].id == cariID) {
            indexHapus = i;
            ditemukan = true;
            break;
        }
    }

    if (!ditemukan) {  
        system("cls");
        cout << "==========================================" << endl;
        cout << "Barang dengan ID tersebut tidak ditemukan." << endl;
        cout << "==========================================" << endl;
        system("cls");
        return;
    }

    
    for (int i = indexHapus; i < jumlahBarang - 1; ++i) {
        barang[i] = barang[i + 1];
    }
    jumlahBarang--;
    for (int i = 0; i < jumlahBarang; ++i) {
        barang[i].id = i + 1;
    }
    
    ofstream outFile(data);
    if (!outFile.is_open()) {
        cerr << "Gagal membuka file: " << data << endl;
        return;
    }

    
    for (int i = 0; i < jumlahBarang; ++i) {
        outFile << barang[i].id << "," << barang[i].nama << "," << barang[i].merk << "," << barang[i].harga << "," << barang[i].jumlah << endl;
        if (outFile.fail()) {
            cerr << "Gagal menulis data barang ke file." << endl;
            outFile.close();
            return;
        }
    }
    outFile.close();
    if (outFile.fail()) {
        cerr << "Gagal menutup file." << endl;
        return;
    }
    system("cls");
    cout << "========================================" << endl;
    cout << "Barang dengan ID tersebut telah dihapus." << endl;
    cout << "========================================" << endl;
    
}

void cariBarangDiFile(const string& data) {
    int cariID;
    cout << "Masukkan ID Barang yang ingin dicari: ";
    if (!(cin >> cariID)) {
        cerr << "Input tidak valid untuk ID." << endl;
        cin.clear();
        cin.ignore(10000, '\n'); // Abaikan input yang tidak valid
        return;
    }
    cin.ignore(); // Menangani karakter newline yang tersisa

    ifstream file(data);
    if (!file.is_open()) {
        cerr << "Gagal membuka file: " << data << endl;
        return;
    }

    bool ditemukan = false;

    while (!file.eof()) {
        string line;
        getline(file, line);
        if (line.empty()) break;

        stringstream ss(line);
        string idStr, nama, merk, hargaStr, jumlahStr;

        getline(ss, idStr, ',');
        getline(ss, nama, ',');
        getline(ss, merk, ',');
        getline(ss, hargaStr, ',');
        getline(ss, jumlahStr, ',');

        if (stoi(idStr) == cariID) {
            cout << "===================\n";
            cout << "Barang ditemukan:" << endl;
            cout << "===================\n";
            cout << "ID: " << idStr << endl;
            cout << "Nama: " << nama << endl;
            cout << "Merk: " << merk << endl;
            cout << "Harga: " << hargaStr << endl;
            cout << "Jumlah: " << jumlahStr << endl;
            ditemukan = true;
            break;
        }
    }
    file.close();

    if (!ditemukan) {
        system("cls");
        cout << "==========================================" << endl;
        cout << "Barang dengan ID tersebut tidak ditemukan." << endl;
        cout << "==========================================" << endl;
    }
}

bool login() {
    string username;
    string password;
    for (int i = 0; i < 3; i++) {
        cout << "=======================================" << endl;
        cout << "Selamat datang admin di Pekerjaan muu" << endl;
        cout << "=======================================" << endl;
        cout << "Masukkan username: ";
        getline(cin, username);
        cout << "Masukkan password: ";
        getline(cin, password);

        if (username == "Admin" && password == "Admin123") {
            cout << "================" << endl;
            cout << "Login berhasil!" << endl;
            cout << "================" << endl;
            system("pause");
            system("cls");  
            return true;
        } else {
            cout << "=================================================" << endl;
            cout << "Username atau Password salah. Silakan coba lagi." << endl;
            cout << "=================================================" << endl;
            system("pause");
            system("cls");
        }
    }
    cout << "======================================================" << endl;
    cout << "Anda telah mencoba login sebanyak 3 kali. Login gagal." << endl;
    cout << "======================================================" << endl;
    return false;
}

void menu(bool& running) {
    char pilihan;
    cout << "==========================================" << endl;
    cout << "Selamat datang di Menu yang ingin dipilih" << endl;
    cout << "==========================================" << endl;
    cout << "1. Tambah Barang\n";
    cout << "2. Tampilkan Barang\n";
    cout << "3. Ubah Barang\n";
    cout << "4. Hapus Barang\n";
    cout << "5. Cari Barang\n"; 
    cout << "6. Keluar\n"; 
    cout << "==========================================" << endl;
    cout << "Masukkan pilihan: "; 
    cin >> ws; // Membaca dan mengabaikan spasi putih sebelum input
    cin.get(pilihan);

    if (cin.fail() || pilihan == '\n') {
        cin.clear(); // clear input buffer to restore cin to a usable state
        cin.ignore(numeric_limits<streamsize>::max(), '\n'); // ignore last input
        cout << "Input tidak valid. Harap masukkan angka antara 1-6.\n";
        return;
    }

    switch (pilihan) {
        case '1':
            system("cls");
            tambahBarangKeCSV("console.csv");
            break;
        case '2':
            system("cls");
            tampilkanBarangDariCSV("console.csv");
            break;
        case '3':
            system("cls");
            ubahBarang("console.csv");
            break;
        case '4':
            system("cls");
            hapusBarang("console.csv");
            break;
        case '5':
            system("cls");
            cariBarangDiFile("console.csv");
            break; 
        case '6':
            cout << "===========================================" << endl;
            cout << "Terimakasih Telah Menggunakan Program Kami" << endl;
            cout << "===========================================" << endl;
            running = false; 
            break;
        default:
            system("cls");
            cout << "Pilihan tidak valid,Silahkan coba Lagi" << endl;
            cout << "==========================================" << endl;
            system("pause");
    }
}

int main() {
    string namaFile = "console.csv";
    bacaCSV(namaFile);
    if (login()) {
        bool running = true; 
        while (running) {
            menu(running); 
        }
    } else {
        cout << "Login gagal.\n";
    }

    delete[] barang; 
    return 0;
}
