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


int contarRamas(Node* root) {
    if (!root) return 0;
    if (!root->left && !root->right) return 1;
    return contarRamas(root->left) + contarRamas(root->right);
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
        for(int num = 0; num < numeros.size()-1;num++) {
            bst.insert(numeros[num]);
        }

        Node* root = bst.getRoot();
        cout << contarRamas(root) << "\n";
    }
    return 0;
}