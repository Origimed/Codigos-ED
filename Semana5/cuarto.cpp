#include <iostream>
#include <string>
#include <sstream>
#include <deque>
#include <vector>
#include <stack>

using namespace std;

deque<string> split(string str, char delimiter) {
    deque<string> tokens;
    stringstream ss(str);
    string token;   
    while (getline(ss, token, delimiter)) {
        tokens.push_back(token);
    }
    return tokens;
}

bool esParValido(char apertura, char cierre) {
    return (apertura == '{' && cierre == '}') ||
           (apertura == '(' && cierre == ')') ||
           (apertura == '[' && cierre == ']');
}

bool verificarDelimitadores(deque<string>& cola) {
    stack<char> pila;
    for ( string token : cola) {
        if (token == "{" || token == "(" || token == "[") {
            pila.push(token[0]);
        } else if (token == "}" || token == ")" || token == "]") {
            if (pila.empty() || !esParValido(pila.top(), token[0])) {
                return false;
            }
            pila.pop();
        }
    }
    return pila.empty();
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int casos;
    cin >> casos;
    cin.ignore();

    for(int i = 0; i < casos; i++){
        string entrada;
        getline(cin, entrada);
        deque<string> cola = split(entrada, ' ');
        string ultimo = cola.back();
        if(ultimo == ";"){
            cola.pop_back();
        }
        else{
            cout << "incorrecta" << endl;
            continue;
        }
        
        if (verificarDelimitadores(cola)) { 
            cout << "correcta" << endl;
        } else {
            cout << "incorrecta" << endl;
        }
    }

    return 0;
}