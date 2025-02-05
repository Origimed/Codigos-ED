#include <iostream>
#include <string>
#include <sstream>
#include <deque>
#include <vector>

using namespace std;

deque<int> split(string str, char delimiter) {
    deque<int> tokens;
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
    int casos;
    cin >> casos;
    cin.ignore();
    int solucion = 0;
    

    for(int i = 0; i < casos; i++){
        string entrada;
        getline(cin, entrada);
        deque<int> pila = split(entrada, ' ');
        int ultimo = pila.back();
        pila.pop_back();
        while (pila.size() != 0)
        {

            if((pila.back() + ultimo) % 2 == 0){
                ultimo =  (pila.back() + ultimo)/2;
                pila.pop_back();
            }
            else{
                solucion = 1;
                break;
                

            }
        }

        cout << pila.size() + 1<< " " << ultimo << endl;
        
        
    }

    

    return 0;
}