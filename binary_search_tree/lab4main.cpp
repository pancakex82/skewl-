/*
Lab 04
Chris Gamboa
This lab create a Binary Search Tree, it will auto add 20 dollar objects and allow
the user to do various operations to the binary search tree.
*/
#include <iostream>
#include <cmath>
#include "currency.cpp"
#include "pounds.cpp"
#include "dollars.cpp"
#include "linkedNode.cpp"
#include "queue.cpp"
#include "stack.cpp"
#include "bst.cpp"
#include<fstream>
using namespace std;

int main() {
    currency* array[21];
    BST bt;
    //freopen("file.txt", "w", stdout);//for some reason this will write AND read??? It seems like its getting the input from the numbres that come out from displaying bst
    //ofstream file("file.txt");
    //if(file.is_open()){
    for(int i = 0; i < 21; i++){//create dollar objects for program
        array[i] = new dollar();
    }
//Your pgm will use the following 20 Dollar objects to be created in the exact order in your main to seed the tree: 
    array[1]->add(57.12);
    array[2]->add(23.44);
    array[3]->add(87.43);
    array[4]->add(68.99);
    array[5]->add(111.22);
    array[6]->add(44.55);
    array[7]->add(77.77);
    array[8]->add(18.36);
    array[9]->add(543.21);
    array[10]->add(20.21);
    array[11]->add(345.67);
    array[12]->add(36.18);
    array[13]->add(48.48);
    array[14]->add(101.00);
    array[15]->add(11.00);
    array[16]->add(21.00);
    array[17]->add(51.00);
    array[18]->add(1.00);
    array[19]->add(251.00);
    array[20]->add(151.00); 
    //int intBST;
    for(int i = 1; i <= 20; i++){
        //cout << "index value: " << temp << endl;
        //cout << "array number: " << i << endl;
        bt.insertBST(*array[i]);
        //intBST = i;
}
//cout << "instBST: " << intBST << endl;

//Also, create an output file to write program output as specified in one or more instructions below.
    
//After seeding the data, perform your traversal operations in the specific sequence of breadth-first, 
//in-order, pre-order, post-order, ensuring that output is written out to both screen and file concurrently
    cout << "---START BREADTH FIRST METHOD---" << endl;
    bt.displayBreadthFirst();
    bt.displayBreadthFirst();
    cout << "---END BREADTH FIRST METHOD---" << endl;
    
    cout << "---START IN ORDER METHOD---" << endl;
    bt.displayInOrder();
    cout << "---END IN ORDER METHOD---" << endl;

    cout <<"---START Pre ORDER METHOD---" << endl;
    bt.displayPreOrder();
    cout << "---END Pre ORDER METHOD---" << endl;

    cout << "---START POST ORDER METHOD---" << endl;
    bt.displayPostOrder();
    cout << "---END POST ORDER METHOD---" << endl;

//Perform adequate input data validation when reading data from the user into the tree - 
//if any data item is invalid, ignore the data item and continue to next item but print a
//message to output (both screen and same output file) to indicate which data items were ignored.


//Also, provide the user the option to print output of traversals or exit the program. Once the user 
//selects the option to print data or exits the program, the data in the BST should be printed out to
//both screen and output file in all four traversal methods in the specific sequence of breadth-first, in-order, pre-order, post-order. 
//Then provide interactivity for the user to add/search/delete nodes from the console after the data
//has been seeded into the application.

    int choice, num;
    num = 0;
    while(num != 1){
    cout << "---OPERATIONS---" << endl;
    cout << "1. Add node" << endl;
    cout << "2. Search node" << endl;
    cout << "3. Delete node" << endl;
    cout << "4. Pre-Order tranversal" << endl;
    cout << "5. Post-order tranversal" << endl;
    cout << "6. In-Order tranversal" << endl;
    cout << "7. Quit" << endl;
    cout << "---OPERATIONS---" << endl;
    
    cin >> choice;
    if(choice == 1){//add
        currency* tempCur;//temp object
        double tempDob;//temp double
        tempCur = new dollar();//new temp dollar
        cout << "Enter desired dollar amount to put in BST" << endl;
        cin >> tempDob;
        if(bt.searchDisplay(tempDob) == true){//check if number is already inside
            cout << "Error, this number is already in BST. Please select another number." << endl;
        }
        if(tempDob < 0){//check if number is negative
            cout << "Error, cannot put negative number inside" << endl;
        }

        tempCur->add(tempDob);
        if(bt.searchDisplay(tempDob) == false && tempDob > 0){//values is greater and not in BST, eligble
            bt.insertBST(*tempCur);
            cout << "Number added!" << endl;
        }
    } else if(choice == 2){//search
        cout << "Enter desired dollar to search in BST" << endl;
        double tempDob;
        cin >> tempDob; 
        if(bt.searchDisplay(tempDob) == true){//found in bst
            cout << "Found in BST!" << endl;
        } else if(bt.searchDisplay(tempDob) == false){//not in bst
            cout << "Your number " << tempDob << " was not found in BST." << endl;
        }
    } else if(choice == 3){//delete 
        cout << "Enter the desired dollar to delete in BST" << endl;
        double tempDob;
        cin >> tempDob;
        if(bt.searchDisplay(tempDob) == true){//if number is found in bst, proceeed to delete
            bt.deleteBST(tempDob);
            cout << "Your number, " << tempDob << " was found and removed in BST." << endl;
        } else if(bt.searchDisplay(tempDob) == false){//number is not in bst, 
            cout << "Not in BST. Try another number." << endl;
        }

    } else if(choice == 4){//pre order 
        
        
        cout <<"---START Pre ORDER METHOD---" << endl;
        bt.displayPreOrder();
        cout << "---END Pre ORDER METHOD---" << endl;

    } else if(choice == 5){//post order

        cout << "---START POST ORDER METHOD---" << endl;
        bt.displayPostOrder();
        cout << "---END POST ORDER METHOD---" << endl;

    } else if(choice == 6){//in order

        cout << "---START IN ORDER METHOD---" << endl;
        bt.displayInOrder();
        cout << "---END IN ORDER METHOD---" << endl;

    } else if(choice == 7 ){//quit
        num = 1;
    } else {

        cout << "Try a number 1-7" << endl;
    }
    }
    //}
    //file.close();
//For submission - upload your BST, Dollar/USD and main code files, screenshots of console window and your output files only.
/*------LAB 3 STUFF*------*/    
/*
    cout << "---Dollar object creation---" << endl;
    currency* array[20];
    //create dollar objects 
    for(int i = 0; i < 21; i++){
        array[i] = new dollar();
    }
    SinglyLinkedList list;

    //add values to dollar objects
    array[1]->add(57.12);
    array[2]->add(23.44);
    array[3]->add(87.43);
    array[4]->add(68.99);
    array[5]->add(111.22);
    array[6]->add(44.55);
    array[7]->add(77.77);
    array[8]->add(18.36);
    array[9]->add(543.21);
    array[10]->add(20.21);
    array[11]->add(345.67);
    array[12]->add(36.18);
    array[13]->add(48.48);
    array[14]->add(101.00);
    array[15]->add(11.00);
    array[16]->add(21.00);
    array[17]->add(51.00);
    array[18]->add(1.00);
    array[19]->add(251.00);
    array[20]->add(151.00); 
    cout << "----Singly Linked List----" << endl;
 
    int temp = 0;
//Add the first seven (7) objects from the array into the linked list in order such that they end up in the 
//reverse order in the linked list, i.e. the seventh element as first node and first element as seventh node. If it is easier, you are allowed to insert copies of the objects.
    for(int i = 0; i <= 7; i++){
        //cout << "index value: " << temp << endl;
        //cout << "array number: " << i << endl;
        list.addCurrency(*array[i], temp++);
}

//Search for $87.43 followed by $44.56 - print the results of each.
cout << "--Search for 87.43 and 44.56---" << endl;
//temp double to compare
double tempDob = 87.43;
    if(list.findCurrency(tempDob) == true){//compare
        cout << "Found 87.43!" << endl;//add index number where it was found
    } else {
        cout << "Found 87.43!" << endl;
    }
//temp double to compare
tempDob = 44.56;//
    if(list.findCurrency(tempDob == true)){//compare
        cout << "Found 44.56!" << endl;
    } else {//not found
        cout << "Cannot find 44.56." << endl;
    }
//Remove the node containing $111.22 followed by the node at index 2.
    list.removeCurrency(*array[5]);
    list.removeCurrency(*array[6]);
//Print the contents of the list.
    cout << "---Print the contest of the list---" << endl;
    list.printList();
//Then add the next four (4) objects (#9 thru 12) 
//such that their index in the linked list is calculated as (index in array % 5).
    for(int i = 9; i<= 12; i++){
        list.addCurrency(*array[i], i % 5);
    }
//Remove two (2) objects at indexes (countCurrency % 6) and (countCurrency / 7) in that order.
//cout << "Node count " << list.countCurrency() << endl;
    list.removeCurrency(*array[list.countCurrency() % 6]);
    list.removeCurrency(*array[list.countCurrency() / 7]);
//Print the contents of the list.
    cout << "---Print the contest of the list---" << endl;
    list.printList();
    cout << "----End of Singly Linked List commands.-----" << endl;
//================================================================



//For the stack, perform the following operations in order 
    stack myStack;
    cout << "-----Entering stack operations-----" << endl;
    //Push seven (7) objects starting from the array index 13 onwards to the stack.
    for (int i = 13; i <= 20; i++){
		myStack.push(*array[i]);
    }
    //Peek the top of the stack - print the result.
    cout << "---Peek at the top of the stack" << endl;
    myStack.peek();
    cout << endl;
    //Perform three (3) pops in succession.
    myStack.pop();
    myStack.pop();
    myStack.pop();
    //Print the contents of the stack.
    cout << "---Print contents of stack---" << endl;
    myStack.printStack();
    cout << endl;
    //Push five (5) more objects from the start of the objects array to the stack.
    for (int i = 1; i <= 5; i++){
	    myStack.push(*array[i]);
    }
    //Pop twice in succession.
    myStack.pop();
    myStack.pop();
    //Print the contents of the stack.
    cout << "---Print contents of stack---" << endl;
    myStack.printStack();  
    cout << endl; 
    cout << "-----End of stack operations.-----" << endl;


    //For the queue, perform the following operations in order - 
    cout << "----Entering queue operations.----" << endl;
    Queue myQueue;
    //Enqueue the seven (7) objects at odd indexes starting from index 5 in the array.
	for (int i = 5; i <= 17; i = i + 2){
		myQueue.enqueue(*array[i]);
    }
    //Peek the front and end of the queue - print the results.
    cout << "---Peeking the front and end of queue---" << endl;
    cout << "Front: ";
    myQueue.peekFront();
    cout << "Rear: ";
    myQueue.peekRear();
    cout << endl;
    //Perform two (2) dequeues in succession.
    myQueue.dequeue();
    myQueue.dequeue();
    //Print the contents of the queue.
    cout << "---Print the content of queue---" << endl;
    myQueue.printQueue();
    //Enqueue five (5) more objects from the index 10 in the array.
    for (int i = 10; i <= 14; i++){
		myQueue.enqueue(*array[i]);
    }
    //Dequeue three times in succession. 
    //Adding ->print(); works, I'm not sure if you wanted this to be printed or not. 
    myQueue.dequeue();
    myQueue.dequeue();
    myQueue.dequeue();

    //Print the contents of the queue.
    cout << "---Print the content of queue---" << endl;
    myQueue.printQueue();
    //End the program with a leaving message of your choice. Remember to clean up before the program ends.
    list.destroyList();
    //myStack.destroyStack();
    myQueue.destroyQueue();
    cout <<"-----End of program----" << endl; 
    //Restrict all your input / output to the main driver program only, except for the existing screen print inside the Currency print methods.
*/   
/*------LAB 2 STUFF*------*/    
/*  
    //declaring array, objects
    currency *type[2];
    type[1] = new pound();
    type[2] = new dollar();

    char a, b, c;
    string currencyName;
    double val;
    
    cout << "Enter: 'a/s' 'p/d' 'xx.xx' 'dollar/pound' " << endl;
    
    while(true){
        cin >> a >> b >> val >> currencyName;
        cin.ignore();
        if(a == 'a'){
            if(b == 'd' && currencyName == "dollar"){
                type[2]->add(val);
            } else if(b =='p' && currencyName == "pound"){
                type[1]->add(val);
            } else {
                cout << "Error, invalid addition" << endl;
                type[1]->print();
                type[2]->print();
            }
        } else if(a == 's'){
            if(b == 'd' && currencyName == "dollar"){
                type[2]->subtract(val);
            } else if(b == 'p' && currencyName == "pound"){
                type[1]->subtract(val);
            }
        } else {
            cout << "Error, invalid subtraction" << endl;
            type[0]->print();
            type[1]->print();
        }
        type[1]->print();
        type[2]->print();
        if(a == 'q'){
            break;
        }
        
    }*/
    return 0;
}