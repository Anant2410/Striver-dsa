class Solution {
public:
    string reverseWords(string s) {
        reverse(s.begin(), s.end());       // reverse the whole string
        int i=0,j=0,n=s.size(), li=0;
        while(j<n)       
        {
            while(j<n && s[j] ==' ')    // fix the spaces before the words//
            {
                j++;
            }
            int si = i;
            while(j<n && s[j] != ' ')     //move the string to remove spaces before words//
            {
                s[i++] = s[j++];
                li = i;
            }
            reverse(s.begin()+si, s.begin()+li);  // reverse each word//
            s[i++] = ' ';
        }
        s.resize(li);                      // resize the string to remove redundant words//
        return s;
    }
};
