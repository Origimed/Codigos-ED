#include <iostream>
#include <string>
#include <vector>
#include <algorithm> 

using namespace std;

int main(){

    vector<long long> lista;
    int m;
    cin >> m;
    
    long long contador = 0;
    while (true)
    {
        long long entrada;
        cin >> entrada;
        
        if (entrada == 0){
            break;
        }

        lista.push_back(entrada);
        contador++;

        if (contador % m == 0) {
            sort(lista.begin(), lista.end());

            int size = lista.size();

            if (size % 2 == 1) { 
                long long numFinal = lista[size / 2];
                cout << numFinal << endl;
            }
            else { 
                long long frac1 = lista[(size / 2) - 1];
                long long frac2 = lista[size / 2];
                if (frac1 == frac2) {
                    cout << frac1 << endl;
                } else {
                    cout << frac1 + frac2 << "/2" << endl;
                }
            }
        }
    }

    return 0;
}
