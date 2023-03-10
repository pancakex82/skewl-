#include <iostream>
using namespace std;




class Queue : public SinglyLinkedList{
    public:
    //contructor and createQeueue (optional) methods
    //enqueue which takes a currency object as a parameter and adds it to the end of queue
    void enqueue(currency &obj){
        //Allocate node 
        Node* curNode = new Node();
        Node* prevNode = new Node();
        //Put object in node
        curNode->data = &obj;
        //push curNode on top of stack
        if(getStart() == NULL){//queue is empty
            setStart(curNode);
            setEnd(curNode);
        } else if(getStart() == getEnd()){//queue has only head and tail
            prevNode = getStart();
            prevNode->next = curNode;
            setEnd(curNode);
        } else {//there is 3 in list, need to tranverse list to get to end
            prevNode = getStart();
            while(prevNode->next != NULL){//tranverse through list until prev node is at the end
                prevNode = prevNode->next;
            }
            //prev node points to new node
            prevNode->next = curNode;
            //new node is now end
            setEnd(curNode);
        }
    }
    
    //dequeue which takes no parameter and removes and returns the Currency object from the front of the queue.
    currency *dequeue(){
        //allocate new node
        Node* curNode = new Node();
        Node* nextNode = new Node();
        //next node will be the head/start. temp
        nextNode = getStart();
        //current node will be the node AFTER the head/start
        curNode = nextNode->next;
        //delete current head/start
        delete nextNode;
        //new head/start will be new node
        setStart(curNode);
        return curNode->data;
    }
    //peekFront which takes no parameter and returns a copy of the currency object at the front of the queue
    void peekFront(){
        //allocate new node
        Node* curNode = new Node();
        //get start/head
        curNode = getStart();
        curNode->data->print();
        //return curNode;
    }
    //peekRear which takes no parameter and returns a copy of the currency object at the end of the queue
    void peekRear(){
        //allocate new node
        Node* curNode = new Node();
        //get end/tail
        curNode = getEnd();
        curNode->data->print();
        //return curNode;
    }
    //printQueue method which returns a string signifying the content of the queue from front to tend, tab spaced
    void printQueue(){
        //allocate new node
        Node* curNode = new Node();

        //this node equals head
        curNode = getStart();
        
        while(curNode->next != NULL){//tranverse through node until this node hits end
            curNode->data->print();//each time it goes through the node it will print
            curNode = curNode->next;
        }
    }
    //destructor and/or destroyQueue (optional) methods
    void destroyQueue(){

    }
    //ensure that the queue objects do not allow linked list functions to be used on thme
};
