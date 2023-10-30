#include <iostream>
#include <cmath>
using namespace std;
//Added pseudocode  
class currency{
    public:
        currency();
        virtual ~currency();
        currency(const currency& p1);
        currency(double input);
        virtual string getCurType() = 0;
        void print();
        int getWhole();
        int getFrac();
        void setWhole(int newWhole);
        void setFrac(int newFrac);
        void add(double input);
        void subtract(double input);
//        bool isEqual(const currency& p1,const currency& p2);
//        void toString(currency p1);
//private integers 
   private:
        int whole;
        int fraction;
};

//default contrusctor 
currency :: currency(){
    whole = 0;
    fraction = 0;
};
//copy contrusctor 
currency :: currency(const currency& p1){
    whole = p1.whole;
    fraction = p1.fraction;
};
//construction parameter for members
currency :: currency(double input){
    whole = int(input);
    fraction = (int)round(fabs(input - trunc(input)) * 1e2);
};
//destructor
currency :: ~currency(){
}
//getters
int currency :: getWhole(){
    return whole;
}
int currency :: getFrac(){
    return fraction;
}

//mutators
void currency :: setWhole(int newWhole){
    whole = newWhole;
}
void currency ::setFrac(int newFrac){
    fraction = newFrac;
}

//methods
//print money
void currency :: print(){
    cout << getWhole() << "." << getFrac()  << " " << getCurType() << endl;//getters get members
}

//add
void currency :: add(double input){
     whole = whole + int(input);
    fraction = fraction + (int)round(fabs(input - trunc(input)) * 1e2);//adds to 1 when ==100
}
//subtract
void currency :: subtract(double input){
    int wholeInput = int(input);
    int fractionInput = (int)round(fabs(input - trunc(input)) * 1e2);//-1 when ==11

    //logic check
    if(whole - wholeInput < 0 || fraction - fractionInput < 0){
        cout << "Error, please try another number" << endl;
    } else {
        whole = whole - wholeInput;
        fraction = fraction - fractionInput;
    }
}
/*
//check equality
bool currency :: isEqual(const currency& p1, const currency& p2){
    if(p1.whole == p2.whole){
        if(p1.whole == p2.whole){
            return true;
        }
   }
    return false;
}

void currency :: toString(currency& p1){
    string result;

}
*/