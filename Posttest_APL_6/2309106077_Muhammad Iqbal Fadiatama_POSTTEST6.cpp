#include <iostream>
#include <string>
#include <limits>
using namespace std;

struct Mobil {
    string nama;
    int tahun;
    string merek;
};

int tambahData(Mobil mobil[], int jumlahData) {
    if (jumlahData >= 10) {
        cout << "Data mobil sudah penuh." << endl;
        return jumlahData;
    }

    cout << "Masukkan nama mobil: ";
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
    getline(cin, (mobil + jumlahData)->nama);

    while (true) {
        cout << "Masukkan tahun mobil: ";
        if (!(cin >> (mobil + jumlahData)->tahun)) {
            cout << "Input tahun tidak valid. Harap masukkan angka." << endl;
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
        } else {
            break;
        }
    }

    cout << "Masukkan merek mobil: ";
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
    getline(cin, (mobil + jumlahData)->merek);
    
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

void lihatData(Mobil mobil[], int jumlahData) {
    if (jumlahData == 0) {
        cout << "Tidak ada data mobil." << endl;
        return;
    }
    cout << "List data mobil:" << endl;
    for (int i = 0; i < jumlahData; ++i) {
        cout << i + 1 << ". Nama: " << (mobil + i)->nama << ", Tahun: " << (mobil + i)->tahun << ", Merek: " << (mobil + i)->merek << endl;
    }
}

void quickSort(Mobil mobil[], int left, int right) {
    int i = left, j = right;
    string pivot = mobil[(left + right) / 2].nama;

    while (i <= j) {
        while (mobil[i].nama < pivot)
            i++;
        while (mobil[j].nama > pivot)
            j--;
        if (i <= j) {
            swap(mobil[i], mobil[j]);
            i++;
            j--;
        }
    }
    if (left < j)
        quickSort(mobil, left, j);
    if (i < right)
        quickSort(mobil, i, right);
}

void bubbleSort(Mobil mobil[], int jumlahData) {
    for (int i = 0; i < jumlahData - 1; ++i) {
        for (int j = 0; j < jumlahData - i - 1; ++j) {
            if (mobil[j].tahun < mobil[j + 1].tahun) {
                swap(mobil[j], mobil[j + 1]);
            }
        }
    }
}

void insertionSort(Mobil mobil[], int jumlahData) {
    for (int i = 1; i < jumlahData; ++i) {
        Mobil temp = mobil[i];
        int j = i - 1;
        while (j >= 0 && mobil[j].tahun > temp.tahun) {
            mobil[j + 1] = mobil[j];
            j--;
        }
        mobil[j + 1] = temp;
    }
}

int binarySearch(Mobil mobil[], int jumlahData, int tahunCari) {
    int kiri = 0;
    int kanan = jumlahData - 1;
    while (kiri <= kanan) {
        int tengah = kiri + (kanan - kiri) / 2;
        if (mobil[tengah].tahun == tahunCari) {
            return tengah;
        }
        if (mobil[tengah].tahun < tahunCari) {
            kiri = tengah + 1;
        } else {
            kanan = tengah - 1;
        }
    }
    return -1;
}

int interpolationSearch(Mobil mobil[], int jumlahData, int tahunCari) {
    int kiri = 0;
    int kanan = jumlahData - 1;
    while (kiri <= kanan && tahunCari >= mobil[kiri].tahun && tahunCari <= mobil[kanan].tahun) {
        int pos = kiri + ((double)(kanan - kiri) / (mobil[kanan].tahun - mobil[kiri].tahun)) * (tahunCari - mobil[kiri].tahun);
        if (mobil[pos].tahun == tahunCari) {
            return pos;
        }
        if (mobil[pos].tahun < tahunCari) {
            kiri = pos + 1;
        } else {
            kanan = pos - 1;
        }
    }
    return -1;
}

int updateData(Mobil mobil[], int jumlahData) {
    if (jumlahData == 0) {
        cout << "Tidak ada data mobil untuk diupdate." << endl;
        return jumlahData;
    }

    cout << "Masukkan nomor mobil yang ingin diupdate: ";
    int nomor;
    if (!(cin >> nomor) || nomor < 1 || nomor > jumlahData) {
        cout << "Nomor mobil tidak valid." << endl;
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        return jumlahData;
    }

    cout << "Masukkan nama mobil baru: ";
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
    getline(cin, (mobil + nomor - 1)->nama);

    while (true) {
        cout << "Masukkan tahun mobil baru: ";
        if (!(cin >> (mobil + nomor - 1)->tahun)) {
            cout << "Input tahun tidak valid. Harap masukkan angka." << endl;
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
        } else {
            break;
        }
    }

    cout << "Masukkan merek mobil baru: ";
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
    getline(cin, (mobil + nomor - 1)->merek);

    cout << "Data mobil berhasil diupdate." << endl;
    return jumlahData;
}

int hapusData(Mobil mobil[], int jumlahData) {
    if (jumlahData == 0) {
        cout << "Tidak ada data mobil untuk dihapus." << endl;
        return jumlahData;
    }

    cout << "Masukkan nomor mobil yang ingin dihapus: ";
    int nomor;
    if (!(cin >> nomor) || nomor < 1 || nomor > jumlahData) {
        cout << "Nomor mobil tidak valid." << endl;
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        return jumlahData;
    }

    for (int i = nomor - 1; i < jumlahData - 1; ++i) {
        *(mobil + i) = *(mobil + i + 1);
    }
    jumlahData--;
    cout << "Data mobil berhasil dihapus." << endl;
    return jumlahData;
}

int main() {
    Mobil mobil[10];
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
        cout << " " << endl;
        cout << "Menu Program Admin Penjualan Mobil" << endl;
        cout << "1. Tambah Data mobil baru." << endl;
        cout << "2. Update Data mobil." << endl;
        cout << "3. Lihat List data mobil" << endl;
        cout << "4. Hapus list data mobil" << endl;
        cout << "5. Sort Data Mobil (Berdasarkan Nama)" << endl;
        cout << "6. Sort Data Mobil (Berdasarkan Tahun Muda)" << endl;
        cout << "7. Sort Data Mobil (Berdasarkan Tahun Tua)" << endl;
        cout << "8. Cari Data Berdasarkan Tahun Mobil (Binary Search)" << endl;
        cout << "9. Cari Data Berdasarkan Tahun Mobil(Interpolation Search)" << endl;
        cout << "10. Keluar" << endl;
        cout << "Pilih menu: ";
        if (!(cin >> pilihan)) {
            cout << "Input tidak valid. Harap masukkan angka." << endl;
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            continue;
        }

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
                quickSort(mobil, 0, jumlahData - 1);
                cout << "Data mobil berhasil diurutkan berdasarkan nama." << endl;
                break;
            case 6:
                bubbleSort(mobil ,jumlahData);
                cout << "Data mobil berhasil diurutkan berdasarkan tahun secara descending." << endl;
                break;
            case 7:
                insertionSort(mobil ,jumlahData);
                cout << "Data mobil berhasil diurutkan berdasarkan tahun secara ascending." << endl;
                break;
            case 8: {
               int tahunCari;
                cout << "Masukkan tahun mobil yang ingin dicari: ";
                cin >> tahunCari;
                int hasilBinary = binarySearch(mobil, jumlahData, tahunCari);
                if (hasilBinary != -1) {
                    cout << "Data ditemukan pada indeks: " << hasilBinary << endl;
                    cout << "Nama: " << mobil[hasilBinary].nama << ", Tahun: " << mobil[hasilBinary].tahun << ", Merek: " << mobil[hasilBinary].merek << endl;
                } else {
                    cout << "Data tidak ditemukan." << endl;
                }
                break;
            }
            case 9: {
                 int tahunCari;
                cout << "Masukkan tahun mobil yang ingin dicari: ";
                cin >> tahunCari;
                int hasilInterpolation = interpolationSearch(mobil, jumlahData, tahunCari);
                if (hasilInterpolation != -1) {
                    cout << "Data ditemukan pada indeks: " << hasilInterpolation << endl;
                    cout << "Nama: " << mobil[hasilInterpolation].nama << ", Tahun: " << mobil[hasilInterpolation].tahun << ", Merek: " << mobil[hasilInterpolation].merek << endl;
                } else {
                    cout << "Data tidak ditemukan." << endl;
                }
                break;
            }
            case 10:
                cout << "Program berakhir." << endl;
                return 0;
            default:
                cout << "Menu tidak valid." << endl;
        }
    }

    return 0;
}
