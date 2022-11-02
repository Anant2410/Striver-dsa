// har ek element ko map me dalenge aur phir length me se most frequent element ko minus karenge ((j-i+1) - maxi) kuch aese //
// agar ye >k hai to jabtak hai tabtak remove krdo//

class Solution {
public:
    int characterReplacement(string s, int k) {
        int n = s.size(),i=0,j=0;
        int ans = -1,maxi = 0;
        unordered_map<char,int> mp;
        while(j<n)
        {
            mp[s[j]]++;
            maxi = max(maxi, mp[s[j]]);
            if((j-i+1) - maxi > k)
            {
                mp[s[i]]--;
                i++;
            }
            ans = max(ans, j-i+1);
            j++;
        }
        return ans;
    }
};
