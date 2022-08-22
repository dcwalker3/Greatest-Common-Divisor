#include "VectorFunctions.h"
#include <iostream>
#include <vector>

using namespace std;


// Function to print all elements of a vector.
void printVector(vector<int> v, int size){
    cout << "Vector: ";
    for (int i = 0; i < size; i++) {
        cout << v[i] << " ";
    }
    cout << endl;
}


// Function to find all divisors for a given number
// Parameters: number to find divisors for
// Returns: Vector containing all divisors
vector<int> findAllDivisors(int number){
    vector<int> divisors;
    for(int i = 1; i < number+1; i++){
        // If the number is a divisor, add it to the vector.
        if(number % i == 0){
            // Add the divisor to the end of the vector.
            divisors.push_back(i);
        }
    }
    return divisors;
}


// Function to find the highest common divisor for two numbers.
// It accomplishes this by finding the divisors for each number and
// comparing them.
// Returns: void
void findGreatestCommonDivisor(){
    int highestDivisor = 0;
    int num1, num2;
    cout << "Enter two numbers: " << endl;
    cout << "Number 1: ";
    cin >> num1;
    cout << "Number 2: ";
    cin >> num2;
    
    // Find the divisors of each number and assign them 
    // to an array.
    vector<int> divisors1 = findAllDivisors(num1);
    vector<int> divisors2 = findAllDivisors(num2);
    
    // Get the length of each divisor array
    int lengthDivisors1 = divisors1.size();
    int lengthDivisors2 = divisors2.size();
    
    // If a element has no divisors (shouldn't happen cause of 1)
    // It will tell the user and then exit.
    if(lengthDivisors1 == 0 || lengthDivisors2 == 0){
        cout << "No divisors found" << endl;
        return;
    }
    
    
    // Loop through each array and see if there are matching divisors.
    for(int i=0; i<lengthDivisors1; i++){
        for(int j=0; j<lengthDivisors2; j++){
            if (divisors1[i] == divisors2[j]){
                
                // Set new variable to highest common divisors
                highestDivisor = divisors1[i];
                
            }
        }
    }
    
    // Print the vectors and highest common divisor to user.
    printVector(divisors1, lengthDivisors1);
    printVector(divisors2, lengthDivisors2);
    cout << "The highest divisor is: " << highestDivisor << endl;    
}