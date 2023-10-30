/*
Lab 1
Chris Gamboa
This program gives the user the optoin to create an array, put numbres in an array. Check if the numbers in the array are prime or not using both iteraion and recursion method.
*/

#include <iostream>
#include <chrono>
using namespace std;

int IsArrayPrimeIter(int *param, int arrSize){
   int i;
      // Record the start time
   auto start = std::chrono::high_resolution_clock::now();
   cout << "Entering IsArrayPrimeIter function" << endl;
  /* checking numbers in array
   for(int i = 0; i < arrSize; i++){
      cout << "Array number " << i + 1 << ": " << param[i] << endl;
   */

  //check if number is a prime
  for(i = 0; i < arrSize; i++){
   if(param[i] == 1 || param[i] == 0){
      //cout << param[i] << " is NOT a prime" << endl;
      
      // Record the end time
   auto end = std::chrono::high_resolution_clock::now();
      // Calculate the elapsed time
   auto duration = std::chrono::duration_cast<std::chrono::microseconds>(end - start);

   cout << "Exiting IsArrayPrimeIter functoin" << endl;
   cout << "Time taken by IsArrayPrimeIter: " << duration.count() << " microseconds" << endl;
   
      return 0;
      }
   } 
   for(int x = 0; x < arrSize; ++x){
   for(i = 2; i <= param[x] / 2; ++i){
      if(param[x] % i == 0){
      //cout << param[x] << " is NOT a prime" << endl;
      
      // Record the end time
   auto end = std::chrono::high_resolution_clock::now();
      // Calculate the elapsed time
   auto duration = std::chrono::duration_cast<std::chrono::microseconds>(end - start);

   cout << "Exiting IsArrayPrimeIter functoin" << endl;
   cout << "Time taken by IsArrayPrimeIter: " << duration.count() << " microseconds" << endl;
      
      return 0;
      break;
      }
   }
}
  cout << "Exiting IsArrayPrimeIter function" << endl; 
  return 1;
}

bool IsPrimeRecur(int num, int divisor){
   cout << "Entering IsPrimeRecur function" << endl;
    if (num <= 2) return (num == 2) ? true : false; if (num % divisor == 0) return false; if (divisor * divisor > num)
       return true;

    return IsPrimeRecur(num, divisor + 1);
   cout << "Exiting IsPrimeRecur functin" << endl;
}

int IsArrayPrimeRecur(int *param, int arrSize){
   cout << "Entering IsArrayPrimeRecur" << endl;
      // Record the start time
   auto start = std::chrono::high_resolution_clock::now();
   for(int i = 0; i < arrSize; ++i){
      if(IsPrimeRecur(param[i], 2)){
         //cout << param[i] << " is a prime a number" << endl;
         
      } else {
        // cout << param [i] << " is NOT a prime number" << endl;
      // Record the end time
    auto end = std::chrono::high_resolution_clock::now();
      // Calculate the elapsed time
    auto duration = std::chrono::duration_cast<std::chrono::microseconds>(end - start);

   cout << "Exiting IsArrayPrimerecur functoin" << endl;
   cout << "Time taken by IsArrayPrimeRecur: " << duration.count() << " microseconds" << endl;
        return 0;
      }
   }
    // Record the end time
    auto end = std::chrono::high_resolution_clock::now();
    // Calculate the elapsed time
    auto duration = std::chrono::duration_cast<std::chrono::microseconds>(end - start);

   cout << "Exiting IsArrayPrimerecur functoin" << endl;
   cout << "Time taken by IsArrayPrimeRecur: " << duration.count() << " microseconds" << endl;
   return 1;
}

int main(){
   //vars
   int sort_max_size = 16;
   int arraySize = 0;
   int arrayNum;

   //create array 
   cout << "Enter your array size" << endl;
   cin >> arraySize;
   while(arraySize > 16){
      cout << "Error, array too large. Please enter a number less than or equal to 16." << endl;
      cin >> arraySize;
   }
   
   int array[arraySize];

   /* check size of array
   array = new int[arraySize];

   int arraylen = sizeof(array)/sizeof(array[0]);
   cout << "Size of array: " << arraylen << endl;*/

   //put numbers in array
   cout << "Enter numbers separated by spaces for your array" << endl;
   for(int i = 0; i < arraySize; i++){
      cin >>  array[i];
      
   }
   /* check numbers in array
   for(int i = 0; i < arraySize; i++){
      cout << array[i] << " ";
   }*/



   if(IsArrayPrimeIter(array, arraySize) == 0){
      cout << "Array is NOT a prime using iteration." << endl;
   } else{
      cout << "Array is a prime using iteration." << endl;
   }
  if(IsArrayPrimeRecur(array, arraySize) == 0){
      cout << "Array is NOT a prime using recursion" << endl;
  } else {
   cout << "Array is a prime using recursion" << endl;
  }


   return 0;
}