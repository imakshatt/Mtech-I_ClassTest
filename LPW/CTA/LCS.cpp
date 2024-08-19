#include<bits/stdc++.h>
using namespace std;

void printDP(const string& x, const string &y, vector<vector<int>>& c, vector<vector<char>>& s){
    int m = x.length();
    int n = y.length();

    cout << "      ";
    for(int j=0;j<n;j++){
        cout << y[j] << "   ";
    }
    cout << endl;

    for(int i=0;i<=m;i++){
        if(i==0){
            cout << "  ";
        }
        else{
            cout << x[i-1] << " ";
        }
        for(int j=0;j<=n;j++){
            cout << c[i][j] << s[i][j] << "  ";
        }
        cout << endl;
    }
}
void print_LCS(vector<vector<char>>& s, const string& x, int i, int j){
    if(i==0 || j==0){
        return;
    }

    if(s[i][j] == 'D'){
        print_LCS(s,x,i-1,j-1);
        cout << x[i-1];
    }
    else if(s[i][j] == 'U'){
        print_LCS(s,x,i-1,j);
    }
    else{
        print_LCS(s,x,i,j-1);
    }
}
int LCS(const string& x, const string& y){
    int m = x.length();
    int n = y.length();

    vector<vector<int>> c(m+1, vector<int>(n+1, 0));
    vector<vector<char>> s(m+1, vector<char>(n+1, ' '));

    for(int i=1;i<=m;i++){
        for(int j=1;j<=n;j++){
            if(x[i-1] == y[j-1]){
                c[i][j] = c[i-1][j-1] + 1;
                s[i][j] = 'D';
            }
            else if(c[i-1][j] >= c[i][j-1]){
                c[i][j] = c[i-1][j];
                s[i][j] = 'U';
            }
            else{
                c[i][j] = c[i][j-1];
                s[i][j] = 'L';
            }
        }
    }

    printDP(x,y,c,s);
    cout << "Longest Common Subsequence are: " << endl;
    print_LCS(s,x,m,n);
    cout << endl;
    return c[m][n];
}
int main(){
    string x;
    string y;
    cout << "Enter the X string: " << endl;
    cin >> x;
    cout << "Enter the Y string: " << endl;
    cin >> y;

    int length = LCS(x,y);
    cout << "Total Length of LCS is: " << length;
    return 0;
}