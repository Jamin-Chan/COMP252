//Jamin Chan 8/29/22

#include <iostream>
using namespace std;


void FizzBuzz(int num) {
    if (num % 3 == 0 && num % 5 == 0) {
        printf("FizzBuzz\n");  

    } 
    else if (num % 3 == 0) {
        printf("Fizz\n");
     

    }
    else if (num % 5 == 0) {
        printf("Buzz\n");
  
    }
    else {
        cout << num << "\n";
   
    }
}


int main() {
    int arr[] = { 5, 8, 30, 12, 7, 10};
    int getArrayLength = sizeof(arr) / sizeof(int);

    for (int i = 0; i < getArrayLength; i++) {
        FizzBuzz(arr[i]);
    }
}

