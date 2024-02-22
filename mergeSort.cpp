#include<bits/stdc++.h>
using namespace std;


void merge(vector<int>&arr,int l,int m,int r){
    vector<int> temp;
    int s1 = l, m1 = m, s2 = m + 1, e = r;
    while(s1<=m1 && s2<=e){
       if(arr[s1]<=arr[s2]){
           temp.push_back(arr[s1++]);
       }
       else {
           temp.push_back(arr[s2++]);
       }
    }
    while(s1<=m1) temp.push_back(arr[s1++]);
    while(s2<=e)  temp.push_back(arr[s2++]);
    for (int i = l; i <= r;i++){
        arr[i] = temp[i - l];
    }
}


void  mergeSort(vector<int>&arr,int l,int r){
    if(l==r)
        return;
    int m = (l + r) / 2;
    mergeSort(arr, l, m);
    mergeSort(arr, m + 1, r);
    merge(arr, l, m, r);
}



int main(){
    vector<int>arr = {3,1,2,4,1,5,6,4};
    int l = 0, r = arr.size() - 1;
    mergeSort(arr, l, r);
    for(auto it:arr){
        cout << it << " ";
    }
    return 0;
}
