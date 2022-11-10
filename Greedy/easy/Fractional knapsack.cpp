bool comp(Item a, Item b)
    {
        double r1 = (double)a.value/(double)a.weight;
        double r2 = (double)b.value/(double)b.weight;
        return r1 > r2;
    }

class Solution
{
    public:
    double fractionalKnapsack(int W, Item arr[], int n)
    {
        sort(arr,arr+n,comp);
        int wt=0;
        double ans = 0.0;
        for(int i=0;i<n;i++)
        {
            if(wt + arr[i].weight <= W)
            {
                wt += arr[i].weight;
                ans += arr[i].value;
            }
            else
            {
                int remain = W - wt;
                ans += (arr[i].value/(double)arr[i].weight)*(double)remain;
                break;
            }
        }
        return ans;
    }
        
};
