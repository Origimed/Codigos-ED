#include <iostream>
#include <string>
#include <sstream>
#include <deque>
#include <vector>

using namespace std;

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
    deque<int> cola;

    
    while (true) {
        string entrada;
        getline(cin, entrada);
        vector<string> listaEntrada = split(entrada, ' ');
        if(listaEntrada[0] == "termina"){       
            break;

        }
        else if (listaEntrada[0] == "agrega") {
            cola.push_back(stoi(listaEntrada[1]));
            
        } else if (listaEntrada[0] == "engulle") {
            if(cola.front() > cola.back()){
                cola.pop_back();
            }
            else{
                cola.pop_front();
            }
            
        } else {
            break; 
        }
        
    }

    if(cola.size() == 0){
        cout << "uroboro vacio";
    }
    else{
        cout << "cabeza " << cola.front() <<  " cola " << cola.back();
    }


   
    return 0;
}