#include <iostream>
#include <string>
#include <vector>
#include <sstream>

using namespace std;

vector<string> split(string str, char delimiter) {
    vector<string> tokens;
    stringstream ss(str);
    string token;
    
    while (getline(ss, token, delimiter)) {
        tokens.push_back(token);
    }
    return tokens;
}
     
        int main() {
            vector<int> nums;
            while (true)
            {

                string entrada;
                getline(cin,entrada);
                char a = entrada[0];
                if(entrada == "end"){
                    break;
                }
                else if(a == 'C'){
                    if (nums.size() > 0)
                    {
                        nums.pop_back();
                    }
                } 

                else if(a == 'D'){
                    vector<string> listaEntrada = split(entrada,' ');
                    if (stoi(listaEntrada[1]) <= nums.size()){
                        for(int i=0;i < (stoi(listaEntrada[1])); i++){
                        nums.pop_back();
                    }
                    }

                    
                }

                else if (a == 'M'){
                    vector<string> listaEntrada = split(entrada,' ');
                    int min = stoi(listaEntrada[1]);
                    int max = stoi(listaEntrada[2]);

                    if (max <= nums.size())
                    {
                        for(int i = (min -1);i < max;i++){
                        cout << nums[i];
                        }
                        cout << endl;
                    }
                }   
                else{
                    int num = stoi(entrada);
                    nums.push_back(num);
                }

            
            }
            

        }