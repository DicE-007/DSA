#include<bits/stdc++.h>
using namespace std;
int merge(vector<int>& arr, int left, int mid, int right) {
        int count = 0;
        vector<int> temp;
        int start1 = left, start2 = mid + 1;


        //reverse pair logic start
        // [2,8,9] [1,2,3,4,5] dry run you will get it
        int start3 = mid + 1;
        for (int i = left; i <= mid; i++) {
            while (start3 <= right && arr[i] > 2 * (long)arr[start3])
                start3++;
            count += (start3 - (mid + 1));
        }
        //logic end

        while (start1 <= mid && start2 <= right) {
            if (arr[start1] <= arr[start2]) {
                temp.push_back(arr[start1++]);
            } else {
                temp.push_back(arr[start2++]);
            }
        }
        while (start1 <= mid)
            temp.push_back(arr[start1++]);
        while (start2 <= right)
            temp.push_back(arr[start2++]);
        for (int i = left; i <= right; i++) {
            arr[i] = temp[i - left];
        }
        return count;
    }

    int mergeSort(vector<int>& arr, int left, int right) {
        int count = 0;
        if (left >= right)
            return count;
        int mid = left + (right - left) / 2;
        count += mergeSort(arr, left, mid);
        count += mergeSort(arr, mid + 1, right);
        count += merge(arr, left, mid, right);
        return count;
    }

    int reversePairs(vector<int>& arr) {
        int left = 0, right = arr.size() - 1;
        // int ans=0;
        return mergeSort(arr, left, right);
    }

    int main(){
        vector<int>arr = {2147483647,2147483647,2147483647,2147483647,2147483647,2147483647};
        cout<<reversePairs(arr);
        return 0;
    }