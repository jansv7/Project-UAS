#include<iostream>
#include<vector>
using namespace std;

struct Makanan {
    string jenisMakanan;
    double harga;
};

struct Minuman {
    string jenisMinuman;
    double harga;
};

int const JUMLAH_MAKANAN=10;
Makanan menuMakanan[JUMLAH_MAKANAN]={
    {"Mie Ayam Ambaritma", 13000},
    {"Bubur Ambaritma", 10000},
    {"Bakso Ambaritma", 15000},
    {"Nasi Omelet Ambaritma", 13000},
    {"Siomay Ambaritma", 10000},
    {"Soto Ayam Ambaritma", 12000},
    {"Nasi Uduk Ambaritma", 7000},
    {"Nasi Kuning Ambaritma", 7000},
    {"Nasi Goreng Ambaritma", 15000},
    {"Batagor Ambaritma", 10000},
};

int const JUMLAH_MINUMAN=6;
Minuman menuMinuman[JUMLAH_MINUMAN]={
    {"Air Mineral Ambaritma", 5000},
    {"Es Teh Manis Ambaritma", 5000},
    {"Es Milo Ambaritma", 10000},
    {"Thai Tea Ambaritma", 10000},
    {"Lemon Tea Ambaritma", 7000},
    {"Green Tea Ambaritma", 10000},
};

void tampilkanMenuMakanan(){
    cout<<"Menu Makanan Kami:"<<endl;
    for(int i=0; i<JUMLAH_MAKANAN; i++) {
        cout<<i+1<<". "<<menuMakanan[i].jenisMakanan<<": Rp "<<menuMakanan[i].harga<<endl;
    }
}

void tampilkanMenuMinuman(){
    cout<<"Menu Minuman Kami:"<<endl;
    for(int i=0; i<JUMLAH_MINUMAN; i++) {
        cout<<i+1<<". "<<menuMinuman[i].jenisMinuman<<": Rp "<<menuMinuman[i].harga<<endl;
    }
}

int main(){
    int pilihan;
    int pemilihanPesanan;
    double totalHarga=0;
    vector<string> daftarPesananMakanan;
    vector<string> daftarPesananMinuman;

    while (true) {
        system("CLS");
        cout<<"----------Selamat Datang di Kantin Ambaritma----------"<<endl;
        cout<<"Mau pesen apa nich??"<<endl;
        cout<<"1. Makanan"<<endl;
        cout<<"2. Minuman"<<endl;
        cout<<"0. Selesai dan Lihat Pesanan"<<endl;
        cout<<"Masukkan pilihan kamu yahh (1/2/0): ";
        cin>>pilihan;

        if (pilihan == 1) {
            system("CLS");
            cout<<"Silahkan pilih makanan mu broo!"<<endl;
            tampilkanMenuMakanan();
            cout<<"Masukkan nomor makanan yang mau dibeli broo (0 untuk kembali ke menu utama): ";
            cin>>pemilihanPesanan;
            if(pemilihanPesanan>0 && pemilihanPesanan<=JUMLAH_MAKANAN) {
                totalHarga += menuMakanan[pemilihanPesanan-1].harga;
                daftarPesananMakanan.push_back(menuMakanan[pemilihanPesanan-1].jenisMakanan);
                cout<<menuMakanan[pemilihanPesanan-1].jenisMakanan<<" telah ditambahkan."<<endl;
            } else if(pemilihanPesanan!=0) {
                cout<<"Pilihan tidak valid broo, coba lagi!"<<endl;
            }
            system("pause");

        } else if (pilihan == 2) {
            system("CLS");
            cout<<"Silahkan pilih minuman mu broo!"<<endl;
            tampilkanMenuMinuman();
            cout<<"Masukkan nomor minuman yang mau dibeli broo (0 untuk kembali ke menu utama): ";
            cin>>pemilihanPesanan;
            if(pemilihanPesanan>0 && pemilihanPesanan<=JUMLAH_MINUMAN) {
                totalHarga += menuMinuman[pemilihanPesanan-1].harga;
                daftarPesananMinuman.push_back(menuMinuman[pemilihanPesanan-1].jenisMinuman);
                cout<<menuMinuman[pemilihanPesanan-1].jenisMinuman<<" telah ditambahkan."<<endl;
            } else if(pemilihanPesanan!=0) {
                cout<<"Pilihan tidak valid broo, coba lagi!"<<endl;
            }
            system("pause");

        } else if (pilihan == 0) {
            system("CLS");
            cout<<"==================================="<<endl;
            cout<<"       Daftar Pesanan Anda:      "<<endl;
            cout<<"==================================="<<endl;
            cout<<"Makanan:"<<endl;
            for (string makanan : daftarPesananMakanan) {
                cout<<"- "<<makanan<<endl;
            }
            cout<<"Minuman:"<<endl;
            for (string minuman : daftarPesananMinuman) {
                cout<<"- "<<minuman<<endl;
            }
            cout<<endl;
            cout<<"Total Harga: Rp "<<totalHarga<<endl;
            cout<<"TERIMAKASIH SUDAH MEMESAN :)"<<endl;
            break;
        }
        else {
            cout<<"Pilihan tidak valid, coba lagi broo!"<<endl;
            system("pause");
        }
}
return 0;
}
