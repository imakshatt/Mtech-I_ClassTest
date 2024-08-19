//
// Created by AKSHAT on 12/2/2023.
//
#include<bits/stdc++.h>
using  namespace std;

void Knapsack(multimap<float, pair<int, int>, greater<float>> &final_df, int objects){
    int M;
    cout << endl;
    cin >> M;
    float profit = 0;
    cout << "Selected Item is: ";
    cout << endl;
    int item = 1;
    for(auto it : final_df){
        if(M>0 && (it.second.second <= M)){
            float selectedProfit = it.second.first;
            int selectedWeight = it.second.second;
            M -= selectedWeight;
            profit += selectedProfit;

            cout << item << ") pw_ratio = " << it.first << " is selected with profit = " << selectedProfit << " and weight = " << selectedWeight << " so remaining weight is M = " << M << ". Current total profit: " << profit << endl;
            item++;
        }
        else{
            if(M>0){
                float selectedProfit = it.first * M;
                int selectedWeight = it.second.second;

                profit += selectedProfit;
                cout << item << ") is selected with p/w = " << it.first << " profit = " << selectedProfit << " weight = " << selectedWeight << " With total profit = " << profit << " and Remaining Weight - " << M;
                break;
            }
        }
    }
    cout << endl;
    cout << "Total Profit is: " << profit;
}
int main(){
    int objects;
    cin >> objects;
    vector<int> profit(objects);
    vector<int> weight(objects);
    vector<pair<int,int>> pw;
    vector<float> pw_ratio;
    multimap<float, pair<int, int>, greater<float>> final_df;
    for(int i=0;i<objects;i++){
        cin >> profit[i];
        cin >> weight[i];
    }
    for(int i=0;i<objects;i++){
        pw.push_back({profit[i], weight[i]});
    }
    for(int i=0;i<objects;i++){
        float result = static_cast<float>(pw[i].first)/static_cast<float>(pw[i].second);
        pw_ratio.push_back(result);
    }
    for(auto it : pw_ratio){
        cout << it;
    }
    for(int i=0;i<objects;i++){
        final_df.insert({pw_ratio[i], {pw[i].first, pw[i].second}});
    }
    cout << "Knapsack table is : " << endl;
    for(auto it : final_df){
        cout << "[p/w: " << it.first << ", {P: " << it.second.first << ", W: " << it.second.second << "}]";
    }
    Knapsack(final_df, objects);
    return 0;

}