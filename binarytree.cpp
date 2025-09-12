#include<iostream>
#include"bold/mylinkqueue.cpp"
using namespace std;

typedef struct TNode{
    char data;
    TNode *left,*right;
    int lflag,rflag;
}TNode,*BinaryTree;

void treeinit(BinaryTree &tree){
    
}
void treeugly(BinaryTree &tree){
    TNode *node[5];
    for(int i=0;i<5;i++){
        node[i] = (TNode *)malloc(sizeof(TNode));
        node[i]->data = 'a'+i;
        node[i]->left = nullptr;
        node[i]->right = nullptr;
        node[i]->lflag = node[i]->rflag = 0;
    }
    node[0]->left = node[1];
    node[0]->right = node[2];
    node[1]->right = node[3];
    node[2]->left = node[4];
    tree = node[0];
}
void visit(BinaryTree &tree){
    cout<<tree->data;
}

void preorder(BinaryTree &tree){
    if(!tree) return;
    visit(tree);
    preorder(tree->left);
    preorder(tree->right);
}
void inorder(BinaryTree &tree){
    if(!tree) return;
    inorder(tree->left);
    visit(tree);
    inorder(tree->right);
}
void postorder(BinaryTree &tree){
    if(!tree) return;
    postorder(tree->left);
    postorder(tree->right);
    visit(tree);
}
void treedestroy(BinaryTree &tree){
    if(tree->left != nullptr) treedestroy(tree->left);
    if(tree->right != nullptr) treedestroy(tree->right);
    free(tree);
    tree=nullptr;
}

//线索化
//in order
void inthreadnode(BinaryTree &tree,TNode* &pre){
    if(tree != nullptr){
        inthreadnode(tree->left,pre);
        if(tree->left == nullptr){
            tree->left = pre;
            tree->lflag = 1;
        }
        if(pre != nullptr && pre->right ==nullptr){
            pre->right = tree;
            pre->rflag = 1;
        }
        pre = tree;
        inthreadnode(tree->right,pre);
    }
}
void inthread(BinaryTree &tree){
    TNode *pre = nullptr;
    if(tree != nullptr){
        inthreadnode(tree,pre);
        pre->right = nullptr;
        pre->rflag = 1;
    }

}
TNode* inthreadfirst(TNode* node){
    while(node->lflag ==0)
        node = node->left;
    return node;
}
TNode* inthreadnext(TNode * node){
    if(node->rflag == 0){
        return inthreadfirst(node->right);
    }else{
        return node->right;
    }
}

void inorderthreading(BinaryTree &tree){

}
void postorderthreading(BinaryTree &tree){
    
}
//层序遍历
//#include"mylinkqueue.cpp"
void test1(){
    BinaryTree tree;
    treeinit(tree);
    treeugly(tree);
    mylinkqueue<TNode *> mq;
    mq.init();

    mq.enqueue(tree);
    TNode * tnode;
    while(!mq.isempty()){
        mq.dequeue(tnode);
        cout<<tnode->data;
        if(tnode->left){
            mq.enqueue(tnode->left);
        }
        if(tnode->right){
            mq.enqueue(tnode->right);
        }
    }

    mq.destroy();
    treedestroy(tree);
    cout <<endl<< "层序遍历end\n";
}

void test(){
    BinaryTree tree;
    treeinit(tree);
    treeugly(tree);
    inorder(tree);
    cout << endl;
    cout<<"in order end"<<endl;
    preorder(tree);
    cout<<endl;
    cout<<"pre order end"<<endl;
    postorder(tree);
    cout<<endl;
    cout<<"post order end"<<endl;
    int a;
    cin>>a;
    treedestroy(tree);

}


int main(){
    test1();
    
    return 0;
}