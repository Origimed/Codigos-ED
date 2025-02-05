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

    ios::sync_with_stdio(false);cin.tie(0);
    int numArray; 
    cin >> numArray;
    cin.ignore();
    for(int i = 0; i < numArray; i++){
        string entrada;
        getline(cin, entrada);
        vector<int> pesos = split(entrada, ',');
        sort(all(pesos));
        int menorPesadoDer  = pesos[pesos.size() - 1];
        int diferencia = pesos[pesos.size() - 1]; 
        vector<int> izquierda;
        vector<int> derecha;

        for (int i = 0; i < pesos.size()-1; i++){
            if(diferencia >= 0 && pesos[i] <= menorPesadoDer){
                diferencia -= pesos[i];
                izquierda.push_back(pesos[i]);
            }
            else{
                diferencia += pesos[i];
                menorPesadoDer = pesos[i];
                derecha.push_back(pesos[i]);
            }


        }
        cout << abs(diferencia) << endl;



    }


}

