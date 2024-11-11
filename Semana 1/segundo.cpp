#include <iostream>
using namespace std;

int main(){

    string palabras[2] = {"Hola mundo\n","Hello world\n"};
    int N;
    cin >> N;

    for (int i = 0;i<N;i++){

        cout << palabras[i%2];
    }
    
    return 0;
}