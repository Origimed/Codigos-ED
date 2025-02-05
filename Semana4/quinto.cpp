#include <iostream>
#include <string>
#include <vector>
#include <sstream>
#include <bits/stdc++.h>

using namespace std;

int insertionSort(std::vector<int>& arr) {
    int n = arr.size();
    int contador = 0;
    for (int i = 1; i < n; ++i) {
        int key = arr[i];      
        int j = i - 1;
        while (j >= 0 && arr[j] > key) {
            contador += 1;
            arr[j + 1] = arr[j];
            --j;
        }
        arr[j + 1] = key;       
    }
    return contador;
}

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
        vector<int> identificaiones = split(entrada, ' ');
        cout << insertionSort(identificaiones) << endl;
    }


}

