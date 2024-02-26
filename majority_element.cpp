#include <bits/stdc++.h>
using namespace std;
 int majorityElement(vector<int>& nums) {
        int ans=nums[0];
        int count=1;
        int n=nums.size();
        for(int i=1;i<n;i++){
            if(count==0){
                ans=nums[i];
                count=1;
            }
            else if(ans==nums[i])count++;
            else count--;
        }
        return ans;
    }

int main()
{
    vector<int> arr = {2, 2, 1, 1, 1, 2, 2};
    int ans = majorityElement(arr);
    cout << ans << endl;
}
