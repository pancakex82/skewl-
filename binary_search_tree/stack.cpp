#include <iostream>
using namespace std;
class stack : public SinglyLinkedList{// derived from the SinglyLinkedList but with no additional attributes and the usual stack methods
    public:
    //contructor and createStack (optional) method
    //push which takes a currency object as parameter and adds it to the top of the stack
    void push(currency &obj){
        //Allocate node 
        Node* curNode = new Node();
        Node* prevNode = new Node();
        //Put object in node
        curNode->data = &obj;
        //push curNode on top of stack
        if(getStart() == NULL){//create new stack and make this node start and end
            setStart(curNode);
            setEnd(curNode);
        } else if(getStart() == getEnd()){//if theres a list create AND only one node (check by start == end), put new node in front of head and make new node the end
            prevNode = getStart();
            prevNode->next = curNode;
            setEnd(curNode);
        } else {//all else fails then theres a stack and more than two. Tranverse through list until we hit the end and make new node the end/tail
            prevNode = getStart();
            while(prevNode->next != NULL){//tranverse through list
                prevNode = prevNode->next;
            }
            //once end is reached, prev tail/end will point to new node and new node will be the new tail/end
            prevNode->next = curNode;
            setEnd(curNode);
        }
    }
    //peek which takes no parameter and returns a copy of the currency object at the top of the stack
    void peek(){
        //allocate node
        Node* curNode = new Node();
        //get tail//end
        curNode = getEnd();
        //print
        curNode->data->print();
    }
    //pop which takes no parameter and removes and returns the currency object from the top of the stack
    void pop(){
        //allocate node
        Node* curNode = new Node();
        Node* prevNode = new Node();
        //curnode start at head
        curNode = getStart();
        while(curNode->next != NULL){//tranverse until curnode hits the end
            while(curNode->next != NULL){//keep tranversing
                prevNode = curNode;
                curNode = curNode->next;
            }
            //end is reached, prev node will be the new end/tail and delete old head(curnode)
            setEnd(prevNode);
            delete curNode;
            return;
        }
    }   
    //ensure stack objects do now allow linked list function to be used on them

    void printStack(){
        //allocate new node
        Node* curNode = new Node();

        //this node equals head
        curNode = getStart();
        
        //go through node until next == NULL and prin
        while(curNode->next != NULL){
            //cout << "index #: " << getCount() << endl;
            curNode->data->print();
            curNode = curNode->next;
        }
    }
        //destructor and/or destroystacks (optionsal) methods
    void destroyStack(){

    }

};