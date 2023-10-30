#include <iostream>
using namespace std;

//Linked node strucutre/class
//   - data attribute, pointer attribute to next code
//    - data attribute of link node should be a pointer to currency class
//    - NO INNER CLASS/MEMBER STRUC
struct Node{
    currency *data; //contain data
    struct Node* next; //point to next node
};

class SinglyLinkedList{
    private:
    int count; 
    Node *start;
    Node *end;
    public:
    friend class currency;
    //Default contructor
    SinglyLinkedList(){
        start = NULL; //node head
        end = NULL; //node tail
        }
    ~SinglyLinkedList(){};
    //addCurrency method which takes a Currency object and a node index value as parameters to add the Currency to the list at that index
    void addCurrency(currency& obj, int temp){
        //Allocate node 
        Node* curNode = new Node();
        //Put object in node
        curNode->data = &obj;  
        //cout << "You've made it before in(start == NULL)" << endl;

        //If head is null (list tempty), make this node the head
        if(start == NULL){
            //cout << "You're in if(temp ==0) statement" << endl;
            start = curNode;
            end = curNode;

            //cout << "Index value: " << temp << endl;
        //else tranverse through list set this node  according to index number
        } else {
            setCount(temp);
            curNode->next = start;
            start = curNode;
            //cout << "Index value: " << temp << endl;
        }
    }
    //removeCurrency method which takes a Currency object as parameter and removes that Currency object from the list and may return a copy of the Currency
    void removeCurrency(currency &obj){
        //allocate new node
        Node* curNode = new Node();
        //prevNode address to hold
        Node* prevNode = new Node();
        //set this node to head
        curNode = start;
        //search through list
        double object = double(obj.getWhole()) + double(obj.getFrac()) / 100.0;
        while(curNode->next !=NULL){
            //if data matches with data that was passed, delete node
            double tempComp = double(curNode->data->getWhole()) + double(curNode->data->getFrac()) / 100.0;
            if(tempComp == object){//match found, delete this node
                prevNode->next = curNode->next;//curNode acts as a dummy to hold address so prevNode can have it
                delete curNode;//delete node
                return;
            }
            prevNode = curNode;//holds node behind curNode
            curNode = curNode->next;
        }
    }
    //removeCurrency overload method which takes a node index as parameter and removes the Currency object at that index and may return a copy of the Currency
    void removeCurrencyOverload();
    //findCurrency method which takes a Currency object as parameter and returns the node index at which the Currency is found in the list
    bool findCurrency(double tempDub){
        //allocate new node
        Node* curNode = new Node();
        //set this node to head
        curNode = start;
        //search through node
        while(curNode->next != NULL){
            //get data from node and covert whole and frac into a double
            int tempWhole = curNode->data->getWhole();
            int tempFrac = curNode->data->getFrac();
            double tempComp = double(tempWhole) + double(tempFrac) / 100.0;
            //compare the data, if true return true else return false
            if(tempComp == tempDub){
                return true;
            }
            //point node to next node
            curNode = curNode->next;
            }
    };
    //getCurrency method which takes an index values as a parameter and returns the Currency object
    void getCurrency();
    //printList method which returns a string of all the Currency objects in the list in the order of index, tab spaced
    void printList(){
        //allocate new node
        Node* curNode = new Node();

        //this node equals head
        curNode = start;
        
        //go through node until next == NULL and prin
        while(curNode->next != NULL){
            //cout << "index #: " << getCount() << endl;
            curNode->data->print();
            curNode = curNode->next;
        }
    };
    //isListEmpty method which returns if a list is empty or not
    bool isListEmpty();
    //countCurrency method which returns a count of Currency nodes in the list
    int countCurrency(){
        //allocate new node
        Node* curNode = new Node();
        //start at head
        curNode = start;
        //variable to count node
        int i = 0;
        while(curNode != NULL){//go through list and increment i by 1 everytime
            i++;
            curNode = curNode->next;
        }
        return i;//return the given amount
    };

    //Any other methods you think would be useful in your program
    int getCount(){
        return count;
    }
    void setCount(int temp){
        count = temp;
    }
    Node *getStart(){
        return start;
    }
    Node *getEnd(){
        return end;
    }
    void setStart(Node *temp){//node passed will be the new start/head
        start = temp;
    }
    void setEnd(Node *temp){//node passed will be the new end/tail
        Node *prevNode = new Node();
        prevNode = getEnd();
        prevNode = temp;
        end = temp;
        end->next = NULL;
    }

    void destroyList(){

    }
};