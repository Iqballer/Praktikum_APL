#include <iostream>
#include <string>
using namespace std;

int main() {
    string mobil[10] = {"Honda Jazz","Toyota Fortuner","Suzuki SX4"};
    int jumlahData = 3;
    string nama;
    int percobaan = 0; // Inisialisasi penghitung percobaan login
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
                return 0; // Keluar dari program
            }
        } else {
            cout << "Login Berhasil." << endl;
            break;
        }
    }

    while (true) {
        int pilihan;
        cout << " " << endl;
        cout << "Menu Program Admin Penjualan Mobil" << endl;
        cout << "1. Tambah Data mobil baru." << endl;
        cout << "2. Lihat List data mobil" << endl;
        cout << "3. Update Data mobil." << endl;
        cout << "4. Hapus list data mobil" << endl;
        cout << "5. Keluar" << endl;
        cout << "Pilih menu: ";
        cin >> pilihan;
        cout << " " << endl;

        switch (pilihan) {
            case 1:
                if(jumlahData >= 10){
                    cout << "Jumlah data mobil sudah penuh";
                    break;
                }

                cout << "Masukan nama mobil: ";
                cin >> mobil[jumlahData];
                cout << "Data mobil sudah ditambahkan." << endl;
                jumlahData++;
                break;
            case 2:
                cout << "List Data mobil yang tersedia." << endl;
                for(int i=0;i < jumlahData;++i){
                    cout << i + 1 << ". " << mobil[i] << endl;
                }
                break;
            case 3:
                int nomor_update;
                cout << "masukan nomor mobil yang ingin di update: ";
                cin >> nomor_update;

                if(nomor_update < 1 || nomor_update > jumlahData){
                    cout << "Nomor mobil tidak valid." << endl;
                    break;
                }

                cout << "Masukan nama mobil baru: ";
                cin >> mobil[nomor_update - 1];
                cout << "Data mobil berhasil di update." << endl;
                break;
            case 4:
                int nomor_hapus;
                cout << "Masukan nomor mobil yang ingin dihapus: ";
                cin >> nomor_hapus;

                if(nomor_hapus < 1 || nomor_hapus > jumlahData){
                    cout << "Nomor mobil tidak valid." << endl;
                    break;
                }

                for(int i = nomor_hapus - 1;i < jumlahData - 1;++i){
                    mobil[i]=mobil[i+1];
                }
                jumlahData--;
                cout << "data mobil berhasil dihapus." << endl;
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
