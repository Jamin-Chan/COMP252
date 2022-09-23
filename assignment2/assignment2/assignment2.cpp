// Jamin Chan 9/6/22
// Assignemnt 2

#include <iostream>
using namespace std;

void function1(int num) {
    if (num % 2 == 0) {
        cout << 2 * num;
    }
    else {
        cout << 5 * num;
    }
}

void function2(int& num, double& num2, string& word) {
    num = 2;
    num2 = 2;
    word = "two";
}

int reverseDigits(int num) {
    int reversedNum = 0;

    while (num != 0) {
        reversedNum *= 10;
        reversedNum += (num % 10);

        num /= 10;
    }

    return reversedNum;
}


int main() {
    //function1 tests
    printf("function1 tests\n");
    printf("Input: 4 Output should be 8\n");
    printf("Input: 9 Output should be 45\n");

    function1(4);
    printf("\n");
    function1(9);
    printf("\n\n");

    //function2 tests
    printf("function2 tests\n");
    int testNum = 90;
    double testNum2 = 78.4;
    string testWord = "compsci";

    cout << "Before - testNum: " << testNum << " testNum2: " << testNum2 << " testWord: " << testWord << "\n";
    function2(testNum, testNum2, testWord);
    cout << "After - testNum: "<< testNum << " testNum2: " << testNum2 << " testWord: " << testWord << "\n\n";


    //reverseDigit tests
    printf("reverseDigits tests\n");
    cout << reverseDigits(7008) << "\n";
    cout << reverseDigits(-143) << "\n";
    cout << reverseDigits(6500) << "\n";
}
