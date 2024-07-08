#include<bits/stdc++.h>
using namespace std;

int main(){
    vector<int>arr={4, 2, 2, 6, 4};
    int k = 6,n=arr.size(),xr=0;
    unordered_map<int,int>mp;
    mp[0]=1;
    int ans=0;
    for(int i=0;i<n;i++){
        xr^=arr[i];
        int x = xr^k;
        if(mp.find(x)!=mp.end()){
            ans+=mp[x];
        }
        mp[xr]++; // increasing xor values why suppose xr^k = 4 and there were 2 points where xor
        // was 4 so at the time we get x = 4 we need to do ans+= frequency of that xor 
    }
    cout<<ans<<endl;
    return 0;
}