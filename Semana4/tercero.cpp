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
    vector<int> listaNums;

    for(int i = 0; i < numArray; i++){
        string entrada;
        getline(cin, entrada);
        vector<int> entrada1 = split(entrada, ' ');  
        int p = entrada1[1];
        int len = entrada1[0];
        int numMax = sqrt(p);

        string entrada2;
        getline(cin, entrada2);
        vector<int> nums = split(entrada2, ' ');  
        

        vector<int> listaDivisores;
        for (int k= 1;k <= numMax;k++){
            if(p%k == 0){
                listaDivisores.push_back(k);
                if (k != p / k) {
                    listaDivisores.push_back(p / k);
                }
            }

        }

        int contandorEncontrados = 0;
        for (int j: listaDivisores){
            auto encontrado = lower_bound(all(nums),j);
            if(encontrado == nums.end() || *encontrado != j){
                cout << "No es PrimiConjunto" << endl;
                break;
            }
            else{
                contandorEncontrados += 1;
            }

        }
        if(contandorEncontrados == listaDivisores.size()){
            cout << "Es PrimiConjunto" << endl;
        }

    }


    return 0;
}