#include <iostream>
#include <vector>
#include <algorithm>
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


class Node {
public:
    int key;
    Node* left;
    Node* right;
    int height;

    Node(int key) {
        this->key = key;
        this->left = nullptr;
        this->right = nullptr;
        this->height = 1;
    }
};

class AVLTree {
private:
    Node* root;
    int size;

    Node* insertRecursively(Node* root, int key) {
        if (!root) {
            size++;
            return new Node(key);
        }
        if (key < root->key) {
            root->left = insertRecursively(root->left, key);
        } else {
            root->right = insertRecursively(root->right, key);
        }

        root->height = 1 + std::max(getNodeHeight(root->left), getNodeHeight(root->right));

        int balanceFactor = getNodeBalance(root);
        if (balanceFactor > 1) {
            if (key < root->left->key) {
                return rightRotate(root);
            } else {
                root->left = leftRotate(root->left);
                return rightRotate(root);
            }
        }
        if (balanceFactor < -1) {
            if (key > root->right->key) {
                return leftRotate(root);
            } else {
                root->right = rightRotate(root->right);
                return leftRotate(root);
            }
        }
        return root;
    }

    Node* deleteRecursively(Node* root, int key) {
        if (!root) return root;

        if (key < root->key) {
            root->left = deleteRecursively(root->left, key);
        } else if (key > root->key) {
            root->right = deleteRecursively(root->right, key);
        } else {
            if (!root->left) {
                Node* temp = root->right;
                delete root;
                return temp;
            } else if (!root->right) {
                Node* temp = root->left;
                delete root;
                return temp;
            }
            Node* temp = getMin(root->right);
            root->key = temp->key;
            root->right = deleteRecursively(root->right, temp->key);
        }

        if (!root) return root;

        root->height = 1 + std::max(getNodeHeight(root->left), getNodeHeight(root->right));
        int balanceFactor = getNodeBalance(root);

        if (balanceFactor > 1) {
            if (getNodeBalance(root->left) >= 0) {
                return rightRotate(root);
            } else {
                root->left = leftRotate(root->left);
                return rightRotate(root);
            }
        }
        if (balanceFactor < -1) {
            if (getNodeBalance(root->right) <= 0) {
                return leftRotate(root);
            } else {
                root->right = rightRotate(root->right);
                return leftRotate(root);
            }
        }
        return root;
    }

    Node* leftRotate(Node* z) {
        Node* y = z->right;
        Node* aux = y->left;
        y->left = z;
        z->right = aux;
        z->height = 1 + std::max(getNodeHeight(z->left), getNodeHeight(z->right));
        y->height = 1 + std::max(getNodeHeight(y->left), getNodeHeight(y->right));
        return y;
    }

    Node* rightRotate(Node* z) {
        Node* y = z->left;
        Node* aux = y->right;
        y->right = z;
        z->left = aux;
        z->height = 1 + std::max(getNodeHeight(z->left), getNodeHeight(z->right));
        y->height = 1 + std::max(getNodeHeight(y->left), getNodeHeight(y->right));
        return y;
    }

    int getNodeHeight(Node* root) {
        if (!root) return 0;
        return root->height;
    }

    int getNodeBalance(Node* root) {
        if (!root) return 0;
        return getNodeHeight(root->left) - getNodeHeight(root->right);
    }

    Node* getMin(Node* root) {
        if (!root) return nullptr;
        if (!root->left) return root;
        return getMin(root->left);
    }

    Node* searchRecursively(Node* root, int key) {
        if (!root || root->key == key) return root;
        if (key < root->key) return searchRecursively(root->left, key);
        return searchRecursively(root->right, key);
    }

    void inOrderRecursively(Node* root, std::vector<int>& elements) {
        if (root) {
            inOrderRecursively(root->left, elements);
            elements.push_back(root->key);
            inOrderRecursively(root->right, elements);
        }
    }

    void inPosOrderRecursively(Node* root, std::vector<int>& elements) {
        if (root) {
            inPosOrderRecursively(root->left, elements);
            inPosOrderRecursively(root->right, elements);
            elements.push_back(root->key);
            
        }
    }

public:
    AVLTree() {
        root = nullptr;
        size = 0;
    }

    void insert(int key) {
        if (!search(key)) {
            root = insertRecursively(root, key);
        }
    }

    void deleteKey(int key) {
        if (search(key)) {
            root = deleteRecursively(root, key);
            size--;
        }
    }

    bool search(int key) {
        return searchRecursively(root, key) != nullptr;
    }

    vector<int> inOrder() {
        vector<int> elements;
        inOrderRecursively(root, elements);
        return elements;
    }

    int popMin() {
        if (size == 0) return -1;
        int key = getMin(root)->key;
        deleteKey(key);
        return key;
    }

    vector<int> inpPosOrder() {
        vector<int> elements;
        inPosOrderRecursively(root, elements);
        return elements;
    }


};
int convertToInt(const std::string& str) {
    int result = 0;
    for (char c : str) {
        result = result * 100 + static_cast<int>(c);
    }
    return result;
}

std::string convertToString(int num) {
    std::string result;
    std::string numStr = std::to_string(num);
    
    if (numStr.size() % 2 != 0) {
        numStr = "0" + numStr;
    }

    for (size_t i = 0; i < numStr.size(); i += 2) {
        int asciiValue = std::stoi(numStr.substr(i, 2)); 
        result += static_cast<char>(asciiValue);
    }
    
    return result;
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
        vector<string> letras = split(line, ' ');
 
        AVLTree AVL;
        for(int j = 0; j < letras.size()-1; j++){
            int asciiValue = convertToInt(letras[j]);
            AVL.insert(asciiValue);
        }

        vector<int> elements = AVL.inpPosOrder();
        for(int j = 0; j < elements.size(); j++){
            cout << convertToString(elements[j]);
        }
        cout << endl;

    }
    return 0;
}