#include <iostream>
#include <fstream>
using namespace std;

void escribirFibonacciBinario() {
    ofstream out("fibonacci.bin", ios::binary);
    if (!out) { cerr << "Error creando fibonacci.bin\n"; return; }
    long long a = 0, b = 1;
    out.write(reinterpret_cast<char*>(&a), sizeof(a));
    out.write(reinterpret_cast<char*>(&b), sizeof(b));
    for (int i = 3; i <= 20; ++i) {
        long long c = a + b;
        out.write(reinterpret_cast<char*>(&c), sizeof(c));
        a = b; b = c;
    }
    out.close();
}

void leerFibonacciBinario() {
    ifstream in("fibonacci.bin", ios::binary);
    if (!in) { cerr << "No se pudo abrir fibonacci.bin\n"; return; }
    long long x;
    cout<< "Funcion leer Fibonacci binario:\n";
    while (in.read(reinterpret_cast<char*>(&x), sizeof(x))) {
        static int i = 1;
        cout << "termino " << i << ":  "<< x << "\n";
        i++;
    }
    in.close();
}

int main() {
    escribirFibonacciBinario();
    leerFibonacciBinario();
    return 0;
}
