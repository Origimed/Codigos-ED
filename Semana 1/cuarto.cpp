#include <iostream>

using namespace std;

int main(){

    int N;

    cin >> N;

    if (N%2 == 0)
    {
        cout << "es multiplo de 2";
    }
    else if (N%3 == 0)
    {
        cout << "es multiplo de 3";
    
    }
    else if (N%5 == 0)
    {
        cout << "es multiplo de 5";
    }
    else if (N%7 == 0)
    {
        cout << "es multiplo de 7";
    }
    else{

        cout << "no es multiplo de ninguno de los primeros cuatro primos";
    }
    

    return 0;
}