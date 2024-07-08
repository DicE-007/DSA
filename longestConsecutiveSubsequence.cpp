#include<bits/stdc++.h>
using namespace std;

int longestConsecutive(vector<int>& nums) {
        if(nums.size()==0)return 0;
        set<int>mp;
        int ans=1;
        for(auto it:nums)mp.insert(it);
        for(auto it:mp){
            if(mp.find(it-1)==mp.end()){
                int x = it,temp=1;
                while(mp.find(x+1)!=mp.end()){
                    temp++;
                    x++;
                }
                ans=max(ans,temp);
            }
        }
        return ans;
    }

int main(){
    vector<int>arr = {102,0,100,1,3,2,101,4};
    cout<< longestConsecutive(arr);
}