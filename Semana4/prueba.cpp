#include <iostream>
#include <string>
#include <vector>
#include <sstream>
#include <bits/stdc++.h>

using namespace std;

#define all(v) v.begin(), v.end()

vector<int> split(string str, char delimiter) {
    vector<int> tokens;
    stringstream ss(str);
    string token;   
    while (getline(ss, token, delimiter)) {
        tokens.push_back(stoi(token));
    }
    return tokens;
}

int main(){
    ios::sync_with_stdio(false); cin.tie(0);
    int numArray; 
    cin >> numArray;
    cin.ignore();
    
    for(int i = 0; i < numArray; i++){
        string entrada;
        getline(cin, entrada);
        vector<int> pesos = split(entrada, ',');
        sort(all(pesos));  // Ordenar los pesos
        
        // Inicializar las filas y las sumas
        vector<int> izquierda, derecha;
        int sumaIzquierda = 0, sumaDerecha = 0;
        
        // Distribuir los perros entre las filas tratando de balancear las sumas
        for (int i = 0; i < pesos.size(); i++) {
            // Insertar el perro en la fila con la suma más baja
            if (sumaIzquierda <= sumaDerecha) {
                izquierda.push_back(pesos[i]);
                sumaIzquierda += pesos[i];
            } else {
                derecha.push_back(pesos[i]);
                sumaDerecha += pesos[i];
            }
        }

        // Verificar si la segunda regla se cumple: El perro más pesado de la izquierda no debe ser más pesado que el más liviano de la derecha
        if (izquierda.back() > derecha.front()) {
            swap(izquierda, derecha);  // Intercambiar filas si no se cumple
        }

        // Imprimir la diferencia de peso entre las filas
        cout << abs(sumaIzquierda - sumaDerecha) << endl;

        // Mostrar las filas
        for (int j : izquierda) {
            cout << j << ",";
        }
        cout << endl << "/////////////////////////////////////////" << endl;
        
        for (int j : derecha) {
            cout << j << ",";
        }
        cout << endl;
    }

    return 0;
}
