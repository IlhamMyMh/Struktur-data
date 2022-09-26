#include<iostream>
#include<conio.h>



using namespace std;
struct paket
{
    char jenis_brg[30];
    int berat;
    char kota[30];
};

struct paket kirim[100];

/***************/


void tambahdata(int x,int y)
{
    if(x<=y){
    cout<<"Inputkan Jenis Barang    :";
    cin>>kirim[x].jenis_brg;
    cout<<"Inputkan Berat           :";
    cin>>kirim[x].berat;
    cout<<"Inputkan Kota Tujuan     :";
    cin>>kirim[x].kota;
    }else
    cout << "data telah penuh" << endl;
    x--;


    cout<<"Press Any Key...";
    getch();
}

void tampildata(int x)
{
    cout<<"Daftar Kiriman Paket"<<endl;
    if(x==1){
        cout << "Data kosong" << endl;
    }else if(x>0){
    for(int a=1; a<x; a++)
    {

        cout<<a<<" ";
        cout<<kirim[a].jenis_brg<<" ";
        cout<<kirim[a].berat<<" ";
        cout<<kirim[a].kota<<endl;
    }
    }

    cout<<"Press Any Key...";
    getch();
    //harus Ijin --> #include<conio.h>/
}

void hapusdata(int x)
{
    cout<<"Data Terakhir yang anda Hapus Adalah :"<<endl;
    cout<<kirim[x].jenis_brg<<" ";
    cout<<kirim[x].berat<<" Kg ";
    cout<<kirim[x].kota<<endl<<endl;

    cout<<"Press Any Key...";
    getch();
}
void maxBrt(int x)
{
    int maxBerat = 0;
    string namaPkt,tujuan;
    for(int i=0;i<x;i++){
        if(maxBerat < kirim[i].berat)
        {
            maxBerat = kirim[i].berat;
            namaPkt = kirim[i].jenis_brg;
            tujuan = kirim[i].kota;
        }
    }
    cout << "Paket Terberat Seberat "
        <<maxBerat<<"Kg Berupa "
        <<namaPkt<<" Menuju ke "
        <<tujuan<<endl;

    cout<<"Press Any Key...";
    getch();
    cout<<endl<<endl;
}

int main()
{
    int pilih,c;
    int datake=1;
    int k=0;
    cout << "masukan jumlah data = ";
    cin >> k;
    do
    {
        cout<<endl<<endl;
        cout<<"PROGRAM MENU STACK" << endl;
        cout<<"1. Tambah Data"<< endl;;
        cout<<"2. Hapus Data Terakhir"<<endl;
        cout<<"3. Tampil Data"<<endl;
        cout<<"4. Tampil Berat Max"<<endl;
        cout<<"5. kosongkan data"<<endl;

        cout<<"9. Keluar"<<endl;

        cout<<"Pilihan Anda [1-9] : ";
        cin>>pilih;
        if(pilih==1)
            { //Menambah data baru diletakan di DATAKE/
                tambahdata(datake,k);
                datake++;
            }
        if(pilih==2)
            { //Menghapus Data Terakhir (DATAKE-1/
                hapusdata(datake-1);
                datake--;
            }
        if(pilih==3)
            { /*Menampilkan Data mulai
                        data ke-1 hingga DATAKE*/
            tampildata(datake);
            }
        if(pilih==4)
        {
            maxBrt(datake);
        }
        if(pilih==5)
            { /*Menghapus Data Terakhir (DATAKE-1*/
                cout << "Data berhsail di hapus " << endl;
                datake= 1 +(datake-datake);
            }

    }
    while(pilih!=9);
    return 0;
}
