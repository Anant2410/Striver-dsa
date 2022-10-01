 bool valid(int num, int d)
    {
        int digit = num%10;
        int sum = digit;
        if(digit==d) return false;
        num = num/10;
        while(num)
        {
            digit = num%10;
            if(digit==d || digit <= sum) return false;
            sum += digit;
            num /= 10;
        }
        return true;
    }
    vector<int> goodNumbers(int L, int R, int D) {
        vector<int> ans;
        for(int i=L;i<=R;i++)
        {
            if(valid(i,D))
            {
                ans.push_back(i);
            }
        }
        return ans;
    }

    //leetcode//
#define mod 1000000007
class Solution {
public:
   long long power(long long x , long long y)
    {
       if(y==0) return 1;
       long long ans = power(x,y/2);
       ans *= ans;
       ans %= mod;
       if(y%2) ans*=x;
       ans %=mod;
       return ans;
    }
    int countGoodNumbers(long long n) {
        long long even = n/2 + n%2;
        long long odd = n/2;
        
        return (power(5,even) * power(4,odd))%mod;
    }
};
