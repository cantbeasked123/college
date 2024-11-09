//scan
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

void scanleft(int ch, int request[], int n, int startcyl, int largestcyl) {
    int tdhm = (ch - startcyl) + (largestcyl - startcyl);
    cout << "\nTotal Disk Head Movement (Left): " << tdhm << endl;
}

void scanright(int ch, int request[], int n, int endcyl, int smallestcyl) {
    int tdhm = (endcyl - ch) + (endcyl - smallestcyl);
    cout << "\nTotal Disk Head Movement (Right): " << tdhm << endl;
}

int main()
 {
    int n, request[20], startcyl, endcyl, ch, direction;

    cout << "\nEnter the number of requests: ";
    cin >> n;

    cout << "\nEnter the requests: ";
    for (int i = 0; i < n; i++) {
        cin >> request[i];
    }

    cout << "\nEnter the current head position: ";
    cin >> ch;

    cout << "\nEnter starting cylinder: ";
    cin >> startcyl;

    cout << "Enter ending cylinder: ";
    cin >> endcyl;

    bubbleSort(request, n);

    cout << "\nSorted requests: ";
    for (int i = 0; i < n; i++) {
        cout << request[i] << " ";
    }
    cout << endl;

    int smallestcyl = request[0];
    int largestcyl = request[n - 1];

    cout << "\nSmallest cylinder: " << smallestcyl << endl;
    cout << "Largest cylinder: " << largestcyl << endl;

    cout << "\nEnter the direction it is moving: \n1.Left\n2.Right\n\nYour choice: ";
    cin >> direction;

    switch (direction) {
        case 1:
            scanleft(ch, request, n, startcyl, largestcyl);
            break;
        case 2:
            scanright(ch, request, n, endcyl, smallestcyl);
            break;
        default:
            cout << "Invalid direction." << endl;
    }

    return 0;
}
