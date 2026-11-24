# <h1 align="center">Laporan Praktikum Modul 8 - QUEUE </h1>

<p align="center">Nafisah Salsabila - 109082500063</p>

## Dasar Teori

### 8.1. Pengertian Queue<br/>
Queue (antrian) adalah struktur data yang prinsip operasinya seperti antrian. Elemen yang masuk lebih dulu akan keluar lebih dulu. Prinsip ini disebut FIFO (First In First Out), berbeda dengan stack yang menggunakan LIFO.

### 8.2. Komponen Queue<br/>
Queue memiliki dua penunjuk utama, yaitu head yang menunjuk elemen paling depan (tempat elemen diambil) dan tail yang menunjuk elemen paling belakang (tempat elemen ditambahkan). Pada representasi tabel (array), head dan tail berupa indeks array. Queue dikatakan kosong jika head = -1 dan tail = -1, dan dikatakan penuh jika tidak ada lagi indeks yang bisa dipakai untuk menambah elemen.

### Operasi Queue<br/>
Operasi utama pada queue adalah:
Enqueue: menambahkan elemen baru di bagian belakang queue (pada tail). Dequeue: mengambil elemen dari bagian depan queue (pada head). Primitif lainnya: createQueue (membuat queue kosong), isEmptyQueue (mengecek queue kosong), isFullQueue (mengecek queue penuh), dan printInfo (menampilkan isi queue).

### 8.4. Mekanisme Queue Representasi Tabel<br/>
Pada representasi tabel ada tiga alternatif mekanisme pergerakan head dan tail:
Alternatif 1 (head diam, tail bergerak): head selalu berada di indeks 0. Saat enqueue, tail bergeser maju. Saat dequeue, semua elemen digeser ke depan sehingga head tetap di indeks 0 dan tail mundur satu indeks. Alternatif 2 (head bergerak, tail bergerak): saat enqueue tail bergeser maju, dan saat dequeue head yang bergeser maju tanpa menggeser elemen. Kekurangannya, ruang kosong di depan head tidak bisa dipakai lagi. Alternatif 3 (head dan tail berputar / circular): head dan tail bergerak maju dan kembali ke indeks 0 setelah melewati indeks terakhir (menggunakan operasi modulo), sehingga ruang kosong di depan head dapat dipakai kembali.

## Unguided

### 1. Buatlah ADT Stack menggunakan ARRAY sebagai berikut di dalam file “queue.h”:

### queue.h
```cpp
source code unguided 1
#ifndef QUEUE_H_INCLUDED
#define QUEUE_H_INCLUDED

#include <iostream>
using namespace std;

typedef int infotype;

struct Queue {
    infotype info[5];
    int head;
    int tail;
};

void createQueue(Queue &Q);
bool isEmptyQueue(Queue Q);
bool isFullQueue(Queue Q);
void enqueue(Queue &Q, infotype x);
infotype dequeue(Queue &Q);
void printInfo(Queue Q);

#endif 
```

### queue.cpp
```cpp
source code unguided 1
#include "queue.h"

void createQueue(Queue &Q) {
    Q.head = -1;
    Q.tail = -1;
}

bool isEmptyQueue(Queue Q) {
    return (Q.head == -1 && Q.tail == -1);
}

bool isFullQueue(Queue Q) {
    return (Q.tail == 4);
}

void enqueue(Queue &Q, infotype x) {
    if (isFullQueue(Q)) {
        cout << "Queue penuh!" << endl;
        return;
    }
    if (isEmptyQueue(Q)) {
        Q.head = 0;
        Q.tail = 0;
    } else {
        Q.tail++;
    }
    Q.info[Q.tail] = x;
}

infotype dequeue(Queue &Q) {
    if (isEmptyQueue(Q)) {
        cout << "Queue kosong!" << endl;
        return -1;
    }
    infotype x = Q.info[Q.head];
    for (int i = Q.head; i < Q.tail; i++) {
        Q.info[i] = Q.info[i + 1];
    }
    Q.tail--;
    if (Q.tail < 0) {
        Q.head = -1;
        Q.tail = -1;
    }
    return x;
}

void printInfo(Queue Q) {
    cout << Q.head << " - " << Q.tail << "\t | ";
    if (isEmptyQueue(Q)) {
        cout << "empty queue";
    } else {
        for (int i = Q.head; i <= Q.tail; i++) {
            cout << Q.info[i] << " ";
        }
    }
    cout << endl;
}
```

