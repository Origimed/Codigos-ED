#include <iostream>
#include <string>
#include <sstream>
#include <deque>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> split(string str, char delimiter) {
    vector<int> tokens;
    stringstream ss(str);
    string token;   
    while (getline(ss, token, delimiter)) {
        tokens.push_back(stoi(token));
    }
    return tokens;
}

deque<pair<int, bool>> splitDe(string str, char delimiter, int elfoPos) {
    deque<pair<int, bool>> tokens;
    stringstream ss(str);
    string token;   
    int contador = 1; 
    while (getline(ss, token, delimiter)) {
        if (contador == elfoPos) {
            tokens.push_back(make_pair(stoi(token), true));
        } else {
            tokens.push_back(make_pair(stoi(token), false));
        }
        contador++;
    }
    return tokens;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int casos;
    cin >> casos;
    cin.ignore();

    for (int i = 0; i < casos; i++) {
        string entrada1;
        getline(cin, entrada1);
        vector<int> ciuElfo = split(entrada1, ' ');
        int ciudanos = ciuElfo[0];
        int posElfo = ciuElfo[1];

        string entrada2;
        getline(cin, entrada2);
        deque<pair<int, bool>> numpeticiones = splitDe(entrada2, ' ', posElfo);
        int minutos = 0;

        while (true) {
            numpeticiones.front().first -= 1; 
            minutos += 5;

            if (numpeticiones.front().first == 0 && numpeticiones.front().second) {
                break;
            }

            else if (numpeticiones.front().first == 0) {
                numpeticiones.pop_front();
            }

            else {
                numpeticiones.push_back(numpeticiones.front());
                numpeticiones.pop_front();
            }
        }

        cout << minutos << endl;
    }

    return 0;
}
