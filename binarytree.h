#ifndef BINARYTREE_H
#define BINARYTREE_H
#include <iostream>
#include <iomanip>

using namespace std;

template<class item>
struct TreeNode
{
    item value;
    TreeNode<item> *left;
    TreeNode<item> *right;
};

template<class item>
class BinaryTree
{
public:
    BinaryTree(){ root = NULL;}

    ~BinaryTree(){destroySubTree(root);}
    //Binary Tree Operations
    void insertNode(item);
    bool searchNode(item);
    bool searchNode(int num, item &person);
    void remove(item);
    int size() const{return size(root);}
    item& getRoot();

    void displayInOrder() const{ displayInOrder(root);}
    void displayPreOrder() const{ displayPreOrder(root);}
    void displayPostOrder() const{ displayPostOrder(root);}
private:
    TreeNode<item>* root;

    void insert(TreeNode<item> *&, TreeNode<item> *&);
    void destroySubTree(TreeNode<item> *);
    void deleteNode(item, TreeNode<item> *&);
    void makeDeletion(TreeNode<item> *&);
    void displayInOrder(TreeNode<item> *) const;
    void displayPreOrder(TreeNode<item> *) const;
    void displayPostOrder(TreeNode<item> *) const;
    int size(TreeNode<item> *) const;
};

template<class item>
void BinaryTree<item>::insertNode(item num){
    TreeNode<item> *newNode = new TreeNode<item>;

    newNode->value = num;
    newNode->left = newNode->right = NULL;

    //Insert the Node
    insert(root, newNode);
}

template<class item>
void BinaryTree<item>::insert(TreeNode<item> *&nodePtr, TreeNode<item> *&newNode){
    if (nodePtr == NULL)
        nodePtr = newNode;
    else if (newNode->value < nodePtr->value)
        insert(nodePtr->left, newNode);
    else
        insert(nodePtr->right, newNode);
}

template<class item>
void BinaryTree<item>::displayInOrder(TreeNode<item> *nodePtr) const{
    if(nodePtr){
        displayInOrder(nodePtr->left);
        cout << nodePtr->value << " ";
        displayInOrder(nodePtr->right);
    }
}

template<class item>
void BinaryTree<item>::displayPreOrder(TreeNode<item> *nodePtr) const{
    if(nodePtr){
        cout << nodePtr->value << " ";
        displayPreOrder(nodePtr->left);
        displayPreOrder(nodePtr->right);
    }
}

template<class item>
void BinaryTree<item>::displayPostOrder(TreeNode<item> *nodePtr) const{
    if(nodePtr){
        displayPostOrder(nodePtr->left);
        displayPostOrder(nodePtr->right);
        cout << nodePtr->value << " ";
    }
}

template<class item>
void BinaryTree<item>::destroySubTree(TreeNode<item> *nodePtr){
    cout << "Binary Tree Destroyed\n";
    delete nodePtr;
}

template<class item>
bool BinaryTree<item>::searchNode(item num){
    TreeNode<item>* nodePtr = root;

    while(nodePtr){
        if (nodePtr->value == num)
            return true;
        else if (num < nodePtr->value)
            nodePtr = nodePtr->left;
        else
            nodePtr = nodePtr->right;
    }
    return false;
}

template<class item>
bool BinaryTree<item>::searchNode(int num,item& person){
    TreeNode<item>* nodePtr = root;

    while(nodePtr){
        if (nodePtr->value == num){
            person = nodePtr->value;
            return true;
        }else if (num < nodePtr->value)
            nodePtr = nodePtr->left;
        else
            nodePtr = nodePtr->right;
    }
    return false;
}

template<class item>
void BinaryTree<item>::remove(item num){
    deleteNode(num, root);
}

template<class item>
void BinaryTree<item>::deleteNode(item num, TreeNode<item> *&nodePtr){
    if (num < nodePtr->value)
        deleteNode(num, nodePtr->left);
    else if (num > nodePtr->value)
        deleteNode(num, nodePtr->right);
    else
        makeDeletion(nodePtr);
}

template<class item>
void BinaryTree<item>::makeDeletion(TreeNode<item> *&nodePtr){
    TreeNode<item> *tempNodePtr;

    if (nodePtr == NULL)
        cout << "Cannot delete empty node\n";
    else if(nodePtr->right == NULL)
    {
        tempNodePtr = nodePtr;
        nodePtr = nodePtr->left;
        delete tempNodePtr;
    }
    else if(nodePtr->left == NULL)
    {
        tempNodePtr = nodePtr;
        nodePtr = nodePtr->right;
        delete tempNodePtr;
    }
    //If the node has two Children
    else
    {
        //Move one node to the right
        tempNodePtr = nodePtr->right;
        //Go to the end left node
        while(tempNodePtr->left)
            tempNodePtr = tempNodePtr->left;
        //Reattach the left subtree
        tempNodePtr->left = nodePtr->left;
        tempNodePtr = nodePtr;
        //Reattach the right subtree
        nodePtr = nodePtr->right;
        delete tempNodePtr;
    }
}

template<class item>
int BinaryTree<item>::size(TreeNode<item> *node) const
{

    if(node == NULL)
        return 0;
    else
        return 1 + size(node->left) + size(node->right);


}

template<class item>
item& BinaryTree<item>::getRoot(){
    return root->value;
}
#endif // BINARYTREE_H
