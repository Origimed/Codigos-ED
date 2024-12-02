#include <iostream>
#include <string>
#include <vector>
#include <sstream>
    
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

int main(){
    ios:: sync_with_stdio(false);cin.tie(0);
    int numArray; 
    cin >> numArray;
    cin.ignore();
    vector<int> listaNums;

    string entrada;
    getline(cin,entrada);
    vector<string> listaEntrada = split(entrada,' ');  
    
    for (int i=0;i<numArray;i++){
        
        int num = stoi(listaEntrada[i]);
        listaNums.push_back(num);
    }

    int numBusqueda; 
    cin >> numBusqueda;
    cin.ignore();
    vector<int> listaBusqueda;
    string entrada1;
    getline(cin,entrada1);
    vector<string> listaEntrada1 = split(entrada1,' ');
    
    for (int i=0;i<numBusqueda;i++){
        
        int num = stoi(listaEntrada1[i]);
        listaBusqueda.push_back(num);
    }

    int suma = 0;

    for(int j: listaBusqueda){
        auto index = lower_bound(all(listaNums),j);
        if (index != listaNums.end()&& *index == j){
            int pos = index - listaNums.begin();
            suma += pos + 1;
        }
    }

    cout << suma;

    return 0;
}



     