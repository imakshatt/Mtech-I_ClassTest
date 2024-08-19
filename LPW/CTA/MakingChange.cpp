//
// Created by AKSHAT on 12/2/2023.
//

#include<bits/stdc++.h>
using namespace std;

void MakingChange(int n, vector<int> &coins, int change){
    vector<int> out(n, 0);
    sort(coins.begin(), coins.end(), greater<int>());
    for(int i=0;i<n;i++){
        if(coins[i] > change){
            continue;
        }
        else{
            change-=coins[i];
            out[i]++;
            i--;
        }
    }
    int totalcoins = accumulate(out.begin(), out.end(), 0);
    cout << "TotalCoins = " << totalcoins << endl;
    for(int i=0;i<n;i++){
        if(out[i] > 0){
            cout << "{" << coins[i] << "} x " << out[i] << "times, ";
        }
    }
}

int main(){
    int n;
    cin >> n;
    vector<int> coins(n);
    for(int i=0;i<n;i++){
        cin >> coins[i];
    }
    int change;
    cin >> change;
    MakingChange(n, coins, change);
    return 0;
}
