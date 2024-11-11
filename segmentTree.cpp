#include<iostream>
#include<vector>

using namespace std;
#define GLOBALSPACE 5

class SegmentTree{

    
    
    class Node{
        public:
        int data;
        int startInterval;
        int endInterval;
        Node *left;
        Node *right;

        

        Node(int startInterval,int endInterval):startInterval(startInterval),endInterval(endInterval),data(0),left(nullptr),right(nullptr){}


    };
    public:   
    
    Node *root;
    SegmentTree(int array[],int ArraySize){
        root=segmentTree(array,0,ArraySize-1);
         cout << "Segment tree built successfully!" << endl;
    }
    Node *segmentTree(int array[],int start,int end){
           if(start==end){
            Node *node=new Node(start,end);
            node->data=array[start];
            cout << "Created leaf node with interval [" << start << "," << end << "] and value: " << node->data << endl;
            return node;
           }
           

           Node *node=new Node(start,end);
           int mid=start+(end-start)/2;


           node->left=segmentTree(array,start,mid);
           node->right=segmentTree(array,mid+1,end);
            cout << "Created internal node with interval [" << start << "," << end << "] and value: " << node->data << endl;
           node->data=node->left->data+node->right->data;


           return node;


    }

    int query(Node *root,int start,int end){
        //case 1:if the node's interval is within the query
        if(root->startInterval>=start&&root->endInterval<=end){
            return root->data;
        }
        //case2: if the node's interval is completely out of the query
        if(root->startInterval>end||root->endInterval<start){
            return 0;
        }

        //case 3: overlapping(if it is past the above cases it means it fits in this cas so no need for if statement)
        int leftSum = query(root->left, start, end);
        int rightSum = query(root->right, start, end);
        return leftSum + rightSum;

    }


    Node *updateNode(Node *root,int index,int value){
        
        if(index>=root->startInterval&&index<=root->endInterval){
            if(index==root->startInterval&&index==root->endInterval){
                root->data=value;
                return root;
            }
            if(index>=root->endInterval){
                root->right=updateNode(root->right,index,value);
            }else{
                root->left=updateNode(root->left,index,value);
            }

        root->data=root->left->data+root->right->data;
            
        }else{
            cout<<"Index out of range"<<endl;

        }

        return root;
      
    }



    void display(Node *root,int space){
       
       if( root==nullptr) return;
       space=space+GLOBALSPACE;
       display(root->right,space);
       cout<<endl;
       for(int i=GLOBALSPACE;i<space;i++){
        cout<<" ";
       }
       cout<<root->data<<"("<<root->startInterval<<","<<root->endInterval<<")"<<endl;
       display(root->left,space);

    }

 

    
};