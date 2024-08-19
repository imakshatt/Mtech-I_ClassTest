#include<bits/stdc++.h>
using namespace std;

int kanpsack(int W, int n, vector<int> &profit, vector<int> &weight){
    vector<vector<int>> m(n+1, vector<int>(W+1, 0));
    for(int i=1;i<=n;i++){
        for(int w=0;w<=W;w++){
            if(weight[i-1] <= w){
                if(profit[i-1]+m[i-1][w-weight[i-1]] >= m[i-1][w]){
                    m[i][w] = profit[i-1]+m[i-1][w-weight[i-1]];
                }
                else{
                    m[i][w] = m[i-1][w];
                }
            }
            else{
                m[i][w] = m[i-1][w];
            }
        }
    }
    cout << "DP table is as follows: " << endl;
    for(int i=0;i<=n;i++){
        for(int w=0;w<=W;w++){
            cout << m[i][w] << " ";
        }
        cout << endl;
    }
    cout << endl << "Selected Items: ";
    int i=n, w=W;
    while(i>0 && w>0){
        if(m[i][w] != m[i-1][w]){
            cout << "Item: " << i << "(Weight: " << weight[i-1] << ", profit: " << profit[i-1] << ")\n";
        }
        i--;
    }
    return m[n][w];
}
int main(){
    int W;
    int n;
    cout << "Enter the Maximum Knapsack Capacity: ";
    cin >> W;
    cout << "Enter the total number of items:  ";
    cin >> n;

    vector<int> profit(n);
    vector<int> weight(n);
    cout << "Enter the (weight and profit): " << endl;
    for(int i=0;i<n;i++){
        cin >> weight[i];
        cin >> profit[i];
    }
    int maxprofit = kanpsack(W,n,profit,weight);
    cout << endl << "Maximum Profit: " << maxprofit;
    return 0;
}