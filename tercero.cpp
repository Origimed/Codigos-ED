#include <iostream>

using namespace std;

int main(){

    int N, N_act;
    int sum_pos = 0;
    int sum_neg = 0;

    cin >> N;

    for (int i = 0; i < N; i++){

        cin >> N_act;

        if (N_act >0){
            sum_pos += N_act;
        }
        else{
            sum_neg += N_act;
        }

    }

    cout << "positivos: " << sum_pos << ", negativos: " << sum_neg;
    
    return 0;
}