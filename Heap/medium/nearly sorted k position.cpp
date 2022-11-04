// agar size k se bda hojaye to top elemet ko ans me push karna hai //

vector <int> nearlySorted(int arr[], int num, int K){
        vector<int> ans;
        priority_queue<int, vector<int>, greater<int>> minh;
        
        for(int i=0;i<num;i++)
        {
            minh.push(arr[i]);
            if(minh.size() > K)
            {
                ans.push_back(minh.top());
                minh.pop();
            }
        }
        while(!minh.empty())
        {
            ans.push_back(minh.top());
            minh.pop();
        }
        return ans;
    }
