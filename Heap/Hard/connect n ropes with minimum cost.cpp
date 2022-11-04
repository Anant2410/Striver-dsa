 long long minCost(long long arr[], long long n) {
        priority_queue<long long , vector<long long>, greater<long long>>minh;
        long long cost= 0;
        for(int i=0;i<n;i++)
        {
            minh.push(arr[i]);
        }
        while(minh.size() >= 2)
        {
            long long sum = 0;
            sum += minh.top();
            minh.pop();
            sum += minh.top();
            minh.pop();
            cost += sum;
            minh.push(sum);
        }
        return cost;
    }
