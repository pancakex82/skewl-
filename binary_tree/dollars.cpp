#include <iostream>
using namespace std;
/*

I've removed unnecessary code to fix my problem of string CurrencyType not printing. Base class currency can now access derived 
classs non public member currency type.

*/

//derived class pound
class dollar : public currency{
    private:
    //non public member for currency type
    string currencyType = "dollar";
    public:
    //getter for currency type
    string getCurType(){ return currencyType;};
};