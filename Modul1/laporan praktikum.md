# <h1 align="center">Laporan Praktikum Modul 1 - Codeblocks IDE & Pengenalan Bahas C++ (Bagian Pertama)</h1>

<p align="center">Nafisah Salsabila - 109082500063</p>

## Dasar Teori

### A. Abstract Data Type<br/>

#### 1. Pengertian
Abstract Data Type (ADT) adalah model data yang mendefinisikan data dan operasi yang dapat dilakukan terhadap data tersebut, tanpa menjelaskan bagaimana implementasinya secara detail.

#### 2. Contoh
Stack — menggunakan prinsip LIFO (Last In, First Out).
Queue — menggunakan prinsip FIFO (First In, First Out).
List — menyimpan sekumpulan elemen yang memiliki urutan tertentu.

### B. Algoritma<br/>
Algoritma adalah langkah-langkah logis dan sistematis yang digunakan untuk menyelesaikan suatu masalah.
Dalam praktikum, algoritma dapat dituliskan dalam bentuk pseudocode sebelum diimplementasikan ke dalam bahasa pemrograman.

#### C. Pseudocode
Pseudocode adalah penulisan langkah-langkah algoritma menggunakan bahasa yang sederhana dan terstruktur sehingga mudah dipahami sebelum diterjemahkan menjadi kode program.

#### D. Percabangan
 Percabangan digunakan untuk menentukan instruksi yang dijalankan berdasarkan suatu kondisi. Dalam C++, percabangan dapat menggunakan if, else if, dan else.

#### E. Input/Output
C++ menggunakan cin untuk menerima input dari pengguna dan cout untuk menampilkan output ke layar.


## Guided

### 1. ...

```C++
source code guided 1
```

penjelasan singkat guided 1

### 2. ...

```C++
source code guided 2
```

penjelasan singkat guided 2

### 3. ...

```C++
source code guided 3
```

penjelasan singkat guided 3

## Unguided

### 1. Buatlah program yang menerima input-an dua buah bilangan betipe float, kemudian memberikan output-an hasil penjumlahan, pengurangan, perkalian, dan pembagian dari dua bilangan tersebut.

```cpp
#include <iostream>
using namespace std;

int main() {
    float a, b;

    cin >> a >> b;

    cout << "Penjumlahan = " << a + b << endl;
    cout << "Pengurangan = " << a - b << endl;
    cout << "Perkalian = " << a * b << endl;
    cout << "Pembagian = " << a / b << endl;

    return 0;
}
source code unguided 1
```

### Output Unguided 1 :

![Screenshot Output Unguided 1_1](https://github.com/(billaforse)/109082500063_NAFISAH_SALSABILA_STRUKDAT/blob/main/Modul1/soal1.png)

penjelasan unguided 1 :
Program ini digunakan untuk menerima input dua buah bilangan bertipe float, kemudian melakukan operasi aritmatika berupa penjumlahan, pengurangan, perkalian, dan pembagian dari kedua bilangan tersebut, lalu menampilkan hasilnya.

### 2. Buatlah sebuah program yang menerima masukan angka dan mengeluarkan output nilai angka tersebut dalam bentuk tulisan. Angka yang akan di-input-kan user adalah bilangan bulat positif mulai dari 0 s.d 100

```cpp
#include <iostream>
using namespace std;

int main() {
    int n;
    string satuan[] = {
        "nol", "satu", "dua", "tiga", "empat",
        "lima", "enam", "tujuh", "delapan", "sembilan"
    };

    cin >> n;

    if (n < 10) {
        cout << satuan[n];
    } 
    else if (n == 10) {
        cout << "sepuluh";
    } 
    else if (n == 11) {
        cout << "sebelas";
    } 
    else if (n < 20) {
        cout << satuan[n - 10] << " belas";
    } 
    else if (n < 100) {
        cout << satuan[n / 10] << " puluh";
        if (n % 10 != 0)
            cout << " " << satuan[n % 10];
    } 
    else if (n == 100) {
        cout << "seratus";
    }

    return 0;
}
source code unguided 2
```

### Output Unguided 2 :

![Screenshot Output Unguided 2_1](https://github.com/(billaforse)/109082500063_NAFISAH_SALSABILA_STRUKDAT/blob/main/Modul1/soal2.png)

penjelasan unguided 2 :
Program ini digunakan untuk menerima input bilangan bulat positif dari 0 sampai 100, kemudian mengubah bilangan tersebut menjadi bentuk tulisan dan menampilkan hasilnya.

### 3. Buatlah program yang dapat memberikan input dan output sbb.

```cpp
#include <iostream>
using namespace std;

int main() {
    int n;
    cin >> n;

    for (int i = n; i >= 1; i--) {
        for (int j = n; j > i; j--) {
            cout << "  ";
        }

        for (int j = i; j >= 1; j--) {
            cout << j << " ";
        }

        cout << "* ";

        for (int j = 1; j <= i; j++) {
            cout << j << " ";
        }

        cout << endl;
    }

    for (int j = 0; j < n; j++) {
        cout << "  ";
    }
    cout << "*";

    return 0;
}
source code unguided 3
```

### Output Unguided 3 :

![Screenshot Output Unguided 3_1] (https://github.com/(billaforse)/109082500063_NAFISAH_SALSABILA_STRUKDAT/blob/main/Modul1/soal3.png)

penjelasan unguided 3 :
Program ini digunakan untuk menerima sebuah angka sebagai input, kemudian membuat pola mirror berdasarkan angka tersebut, yaitu pola angka yang semakin mengecil pada setiap baris dan memiliki tanda * di bagian tengah.

## Kesimpulan
Jadi di dalam praktikum minggu ini, saya mempelajari konsep dasar Struktur Data dan Abstract Data Type (ADT), serta pengenalan bahasa pemrograman C++ sebagai dasar untuk membuat dan mengimplementasikan program. Saya juga mempelajari penggunaan input dan output, tipe data, operasi aritmatika, percabangan, serta perulangan dalam C++. Selanjutnya, konsep tersebut diterapkan melalui beberapa latihan, yaitu membuat program untuk melakukan operasi aritmatika pada dua bilangan float, mengubah bilangan 0–100 menjadi bentuk tulisan, dan membuat pola mirror menggunakan perulangan. Dari praktikum ini, saya memahami bagaimana konsep dasar pemrograman C++ diterapkan untuk menyelesaikan berbagai permasalahan dalam Struktur Data.

## Referensi

[1] Triase. (2020). Diktat Edisi Revisi : STRUKTUR DATA. Medan: UNIVERSTAS ISLAM NEGERI SUMATERA UTARA MEDAN.
<br>[2] Indahyati, Uce., Rahmawati Yunianita. (2020). "BUKU AJAR ALGORITMA DAN PEMROGRAMAN DALAM BAHASA C++". Sidoarjo: Umsida Press. Diakses pada 10 Maret 2024 melalui https://doi.org/10.21070/2020/978-623-6833-67-4.
<br>...
Halaman 20 dari 20