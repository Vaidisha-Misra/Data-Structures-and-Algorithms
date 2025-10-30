#include <iostream>
#include <queue>
#include <stack>
using namespace std;

class Node{
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
void InorderTraversal(Node *root){
    if(root==NULL) return;
    InorderTraversal(root->left);
    cout<<root->data<<" ";
    InorderTraversal(root->right);
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

void LevelorderTraversal(Node *root){
    if(root==NULL) return;
    queue<Node *> q;
    q.push(root);
    while(!q.empty()){
        Node *current=q.front();
        cout<<current->data<<" ";
        if(current->left) q.push(current->left);
        if(current->right) q.push(current->right);
        q.pop();
    }
}

void IterativePreorderTraversal(Node *root){
    if(root==NULL) return;
    stack <Node *> st;
    st.push(root);
    while(!st.empty()){
        Node *current=st.top();
        cout<<current->data<<" ";
        st.pop();
        if(current->right) st.push(current->right);
        if(current->left) st.push(current->left);
    }
}

void IterativeInorderTraversal(Node *root){
    if(root==NULL) return;
    stack<Node *> st;
    Node *current=root;
    while(true){
        if(current!=NULL){
            st.push(current);
            current=current->left;
        }
        else{
            if(st.empty()) break;
            current=st.top();
            st.pop();
            cout<<current->data<<" ";
            current=current->right;
        }
    }
    
}

int main(){
    Node *root=new Node(1);
    root->left=new Node(2);
    root->right=new Node(3);
    root->left->left= new Node(4);
    root->left->right=new Node(5);
    root->right->left=new Node(6);
    root->right->right=new Node(7);

    InorderTraversal(root);
    cout<<endl;
    IterativeInorderTraversal(root);
    cout<<endl;
    PreorderTraversal(root);
    cout<<endl;
    IterativePreorderTraversal(root);
    cout<<endl;
    PostorderTraversal(root);
    cout<<endl;
    LevelorderTraversal(root);
    cout<<endl;

}