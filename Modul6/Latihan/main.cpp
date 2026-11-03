#include <iostream>
#include "Doublylist.h"
using namespace std;

int main()
{
    List L;
    infotype x;

    createList(L);

    for (int i = 1; i <= 4; i++) {
        cout << "masukkan nomor polisi: ";
        cin >> x.nopol;
        cout << "masukkan warna kendaraan: ";
        cin >> x.warna;
        cout << "masukkan tahun kendaraan: ";
        cin >> x.thnBuat;

        // cek apakah nomor polisi sudah ada di list
        bool sudahAda = false;
        address Q = L.first;
        while (Q != Nil) {
            if (Q->info.nopol == x.nopol) {
                sudahAda = true;
            }
            Q = Q->next;
        }

        if (sudahAda) {
            cout << "nomor polisi sudah terdaftar" << endl;
        } else {
            insertLast(L, alokasi(x));
        }
        cout << endl;
    }

    cout << "DATA LIST 1" << endl << endl;
    printInfo(L);

    return 0;
}