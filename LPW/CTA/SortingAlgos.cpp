//
// Created by AKSHAT on 12/4/2023.
//
#include<bits/stdc++.h>
using namespace std;

void selectionSort(vector<int> &arr, int n){
    //select the minimum and swap to the first index
    for(int i=0;i<=n-2;i++){
        int min = i;
        for(int j=i;j<=n-1;j++){
            if(arr[j] < arr[min]){
                min = j;
            }
            swap(arr[min], arr[i]);
        }
    }
}
void bubbleSort(vector<int> &arr, int n){
    for(int i=n-1;i>=1;i--){
        for(int j=0;j<=i-1;j++){
            if(arr[j] > arr[j+1]){
                swap(arr[j], arr[j+1]);
            }
        }
    }
}
void insertionSort(vector<int> &arr, int n){
    for(int i=0;i<=n-1;i++){
        int j = i;
        while(i>0 && arr[j-1] > arr[j]){
            swap(arr[j], arr[j-1]);
        }
    }
}
int pivotsel(vector<int> &arr, int low, int high){
    int pivot = arr[high];
    //if pivot is low then i=low+1 and j=high
    //if pivot is high then i=low and j=high-1
    //if pivot is midian then i=low and j=high
    int i=low;
    int j=high;

    while(i<j){
        while(arr[i] <= pivot && i<=high-1){
            i++;
        }
        while(arr[j] > pivot && j>=low+1){
            j--;
        }
        if(i<j){
            swap(arr[i], arr[j]);
        }
    }
    swap(arr[low], arr[j]);
    return j;
}
void quicksort(vector<int> &arr, int low, int high){
    if(low>=high){
        return;
    }
    int pIndex = pivotsel(arr,low,high);
    quicksort(arr,low,pIndex-1);
    quicksort(arr,pIndex+1,high);
}
int main(){
    int n;
    cin >> n;
    vector<int> arr(n);
    for(int i=0;i<n;i++){
        cin >> arr[i];
    }
    cout << "Array before Sorting: ";
    for(int i=0;i<n;i++){
        cout << arr[i];
    }
    quicksort(arr,0,n-1);
    cout << endl << "Array After Sorting: ";
    for(int i=0;i<n;i++){
        cout << arr[i];
    }
}