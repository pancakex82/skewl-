#include <iostream>
using namespace std;

//derived class dollar
class pound : public currency{
    //non public member for currency type
    string currencyType = "pound";
    public:
    //getter for currency type
    string getCurType(){ return currencyType;};
};

