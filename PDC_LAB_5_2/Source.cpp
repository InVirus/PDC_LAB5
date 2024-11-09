#include <iostream>
#include <vector>
#include <algorithm>
#include "Windows.h"

using namespace std;

void performSetOperations() {
    int n;
    cout << "¬вед≥ть к≥льк≥сть елемент≥в в ун≥версум≥ U: ";
    cin >> n;

    vector<int> U(n);
    cout << "¬вед≥ть елементи ун≥версуму U: ";
    for (int i = 0; i < n; ++i) {
        cin >> U[i];
    }

    int ka;
    cout << "¬вед≥ть к≥льк≥сть елемент≥в у множин≥ A: ";
    cin >> ka;

    vector<int> A(ka);
    cout << "¬вед≥ть елементи множини A: ";
    for (int i = 0; i < ka; ++i) {
        cin >> A[i];
    }

    int kb;
    cout << "¬вед≥ть к≥льк≥сть елемент≥в у множин≥ B: ";
    cin >> kb;

    vector<int> B(kb);
    cout << "¬вед≥ть елементи множини B: ";
    for (int i = 0; i < kb; ++i) {
        cin >> B[i];
    }

    vector<int> Abit(n, 0), Bbit(n, 0);
    vector<int> notA(n), AperB(n), AobB(n), ArizB(n), AxorB(n);

    for (int i = 0; i < n; ++i) {
        if (find(A.begin(), A.end(), U[i]) != A.end()) {
            Abit[i] = 1;
        }
        if (find(B.begin(), B.end(), U[i]) != B.end()) {
            Bbit[i] = 1;
        }
    }

    for (int i = 0; i < n; ++i) {
        notA[i] = 1 - Abit[i];
        AperB[i] = Abit[i] & Bbit[i];
        AobB[i] = Abit[i] | Bbit[i];
        ArizB[i] = Abit[i] & ~Bbit[i];
        AxorB[i] = Abit[i] ^ Bbit[i];
    }

    cout << "Bit A: ";
    for (int i = 0; i < n; ++i) {
        cout << Abit[i] << " ";
    }

    cout << "\nBit B: ";
    for (int i = 0; i < n; ++i) {
        cout << Bbit[i] << " ";
    }

    cout << "\nnot A: ";
    for (int i = 0; i < n; ++i) {
        cout << notA[i] << " ";
    }

    cout << "\nAperB: ";
    for (int i = 0; i < n; ++i) {
        cout << AperB[i] << " ";
    }

    cout << "\nAob B: ";
    for (int i = 0; i < n; ++i) {
        cout << AobB[i] << " ";
    }

    cout << "\nA \\ B: ";
    for (int i = 0; i < n; ++i) {
        cout << ArizB[i] << " ";
    }

    cout << "\nAxorB: ";
    for (int i = 0; i < n; ++i) {
        cout << AxorB[i] << " ";
    }

    cout << endl;
}

int main() {
    SetConsoleCP(1251); 
    SetConsoleOutputCP(1251);
    performSetOperations();
    return 0;
}
