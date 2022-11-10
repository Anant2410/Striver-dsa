vector<int> minPartition(int num)
    {
        vector<int> coin =  { 1, 2, 5, 10, 20, 50, 100, 200, 500, 2000 };
        vector<int> ans;
        int i = 9;
        while(i>=0)
        {
            if(num >= coin[i])
            {
                num -= coin[i];
                ans.push_back(coin[i]);
            }
            else
            {
                i--;
            }
        }
        return ans;
    }
