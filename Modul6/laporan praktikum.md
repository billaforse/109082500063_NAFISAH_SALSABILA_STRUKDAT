# <h1 align="center">Laporan Praktikum Modul 4 - SINGLY LINKED LIST (BAGIAN PERTAMA) </h1>

<p align="center">Nafisah Salsabila - 109082500063</p>

## Dasar Teori

### 6.1. Doubly Linked List<br/> 
Doubly linked list adalah linked list yang setiap elemennya memiliki dua successor (pointer), yaitu prev yang menunjuk ke elemen sebelumnya dan next yang menunjuk ke elemen sesudahnya. Karena punya dua arah, list ini bisa ditelusuri maju maupun mundur, sehingga proses akses elemen menjadi lebih mudah dibandingkan singly linked list. List dikatakan kosong jika L.first = Nil.

### 6.2. Komponen Doubly Linked List<br/>
Komponen-komponen yang ada pada doubly linked list adalah sebagai berikut:

First: pointer pada list yang menunjuk ke elemen pertama list.
Last: pointer pada list yang menunjuk ke elemen terakhir list.
Next: pointer pada elemen yang menunjuk ke elemen sesudahnya.
Prev: pointer pada elemen yang menunjuk ke elemen sebelumnya.

### 6.3. Operasi Insert<br/>
Insert First: elemen baru dialokasikan (P->next dan P->prev diisi Nil), lalu P->next = L.first, (L.first)->prev = P, dan terakhir L.first = P.
Insert Last: elemen baru dialokasikan, lalu P->prev = L.last, (L.last)->next = P, dan terakhir L.last = P.
Insert After: elemen baru disisipkan setelah elemen R dengan P->next = R->next, P->prev = R, (R->next)->prev = P, dan R->next = P.
Insert Before: kebalikan dari insert after, perbedaannya hanya pada pencarian elemennya.

### 6.4. Operasi Delete<br/>
Delete First: simpan elemen pertama ke P (P = L.first), geser first (L.first = (L.first)->next), lalu putuskan hubungan ((L.first)->prev = Nil, P->next = Nil).
Delete Last: simpan elemen terakhir ke P (P = L.last), geser last (L.last = (L.last)->prev), lalu putuskan hubungan ((L.last)->next = Nil, P->prev = Nil).
Delete After: elemen setelah R dilepas dengan R->next = P->next dan (P->next)->prev = R, lalu P->next dan P->prev diisi Nil.
Delete Before: kebalikan dari delete after, perbedaannya hanya pada pencarian elemennya.
Elemen yang sudah dilepas dapat dikembalikan (return P) atau langsung dihapus dari memori dengan dealokasi(P).

### 6.5. Update, View, dan Searching<br/>
Proses pencarian, update data, dan view data pada dasarnya sama dengan singly linked list. Bedanya, pada doubly linked list proses akses elemen lebih mudah karena iterasi bisa dilakukan maju dan mundur. ADT doubly linked list juga pada dasarnya sama dengan ADT singly linked list, hanya ditambah pointer prev pada elemen dan pointer last pada list.
## Unguided

### 1. Buatlah ADT Singly Linked list sebagai berikut di dalam file “Doublylist.h”:

### Doublylist.h
```cpp
source code unguided 1

source code unguided 1

#ifndef DOUBLYLIST_H
#define DOUBLYLIST_H

#include <iostream>
#include <string>
using namespace std;

#define Nil NULL

struct kendaraan {
    string nopol;
    string warna;
    int thnBuat;
};

typedef kendaraan infotype;
typedef struct elmList *address;

struct elmList {
    infotype info;
    address next;
    address prev;
};

struct List {
    address first;
    address last;
};

void createList(List &L);
address alokasi(infotype x);
void dealokasi(address &P);
void printInfo(List L);
void insertLast(List &L, address P);

#endif
```

### Doublylist.cpp
```cpp
source code unguided 1
source code unguided 1

#include "Doublylist.h"

void createList(List &L) {
    L.first = Nil;
    L.last = Nil;
}

address alokasi(infotype x) {
    address P = new elmList;
    P->info = x;
    P->next = Nil;
    P->prev = Nil;
    return P;
}

void dealokasi(address &P) {
    delete P;
    P = Nil;
}

void printInfo(List L) {
    address P = L.last;
    while (P != Nil) {
        cout << "no polisi : " << P->info.nopol << endl;
        cout << "warna     : " << P->info.warna << endl;
        cout << "tahun     : " << P->info.thnBuat << endl;
        P = P->prev;
    }
}

void insertLast(List &L, address P) {
    if (L.first == Nil) {
        L.first = P;
        L.last = P;
    } else {
        P->prev = L.last;
        (L.last)->next = P;
        L.last = P;
    }
}
```

