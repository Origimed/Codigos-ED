

#include <iostream>
#include <string>
#include <vector>
#include <sstream>
    
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

int main(){

    vector<int> tolFila;

    while (true){

        string entrada;

        getline(cin,entrada);

        vector<string> listaEntrada = split(entrada,' ');
        int num = stoi(listaEntrada[1]);

        if(num == 0){
            break;
        }

        tolFila.push_back(num);


        for(int i = 0; i < tolFila.size(); i++){

            if(tolFila[i] < tolFila.size()){
                tolFila.erase(tolFila.begin() + i);
            }
            
        }
        cout << tolFila.size();

    }

    cout << tolFila.size();



    return 0;
}



     