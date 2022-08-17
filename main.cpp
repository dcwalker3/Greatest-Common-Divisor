#include <iostream>
#include <vector>

using namespace std;

// Function to print vector v by iterating through it.
void printVector(vector<int> v) {
    cout << "Vector: ";
    for (int i = 0; i < v.size(); i++) {
        cout << v[i] << " ";
    }
    cout << endl;
}

// Function to find all divisors for a given number
// Returns: Vector containing all divisors
vector<int> findDivisors(int number){
    vector<int> divisors;
    for(int i = 1; i < number+1; i++){
        if(number % i == 0){
            divisors.push_back(i);
        }
    }
    return divisors;
}


int main() {
    int highestDivisor = 0;

    // Get number inputs from user.
    int num1, num2;
    cout << "Enter two numbers: " << endl;
    cout << "Number 1: ";
    cin >> num1;
    cout << "Number 2: ";
    cin >> num2;

    // Find the divisors of each number and assign them 
    // to an array.
    vector<int> divisors1 = findDivisors(num1);
    vector<int> divisors2 = findDivisors(num2);

    // Get the length of each divisor array
    int lengthDivisors1 = divisors1.size();
    int lengthDivisors2 = divisors2.size();

    // If a element has no divisors (shouldn't happen cause of 1)
    // It will tell the user and then exit.
    if(lengthDivisors1 == 0 || lengthDivisors2 == 0){
        cout << "No divisors found" << endl;
        return 0;
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
    printVector(divisors1);
    printVector(divisors2);
    cout << "The highest divisor is: " << highestDivisor << endl;
    return 0;



}

