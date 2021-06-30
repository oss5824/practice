#include <vector>
#include <queue>
#include <cmath>
#include <string>
#include <stack>
#include <algorithm>
#include <iostream>
using namespace std;
int root;
struct Node
{
    int value;
    Node* left,* right;
    Node(int val) { setValue(val); setLeft(NULL); setRight(NULL); }
    void setLeft(Node* node) { left = node; }
    void setRight(Node* node) { right = node; }
    void setValue(int val) { value = val; }
    int getValue() { return value; }
    Node* getLeft() { return left; }
    Node* getRight() { return right; }
};
void postOrder(Node* node)
{
    if (node == NULL)return;
    if (node->getLeft() != NULL)postOrder(node->getLeft());
    if (node->getRight() != NULL)postOrder(node->getRight());
    cout << node->getValue() << "\n";
}
int main()
{
    cin.tie(NULL); cout.tie(NULL); ios::sync_with_stdio(false);
    cin >> root;
    Node* node = new Node(root);
    int a;
    while (cin >> a) {
        Node* tmp = node;
        Node* newNode = new Node(a);
        while (1) {
            if (tmp->getValue() < a)
            {
                if (tmp->getRight() == NULL) { tmp->setRight(newNode); break; }           
                else tmp = tmp->getRight();
            }
            else
            {
                if (tmp->getLeft() == NULL) { tmp->setLeft(newNode); break; }
                else tmp = tmp->getLeft();
            }
        }
    }
    postOrder(node);
}