#include <iostream>
#include <fstream>
#include <cmath>
using namespace std;

double areaTriangulo(double x1,double y1,double x2,double y2,double x3,double y3) {
    double val = x1*(y3-y2) + x2*(y1-y3) + x3*(y2-y1);
    return fabs(val) / 2.0;
}

int main() {
    ifstream in("laguna.txt");
    if (!in) {
        cerr << "No se pudo abrir laguna.txt\n";
        return 1;
    }
    int nt, nv;
    in >> nt;
    in >> nv;
    double* xs = new double[nv+1]; 
    double* ys = new double[nv+1];
    for (int i = 1; i <= nv; ++i) in >> xs[i] >> ys[i];
    double areaTotal = 0.0;
    for (int t = 0; t < nt; ++t) {
        int i,j,k;
        in >> i >> j >> k;
        areaTotal += areaTriangulo(xs[i], ys[i], xs[j], ys[j], xs[k], ys[k]);
    }
    in.close();

    ofstream out("area.txt");
    if (!out) {
        cerr << "No se pudo escribir area.txt\n";
        delete[] xs; delete[] ys;
        return 1;
    }
    out.setf(ios::fixed); out.precision(6);
    out << areaTotal << "\n";
    out.close();

    delete[] xs; delete[] ys;
    cout << "Area total calculada y guardada en area.txt\n";
    return 0;
}
