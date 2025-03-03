#include <iostream>
#include <stack>
using namespace std;
#include <iostream>
#include <stack>

using namespace std;

class Node {
public:
    int val;
    Node* left;
    Node* right;
    Node(int x) : val(x), left(nullptr), right(nullptr) {}
    void insert(int x) {
        Node* curr = this;
        while (true) {
            if (x < curr->val) {
                if (curr->left) curr = curr->left;
                else { curr->left = new Node(x); return; }
            } else {
                if (curr->right) curr = curr->right;
                else { curr->right = new Node(x); return; }
            }
        }
    }
    bool search(int x) {
        Node* curr = this;
        while (curr) {
            if (x == curr->val) {
                return true;
            } else if (x < curr->val) {
                curr = curr->left; 
            } else {
                curr = curr->right;
            }
        }
        return false;
    }
    void inorder() {
        stack<Node*> st;
        Node* curr = this;
        bool first = true;
        while (!st.empty() || curr) {
            while (curr) {
                st.push(curr);
                curr = curr->left;
            }
            curr = st.top();
            st.pop();
            if (!first) cout << " -> ";
            cout << curr->val;
            first = false;
            curr = curr->right;
        }
        cout << endl;
    }

    ~Node() {
        delete left;
        delete right;
    }
};

Node* deleteNode(Node* tree, int x) {
    if (!tree) return nullptr;

    if (x < tree->val) {
        tree->left = deleteNode(tree->left, x);
    } else if (x > tree->val) {
        tree->right = deleteNode(tree->right, x);
    } else {
        if (!tree->left) {
            Node* temp = tree->right;
            delete tree;
            return temp;
        }
        if (!tree->right) {
            Node* temp = tree->left;
            delete tree;
            return temp;
        }
        Node* curr = tree->right;
        while (curr->left) {
            curr = curr->left;
        }

        tree->val = curr->val;
        tree->right = deleteNode(tree->right, curr->val);
    }
    return tree;
}
int main() {
    Node* tree = new Node(5);
    tree->insert(3);
    tree->insert(7);
    tree->insert(2);
    tree->insert(4);
    tree->insert(6);
    tree->insert(8);
    cout << "Nodes inserted:  5 3 7 2 4 6 8" << endl;
    cout << "Inorder traversal: ";
    tree->inorder();
    tree->search(2) ? cout<<"trouve"<<endl: cout<<"non trouve"<<endl;
    tree = deleteNode(tree, 7);
    cout << "Inorder after deleting 7: ";
    tree->inorder();
    delete tree;
    return 0;
}