#ifndef BINARYTREE_H
#define BINARYTREE_H
#include <iostream>
#include <iomanip>

using namespace std;

template<class item, class C>
struct TreeNode
{
    item value;
    TreeNode<item, C> *left;
    TreeNode<item, C> *right;
};

template<class item, class C>
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
protected:
    TreeNode<item, C>* root;
private:
    void insert(TreeNode<item, C> *&, TreeNode<item, C> *&);
    void destroySubTree(TreeNode<item, C> *);
    void deleteNode(item, TreeNode<item, C> *&);
    void makeDeletion(TreeNode<item, C> *&);
    void displayInOrder(TreeNode<item, C> *) const;
    void displayPreOrder(TreeNode<item, C> *) const;
    void displayPostOrder(TreeNode<item, C> *) const;
    int size(TreeNode<item, C> *) const;
};

template<class item, class C>
void BinaryTree<item, C>::insertNode(item num){
    TreeNode<item, C> *newNode = new TreeNode<item, C>;

    newNode->value = num;
    newNode->left = newNode->right = NULL;

    //Insert the Node
    insert(root, newNode);
}

template<class item, class C>
void BinaryTree<item, C>::insert(TreeNode<item, C> *&nodePtr, TreeNode<item, C> *&newNode){
    C comparator;
    if (nodePtr == NULL)
        nodePtr = newNode;
    else if (comparator(newNode->value, nodePtr->value))
        insert(nodePtr->left, newNode);
    else
        insert(nodePtr->right, newNode);
}

template<class item, class C>
void BinaryTree<item, C>::displayInOrder(TreeNode<item, C> *nodePtr) const{
    if(nodePtr){
        displayInOrder(nodePtr->left);
        cout << nodePtr->value << endl;
        displayInOrder(nodePtr->right);
    }
}

template<class item, class C>
void BinaryTree<item, C>::displayPreOrder(TreeNode<item, C> *nodePtr) const{
    if(nodePtr){
        cout << nodePtr->value << " ";
        displayPreOrder(nodePtr->left);
        displayPreOrder(nodePtr->right);
    }
}

template<class item, class C>
void BinaryTree<item, C>::displayPostOrder(TreeNode<item, C> *nodePtr) const{
    if(nodePtr){
        displayPostOrder(nodePtr->left);
        displayPostOrder(nodePtr->right);
        cout << nodePtr->value << " ";
    }
}

template<class item, class C>
void BinaryTree<item, C>::destroySubTree(TreeNode<item, C> *nodePtr){
    cout << "Binary Tree Destroyed\n";
    delete nodePtr;
}

template<class item, class C>
bool BinaryTree<item, C>::searchNode(item num){
    TreeNode<item, C>* nodePtr = root;
    C comparator;
    while(nodePtr){
        if (nodePtr->value == num)
            return true;
        else if (comparator(num, nodePtr->value))
            nodePtr = nodePtr->left;
        else
            nodePtr = nodePtr->right;
    }
    return false;
}

template<class item, class C>
bool BinaryTree<item, C>::searchNode(int num,item& person){
    TreeNode<item, C>* nodePtr = root;
    C comparator;
    while(nodePtr){
        if (nodePtr->value == num){
            person = nodePtr->value;
            return true;
        }else if (comparator(num, nodePtr->value))
            nodePtr = nodePtr->left;
        else
            nodePtr = nodePtr->right;
    }
    return false;
}

template<class item, class C>
void BinaryTree<item, C>::remove(item num){
    deleteNode(num, root);
}

template<class item, class C>
void BinaryTree<item, C>::deleteNode(item num, TreeNode<item, C> *&nodePtr){
    C comparator;
    if (comparator(num, nodePtr->value))
        deleteNode(num, nodePtr->left);
    else if (num > nodePtr->value)
        deleteNode(num, nodePtr->right);
    else
        makeDeletion(nodePtr);
}

template<class item, class C>
void BinaryTree<item, C>::makeDeletion(TreeNode<item, C> *&nodePtr){
    TreeNode<item, C> *tempNodePtr;

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

template<class item, class C>
int BinaryTree<item, C>::size(TreeNode<item, C> *node) const
{

    if(node == NULL)
        return 0;
    else
        return 1 + size(node->left) + size(node->right);


}

template<class item, class C>
item& BinaryTree<item, C>::getRoot(){
    return root->value;
}
#endif // BINARYTREE_H
