class Solution {
public:
    bool f(string s)
    {
        int i=0,j=s.size()-1;
        
        while(i<j)
        {
            if(s[i++] != s[j--])
                return false;
        }
        return true;
    }
    string longestPalindrome(string s) {
        int n = s.size();
        
        if(n==0) return "";
        
        if(n==1) return s;
        
        string res = "";
        
        for(int i=0;i<n;i++)
        {
            for(int j=1;j<=n-i;j++)
            {
                if(f(s.substr(i,j)))
                {
                    if(res.size() <j)
                    {
                        res = s.substr(i,j);
                    }
                }
            }
        }
        return res;
    }
};
