/*
Input : No. of items, item(weights), total capacity...
        -> n = 4
        -> capacity = 25
        -> items(array/set) = 10 25 5 10
Output : 
        -> The Solution Vectors are : 
                1   0   1   1   
                0   1   0   0
*/
#include <iostream>
#include <cstring>
#define MAX 20
using namespace std;

int n, capacity;
int set[MAX]; 

void sumOfSubset(int sum, int item, int remainingCapacity, std::string solnVector) {

    if ((sum == capacity) && (remainingCapacity == 0)) { 
        cout << solnVector << endl;
    }
    if ((sum > capacity) || (remainingCapacity == 0)) { 
        return;
    }
    sumOfSubset(sum+set[item], item+1, remainingCapacity-set[item], solnVector + "1   "); 
    sumOfSubset(sum, item+1, remainingCapacity-set[item], solnVector + "0   ");
}
int main()
{
    int totalSum = 0; 
    string solnVector = ""; 

    cout << "Enter no. of elements : ";
    cin >> n;
    cout << "Enter the elements in the set : ";
    for(size_t i{0}; i<n; i++) { 
        cin >> set[i];
        totalSum += set[i];
    }
    cout << "Enter the Capacity : ";
    cin >> capacity;
    cout << endl << "The Solution Vectors are : " << endl;
    sumOfSubset(0, 0, totalSum, solnVector);
    return 0;
}