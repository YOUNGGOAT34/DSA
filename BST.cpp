#include<iostream>
using namespace std;
#include<vector>

#define GLOBALSPACE  5
template<typename T>
class Node{
   public:
   Node<T> *left;
   Node<T> *right;
   T value;

   Node<T>(T value):value(value),left(nullptr),right(nullptr){}
};

template<typename T>
class BST{
    public:
    Node<T> *root;
    BST():root(nullptr){}
    BST(Node<T> *root):root(root){}

    void insert(T value){
        root=insert(root,value);
    }

    Node<T>  *insert(Node<T> *r,T value){
        
        if(r==nullptr){
            return new Node<T>(value);
        }
        if(value<r->value){
          r->left=insert(r->left,value);

        }else{
            r->right=insert(r->right,value);
        }
       return r;
    }

    void display(Node<T>* node,int space) {
        if(node==nullptr) return;

        space=space+GLOBALSPACE;
        display(node->right,space);
        cout<<"\n";
        for(int i=GLOBALSPACE;i<space;i++){
            cout<<" ";

        }

        cout<<node->value<<endl;
        display(node->left,space);
        
    }

    void populateSorted(vector<int> nodes){
        populateSorted(nodes,0,nodes.size());
    }

    void populateSorted(vector<T> nodes,int start,int end){
        if(start>=end){
            return;
        }

      int mid = start + (end - start) / 2;
        insert(nodes[mid]);

        populateSorted(nodes,start,mid);
        populateSorted(nodes,mid+1,end);

    }


    void preorderTreversal(Node<T> *root){
        if(root==nullptr) return;
        cout<<root->value;
        preorderTreversal(root->left);
        preorderTreversal(root->right);

    }

    void inorderTreversal(Node<T> *root){
        if(root==nullptr) return;
        inorderTreversal(root->left);
        cout<<root->value;
        inorderTreversal(root->right);
        
    }

    void postOrderTraversal(Node<T> *root){
        if(root==nullptr) return;
        postOrderTraversal(root->left);
        postOrderTraversal(root->right);
        cout<<root->value; 

    }


   Node<T>* deleteNode(Node<T>* root, T val) {
    if (root == nullptr) return nullptr;

    // Traverse the tree
    if (val < root->value) {
        root->left = deleteNode(root->left, val);
    } else if (val > root->value) {
        root->right = deleteNode(root->right, val);
    } else {
        // Node to be deleted found

        // Case 1: Node with only one child or no child
        if (root->left == nullptr) {
            Node<T>* temp = root;
            root=root->right;
            
            delete temp;
            return root;
        } else if (root->right == nullptr) {
            Node<T>* temp = root;
            root= root->left;
            delete temp;
            return root;
        }

        // Case 2: Node with two children
        Node<T>* temp = findMin(root->right); // Find the minimum value in the right subtree
        root->value = temp->value; // Replace root's value with the minimum value
        root->right = deleteNode(root->right, temp->value); // Delete the inorder successor
    }
    return root;
}

    int height(Node<T> *root){
        if(root==nullptr){ 
            return -1;
        }else{
            int Lheight=height(root->left);
            int Rheight=height(root->right);
            if(Lheight>Rheight){
                return Lheight+1;

            }else{
                return Rheight+1;
            }
        }

    }

    Node<T> *findMin(Node<T> *root){
        while(root->left!=nullptr){
            root=root->left;
        }

        return root;
    }


   
};

