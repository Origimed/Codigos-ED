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
    string entrada;
    getline(cin, entrada);
    vector<int> idPostes = split(entrada, ' ');
    sort(all(idPostes));

    int numPostes; 
    cin >> numPostes;
    cin.ignore();
    for (int i = 0;i < numPostes; i++){
        string entradaPostes;
        getline(cin, entradaPostes);
        vector<int> postes = split(entradaPostes, ' ');
        int poste00 = postes[0];
        int poste01 = postes[1];

        if(poste00 == poste01){
            cout << "0 kms" << endl;
            break;
        }

        int pos00 = lower_bound(all(idPostes),poste00) - idPostes.begin();
        int pos01 = lower_bound(all(idPostes),poste01) - idPostes.begin();

        cout << abs(pos00 - pos01) << " kms" << endl;


        


    }

    


    

    


    return 0;
}