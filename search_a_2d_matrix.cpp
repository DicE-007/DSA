#include<bits/stdc++.h>
using namespace std;
bool searchMatrix(vector<vector<int>> &matrix, int target)
{
    int l = 0;
    int r = (matrix.size() * matrix[0].size()) - 1;
    while (l <= r)
    {
        int m = (l + r) / 2;
        int x = m / matrix[0].size(), y = m % matrix[0].size(); //to find coordinates x = mid/rowsize,y mid%rowsize
        if (matrix[x][y] == target)
            return true;
        else if (matrix[x][y] < target)
            l = m + 1;
        else
            r = m - 1;
    }
    return false;
}

int main(){
    vector<vector<int>> arr = {{1, 3, 5, 7}, {10, 11, 16, 20}, {23, 30, 34, 60}};
    bool ans = searchMatrix(arr,43);
    cout << ans << endl;
}
