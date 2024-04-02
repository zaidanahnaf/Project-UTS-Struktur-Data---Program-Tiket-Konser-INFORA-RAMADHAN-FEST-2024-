#include <iostream>
#include <cstdlib>
#include <ctime>
#include <string>

using namespace std;

void menu();
void tambahDepan();
void tampil();

string kodeTkt(int panjangKode = 8) {
    const string karakter = "0123456789";
    string kodePesanan = "";
    int panjangKarakter = karakter.length();
    srand(time(0));

    for (int i = 0; i < panjangKode; i++) {
        kodePesanan += karakter[rand() % panjangKarakter];
    }
    return kodePesanan;
}

int pilihan;

struct simpul {
    char nama[50];
    string jenisTkt, telepon;
    int harga, kode;
    struct simpul *next;
} *baru, *awal = NULL, *akhir = NULL, *hapus, *bantu;

string dataKode[2] = {"REG", "VIP"};
int pesanTkt;

int main() {
    do {
        cout << "\t\t SELAMAT DATANG DI\t\t\n\t\tLOKET VIRTUAL BY ZAIDAN \t\t" << endl << endl;
        cout << "\t ==============***============\n\t | INFORA RAMADHAN FEST 2024 | \n\t =============================\n\n COMING SOON!" << endl << endl;
        cout << "\t Apakah anda ingin memesan tiket 'INFORA RAMADHAN FEST'? (1) Ya /(2) Tidak: ";
        cin >> pesanTkt;

        if (pesanTkt == 1) {
            menu();
        } else if (pesanTkt != 1 && pesanTkt != 2) {
            cout << "Input Salah!" << endl;
            system("CLS");
        }
    } while (pesanTkt != 2);
    return 0;
}

void menu() {
    cout << endl;
    cout << "\t\t\t ==============***============ \t\t\t" << endl;
    cout << "\t\t\t | INFORA RAMADHAN FEST 2024 |\t\t\t" << endl;
    cout << "\t\t\t ============================= \t\t\t" << endl;
    cout << "\t Menu Pembelian Tiket \t" << endl;
    cout << "\t -----------------------------------------------------------------\t" << endl;
    cout << "\t Jenis Tiket |     Harga     |             Keterangan             " << endl;
    cout << "\t Reguler     | Rp. 20.000,00 | Akses semua venue, Single Entry    " << endl;
    cout << "\t VIP         | Rp. 30.000,00 | Akses semua venue, Multiple Entry  " << endl;
    cout << "\t -----------------------------------------------------------------\t" << endl;
    cout << "\t Keluar(3)";
    cout << "\t Pesan Tiket (1) REGULER /(2) VIP: ";
    cin >> pilihan;

    char konfirmasi;
    switch (pilihan) {
        case 1:
            do {
                tambahDepan();
                cout << "Ingin memesan tiket 'Reguler' lagi? ";
                cin >> konfirmasi;
                if (konfirmasi != 'y' && konfirmasi != 'Y' && konfirmasi != 'n' && konfirmasi != 'N') {
                    cout << "Input salah!" << endl;
                    system("PAUSE");
                    break;
                }
            } while (konfirmasi != 'n' && konfirmasi != 'N');
            cout << "\nKembali ke menu...";
            system("CLS");
            break;

        case 2:
            do {
                tambahDepan();
                cout << "Ingin memesan tiket 'VIP' lagi? ";
                cin >> konfirmasi;
                if (konfirmasi != 'y' && konfirmasi != 'Y' && konfirmasi != 'n' && konfirmasi != 'N') {
                    cout << "Input salah!" << endl;
                    system("PAUSE");
                    break;
                }
            } while (konfirmasi != 'n' && konfirmasi != 'N');
            cout << "\nKembali ke menu...";
            system("CLS");
            break;
    }
}

void tambahDepan() {
    baru = new simpul;
    cout << "Masukkan nama dan nomor ponsel Anda!" << endl;
    cout << "Nama Lengkap: ";
    cin >> baru->nama;
    cout << endl;
    cout << "No. Handphone: ";
    cin >> baru->telepon;
    cout << endl;
    cout << "Jenis Tiket (1: REGULER, 2: VIP): ";
    cin >> baru->kode;
    cout << endl;
    baru->next = NULL;

    if (awal == NULL) {
        awal = baru;
        akhir = baru;
    } else {
        baru->next = awal;
        awal = baru;
    }
    cout << endl;
    tampil();
}

void tampil() {
    if (awal == NULL) {
        cout << "kosong";
    } else {
        bantu = awal;
        while (bantu != NULL) {
            cout << "\t TIKET PESANAN ANDA \t" << endl << endl;
            cout << "Nama Pemesan\t\t :" << bantu->nama << endl;
            cout << "No. Handphone\t\t :" << bantu->telepon << endl;
            cout << "Jenis Tiket\t\t :";
            if (bantu->kode == 1) {
                cout << "REGULER";
                bantu->harga = 20000;
                bantu->jenisTkt = dataKode[0];
            } else if (bantu->kode == 2) {
                cout << "VIP";
                bantu->harga = 30000;
                bantu->jenisTkt = dataKode[1];
            }
            cout << endl;
            cout << "Harga tiket\t\t :" << bantu->harga << endl;
            cout << "Kode Pesanan\t\t :" << bantu->jenisTkt << kodeTkt() << endl << endl;
            cout << "SEGERA LAKUKAN PEMBAYARAN DAN AMANKAN\t\t\n";
            cout << "\tTIKET ANDA!\t" << endl;
            bantu = bantu->next;
        }
    }
}
