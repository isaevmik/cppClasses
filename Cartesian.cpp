#include <algorithm>
#include <iostream>
#include <vector>
#include <stdlib.h>

using namespace std;

struct node {
    long long int y;
    long long int Size;
    long long int x;
    long long Sum;
    node* Left;
    node* Right;
};

node* NodeInit(long long int x) {
    node* res = new node;
    res->x = x;
    res->Sum = res->x;
    res->y = rand();
    res->Size = 1;
    res->Right = nullptr;
    res->Left = res->Right;
    return res;
}

long long int getSize(node* cartesianT) {
    if (cartesianT == nullptr) {
        return 0;
    }
    long long int szOut = cartesianT->Size;
    return szOut;
}

long long getSum(node* x) {
    if (x == nullptr) {
        return 0;
    }
    return x->Sum;
}

void expandOrNarrow(node* cartesianT) {
    if (cartesianT == nullptr) {
        return;
    }
    cartesianT->Size = 1 + getSize(cartesianT->Left) +
                       getSize(cartesianT->Right);
    cartesianT->Sum = cartesianT->x +
            getSum(cartesianT->Left) +
            getSum(cartesianT->Right);
}

node* Merge(node* cartesianT1,
            node* cartesianT2) {
    if (cartesianT1 == nullptr) {
        return cartesianT2;
    } else if (cartesianT2 == nullptr) {
        return cartesianT1;
    }
    if (cartesianT1->y > cartesianT2->y) {
        cartesianT1->Right = Merge(cartesianT1->Right, cartesianT2);
        expandOrNarrow(cartesianT1);
        return cartesianT1;
    } else {
        cartesianT2->Left = Merge(cartesianT1, cartesianT2->Left);
        expandOrNarrow(cartesianT2);
        return cartesianT2;
    }
}

void Split(node* cartesianT,
           node*& cartesianT1,
           node*& cartesianT2,
           const long long int x) {
    if (cartesianT == nullptr) {
        cartesianT2 = nullptr;
        cartesianT1 = cartesianT2;
        return;
    }
    if (getSize(cartesianT->Left) < x) {
        Split(cartesianT->Right,
              cartesianT->Right, cartesianT2,
              x - getSize(cartesianT->Left) - 1);
        cartesianT1 = cartesianT;
    } else {
        Split(cartesianT->Left, cartesianT1, cartesianT->Left, x);
        cartesianT2 = cartesianT;
    }
    expandOrNarrow(cartesianT);
}

node* insert(const vector<long long int>& inputData) {
    node* res = nullptr;
    for (const auto x : inputData) {
        res = Merge(res, NodeInit(x));
    }
    return res;
}

void ascendingPrint(node* cartesianT) {
    if (cartesianT == nullptr) {
        return;
    }
    ascendingPrint(cartesianT->Left);
    cout << cartesianT->x << ' ';
    ascendingPrint(cartesianT->Right);
}

long long Sum(node*& n) {
    long long s = n->x + getSum(n->Left) + getSum(n->Right);
    return s;
}

long long int getValue(node *t,
                       long long int pos) {
    long long int id = getSize(t->Left);
    if (pos < id) {
        return getValue(t->Left, pos);
    }
    else if (pos == id) {
        return t->x;
    }
    else {
        return getValue(t->Right, pos - id - 1);
    }
}

pair<pair<int, int>, pair<int, int>> extract(int L,
                                             int R) {
    int L1, L2, R1, R2;
    L1 = L / 2 + 1;
    R1 = (R + 1) / 2;
    L2 = (L + 1) / 2;
    R2 = R / 2;
    return {{L1, L2}, {R1, R2}};
}

