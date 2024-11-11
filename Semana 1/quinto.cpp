#include <iostream>
#include <cmath>

using namespace std;

int main(){

    long long n, max;
    int potencia = 1;


    cin >> n;
    cin >> max;
    long long resultado = n;

    while (resultado<= max){
        cout << resultado << endl;
        resultado *= n;
    }   

    return 0;
}