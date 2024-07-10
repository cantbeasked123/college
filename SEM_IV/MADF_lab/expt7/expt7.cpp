#include <iostream>
using namespace std;

int max(int item1, int item2); 
int knapsack(int weight[], int profit[], int n, int Capacity);
void knapsackTable(int n, int capacity, int profit[], int weight[], int T[][10]); 
void selectItem(int no_items, int capacity, int profit[], int weight[],int T[][10]);

int main()
{
    int no_items = 4; 
    int capacity = 5; 
    int weight[10] = {0, 2, 1, 3, 3}; 
    int profit[10] = {0, 12, 10, 20, 15}; 
    int T[10][10];

    knapsackTable(no_items, capacity, profit, weight, T);
    selectItem(no_items, capacity, profit, weight, T);

    return(0);
}
int max(int item1, int item2) {
    return ((item1 > item2) ? item1 : item2);
}
void knapsackTable(int no_items, int capacity, int profit[], int weight[], int T[][10]) {

    cout << endl << "KnapSack Table:" << endl;
    for(int i=0; i<=no_items; i++) {
        for(int j=0; j<=capacity; j++) {

            if((i == 0) || (j == 0)) { T[i][j] = 0; }
            else if(weight[i] > j) { T[i][j] = T[i-1][j]; }
            else if(j < weight[i]) { T[i][j] = T[i-1][j]; }
            else { T[i][j] = max(T[i-1][j], T[i-1][j-weight[i]] + profit[i]); }
        }
    }
    for(int i=0; i<=no_items; i++) {
        for(int j=0; j<=capacity; j++) {
            cout << T[i][j] << "\t";  
        }
        cout << endl;
    }
}

void selectItem(int no_items, int capacity, int profit[], int weight[],int T[][10]) {

    int i = no_items;
    int j = capacity;
    bool optimal_solution[10];

    while((i > 0) && (j > 0)) {
        if(T[i][j] != T[i-1][j]) {

            optimal_solution[i] = true;
            cout << endl << "Item added to Knapsack";
            j = j - weight[i];
            i = i - 1;
        }
        else {
            optimal_solution[i] = false;
            i = i - 1;
        }
    }
    cout << endl <<"Maximim profit: " << T[no_items][capacity];  
    cout << endl <<"Optimal solution: ( ";
    for(int i=1; i<=no_items; i++) {
        cout << optimal_solution[i] << "   ";
    }
    cout << ")" << endl;
}
int knapsack(int weight[], int profit[], int n, int Capacity) {

    if(n == 0 || Capacity == 0) {
        return(0);
    }
    if(weight[n-1] > Capacity) {
        return(weight, profit, n-1, Capacity);
    }
    return(
        max(
            knapsack(weight, profit, n-1, Capacity + weight[n-1])+(profit[n-1]),
            knapsack(weight, profit, n-1, Capacity)
        )
    );
}

/*
#include<iostream>
#include<vector>
using namespace std;

int knapsack(int n,int cap,int p[],int w[])
{
    int k[n+1][cap+1];
    for(int i=0;i<=n;i++)
    {
        for(int j=0;j<=cap;j++)
        {
            if(i==0||j==0)
                k[i][j]=0;
            else if(j<w[i-1])
                k[i][j]=k[i-1][j];
            else
                k[i][j]=max((k[i-1][j-w[i-1]]+p[i-1]),(k[i-1][j]));
        }
    }

    cout<<"knapsack table(item weight table):"<<endl;
    cout<<"  ";
    for(int j=0;j<=cap;++j)
        cout<<j<<" ";
    cout<<endl;
    for(int i=0;i<=n;++i)
    {  
        cout<<i<<" ";
        for(int j=0;j<=cap;++j)
        {
            cout<<k[i][j]<<" ";
        }cout<<endl;
    }

    cout<<"maximum profit is: "<<k[n][cap]<<endl;

    vector<int> soln;
    int i=n,j=cap;
    while(i>0 && j>0)
    {
        if(k[i][j]!=k[i-1][j])
        {
            soln.push_back(i);
            j=j-w[i-1];
        }
        i--;
    }

    cout<<"solution vector: "<<endl<<"(";
    for(int i=soln.size()-1;i>=0;--i)
    {
        cout<<soln[i]<<" ";
    }cout<<")"<<endl;
    return k[n][cap];
}

int main()
{
    int n,cap,p[n],w[n];
    cout<<"enter the number of items: ";
    cin>>n;
    cout<<"enter the profit values: "<<endl;
    for(int i=0;i<n;i++)
        cin>>p[i];
    cout<<"enter the weight values: "<<endl;
    for(int i=0;i<n;i++)
        cin>>w[i];
    cout<<"enter the knapsack capacity: ";
    cin>>cap;
    knapsack(n,cap,p,w);
    return 0;
}*/