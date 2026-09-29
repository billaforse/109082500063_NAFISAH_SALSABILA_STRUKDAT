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