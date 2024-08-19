//
// Created by AKSHAT on 12/3/2023.
//
#include<bits/stdc++.h>
using namespace std;
using namespace std::chrono;

void accending(vector<int> &arr, int n){
    for(int i=0;i<n;i++){
        arr[i] = i;
    }
}
void decending(vector<int> &arr, int n){
    for(int i=0;i<n;i++){
        arr[i] = n-i-1;
    }
}
void random(vector<int> &arr, int n){
    for(int i=0;i<n;i++){
        arr[i] = rand()%n;
    }
}
void merge(vector<int> &arr, int low, int mid, int high){
    int left = low;
    int right = mid+1;
    vector<int> temp;
    while(left<=mid && right<=high){
        if(arr[left]<=arr[right]){
            temp.push_back(arr[left]);
            left++;
        }
        else{
            temp.push_back(arr[right]);
            right++;
        }
    }
    while(arr[left]<=mid){
        temp.push_back(arr[left]);
        left++;
    }
    while(right<=high){
        temp.push_back(arr[right]);
        right++;
    }
    for(int i=low;i<=high;i++){
        arr[i] = temp[i-low];
    }
}
void mergesort(vector<int> &arr, int low, int high){
    if(low>=high){
        return;
    }
    int mid = (low+high)/2;
    mergesort(arr,low,mid);
    mergesort(arr,mid+1,high);
    merge(arr,low,mid,high);
}

void mergesort_a(vector<int> &arr, int n){
    accending(arr, n);
    auto start = high_resolution_clock::now();
    mergesort(arr, 0, n-1);
    auto end = high_resolution_clock::now();
    duration<double> total = end-start;
    cout << "Sorted array is: " << endl;
    for(int i=0;i<200;i++){
        cout << arr[i];
    }
    cout << endl;
    cout << "Total Time Taken for " << n << " elements is in ascending order: " << total.count();
}
void mergesort_d(vector<int> &arr, int n){
    decending(arr, n);
    auto start = high_resolution_clock::now();
    mergesort(arr,0,n-1);
    auto end = high_resolution_clock::now();
    duration<double> total = end-start;

    cout << "Sorted array is: " << endl;
    for(int i=0;i<200;i++){
        cout << arr[i];
    }
    cout << endl;
    cout << "Total Time Taken for " << n << " elements in descending order: " << total.count();
}
void mergesort_r(vector<int> &arr, int n){
    random(arr,n);
    auto start = high_resolution_clock::now();
    mergesort(arr,0,n-1);
    auto end = high_resolution_clock::now();
    duration<double> total = end-start;

    cout << "Sorted array is: " << endl;
    for(int i=0;i<200;i++){
        cout << arr[i] << " ";
    }
    cout << endl;
    cout << "Total Time Taken for " << n << " elements in random order: " << total.count();
}
int main(){
    int n;
    cout << "Enter the size of an array: ";
    cin >> n;
    vector<int> arr(n);
    for(int i=1;i<=3;i++){
        if(i==1){
            mergesort_a(arr,n);
        }
        else if(i==2){
            mergesort_d(arr,n);
        }
        else if(i==3){
            mergesort_r(arr,n);
        }
    }
    return 0;
}