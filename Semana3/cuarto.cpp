#include <iostream>
#include <string>
#include <vector>
#include <algorithm> 

using namespace std;

int main(){


    vector<int> lista;
    
    while (true)
    {
        string entrada;
        cin >> entrada;
        int num = stoi(entrada);

        
        if (num == 0){
            break;
        }
        auto igual = find(lista.begin(),lista.end(),num);

        if(igual != lista.end()){

            lista.erase(igual);
            continue;

        }

        auto mayor = find(lista.begin(),lista.end(),num+1);

        if(mayor != lista.end()){

            lista.erase(mayor);
            continue;

        }

        auto menor = find(lista.begin(),lista.end(),num-1);

        if(menor != lista.end()){

            lista.erase(menor);
            continue;
        }

        lista.push_back(num);

    }


    if (lista.size() == 0){
        cout << 0;
    }
    else{
        for (int i = 0; i < lista.size()-1;i++){

        cout << lista[i] << " ";
    }
    cout << lista[lista.size()-1];

    }
    

}