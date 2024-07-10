#include<iostream>
#include<string>
#include<stdlib.h>
#define max 20
#define infinity 999
using namespace std;

int parent[max];
int find(int i) {
    while(parent[i] != 0)
    i = parent[i];
    return i;
    }

void un(int j, int k) {
    if(j < k)
    parent[j] = k;
    else
    parent[k] = j;
    }

int kruskal(int E[][max], int cost[][max], int n, int t[][max]){
    int i, j, k, u, v;
    int min_cost = 0;
    for(i = 1; i <= n; i++)
    parent[i] = 0;
    i = 0;
    while(i < n-1) {
    int min = infinity;
    for(j = 1; j <= n; j++) {
        for(k = 1; k <= n; k++) {
            if(cost[j][k] < min) {
            min = cost[j][k];
            u = j;
            v = k;
            }
        }
    }

    j = find(u);
    k = find(v);
    if(j != k) {
        i = i + 1;
        t[i][1] = u;
        t[i][2] = v;
        min_cost = min_cost + cost[u][v];
        un(j, k);
    }
    cost[u][v] = cost[v][u] = infinity;

    }
    if(i != n-1)
        cout<<"No Spanning Tree"<<endl;
    else{
        cout<<"The minimum cost spanning tree is:"<<endl;
        for(i = 1; i < n; i++){
            cout<<"(" << t[i][1] << ", " << t[i][2] << ")"<<endl;
            }
        return min_cost;
    }
}


int main() {
    int cost[max][max], n;
    int t[max][max];
    cout<<"Enter the number of vertices in the graph: "<<endl;
    cin>>n;
    cout<<"Enter the cost matrix for the graph: "<<
    endl;
    for(int i = 1; i <= n; i++)
        for(int j = 1; j <= n; j++)
            cin >> cost[i][j];
    int minCost = kruskal(cost, cost, n, t);
    cout<<"Minimum Cost of Spanning Tree: "<<minCost<<endl;
    return 0;
}