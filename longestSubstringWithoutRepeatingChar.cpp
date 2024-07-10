// "abba"

#include <bits/stdc++.h>
using namespace std;
int main()
{
    string s = "abba";
    unordered_map<char, int> mp;
    int n = s.size();
    if (s == "")
        return 0;
    if (n == 1)
        return 1;
    int start = 0, ans = 1, i = 0;
    for (i; i < n; i++)
    {
         if (mp.find(s[i]) != mp.end()) {
                ans = max(ans, i - start);
                if (start < mp[s[i]] + 1) // to check if the new repeated char is not in previous window
                    start = mp[s[i]] + 1;
                // while (start < n && mp.find(s[i]) != mp.end())
                //     mp.erase(s[start++]);
            }
        mp[s[i]] = i;
    }
    cout<<ans<<endl;
     cout<<i<<" "<<start<<endl;
    ans = max(ans, i - start);
    cout<<ans<<endl;
    //return ans;
    return 0;
}