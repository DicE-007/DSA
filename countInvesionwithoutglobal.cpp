#include<bits/stdc++.h>
using namespace std;

int merge(vector<int> &arr, int left, int mid, int right) {
	int first = left, second = mid + 1;
	int count = 0;
	vector<int> temp;
	while (first <= mid && second <= right) {
		if (arr[first] <= arr[second]) {
			temp.push_back(arr[first++]);
		}
		else {
			//inversion here
			count += mid - first + 1;
			temp.push_back(arr[second++]);
		}
	}
	while (first <= mid)temp.push_back(arr[first++]);
	while (second <= right)temp.push_back(arr[second++]);
	for (int i = left; i <= right; i++) {
		arr[i] = temp[i - left];
	}
	return count;
}

int mergeSort(vector<int> &arr, int left, int right) {
	int count = 0;
	if (left >= right)return count;
	int mid = (left + right) / 2;
	count += mergeSort(arr, left, mid);
	count += mergeSort(arr, mid + 1, right);
	count += merge(arr, left, mid, right);
	return count;
}

int main() {
	vector<int> arr = {5, 3, 2, 1, 4};
	int first = 0, last = arr.size() - 1;
	cout << mergeSort(arr, first, last);
    return 0;
	//print(arr);
}
