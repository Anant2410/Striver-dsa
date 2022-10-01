 void f(int i, int sum, vector<int>& arr, int n, vector<int>& ans)
    {
        if(i==n)
        {
            ans.push_back(sum);
            return;
        }
        f(i+1,sum+arr[i],arr,n,ans);
        f(i+1,sum,arr,n,ans);
    }
    vector<int> subsetSums(vector<int> arr, int N)
    {
        vector<int> ans;
        f(0,0,arr,N,ans);
        sort(ans.begin(), ans.end());
        return ans;
    }
