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
    ios::sync_with_stdio(false);
    cin.tie(0);

    int numArray; 
    cin >> numArray;
    cin.ignore();
    vector<int> listaNums;
    
    for(int i = 0; i < numArray; i++){
        string entrada;
        getline(cin, entrada);
        vector<int> nums = split(entrada, ' ');  
        sort(all(nums));

        int numAct = nums[0];
        int contador = 0;

        for (int j = 0; j < nums.size(); j++){
            if (numAct == nums[j]){
                contador += 1;
            } else {
                cout << contador << " ";
                numAct = nums[j];
                contador = 1;
            }
        }
        cout << contador << endl;
    }

    return 0;
}