### main.cpp
```cpp
source code unguided 1
#include <iostream>
#include "queue.h"
using namespace std;

int main()
{
    cout << "Hello World" << endl;
    Queue Q;
    createQueue(Q);

    cout << "----------------------" << endl;
    cout << " H - T \t | Queue info" << endl;
    cout << "----------------------" << endl;
    printInfo(Q);
    enqueue(Q, 5); printInfo(Q);
    enqueue(Q, 2); printInfo(Q);
    enqueue(Q, 7); printInfo(Q);
    dequeue(Q); printInfo(Q);
    dequeue(Q); printInfo(Q);
    enqueue(Q, 4); printInfo(Q);
    dequeue(Q); printInfo(Q);
    dequeue(Q); printInfo(Q);

    return 0;
}
```

### Output Unguided 1 :

![Screenshot Output Unguided 1](output/unguided1.png)

penjelasan unguided 1 :
ADT Queue dibuat dalam file "queue.h" yang berisi tipe infotype (integer), struct Queue (array info berukuran 5, head, dan tail), serta prototype fungsi. Pada Alternatif 1, head selalu diam di indeks 0 dan hanya tail yang bergerak. createQueue mengisi head dan tail dengan -1 sebagai penanda queue kosong. enqueue menaikkan tail lalu menyimpan nilai pada info[tail], dan untuk enqueue pertama head dan tail langsung diisi 0. dequeue mengambil info[head], lalu menggeser seluruh elemen setelahnya satu indeks ke depan dan menurunkan tail, sehingga head tetap di indeks 0.

### 2. Buatlah implementasi ADT Queue pada file “queue.cpp” dengan menerapkan mekanisme queue Alternatif 2 (head bergerak, tail bergerak).

### queue.cpp (tambahan)
```cpp
source code unguided 2
#include "queue.h"

void createQueue(Queue &Q) {
    Q.head = -1;
    Q.tail = -1;
}

bool isEmptyQueue(Queue Q) {
    return (Q.head == -1 && Q.tail == -1);
}

bool isFullQueue(Queue Q) {
    return (Q.tail == 4);
}

void enqueue(Queue &Q, infotype x) {
    if (isFullQueue(Q)) {
        cout << "Queue penuh!" << endl;
        return;
    }
    if (isEmptyQueue(Q)) {
        Q.head = 0;
        Q.tail = 0;
    } else {
        Q.tail++;
    }
    Q.info[Q.tail] = x;
}
infotype dequeue(Queue &Q) {
    if (isEmptyQueue(Q)) {
        cout << "Queue kosong!" << endl;
        return -1;
    }
    infotype x = Q.info[Q.head];
    Q.head++;
    if (Q.head > Q.tail) {
        Q.head = -1;
        Q.tail = -1;
    }
    return x;
}

void printInfo(Queue Q) {
    cout << Q.head << " - " << Q.tail << "\t | ";
    if (isEmptyQueue(Q)) {
        cout << "empty queue";
    } else {
        for (int i = Q.head; i <= Q.tail; i++) {
            cout << Q.info[i] << " ";
        }
    }
    cout << endl;
}
```

### main.cpp
```cpp
source code unguided 2
#include <iostream>
#include "queue.h"
using namespace std;

int main()
{
    cout << "Hello World" << endl;
    Queue Q;
    createQueue(Q);

    cout << "----------------------" << endl;
    cout << " H - T \t | Queue info" << endl;
    cout << "----------------------" << endl;
    printInfo(Q);
    enqueue(Q, 5); printInfo(Q);
    enqueue(Q, 2); printInfo(Q);
    enqueue(Q, 7); printInfo(Q);
    enqueue(Q, 4); printInfo(Q);
    enqueue(Q, 9); printInfo(Q);
    dequeue(Q); printInfo(Q);
    dequeue(Q); printInfo(Q);
    enqueue(Q, 6); printInfo(Q);
    enqueue(Q, 8); printInfo(Q);
    enqueue(Q, 1); printInfo(Q);
    dequeue(Q); printInfo(Q);
    dequeue(Q); printInfo(Q);
    dequeue(Q); printInfo(Q);
    dequeue(Q); printInfo(Q);
    dequeue(Q); printInfo(Q);
    return 0;
}
```

### Output Unguided 2 :

![Screenshot Output Unguided 2](output/Unguided2.png)

penjelasan unguided 2 :
ada Alternatif 2, baik head maupun tail dapat bergerak. enqueue tetap menaikkan tail, sedangkan dequeue tidak lagi menggeser elemen, tetapi cukup menaikkan head sehingga proses dequeue lebih cepat karena tidak ada perulangan penggeseran. Jika head melewati tail, berarti queue sudah kosong sehingga head dan tail dikembalikan ke -1.

