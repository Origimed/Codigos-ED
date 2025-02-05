#include <iostream>
#include <stack>
#include <vector>
#include <string>
#include <sstream>

using namespace std;

bool movimientoValido(stack<int>& origen, stack<int>& destino) {
    if (origen.empty()) {
        return false; 
    }
    if (!destino.empty() && destino.top() < origen.top()) {
        return false; 
    }
    return true;
}

string procesaCaso(int discos, vector<pair<char, char>>& movimientos) {
    stack<int> torreA, torreB, torreC;

    for (int i = discos; i >= 1; --i) {
        torreA.push(i);
    }

    for (auto& movimiento : movimientos) {
        char desde = movimiento.first;
        char hacia = movimiento.second;

        stack<int>* origen;
        stack<int>* destino;

        if (desde == 'A') origen = &torreA;
        else if (desde == 'B') origen = &torreB;
        else if (desde == 'C') origen = &torreC;

        if (hacia == 'A') destino = &torreA;
        else if (hacia == 'B') destino = &torreB;
        else if (hacia == 'C') destino = &torreC;

        // Validar el movimiento
        if (!movimientoValido(*origen, *destino)) {
            return "secuencia invalida";
        }

        destino->push(origen->top());
        origen->pop();
    }

    if (torreC.size() == discos) {
        int prev = 0;
        while (!torreC.empty()) {
            int actual = torreC.top();
            torreC.pop();
            if (actual < prev) {
                return "no soluciona la torre";
            }
            prev = actual;
        }
        return "soluciona la torre";
    }

    return "no soluciona la torre";
}

int main() {
    int casos;
    cin >> casos;
    cin.ignore();

    for (int c = 0; c < casos; ++c) {
        int discos;
        cin >> discos;
        cin.ignore();

        vector<pair<char, char>> movimientos;
        string linea;

        while (true) {
            getline(cin, linea);
            if (linea == "X X"){
                break;
            } 

            stringstream ss(linea);
            char desde, hacia;
            ss >> desde >> hacia;
            movimientos.emplace_back(desde, hacia);
        }

        cout << procesaCaso(discos, movimientos) << endl;
    }

    return 0;
}