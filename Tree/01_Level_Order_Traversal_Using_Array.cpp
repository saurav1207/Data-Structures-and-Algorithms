// Generation by generation printing karna --> it does not say order which come first or which come last
// level by level 

// level i de diya toh mein level i+1 de sakta hu --> by iterating all nodes on level i and pushing  there children 

// level 0 pe root node hogi

// How to compute level order traversal using array 
// Homework is to do this using queue


// to swap to array of infinite length is O(1) bcz it swap address 
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
    if(root==NULL) return;
    vector<Node*> currentLevel, nextLevel;
    currentLevel.push_back(root);
    while(currentLevel.size()>0){
        // cout<<currentLevel.size(); // --> to print size
        for(auto itr : currentLevel){
            cout<<(itr->val)<<" ";
            if(itr->left!=NULL){
                nextLevel.push_back(itr->left);
            }
            if(itr->right!=NULL){
                nextLevel.push_back(itr->right);
            }
        }
        swap(currentLevel, nextLevel);
        nextLevel.clear();
    }
}

int main(){
    // freopen("input.txt", "r" ,stdin);
    // freopen("output.txt", "w" ,stdout);

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
}


// jitne bhi leve hai unke size ka product ka factorial ka multiplication 