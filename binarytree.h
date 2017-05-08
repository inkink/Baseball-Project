#ifndef BINARYTREE_H
#define BINARYTREE_H

#include <iostream>
#include <iomanip>

using namespace std;

template <class ItemType>
struct TreeNode
{
    ItemType value;
    TreeNode *left;
    TreeNode *right;
};

template <class ItemType>
class BinaryTree{
public:
    //Constructor
    BinaryTree(){ root = NULL;}

    ~BinaryTree(){destroySubTree(root);}

    //Binary Tree Operations
    void insertNode(ItemType insertMe);
    TreeNode<ItemType>* searchNode(ItemType searchMe);
    void remove(ItemType removeMe);

    int leaf_count() const;
    int non_leaf_count() const;
    int size() const;

    void displayInOrder() const{ displayInOrder(root);}
    void displayPreOrder() const{ displayPreOrder(root);}
    void displayPostOrder() const{ displayPostOrder(root);}

    TreeNode<ItemType>* getFront();
private:
    TreeNode<ItemType>* root;

    void insert(TreeNode<ItemType> *&, TreeNode<ItemType> *&);
    void destroySubTree(TreeNode<ItemType> *);
    void deleteNode(ItemType, TreeNode<ItemType> *&);
    void makeDeletion(TreeNode<ItemType> *&);
    void displayInOrder(TreeNode<ItemType> *) const;
    void displayPreOrder(TreeNode<ItemType> *) const;
    void displayPostOrder(TreeNode<ItemType> *) const;
    int leaf_count(TreeNode<ItemType>* root) const;
    int non_leaf_count(TreeNode<ItemType>* root) const;
    int size(TreeNode<ItemType>* root) const;
};

template <class ItemType>
void BinaryTree<ItemType>::insertNode(ItemType insertMe){
    TreeNode<ItemType> *newNode = new TreeNode<ItemType>;

    newNode->value = insertMe;
    newNode->left = newNode->right = NULL;

    //Insert the Node
    insert(root, newNode);
}

template <class ItemType>
void BinaryTree<ItemType>::insert(TreeNode<ItemType> *&nodePtr, TreeNode<ItemType> *&newNode){
    if (nodePtr == NULL)
        nodePtr = newNode;
    else if (newNode->value < nodePtr->value)
        insert(nodePtr->left, newNode);
    else
        insert(nodePtr->right, newNode);
}

template <class ItemType>
void BinaryTree<ItemType>::displayInOrder(TreeNode<ItemType> *nodePtr) const{
    if(nodePtr){
        displayInOrder(nodePtr->left);
        cout << nodePtr->value << " ";
        displayInOrder(nodePtr->right);
    }
}

template <class ItemType>
void BinaryTree<ItemType>::displayPreOrder(TreeNode<ItemType> *nodePtr) const{
    if(nodePtr){
        cout << nodePtr->value << " ";
        displayPreOrder(nodePtr->left);
        displayPreOrder(nodePtr->right);
    }
}

template <class ItemType>
void BinaryTree<ItemType>::displayPostOrder(TreeNode<ItemType> *nodePtr) const{
    if(nodePtr){
        displayPostOrder(nodePtr->left);
        displayPostOrder(nodePtr->right);
        cout << nodePtr->value << " ";
    }
}

template <class ItemType>
void BinaryTree<ItemType>::destroySubTree(TreeNode<ItemType> *nodePtr){
    while(nodePtr)
        makeDeletion(nodePtr);
}

template <class ItemType>
TreeNode<ItemType>* BinaryTree<ItemType>::searchNode(ItemType searchMe){
    TreeNode<ItemType>* nodePtr = root;

    while(nodePtr){
        if (nodePtr->value == searchMe)
            return nodePtr;
        else if (searchMe < nodePtr->value)
            nodePtr = nodePtr->left;
        else
            nodePtr = nodePtr->right;
    }
    return NULL;
}

template <class ItemType>
void BinaryTree<ItemType>::remove(ItemType removeMe){
    deleteNode(removeMe, root);
}

template <class ItemType>
void BinaryTree<ItemType>::deleteNode(ItemType deleteMe, TreeNode<ItemType> *&nodePtr){
    if (deleteMe < nodePtr->value)
        deleteNode(deleteMe, nodePtr->left);
    else if (deleteMe > nodePtr->value)
        deleteNode(deleteMe, nodePtr->right);
    else
        makeDeletion(nodePtr);
}

template <class ItemType>
void BinaryTree<ItemType>::makeDeletion(TreeNode<ItemType> *&nodePtr){
    TreeNode<ItemType> *tempNodePtr;

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

template <class ItemType>
int BinaryTree<ItemType>::leaf_count(TreeNode<ItemType>* root) const{
    if(root==NULL)
        return 0;
    else if(root->left==NULL&&root->right==NULL)
        return 1;
    else
        return leaf_count(root->left)+leaf_count(root->right);
}

template <class ItemType>
int BinaryTree<ItemType>::non_leaf_count(TreeNode<ItemType>* root) const {
    if(root==NULL)
        return 0;
    else if(root->left==NULL&&root->right==NULL)
        return 0;
    else
        return 1+non_leaf_count(root->left)+non_leaf_count(root->right);
}

template <class ItemType>
int BinaryTree<ItemType>::size(TreeNode<ItemType>* root) const{
    if(root==NULL)
        return 0;
    else
        return 1+size(root->left)+size(root->right);
}

template <class ItemType>
int BinaryTree<ItemType>::leaf_count() const{
    return leaf_count(root);
}

template <class ItemType>
int BinaryTree<ItemType>::non_leaf_count() const{
    return non_leaf_count(root);
}

template <class ItemType>
int BinaryTree<ItemType>::size() const{
    return size(root);
}

template <class ItemType>
TreeNode<ItemType>* BinaryTree<ItemType>::getFront(){
    return root;
}

#endif
