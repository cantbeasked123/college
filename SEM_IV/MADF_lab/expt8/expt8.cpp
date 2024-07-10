#include <iostream>
using namespace std;
#define INFINITY 999
#define MAX 20

int n;
int W[MAX][MAX];
int C[MAX][MAX];
int R[MAX][MAX];
int P[MAX];
int Q[MAX];

void display(int matrix[MAX][MAX])
{
    for (size_t i{0}; i<=n; i++) {
        for (size_t j{0}; j<=n; j++) {
            cout << matrix[i][j] << " ";
        }
        cout<<endl;
    }
}
void optimalBST()
{
    int min, min_preorderIndex;
    for (size_t i{0}; i<=n; i++) {
        W[i][i] = Q[i];
        C[i][i] = 0;
        R[i][i] = 0;
    }
    
    for (size_t i{1}; i<=n; i++) {
        for (size_t j{0}; j<=n-i; j++) {
            
            W[j][j+i] = P[j+i-1] + Q[j+i] + W[j][j+i-1];
        }
    }

    for (size_t i{1}; i<=n; i++) {
        for (size_t j{0}; j<=n-i; j++) {
            
            min = INFINITY;
            for (size_t k{j+1}; k<=j+i; k++) {
                
                if (C[j][k-1] + C[k][j+i] < min) {
                    min = C[j][k-1] + C[k][j+i];
                    min_preorderIndex = k;
                }
            }
            C[j][j+i] = min + W[j][j+i]; 
            R[j][j+i] = min_preorderIndex;
        }
    }
    cout << endl << "Weight Matrix: " << endl; display(W);
    cout << "Cost Matrix: " <<endl; display(C);
    cout << "Root Matrix: " <<endl; display(R);
    cout << "Final Cost: " << C[0][n] <<  ::endl;
}
int main()
{
    cout <<endl<< "Enter the number of nodes in BST: ";
    cin >> n;
    cout << "Enter the Probabilities of Successful Search: ";
    for (size_t i{0}; i<n; i++) {
        cin >> P[i];
    }
    cout << "Enter the Probabilities of Unsuccessful Search: ";
    for (size_t i{0}; i<=n; i++) {
        cin >> Q[i];
    }
    optimalBST();

    return 0;
}