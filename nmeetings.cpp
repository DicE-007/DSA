#include<bits/stdc++.h>
using namespace std;

int maxMeetings(int start[], int end[], int n)
    {
        // Your code here
        vector<pair<int,int>>mp(n);
        for(int i=0;i<n;i++){
            mp[i].first = end[i];
            mp[i].second = start[i];
        }
        sort(mp.begin(),mp.end());
        int ans = 1;
        int prev= mp[0].first;
        for(int i=1;i<n;i++){
            if(mp[i].second>prev){
                ans++;
                prev = mp[i].first;
            }
        }
        return ans;
    }

    int main(){

        return 0;
    }