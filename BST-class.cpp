#include <algorithm>
#include <iostream>

using namespace std;

class TreeFunc {
    struct node {
        size_t val;
        node* left;
        node* right;
        ~node() {delete left; delete right;};
    };

private:
    node* root;
    node* insert(node* leaf, size_t Value) {
        if (leaf == nullptr) {
            leaf = new node;
            leaf->val = Value;
            leaf->left = nullptr;
            leaf->right = nullptr;
        } else if (Value < leaf->val) {
            leaf->left = insert(leaf->left, Value);
        } else if (Value > leaf->val) {
            leaf->right = insert(leaf->right, Value);
        }
        return leaf;
    }

public:
    TreeFunc() {root = nullptr;};
    void insert(size_t x) {
        root = insert(root, x);
    }
    node* Root() {
        return root;
    }
  
    int h(node* leaf) { // Высота дерева
        if (leaf == nullptr) {
            return 0;
        } else {
            return (max(h(leaf->left), h(leaf->right)) + 1);
        }
    }
  
    bool isAVLtree(node* leaf) {
        if (leaf == nullptr) {
            return true;
        }
        if (isAVLtree(leaf->left) && isAVLtree(leaf->right) &&
      (abs(h(leaf->left) - h(leaf->right))) <= 1) {
            return true;
        }
        return false;
    }

    void inorderTraversal(node* leaf) { // Обход
        if (leaf != nullptr) {
            inorderTraversal(leaf->left);
            cout << leaf->val << ' ';
            inorderTraversal(leaf->right);
        } else {
            cout << endl;
            return;
        }
    }
  
    void leafPrint(node* leaf) { // Печать листьев
        if (leaf != nullptr) {
            if (leaf->left) {
                leafPrint(leaf->left);
            }
            if (leaf->right) {
                leafPrint(leaf->right);
            }
            if ((leaf->left == nullptr) && (leaf->right == nullptr)) {
                cout << leaf->val << endl;
                return;
            }
        } else {
            return;
        }
    }

    void forkPrint(node* leaf) { // вывод развилок
        if (leaf != nullptr) {
            if (leaf->left) {
                forkPrint(leaf->left);
            }
            if ((leaf->left != nullptr) && (leaf->right != nullptr)) {
                cout << leaf->val << endl;
            }
            if (leaf->right) {
                forkPrint(leaf->right);
            }
        } else {
            return;
        }
    }

    void branchPrint(node* leaf) { // Печать ветки
        if (leaf != nullptr) {
            if (leaf->left) {
                branchPrint(leaf->left);
            }
            if (((leaf->left == nullptr) && (leaf->right != nullptr)) ||
                    (leaf->left != nullptr) && (leaf->right == nullptr)) {
                cout << leaf->val << endl;
            }
            if (leaf->right) {
                branchPrint(leaf->right);
            }
        } else {
            return;
        }
    }
  
    node* getMax(node* leaf) { // Получить максимум
        if (leaf == nullptr) {
            return nullptr;
        } else if (leaf->right == nullptr) {
            return leaf;
        } else {
            return getMax(leaf->right);
        }
    }
  
    node* get2Max(node* leaf) { // Получить второй максимум
        if ((leaf->left) && (leaf->right == nullptr)) {
            return getMax(leaf->left);
        }
        if ((leaf->right->right == nullptr) && (leaf->right->left == nullptr) &&
                (leaf->right)) {
            return leaf;
        }
        return get2Max(leaf->right);
    }
};
