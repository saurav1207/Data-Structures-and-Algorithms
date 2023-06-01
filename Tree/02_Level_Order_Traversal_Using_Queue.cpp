#include<bits/stdc++.h>
#define ll long long int 
using namespace std;

class Node{
public:
    ll val;
    Node* left;
    Node* right;

    Node(ll val){
        this->val = val;
        left = NULL;
        right = NULL;
    }
};

void levelOrderTraversal(Node* root){
    if(root == NULL)
        return;

    queue<Node*> q;
    q.push(root);

    while(!q.empty()){
        // int size = q.size(); 
        // cout<<size<<" ";

        Node* current = q.front();
        q.pop();

        cout << current->val << " ";

        if(current->left != NULL)
            q.push(current->left);

        if(current->right != NULL)
            q.push(current->right);
    }
}

int main(){

    Node* node1 = new Node(1);
    Node* node2 = new Node(2);
    Node* node3 = new Node(3);
    Node* node4 = new Node(4);
    Node* node5 = new Node(5);
    Node* node6 = new Node(6);

    node1->left = node2;
    node1->right = node3;
    node2->left = node4;
    node2->right = node5;
    node3->right = node6;

    levelOrderTraversal(node1);

    return 0;
}
