#include <iostream>
#include <vector>
#include <sstream>
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



struct Node {
    int key;
    Node* left;
    Node* right;
    Node(int k) : key(k), left(nullptr), right(nullptr) {}
};

class BinarySearchTree {
private:
    Node* root;

    Node* insertRecursively(Node* root, int key) {
        if (!root) {
            return new Node(key);
        }
        if (key < root->key) {
            root->left = insertRecursively(root->left, key);
        } else if (key > root->key) {
            root->right = insertRecursively(root->right, key);
        }
        return root;
    }

    void preOrderRecursively(Node* root, vector<int>& elements) {
        if (root) {
            elements.push_back(root->key);
            preOrderRecursively(root->left, elements);
            preOrderRecursively(root->right, elements);
        }
    }

public:
    BinarySearchTree() : root(nullptr) {}

    void insert(int key) {
        root = insertRecursively(root, key);
    }

    vector<int> preOrder() {
        vector<int> result;
        preOrderRecursively(root, result);
        return result;
    }

    Node* getRoot(){
        return root;
    }
};

int altura(Node* root){
    if (!root) return 0;
    int alturaIzq = altura(root->left);
    int alturaDer = altura(root->right);
    return 1 + max(alturaIzq,alturaDer);
}

int contarNodos(Node* root) {
    if (!root) return 0;
    return 1 + contarNodos(root->left) + contarNodos(root->right);
}

bool completo(Node* root) {
    int h = altura(root);
    int n = contarNodos(root);
    // arbol completo si #nodos == 2^h - 1
    return (n == ( (1 << h) - 1 ));
}



int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int casos;
    cin >> casos;
    cin.ignore();

    for(int i = 0; i < casos; i++) {
        string line;
        getline(cin, line);
        vector<int> numeros = split(line, ' ');

        BinarySearchTree bst;
        for(int j = 0; j < numeros.size()-1; j++){
            bst.insert(numeros[j]);
        }

        if(completo(bst.getRoot())) {
            cout << "completo\n";
        } else {
            cout << "no\n";
        }
    }
    return 0;
}