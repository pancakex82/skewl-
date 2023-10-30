#include <iostream>
using namespace std;
//Declare and implement a BSTNode ADT with a data attribute and two pointer attributes, 
//one for the left child and the other for the right child. Implement the usual getters/setters for these attributes.
struct BSTNode{
    currency *data;
    struct BSTNode *left;
    struct BSTNode *right;
};

//Declare and implement a BST as a link-based ADT whose data will be Dollar objects - the data will be inserted
//based on the actual money value of your Dollar objects as a combination of the whole value and fractional 
//value attributes. 
//For the BST, implement the four traversal methods as well as methods for the usual search, 
//insert, delete, print, count, isEmpty, empty operations and any other needed

class BST{
    private:
    //root node
    BSTNode *root;
    public:
    BST(){
        //start with null
        root = NULL;
    }
    ~BST(){}
    void insertBST(currency& obj, BSTNode* node){//insert double in bst 
        if((double(obj.getWhole()) + double(obj.getFrac())) < (convertDob(node))){//insert left side 
            if(node->left != NULL){
                insertBST(obj, node->left);
                //cout << (convertDob(node)) << " < " << (double(obj.getWhole()) + double(obj.getFrac())) << endl;
            } else {
                node->left = new BSTNode;
                node->left->data = &obj;
                node->left->left = NULL;
                node->left->right = NULL;
                //cout << (convertDob(node)) << " < " << (double(obj.getWhole()) + double(obj.getFrac())) << endl;
            }
        } else {//insert right
            if(node->right != NULL){
                insertBST(obj, node->right);
                //cout << (convertDob(node)) << " > " << (double(obj.getWhole()) + double(obj.getFrac())) << endl;
            } else {
                node->right = new BSTNode;
                node->right->data = &obj;
                node->right->left = NULL;
                node->right->right = NULL;
                //cout << (convertDob(node)) << " > " << (double(obj.getWhole()) + double(obj.getFrac())) << endl;
            }
        }
    }
    void insertBST(currency& obj){
        if(root != NULL){//helper for main
            insertBST(obj, root);
        } else {
            root = new BSTNode;
            root->data = &obj;
            root->right = NULL;
            root->left= NULL;
        }
    }


    void printLevelOrder(BSTNode* root){//print level order traversal a tree
        int h = height(root);
        int i;
        for (i = 1; i <= h; i++)
        printCurrentLevel(root, i);
    }
    void printCurrentLevel(BSTNode* root, int level){//print node at current level
    if (root == NULL){
        return;
    }
    if (level == 1){
        root->data->print();
    }   
    else if (level > 1) {
        printCurrentLevel(root->left, level - 1);
        printCurrentLevel(root->right, level - 1);
        }
    }
    int height(BSTNode* node){//compute height of tree - the number of nodes along the longest path from root node down to farthes leaf node
    if (node == NULL)
        return 0;
    else {
            //compute the height of each subtree
            int lheight = height(node->left);
            int rheight = height(node->right);
 
            //use the larger one 
            if (lheight > rheight) {
                return (lheight + 1);
            }
            else {
                return (rheight + 1);
            }
        }
    }
    void displayBreadthFirst(){//helper for breadth first
        printLevelOrder(getRoot());
    }


    void preOrderTraversal(struct BSTNode* node){//prints nordes in pre order
        if(node == NULL){//empty node
            return;
        }
        //first data of node
        if(node != NULL){
            node->data->print();
            preOrderTraversal(node->left);
            preOrderTraversal(node->right);
        }
    }
    void displayPreOrder(){//helper for preorder
        preOrderTraversal(getRoot());
    }


    void postOrderTraversal(struct BSTNode* node){//prints nodes bottom up
        if(node == NULL){
            return;
        }
        postOrderTraversal(node->left);
        postOrderTraversal(node->right);
        node->data->print();
    }
    void displayPostOrder(){//helper for post order
        postOrderTraversal(getRoot());
    }


    void inOrderTraversal(struct BSTNode* node){//print node in order
        if(node == NULL){
            return;
        }
        inOrderTraversal(node->left);
        node->data->print();
        inOrderTraversal(node->right);
    }
    void displayInOrder(){//helper for inOrder
        inOrderTraversal(getRoot());
    }
BSTNode* deleteBST(double tempDob, BSTNode* node){//delete bode
        BSTNode* tempNode = new BSTNode();
        if(node == NULL){//empty node
            return NULL;
        }
        if(tempDob < (convertDob(node))){//look left
            node->left = deleteBST(tempDob, node->left);
        } else if(tempDob > (convertDob(node))){//look right
            node->right = deleteBST(tempDob, node->right);
        } else {//key found
            if(isLeafNode(node)){
                delete node;
                node = NULL;
            } else if(node->right && node->left){//find min leaf, copy data from min to temp, delete min
                tempNode = findMin(node->right);
                node->data = tempNode->data;
                node->right = deleteBST(tempDob, node->right);
            } else {
                tempNode = node;
                if(node->right == NULL){
                    node = node->left;
                } else if(node->left == NULL){
                    node = node->right;
                    delete tempNode;
                }
            }
        }
        return node;//eveneventually return nood rode after removal node
    }
    BSTNode* deleteBST(double tempDob){//helper for main func
        return deleteBST(tempDob, getRoot());
    }

    bool isLeafNode(BSTNode* node){//check if this node is leaf
        if(node != NULL && node->left == NULL && node->right == NULL){
            return true;
        } else {
        return false;
        }
    }
    BSTNode* findMin(BSTNode* node){//helper func for delete func
        if(node == NULL){
            return node;
        } else if(node->left == NULL){
            return node;
        } else {
            return findMin(node->left);
        }
    }


    bool search(double tempDob,struct BSTNode* node){//search for node
        if(node == NULL){//empty node
            return false;
        }
        if((convertDob(node)) == tempDob){
            return true;
        }
        bool temp1 = search(tempDob, node->left);//recur left
        if(temp1){//node found
            return true;
        }

        bool temp2 = search(tempDob, node->right);//recurd right
        if(temp2){//node found
            return true;
        }
    }
    bool searchDisplay(double tempDob){//helper to display 
        if((search(tempDob, getRoot())) == true){
            return true;
        } else if((search(tempDob, getRoot())) == false){
            return false;
        }
    }

    bool isEmptyBST(BSTNode* node){
        if(node == NULL){
            return true;
        }
    }
    BSTNode *getRoot(){//get root
        return root;
    }
    void setRoot(BSTNode *temp){//set root
        root = temp;
    }
    double convertDob(BSTNode* obj){//convert a node into a double member to compare
        double tempComp = double(obj->data->getWhole()) + double(obj->data->getFrac()) / 100.0;
        return tempComp;
    }
};