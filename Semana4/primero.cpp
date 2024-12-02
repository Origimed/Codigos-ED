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

    int numArray; 
    cin >> numArray;
    vector<int> listaNums;
    
    for (int i=0;i<numArray;i++){
        string entrada;
        getline(cin,entrada);
        vector<string> listaEntrada = split(entrada,' ');
        int num = stoi(listaEntrada[1]);
        listaNums.push_back(num);
    }

    for (int j: listaNums){

        cout << j;
    }



    
    return 0;
}



     