
#include <iostream>
#include <cmath>
using namespace std;
struct Termino { int exp; int coef; };
void combinar(Termino arr[], int &n) {
    for (int i=0;i<n-1;i++) for (int j=i+1;j<n;j++)
        if (arr[j].exp > arr[i].exp) { Termino t = arr[i]; arr[i] = arr[j]; arr[j] = t; }
    int idx = 0;
    for (int i=0;i<n;i++) {
        if (fabs(arr[i].coef) < 1e-9) continue;
        if (idx>0 && arr[i].exp == arr[idx-1].exp) arr[idx-1].coef += arr[i].coef;
        else arr[idx++] = arr[i];
    }
    n = idx;
}

int main() {
    const int MAX = 50;
    Termino A[MAX], B[MAX], R[400];
    int na, nb, nr;

    cout << "Numero de terminos del primer polinomio: ";
    cin >> na;
    for (int i = 0; i < na; i++) {
        cout << "Coeficiente del termino " << (i + 1) << ": ";
        cin >> A[i].coef;
        cout << "Exponente del termino " << (i + 1) << ": ";
        cin >> A[i].exp;
    }

    cout << "Numero de terminos del segundo polinomio: ";
    cin >> nb;
    for (int i = 0; i < nb; i++) {
        cout << "Coeficiente del termino " << (i + 1) << ": ";
        cin >> B[i].coef;
        cout << "Exponente del termino " << (i + 1) << ": ";
        cin >> B[i].exp;
    }

    nr = 0;
    for (int i=0;i<na;i++) for (int j=0;j<nb;j++) {
        R[nr].coef = A[i].coef * B[j].coef;
        R[nr].exp = A[i].exp + B[j].exp;
        nr++;
    }
    combinar(R, nr);

    cout << "Polinomio resultante:\n";
    for (int i=0;i<nr;i++) {
        if (i>0 && R[i].coef >= 0) cout << "+";
        cout << R[i].coef << "x^" << R[i].exp << " ";
    }
    cout << "\n";
    return 0;
}
