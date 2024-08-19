//
// Created by AKSHAT on 12/4/2023.
//
#include<bits/stdc++.h>
using namespace std;

int main(){
    int Vertex;
    cout << "Enter the number of vertex: ";
    cin >> Vertex;
    int numEdges;
    cout << "Enter the number of edges: ";
    cin >> numEdges;
    vector<int> u(numEdges);
    vector<int> v(numEdges);
    vector<int> weight(numEdges);
    multimap<int, pair<int,int>> edges;

    for(int i=0;i<numEdges;i++){
        cout << "Enter U: ";
        cin >> u[i];
        cout << "Enter V: ";
        cin >> v[i];
        cout << "Enter Weight: ";
        cin >> weight[i];
        edges.insert({weight[i], {u[i], v[i]}});
        cout << "---------------------------------------" << endl;
    }
    solution obj;
    cout << "MST "
}