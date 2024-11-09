#include <iostream>
#include <chrono>
#include <array>
using namespace std;
using namespace chrono;

int main(){

    auto start = high_resolution_clock::now();
    string palabras[2] = {"Hola mundo\n","Hello world\n"};
    int N;
    cin >> N;

    for (int i = 0;i<N;i++){

        cout << palabras[i%2];
    }

    auto end = high_resolution_clock::now();
    auto duration = duration_cast<milliseconds>(end - start);
    cout << "Tiempo de ejecución: " << duration.count() << " ms" << endl;
    return 0;
}