### main.cpp
```cpp
source code unguided 1

source code unguided 1

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
```

### Output Unguided 1 :

![Screenshot Output Unguided 1](output/unguided1.png)

penjelasan unguided 1 : ADT Doubly Linked List dibuat dalam tiga file. "Doublylist.h" berisi deklarasi tipe data kendaraan (nopol, warna, thnBuat), elemen list (info, next, prev), list (first, last), serta prototype fungsi. "Doublylist.cpp" berisi implementasi fungsi createList, alokasi, dealokasi, printInfo, dan insertLast. Pada insertLast, jika list masih kosong maka first dan last langsung menunjuk elemen baru, jika tidak maka prev elemen baru diarahkan ke last, next dari last diarahkan ke elemen baru, lalu last dipindahkan ke elemen baru. Fungsi printInfo menelusuri list dari last ke first menggunakan pointer prev, sehingga data yang terakhir dimasukkan (D004) tampil paling awal. Pada main.cpp, empat data kendaraan diinput, dan sebelum dimasukkan ke list nomor polisinya dicek terlebih dahulu dengan menelusuri list; jika sudah ada (D001 yang diinput dua kali), ditampilkan pesan "nomor polisi sudah terdaftar" dan data tidak dimasukkan.

### 2. Carilah elemen dengan info 8 dengan membuat fungsi baru.

### Doublylist.h (tambahan)
```cpp
source code unguided 2
address findElm(List L, infotype x);
```

### Doublylist.cpp (tambahan)
```cpp
source code unguided 2
address findElm(List L, infotype x) {
    address P = L.first;
    while (P != Nil) {
        if (P->info.nopol == x.nopol) {
            return P;
        }
        P = P->next;
    }
    return Nil;
}
```

### main.cpp
```cpp
source code unguided 2
#include <iostream>
#include "Doublylist.h"
using namespace std;

int main()
{
    List L;
    infotype x, cari;

    createList(L);

    for (int i = 1; i <= 4; i++) {
        cout << "masukkan nomor polisi: ";
        cin >> x.nopol;
        cout << "masukkan warna kendaraan: ";
        cin >> x.warna;
        cout << "masukkan tahun kendaraan: ";
        cin >> x.thnBuat;

        if (findElm(L, x) != Nil) {
            cout << "nomor polisi sudah terdaftar" << endl;
        } else {
            insertLast(L, alokasi(x));
        }
        cout << endl;
    }

    cout << "Masukkan Nomor Polisi yang dicari   : ";
    cin >> cari.nopol;
    cout << endl;

    address P = findElm(L, cari);
    if (P != Nil) {
        cout << "Nomor Polisi : " << P->info.nopol << endl;
        cout << "Warna        : " << P->info.warna << endl;
        cout << "Tahun        : " << P->info.thnBuat << endl;
    } else {
        cout << "Data dengan nomor polisi " << cari.nopol << " tidak ditemukan." << endl;
    }

    return 0;
}
```

### Output Unguided 2 :

![Screenshot Output Unguided 2](output/Unguided2.png)

penjelasan unguided 2 :
Fungsi findElm digunakan untuk mencari elemen berdasarkan nomor polisi. Fungsi melakukan traversal dari L.first dengan pointer bantu P, lalu membandingkan P->info.nopol dengan nopol yang dicari. Jika sama, address elemen dikembalikan, dan jika sampai akhir list (Nil) belum ketemu, fungsi mengembalikan Nil. Pada main.cpp, findElm juga dipakai untuk mengecek nomor polisi yang sudah terdaftar saat input, lalu hasil pencarian D001 dicek: jika tidak Nil maka data kendaraan (nopol, warna, tahun) ditampilkan.

### 3. Hitunglah jumlah total info seluruh elemen (9+12+8+0+2=31).

