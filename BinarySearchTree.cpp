#include <iostream>
using namespace std;

// Insert a Node
// Search a Node
// Find Min and Max element in the Tree
// Delete a Node
class Node {
    public:
    int data;
    Node *left;
    Node *right;

    Node(int data){
        this->data=data;
        this->left=NULL;
        this->right=NULL;
    }
};

Node* InsertNodeRecursive(int val,Node *root){
    if(root==NULL){
        Node *newNode= new Node(val);
        root=newNode;
    }
    else if(val<root->data){
        root->left=InsertNodeRecursive(val,root->left);
    } 
    else{
        root->right=InsertNodeRecursive(val,root->right);
    }
    return root;
}

Node* IterativeInsert(int val,Node *root){
    if(root==NULL){
        Node *newNode= new Node(val);
        return newNode;
    }
    Node *curr=root;
    while(true){
        if(curr->data>val ){
            if(curr->left) curr=curr->left;
            else{
                Node *newNode= new Node(val);
                curr->left=newNode;
                return root;
            }
        }
        else if(curr->data<=val){
            if(curr->right) curr=curr->right;
            else{
                Node *newNode= new Node(val);
                curr->right=newNode;
                return root;
            }
        }
        
    }
}

Node* SearchNodeRecursive(int val,Node *root){
    if(root==NULL){
        cout<<"Node not found"<<endl;
        return root;
    }
    else if(root->data==val){
        return root;
    }
    else if(val<root->data){
        return SearchNodeRecursive(val,root->left);
    }
    else{
        return SearchNodeRecursive(val,root->right);
    }
}

Node* IterativeSearch(int val,Node *root){
    while(root!=NULL && root->data!=val){
        root=(val<root->data)?root->left:root->right;
    }
    return root;

}

Node* findMin(Node *root){
    if(root==NULL){
        cout<<"Tree is empty"<<endl;
        return NULL;
    }
    while(root->left){
        root=root->left;
    }
    return root;
}

int findMax(Node *root){
    if(root==NULL){
        cout<<"Tree is empty"<<endl;
        return -1;
    }
    else if(root->right==NULL){
        return root->data;
    }
    else{
        return findMax(root->right);
    }

}

void InorderTraversal(Node *root){
    if(root==NULL) return;
    InorderTraversal(root->left);
    cout<<root->data<<" ";
    InorderTraversal(root->right);
}

Node *DeleteNode(int val,Node *root){
    if(root==NULL) return root;
    else if(val<root->data) root->left=DeleteNode(val,root->left);
    else if(val>root->data) root->right=DeleteNode(val,root->right);
    else{
        if(root->left==NULL && root->right==NULL){
            delete root;
            root=NULL;
        }
        else if(root->left==NULL){
            Node *temp=root;
            root=root->right;
            delete temp;
        }
        else if(root->right==NULL){
            Node *temp=root;
            root=root->left;
            delete temp;
        }
        else{
            Node *temp=findMin(root->right);
            root->data=temp->data;
            root->right=DeleteNode(temp->data,root->right);
        }
        
    }
    return root;
}
int main(){
    Node *root=NULL;
    root=IterativeInsert(20,root);
    root=IterativeInsert(13,root);
    root=IterativeInsert(24,root);
    root=IterativeInsert(21,root);
    root=IterativeInsert(18,root);
    root=IterativeInsert(12,root);
    root=IterativeInsert(50,root);
    root=IterativeInsert(23,root);

    InorderTraversal(root);
    cout<<endl;
    cout<<findMax(root)<<endl;
    cout<<findMin(root)->data<<endl;

    root=DeleteNode(24,root);
    InorderTraversal(root);
    cout<<endl;
    root=DeleteNode(21,root);
    InorderTraversal(root);
    cout<<endl;
    root=DeleteNode(18,root);
    InorderTraversal(root);
    cout<<endl;
    


}