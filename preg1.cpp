#include <iostream>
#include <iomanip>
using namespace std;

struct Dia {
    int pasajeros;
    int dia;   
    int mes;   
};

int main() {
    const int MESES = 12;
    const int DIAS = 30;
    const int N = MESES * DIAS;
    Dia* lista = new Dia[N];

   
    const int CAP_MAX = 700;
    const int UMBRAL = (int)(0.95 * CAP_MAX + 0.5); 

    srand(1);
    for (int m = 1; m <= MESES; ++m) {
        for (int d = 1; d <= DIAS; ++d) {
            int idx = (m-1)*DIAS + (d-1);
            lista[idx].pasajeros = 500 + rand() % 201; 
            lista[idx].dia = d;
            lista[idx].mes = m;
        }
    }

    cout << "Dias con ocupacion >= 95% ("<< UMBRAL << " pasajeros):\n";
    cout << left << setw(6) << "Dia" << setw(6) << "Mes" << setw(12) << "Pasajeros" << "\n";
    for (int i = 0; i < N; ++i) {
        if (lista[i].pasajeros >= UMBRAL) {
            cout << setw(6) << lista[i].dia << setw(6) << lista[i].mes
                 << setw(12) << lista[i].pasajeros << "\n";
        }
    }

    delete[] lista;
    return 0;
}