### Doublylist.h (tambahan)
```cpp
source code unguided 3

void deleteFirst(List &L, address &P);
void deleteLast(List &L, address &P);
void deleteAfter(address Prec, address &P);
```

### Doublylist.cpp (tambahan)
```cpp
source code unguided 3


void deleteFirst(List &L, address &P) {
    P = L.first;
    if (P != Nil) {
        if (L.first == L.last) {
            L.first = Nil;
            L.last = Nil;
        } else {
            L.first = P->next;
            (L.first)->prev = Nil;
            P->next = Nil;
        }
    }
}

void deleteLast(List &L, address &P) {
    P = L.last;
    if (P != Nil) {
        if (L.first == L.last) {
            L.first = Nil;
            L.last = Nil;
        } else {
            L.last = P->prev;
            (L.last)->next = Nil;
            P->prev = Nil;
        }
    }
}

void deleteAfter(address Prec, address &P) {
    P = Nil;
    if (Prec != Nil && Prec->next != Nil) {
        P = Prec->next;
        Prec->next = P->next;
        if (P->next != Nil) {
            (P->next)->prev = Prec;
        }
        P->next = Nil;
        P->prev = Nil;
    }
}
```

### main.cpp
```cpp
source code unguided 3

#include <iostream>
#include "Doublylist.h"
using namespace std;

int main()
{
    List L;
    infotype x, hapus;

    createList(L);

    for (int i = 1; i <= 4; i++) {
        cout << "masukkan nomor polisi: ";
        cin >> x.nopol;
        cout << "masukkan warna kendaraan: ";
        cin >> x.warna;
        cout << "masukkan tahun kendaraan: ";
        cin >> x.thnBuat;

        if (findElm(L, x) != Nil) {
            cout << "nomor polisi sudah terdaftar" << endl;
        } else {
            insertLast(L, alokasi(x));
        }
        cout << endl;
    }

    cout << "Masukkan Nomor Polisi yang akan dihapus   : ";
    cin >> hapus.nopol;

    address P = findElm(L, hapus);
    if (P == Nil) {
        cout << "Data dengan nomor polisi " << hapus.nopol << " tidak ditemukan." << endl;
    } else {
        if (P == L.first) {
            deleteFirst(L, P);
        } else if (P == L.last) {
            deleteLast(L, P);
        } else {
            deleteAfter(P->prev, P);
        }
        dealokasi(P);
        cout << "Data dengan nomor polisi " << hapus.nopol << " berhasil dihapus." << endl;
    }
    cout << endl;

    cout << "DATA LIST 1" << endl << endl;
    printInfo(L);

    return 0;
}
```

### Output Unguided 3 :

![Screenshot Output Unguided 3](output/Unguided3.png)

penjelasan unguided 3 :
Penghapusan dilakukan dengan tiga prosedur. deleteFirst melepas elemen pertama (first digeser ke elemen berikutnya, prev-nya diisi Nil), deleteLast melepas elemen terakhir (last digeser ke elemen sebelumnya, next-nya diisi Nil), dan deleteAfter melepas elemen setelah Prec dengan menyambungkan Prec langsung ke elemen sesudah P. Pada deleteFirst dan deleteLast ditambahkan pengecekan jika list hanya berisi satu elemen, maka first dan last langsung diisi Nil. Pada main.cpp, elemen D003 dicari dengan findElm, lalu dihapus dengan prosedur yang sesuai posisinya (awal, akhir, atau tengah), kemudian dealokasi dipanggil untuk membebaskan memori. Karena D003 berada di tengah list, yang dipakai adalah deleteAfter. Hasilnya, data D003 tidak muncul lagi pada list.

## Kesimpulan
Berdasarkan praktikum yang telah dilakukan, Doubly Linked List merupakan struktur data yang setiap elemennya memiliki dua pointer, yaitu next dan prev, serta list memiliki pointer first dan last. Dengan adanya prev dan last, penambahan di akhir list dan penelusuran mundur menjadi lebih mudah. Operasi insertLast, findElm, serta deleteFirst, deleteLast, dan deleteAfter berhasil diimplementasikan pada ADT yang dibagi menjadi Doublylist.h, Doublylist.cpp, dan main.cpp. Pada operasi delete, pointer next dan prev dari elemen di sekitarnya harus diatur dengan benar agar list tetap terhubung dua arah.

## Referensi

[1] Modul pembelajaran