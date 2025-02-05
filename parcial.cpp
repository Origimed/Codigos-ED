#include <iostream>
#include <vector>
#include <sstream>
#include <deque>
#include <bits/stdc++.h>
using namespace std;

#define all(v) v.begin(), v.end()

vector<string> split(string str, char delimiter) {
    vector<string> tokens;
    stringstream ss(str);
    string token;   
    while (getline(ss, token, delimiter)) {
        tokens.push_back(token);
    }
    return tokens;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    priority_queue<int> heap;
    int mayorPrestigio = 0;
    while (true)
    {
        if(heap.size() == 0){
            mayorPrestigio = 0;
        }
        string entrada;
        getline(cin,entrada);
        vector<string> listaEntrada = split(entrada,' ');
        if(listaEntrada[0] == "fin"){
            break;
        }

        if(listaEntrada[0] == "ingresa"){
            int prestigio = stoi(listaEntrada[1]);
            int mitadPrestigio;
            if(heap.size() > 0){
                mayorPrestigio = heap.top();
            }
            if(mayorPrestigio % 2 == 0){
                mitadPrestigio = mayorPrestigio/2;
            }
            else{
                mitadPrestigio = (mayorPrestigio / 2) +1;

            }

            if(prestigio >= mitadPrestigio){
                heap.push(prestigio);
                cout << "adelante" << endl;
            }
            else{
                cout << "denegado" << endl;
            }

        }
        if (listaEntrada[0] == "salida"){
            if(heap.size() > 0){
                int prestigioMayor = heap.top();
                heap.pop();
                cout << "hasta pronto" << endl;

            }
        }
        
    }
    
    

    return 0;
}