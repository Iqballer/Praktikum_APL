#include <iostream>
#include <string>
using namespace std;


int tambahData(string mobil[], int jumlahData) {
    if (jumlahData >= 10) {
        cout << "Data mobil sudah penuh." << endl;
        return jumlahData;
    }

    cout << "Masukkan nama mobil: ";
    cin >> mobil[jumlahData];
    jumlahData++;
    cout << "Data mobil berhasil ditambahkan." << endl;


    char tambah;
    cout << "Tambahkan data mobil lagi? (y/n): ";
    cin >> tambah;
    if (tambah == 'y' || tambah == 'Y') {
        return tambahData(mobil, jumlahData); 
    } else {
        return jumlahData;
    }
}


void lihatData(string mobil[], int jumlahData) {
    cout << "List data mobil:" << endl;
    for (int i = 0; i < jumlahData; ++i) {
        cout << i + 1 << ". " << mobil[i] << endl;
    }
}

int updateData(string mobil[], int jumlahData) {
    cout << "Masukkan nomor mobil yang ingin diupdate: ";
    int nomor;
    cin >> nomor;

    if (nomor < 1 || nomor > jumlahData) {
        cout << "Nomor mobil tidak valid." << endl;
        return jumlahData;
    }

    cout << "Masukkan nama mobil baru: ";
    cin >> mobil[nomor - 1];
    cout << "Data mobil berhasil diupdate." << endl;
    return jumlahData;
}


int hapusData(string mobil[], int jumlahData) {
    cout << "Masukkan nomor mobil yang ingin dihapus: ";
    int nomor;
    cin >> nomor;

    if (nomor < 1 || nomor > jumlahData) {
        cout << "Nomor mobil tidak valid." << endl;
        return jumlahData;
    }

    for (int i = nomor - 1; i < jumlahData - 1; ++i) {
        mobil[i] = mobil[i + 1];
    }
    jumlahData--;
    cout << "Data mobil berhasil dihapus." << endl;
    return jumlahData;
}

int main() {
    string mobil[10];
    int jumlahData = 0;
    string nama;
    int percobaan = 0;
    int nim;

    while (percobaan < 3) {
        cout << "Masukan Username: ";
        cin >> nama;
        cout << "Masukan password(3 angka belakang NIM): ";
        cin >> nim;

        if (nama != "iqbal" || nim != 77) {
            cout << "Login gagal." << endl;
            percobaan++;
            if (percobaan == 3) {
                cout << "Percobaan login telah mencapai batas, Program berhenti." << endl;
                return 0; 
            }
        } else {
            cout << "Login Berhasil." << endl;
            break;
        }
    }

    while (true) {
        int pilihan;
        cout << "Menu Program Admin Penjualan Mobil" << endl;
        cout << "1. Tambah Data mobil baru." << endl;
        cout << "2. Update Data mobil." << endl;
        cout << "3. Lihat List data mobil" << endl;
        cout << "4. Hapus list data mobil" << endl;
        cout << "5. Keluar" << endl;
        cout << "Pilih menu: ";
        cin >> pilihan;

        switch (pilihan) {
            case 1:
                jumlahData = tambahData(mobil, jumlahData);
                break;
            case 2:
                jumlahData = updateData(mobil, jumlahData);
                break;
            case 3:
                lihatData(mobil, jumlahData);
                break;
            case 4:
                jumlahData = hapusData(mobil, jumlahData);
                break;
            case 5:
                cout << "Program berakhir." << endl;
                return 0;
            default:
                cout << "Menu tidak valid." << endl;
        }
    }

    return 0;
}
