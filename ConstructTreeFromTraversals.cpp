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
Node* constructTreePre(vector<int> &inorder,int inStart,int inEnd,vector<int> &preorder,int preStart,int preEnd,map<int,int> inMap){
    if(inStart>inEnd || preStart>preEnd) return NULL;
    Node *temp=new Node(preorder[preStart]);

    int inRoot=inMap[temp->data];
    int numsLeft=inRoot-inStart;

    temp->left=constructTreePre(inorder,inStart,inRoot-1,preorder,preStart+1,preStart+numsLeft,inMap);
    temp->right=constructTreePre(inorder,inRoot+1,inEnd,preorder,preStart+numsLeft+1,preEnd,inMap);
    return temp;

}
Node* ReturnTree(vector<int> &inorder,vector<int> &preorder){
    map <int,int> inMap;
    for(int i=0;i<inorder.size();i++){
        inMap[inorder[i]]=i;
    }
    Node * root= constructTreePre(inorder,0,inorder.size()-1,preorder,0,preorder.size()-1,inMap);
    return root;
}

Node* constructTreePost(vector<int> &inorder,int inStart,int inEnd,vector<int> &postorder,int postStart,int postEnd,map<int,int> inMap){
    if(inStart>inEnd || postStart>postEnd) return NULL;
    Node *temp=new Node(postorder[postEnd]);

    int inRoot=inMap[temp->data];
    int numsLeft=inRoot-inStart;

    temp->left=constructTreePost(inorder,inStart,inRoot-1,postorder,postStart,postStart+numsLeft-1,inMap);
    temp->right=constructTreePost(inorder,inRoot+1,inEnd,postorder,postStart+numsLeft,postEnd-1,inMap);
    return temp;

}
Node* ReturnTreePost(vector<int> &inorder,vector<int> &postorder){
    map <int,int> inMap;
    for(int i=0;i<inorder.size();i++){
        inMap[inorder[i]]=i;
    }
    Node * root= constructTreePost(inorder,0,inorder.size()-1,postorder,0,postorder.size()-1,inMap);
    return root;
}


void PreorderTraversal(Node *root){
    if(root==NULL) return;
    cout<<root->data<<" ";
    PreorderTraversal(root->left);
    PreorderTraversal(root->right);
}

void PostorderTraversal(Node *root){
    if(root==NULL) return;
    PostorderTraversal(root->left);
    PostorderTraversal(root->right);
    cout<<root->data<<" ";
}

int main(){
    vector<int> i={40,20,50,10,60,30};
    vector<int> pre={10,20,40,50,30,60};
    vector<int> post={40,50,20,60,30,10};
    Node *root=ReturnTree(i,pre);
    PreorderTraversal(root);
    cout<<endl;
    Node *root2=ReturnTreePost(i,post);
    PostorderTraversal(root2);
    cout<<endl;
}