#include <iostream>
#include <string.h>
#include <cstdlib>

using namespace std;

string nama, telepon;

int main() {
    int pesanTkt;
    do {
        cout << endl;
        cout << "\t\t\t ==============***============ \t\t\t" << endl;
        cout << "\t\t\t | INFORA RAMADHAN FEST 2024 |\t\t\t" << endl;
        cout << "\t\t\t ============================= \t\t\t" << endl;
        cout << "\t Menu Pembelian Tiket \t" << endl;
        cout << "\t -----------------------------------------------------------------\t" << endl;        cout << "\t Jenis Tiket |     Harga     |             Keterangan             " << endl;
        cout << "\t Reguler     | Rp. 20.000,00 | Akses semua venue, Single Entry    " << endl;
        cout << "\t VIP         | Rp. 30.000,00 | Akses semua venue, Multiple Entry  " << endl;
        cout << "\t -----------------------------------------------------------------\t" << endl;
        cout << "\t Keluar(3)";
        cout << "\t Pesan Tiket (1)/(2): ";
        cin >> pesanTkt;;

        char konfirmasi;
        switch (pesanTkt) {
        do{
            case 1:
            cout << "Ingin memesan tiket 'Reguler'? ";
            cin >> konfirmasi;
            if (konfirmasi == 'y' || konfirmasi == 'Y') {
                cout << "Masukkan nama dan nomor ponsel Anda!" << endl;
                cout << "Nama Lengkap: ";
                cin >> nama;
                cout << endl;
                cout << "No. Handphone: ";
                cin >> telepon;
                cout << "Pesanan telah dibuat, segera melakukan pembayaran\nuntuk mendapatkan tiket!";
            } else {
                cout << "Input salah!";
            }
        }while (konfirmasi == 'n' || konfirmasi == 'N');
            cout << "\nKembali ke menu...";
        }
    }while (pesanTkt != 3);
}
