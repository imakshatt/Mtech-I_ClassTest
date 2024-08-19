//
// Created by AKSHAT on 12/3/2023.
//
#include<bits/stdc++.h>
using namespace std;

void printstations(vector<vector<int>> &l, int n, int l_star){
    int i = l_star;
    cout << "Line: " << i << ", Station - " << n << endl;
    for(int j=n;j>=2;j--){
        i = l[i-1][j-1];
        cout << "Line: " << i << ", station - " << j-1 << endl;
    }
}
void assembly(int n){
    vector<vector<int>> a(2, vector<int>(n));
    vector<vector<int>> t(2, vector<int>(n));
    vector<int> e(2);
    vector<int> x(2);
    vector<vector<int>> f(2, vector<int>(n));
    vector<vector<int>> l(2, vector<int>(n));

    cout << "Enter Processing time for line1: ";
    for(int i=0;i<n;i++){
        cin >> a[0][i];
    }
    cout << endl << "Enter the processing time for line2: ";
    for(int i=0;i<n;i++){
        cin >> a[1][i];
    }
    cout << endl << "Enter the Transfer time from line 1 to 2: ";
    for(int i=0;i<n-1;i++){
        cin >> t[0][i];
    }
    cout << endl << "Enter the transfer time from line 2 to 1: ";
    for(int i=0;i<n-1;i++){
        cin >> t[1][i];
    }
    cout << endl << "Enter the entering time: ";
    cin >> e[0] >> e[1];
    cout << endl << "enter the execution time: ";
    cin >> x[0] >> x[1];

    f[0][0] = e[0]+a[0][0];
    f[1][0] = e[1]+a[1][0];

    for(int j=1;j<n;j++){
        //line-1
        if(f[0][j-1] + a[0][j] <= f[1][j-1] + t[1][j-1] + a[0][j]){
            f[0][j] = f[0][j-1] + a[0][j];
            l[0][j] = 1;
        }
        else{
            f[0][j] = f[1][j-1] + t[1][j-1] + a[0][j];
            l[0][j] = 2;
        }

        //line-2
        if(f[1][j-1] + a[1][j] <= f[0][j-1] + t[0][j-1] + a[1][j]){
            f[1][j] = f[1][j-1] + a[1][j];
            l[1][j] = 2;
        }
        else{
            f[1][j] = f[0][j-1] + t[0][j-1] + a[1][j];
            l[1][j] = 1;
        }
    }
    int f_star, l_star;
    if(f[0][n-1] + x[0] <= f[1][n-1] + x[1]){
        f_star = f[0][n-1] + x[0];
        l_star = 1;
    }
    else{
        f_star = f[1][n-1] + x[1];
        l_star = 2;
    }
    cout << "Optimal Cost: " << f_star << endl;
    cout << "Optimal Path Line: " << l_star << " -> Station " << n << endl;

    cout << "DP table for Line-1: " << endl;
    for(int i=0;i<n;i++){
        cout << "Station: " << i+1 << ": " << f[0][i] << "[" << l[0][i] <<"]" << " ";
    }
    cout << endl;
    cout << "DP table for line-2: " << endl;
    for(int i=0;i<n;i++){
        cout << "Station: " << i+1 << ": " << f[1][i] << "[" << l[1][i] << "]" << " ";
    }
    cout << endl;

    printstations(l, n, l_star);
}
int main(){
    int n;
    cin >> n;
    assembly(n);
    return 0;
}