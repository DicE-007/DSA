#include<bits/stdc++.h>
using namespace std;

int main(){
    vector<int>arr={15,-2,2,-8,1,7,10,23,1,1,1,1,1,1,1,1,-15};
    int target = -7;
    map<int,int>mp;
    int ans=-1,temp=0,sum=0;
    for(int i=0;i<arr.size();i++){
        sum+=arr[i];
        if(sum==target)ans=max(ans,i+1);
        else if(mp.find(sum-target)!=mp.end()){
            ans=max(ans,i-mp[sum-target]);
        }
        else mp[sum]=i;
    }
    cout<<ans;
    return 0;
}