### 3. Buatlah implementasi ADT Queue pada file “queue.cpp” dengan menerapkan mekanisme queue Alternatif 3 (head dan tail berputar).

### queue.cpp (tambahan)
```cpp
source code unguided 3
#include "queue.h"

void createQueue(Queue &Q) {
    Q.head = -1;
    Q.tail = -1;
}

bool isEmptyQueue(Queue Q) {
    return (Q.head == -1 && Q.tail == -1);
}

bool isFullQueue(Queue Q) {
    return (!isEmptyQueue(Q) && (Q.tail + 1) % 5 == Q.head);
}

void enqueue(Queue &Q, infotype x) {
    if (isFullQueue(Q)) {
        cout << "Queue penuh!" << endl;
        return;
    }
    if (isEmptyQueue(Q)) {
        Q.head = 0;
        Q.tail = 0;
    } else {
        Q.tail = (Q.tail + 1) % 5;
    }
    Q.info[Q.tail] = x;
}

infotype dequeue(Queue &Q) {
    if (isEmptyQueue(Q)) {
        cout << "Queue kosong!" << endl;
        return -1;
    }
    infotype x = Q.info[Q.head];
    if (Q.head == Q.tail) {
        Q.head = -1;
        Q.tail = -1;
    } else {
        Q.head = (Q.head + 1) % 5;
    }
    return x;
}

void printInfo(Queue Q) {
    cout << Q.head << " - " << Q.tail << "\t | ";
    if (isEmptyQueue(Q)) {
        cout << "empty queue";
    } else {
        int i = Q.head;
        while (true) {
            cout << Q.info[i] << " ";
            if (i == Q.tail) break;
            i = (i + 1) % 5;
        }
    }
    cout << endl;
}
```
### main.cpp
```cpp
source code unguided 3
#include <iostream>
#include "queue.h"
using namespace std;

int main()
{
    cout << "Hello World" << endl;
    Queue Q;
    createQueue(Q);

    cout << "----------------------" << endl;
    cout << " H - T \t | Queue info" << endl;
    cout << "----------------------" << endl;
    printInfo(Q);
    enqueue(Q, 5); printInfo(Q);
    enqueue(Q, 2); printInfo(Q);
    enqueue(Q, 7); printInfo(Q);
    enqueue(Q, 4); printInfo(Q);
    enqueue(Q, 9); printInfo(Q);
    dequeue(Q); printInfo(Q);
    dequeue(Q); printInfo(Q);
    enqueue(Q, 6); printInfo(Q);
    enqueue(Q, 8); printInfo(Q);
    enqueue(Q, 1); printInfo(Q);
    dequeue(Q); printInfo(Q);
    dequeue(Q); printInfo(Q);
    dequeue(Q); printInfo(Q);
    dequeue(Q); printInfo(Q);
    dequeue(Q); printInfo(Q);
    return 0;
}
```

### Output Unguided 3 :

![Screenshot Output Unguided 3](output/Unguided3.png)

penjelasan unguided 3 :
Pada Alternatif 3, head dan tail berputar (circular) menggunakan operasi modulo 5, sehingga setelah mencapai indeks 4 keduanya kembali ke indeks 0. Dengan cara ini ruang kosong di depan head dapat dipakai kembali, jadi kapasitas array terpakai maksimal. Queue dikatakan penuh jika (tail + 1) % 5 sama dengan head, dan kosong jika head dan tail bernilai -1. Pada dequeue, jika head sama dengan tail berarti hanya ada satu elemen, sehingga head dan tail dikembalikan ke -1.

## Kesimpulan
Berdasarkan praktikum yang telah dilakukan, Queue adalah struktur data dengan prinsip FIFO (First In First Out), di mana elemen ditambahkan di belakang (tail) dan diambil dari depan (head). Pada representasi array terdapat tiga mekanisme. Alternatif 1 (head diam, tail bergerak) sederhana tetapi dequeue memerlukan penggeseran elemen. Alternatif 2 (head dan tail bergerak) lebih cepat karena tidak ada penggeseran, tetapi ruang di depan head tidak bisa dipakai lagi. Alternatif 3 (circular) memanfaatkan seluruh kapasitas array dengan memutar head dan tail menggunakan modulo. Operasi createQueue, isEmptyQueue, isFullQueue, enqueue, dequeue, dan printInfo berhasil diimplementasikan pada ADT yang dibagi menjadi queue.h, queue.cpp, dan main.cpp.

## Referensi

[1] Modul pembelajaran