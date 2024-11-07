//optimal
#include <iostream>
using namespace std;

int main() {
    int pages[25], frame[3], n, fs, count = 0;
    cout << "Enter the number of referenced strings: ";
    cin >> n;
    cout << "\nEnter the referenced pages:";
    for (int i = 0; i < n; i++) {
    cin >> pages[i];
    }
    cout << "\nEnter the frame size: ";
    cin >> fs;
    for (int i = 0; i < fs; i++) {
    frame[i] = -1;
    }
    cout << "\nPages:\tFrame:\n";
    for (int i = 0; i < n; i++) {
        bool available = false;
        for (int j = 0; j < fs; j++) {
            if (frame[j] == pages[i]) {
                available = true;
                break;
            }
        }
        if (!available) {
            count++;
            int index = -1;
            for (int j = 0; j < fs; j++) {
                if (frame[j] == -1) {
                index = j;
                break;
                }
            }
            if (index == -1) {
                int farthest = -1;

                for (int j = 0; j < fs; j++) {
                    int k;
                    for (k = i + 1; k < n; k++) {
                    if (frame[j] == pages[k]) {
                        if (k > farthest) {
                            farthest = k;
                            index = j;
                        }
                        break;
                    }
                    }
                    if (k == n) {
                        index = j;
                        break;
                    }
                }
            }
            frame[index] = pages[i];
        }
        cout << pages[i] << "\t";
        for (int j = 0; j < fs; j++) {
            cout << frame[j] << " ";
        }
        cout << endl;
    }
    cout << "\nTotal number of page faults: " << count << endl;
    return 0;
}
