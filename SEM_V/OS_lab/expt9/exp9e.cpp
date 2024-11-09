//LOOK
#include <iostream>
using namespace std;

void bubbleSort(int arr[], int n) {
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            if (arr[j] > arr[j + 1]) {
                int temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }
}

void scanleft(int ch, int smallestcyl, int largestcyl) {
    int tdhm = (ch - smallestcyl) + (largestcyl - smallestcyl) ;
    cout << "\nTotal Disk Head Movement (Left): " << tdhm << endl;
}

void scanright(int ch,int largestcyl, int smallestcyl) {
    int tdhm = (largestcyl - ch) + (largestcyl - smallestcyl) ;
    cout << "\nTotal Disk Head Movement (Right): " << tdhm << endl;
}

int main()
 {
    int n, request[20], ch, direction,i;

    cout << "\nEnter the number of requests: ";
    cin >> n;

    cout << "\nEnter the requests: ";
    for (i = 0; i < n; i++) {
        cin >> request[i];
    }

    cout << "\nEnter the current head position: ";
    cin >> ch;
    bubbleSort(request, n);

    cout << "Sorted requests: ";
    for (i = 0; i < n; i++) {
        cout << request[i] << " ";
    }

    int smallestcyl = request[0];
    int largestcyl = request[n - 1];

    cout << "\nEnter the direction it is moving: \n1.Left\n2.Right\n\nYour choice";
    cin >> direction;

    switch (direction) {
        case 1:
            scanleft(ch, smallestcyl, largestcyl);
            break;
        case 2:
            scanright(ch, largestcyl, smallestcyl);
            break;
        default:
            cout << "Invalid direction." << endl;
    }

    return 0;
}
