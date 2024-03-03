#include <iostream>
using namespace std;

int main(){
    int nim;
    string nama;
    int percobaan;
    
    do {
        percobaan = 0;
        while(percobaan < 3){
            cout << "Masukan Username: ";
            cin >> nama;
            cout << "Masukan Password(3 angka belakang NIM): ";
            cin >> nim;
            if(nama == "iqbal" && nim == 77){
                cout << "Login Berhasil" << endl;
                cout << " " << endl;
            
                cout << "Menu Konversi Kecepatan" << endl;
                cout << "1. Konversi Kilometer/jam ke (Centimeter/detik, Meter/detik, Mil/jam)" << endl;
                cout << "2. Konversi Centimeter/detik ke (Kilometer/jam, Meter/detik, Mil/jam)" << endl;
                cout << "3. Konversi Meter/detik ke (Kilometer/jam, Meter/detik, Mil/jam)" << endl;
                cout << "4. Konversi Mil/jam ke (Kilometer/jam, Centimeter/detik, Meter/detik)" << endl;
                cout << " " << endl;

                int pilihan;
                cout << "Masukan Pilihan: ";
                cin >> pilihan;

                double kecepatan;
                double cmperdetik, mperdetik, milperjam, kmperjam;
                switch(pilihan) {
                    case 1:
                        cout << "Masukan Kecepatan dalam Kilometer/jam: ";
                        cin >> kecepatan;
                        cmperdetik = kecepatan * 100000 / 3600;
                        mperdetik = kecepatan * 1000 / 3600;
                        milperjam = kecepatan / 1.60934;
                        cout << "Centimeter/detik = " << cmperdetik << "cm/detik" << endl;
                        cout << "Meter/detik = " << mperdetik << "m/detik" << endl;
                        cout << "Mil/jam = " << milperjam << "mil/jam" << endl;
                        break;
                    case 2:
                        cout << "Masukan kecepatan dalam Centimeter/detik: ";
                        cin >> kecepatan;
                        kmperjam = kecepatan * 0.036;
                        mperdetik = kecepatan / 100;
                        milperjam = kecepatan *  0.0223694;
                        cout << "Kilometer/jam = " << kmperjam << "km/jam" << endl;
                        cout << "Meter/detik = " << mperdetik << "m/detik" << endl;
                        cout << "Mil/jam = " << milperjam << "mil/jam" << endl;
                        break;
                    case 3:
                        cout << "Masukan Kecepatan dalam Meter/detik: ";
                        cin >> kecepatan;
                        kmperjam = kecepatan * 3.6;
                        cmperdetik = kecepatan * 100;
                        milperjam = kecepatan * 2.23694;
                        cout << "Kilometer/jam = " << kmperjam << "km/jam" << endl;
                        cout << "Centimeter/detik = " << cmperdetik << "cm/detik" << endl;
                        cout << "Mil/jam = " << milperjam << "mil/jam" << endl;
                        break;
                    case 4:
                        cout << "Masukan kecepatan dalam Mil/jam: ";
                        cin >> kecepatan;
                        kmperjam = kecepatan * 1.60934;
                        mperdetik = kecepatan * 0.44704;
                        cmperdetik = kecepatan * 44.704;
                        cout << "Kilometer/jam = " << kmperjam << "km/jam" << endl;
                        cout << "Meter/detik = " << mperdetik << "m/detik" << endl;
                        cout << "Centimeter/detik = " << cmperdetik << "cm/detik" << endl;
                        break;
                    default:
                        cout << "Pilihan tidak valid" << endl;

                }
                break;
            } else{
            cout << "Nama atau Password salah,silahkan coba lagi." << endl;
            percobaan++;
            }
        }
        if(percobaan == 3) {
            cout << "Login telah mencapai batas, Program berhenti";
            break;
        }
        char ulangi;
        cout << "Apakah Anda ingin menjalankan program lagi? (y/n): ";
        cin >> ulangi;
        if (ulangi != 'y' && ulangi != 'Y') {
            break;
        }
    } while (true);
    
    
    return 0;
}