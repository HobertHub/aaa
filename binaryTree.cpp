#include <iostream>
using namespace std;
struct Node{
    int value;
    Node *Left=NULL,*Right=NULL;
};
class Tree{
private:
    Node* first=NULL;
    void insert(int nums,Node*& nowNode){
        if (nowNode==NULL){
            nowNode=new Node;
            nowNode->value=nums;
        }
        else{
            if (nums<nowNode->value){
                insert(nums,nowNode->Left);
            }
            else{
                insert(nums,nowNode->Right);
            }
        }
    }
    void traversal_preOrder(Node*& nowNode){
        if (nowNode!=NULL){
            cout<<nowNode->value<<" ";
            traversal_preOrder(nowNode->Left);
            traversal_preOrder(nowNode->Right);
        }
    }
    void traversal_inOrder(Node*& nowNode){
        if (nowNode!=NULL){
            traversal_inOrder(nowNode->Left);
            cout<<nowNode->value<<" ";
            traversal_inOrder(nowNode->Right);
        }
    }
    void traversal_postOrder(Node*& nowNode){
        if (nowNode!=NULL){
            traversal_postOrder(nowNode->Left);
            traversal_postOrder(nowNode->Right);
            cout<<nowNode->value<<" ";
        }
    }
    Node* search(int nums,Node*& nowNode){
        if (nowNode!=NULL){
            if (nums<nowNode->value){
                return(search(nums,nowNode->Left));
            }
            else if (nums>nowNode->value){
                return(search(nums,nowNode->Right));
            }
            else{
                return(nowNode);
            }
        }
        else{
            return(NULL);
        }
    }
    void del(int nums,Node*& nowNode){
        if (nowNode->Right!=NULL && nowNode->Left!=NULL){
            cout<<"j";
        }
        else if (nowNode->Right==NULL && nowNode->Left==NULL){
            nowNode=NULL;
        }
        else{
            if (nowNode->Right==NULL){
                cout<<nowNode->value<<"\n";
                nowNode=nowNode->Left;
            }
            else{
                nowNode=nowNode->Right;
            }
        }
    }
public:
    void insert(int nums){
        insert(nums,first);
    }
    void traversal_preOrder(){
        traversal_preOrder(first);
    }
    void traversal_inOrder(){
        traversal_inOrder(first);
    }
    void traversal_postOrder(){
        traversal_postOrder(first);
    }
    Node* search(int nums){
        return(search(nums,first));
    }
    void del(int nums){
        Node* delNode=search(nums,first);
        if (delNode==NULL){
            cout<<"del nums not found";
            cout<<delNode;
        }
        else{
            del (nums,delNode);
        }
    }
};
int main(){
    Tree tree;
    int times;
    cin>>times;
    for (int i=0;i<times;i++){
        int input;
        cin>>input;
        tree.insert(input);
    }

    tree.traversal_preOrder();
    cout<<"\n";
    tree.traversal_inOrder();
/*
    cout<<tree.search(1);
*/
}