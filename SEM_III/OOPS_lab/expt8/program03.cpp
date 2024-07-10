//Write a program to implement binary search and bubble sort on an array
//22CO35 Neel de Souza 7/11/23
#include <iostream>
using namespace std;

int binarySearch(const int arr[], int size, int item)
{
    int left = 0;
    int right = size - 1;

    while (left <= right)
    {
        int mid = left + (right - left) / 2;

        if (arr[mid] == item)
        {
            return mid; 
        } 
        else if (arr[mid] < item) 
        {
            left = mid + 1;
        } 
        else 
        {
            right = mid - 1; 
        }
    }

    return -1;
}

void bubbleSort(int arr[], int size) 
{
    for (int i = 0; i < size - 1; ++i) 
    {
        for (int j = 0; j < size - i - 1; ++j) 
        {
            if (arr[j] > arr[j + 1]) 
            {
                  swap(arr[j], arr[j + 1]);
            }
        }
    }
}

void displayArray(const int arr[], int size) 
{
    for (int i = 0; i < size; ++i) 
    {
        cout << arr[i] << " ";
    }
    cout <<endl;
}

int main() 
{
    const int size = 10;
    cout<<"Enter unsorted array elements: "<<endl;
    int arr[size];
    for(int i=0;i<arr[size];i++)
	{
	 	cin>>arr[i];
    }
    int item;
    cout << "Original Array: ";
    displayArray(arr, size);

    bubbleSort(arr, size);
    cout <<"Array after Bubble Sort: ";
    displayArray(arr, size);

    cout <<"Enter the element to search: ";
    cin >> item;
    int result = binarySearch(arr, size, item);

    if (result != -1)
    {
        cout <<"Element found at position " << result <<endl;
    } 
    else 
    {
        cout <<"Element not found in the array" <<endl;
    }

    return 0;
}
