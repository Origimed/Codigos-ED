#include <iostream>
#include <string>
#include <sstream>
#include <deque>
#include <vector>

using namespace std;

vector<int> split(string str, char delimiter) {
    vector<int> tokens;
    stringstream ss(str);
    string token;   
    while (getline(ss, token, delimiter)) {
        tokens.push_back(stoi(token));
    }
    return tokens;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    deque<pair<int, int>> cola;

    string entrada;
    getline(cin, entrada);

    vector<int> entrada1 = split(entrada, ' ');

    int numEntradas = entrada1[1]; 
    int numComprada = 0;
    int contador = 0;

    for (int i = 0; i < entrada1[0]; i++) {
        string entrada;
        getline(cin, entrada);
        vector<int> entrada2 = split(entrada, ' ');
        cola.push_back(make_pair(entrada2[0], entrada2[1])); 
    }

    while (true) {
        if (cola.empty()) {  
            cout << "quedaron boletas disponibles";
            break;
        }
        int compras = cola.front().second;
        int ID = cola.front().first;
        numComprada += compras;
        contador++;


        if (numComprada >= numEntradas) {
            cout << ID << " " << (compras - (numComprada - numEntradas)) << endl;
            break;
        } 
        if (contador == 5) {
            cola.pop_front();
            contador = 0; 
        } else {
            auto front = cola.front(); 
            cola.pop_front(); 
            cola.push_back(front);
        }
    }

    return 0;
}