#include <iostream>
#include <map>
#include <vector>
using namespace std;

class Node {
    public:
        Node *right;
        Node *left;
        int data;

        Node(int data){
            this->data=data;
            this->left=NULL;
            this->right=NULL;
        }
};
Node* constructTree(vector<int> &inorder,int inStart,int inEnd,vector<int> &preorder,int preStart,int preEnd,map<int,int> inMap){
    if(inStart>inEnd || preStart>preEnd) return NULL;
    Node *temp=new Node(preorder[preStart]);

    int inRoot=inMap[temp->data];
    int numsLeft=inRoot-inStart;

    temp->left=constructTree(inorder,inStart,inRoot-1,preorder,preStart+1,preStart+numsLeft,inMap);
    temp->right=constructTree(inorder,inRoot+1,inEnd,preorder,preStart+numsLeft+1,preEnd,inMap);
    return temp;

}
Node* ReturnTree(vector<int> &inorder,vector<int> &preorder){
    map <int,int> inMap;
    for(int i=0;i<inorder.size();i++){
        inMap[inorder[i]]=i;
    }
    Node * root= constructTree(inorder,0,inorder.size()-1,preorder,0,preorder.size()-1,inMap);
    return root;
}


void PreorderTraversal(Node *root){
    if(root==NULL) return;
    cout<<root->data<<" ";
    PreorderTraversal(root->left);
    PreorderTraversal(root->right);
}

int main(){
    vector<int> i={40,20,50,10,60,30};
    vector<int> p={10,20,40,50,30,60};
    Node *root=ReturnTree(i,p);
    PreorderTraversal(root);
    cout<<endl;
}