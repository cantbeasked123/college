//c++ implementation for optimal binary search tree

//Nathan Cordeiro 22co09


#include <iostream>

#include <iomanip>

#define MAX 20

using namespace std;


int C[MAX][MAX]; // cost matrix

int W[MAX][MAX]; // weight matrix

int R[MAX][MAX]; // root matrix

int q[MAX]; // unsuccessful searches

int p[MAX]; // frequencies


int NUMBER_OF_KEYS; // number of keys in the tree

int KEYS[MAX];


void COMPUTE_W_C_R() {

    int x, min;

    int i, j, k, h, m;

    float average_cost_per_weight;

    int total_cost, total_weight;


    // Construct weight matrix W

    for (i = 0; i <= NUMBER_OF_KEYS; i++) {

        W[i][i] = q[i];

        for (j = i + 1; j <= NUMBER_OF_KEYS; j++)

            W[i][j] = W[i][j - 1] + p[j] + q[j];

    }


    // Construct cost matrix C and root matrix R

    for (i = 0; i <= NUMBER_OF_KEYS; i++)

        C[i][i] = W[i][i];

    for (i = 0; i <= NUMBER_OF_KEYS - 1; i++) {

        j = i + 1;

        C[i][j] = C[i][i] + C[j][j] + W[i][j];

        R[i][j] = j;

    }

    for (h = 2; h <= NUMBER_OF_KEYS; h++)

        for (i = 0; i <= NUMBER_OF_KEYS - h; i++) {

            j = i + h;

            m = R[i][j - 1];

            min = C[i][m - 1] + C[m][j];

            for (k = m + 1; k <= R[i + 1][j]; k++) {

                x = C[i][k - 1] + C[k][j];

                if (x < min) {

                    m = k;

                    min = x;

                }

            }

            C[i][j] = W[i][j] + min;

            R[i][j] = m;

        }


    // Display weight matrix W

    cout << "\nThe weight matrix W:\n";

    for (i = 0; i <= NUMBER_OF_KEYS; i++) {

        for (j = i; j <= NUMBER_OF_KEYS; j++)

            cout << setw(4) << W[i][j];

        cout << "\n";

    }


    // Display Cost matrix C

    cout << "\nThe cost matrix C:\n";

    for (i = 0; i <= NUMBER_OF_KEYS; i++) {

        for (j = i; j <= NUMBER_OF_KEYS; j++)

            cout << setw(4) << C[i][j];

        cout << "\n";

    }


    // Display root matrix R

    std::cout << "\nThe root matrix R:\n";

    for (i = 0; i <= NUMBER_OF_KEYS; i++) {

        for (j = i; j <= NUMBER_OF_KEYS; j++)

            cout << setw(4) << R[i][j];

        cout << "\n";

    }


    // Compute total cost and weight

    total_cost = C[0][NUMBER_OF_KEYS];

    total_weight = W[0][NUMBER_OF_KEYS];


    // Display total cost and weight

    cout << "Total cost: " << total_cost << endl;

    cout << "Total weight: " << total_weight << endl;


    // Compute average cost per weight

    average_cost_per_weight = static_cast<float>(total_cost) / total_weight;


    // Display average cost per weight

    cout << "Average cost per weight: " << average_cost_per_weight << endl;

}


int main() {

    int i;


    cout << "Input number of keys: ";

    cin >> NUMBER_OF_KEYS;

    for (i = 1; i <= NUMBER_OF_KEYS; i++) {

        cout << "key[" << i << "]= ";

        cin >> KEYS[i];

        cout << " frequency = ";

        cin >> p[i];

    }

    for (i = 0; i <= NUMBER_OF_KEYS; i++) {

        cout << "q[" << i << "] = ";

        cin >> q[i];

    }


    COMPUTE_W_C_R();


    return 0;

}