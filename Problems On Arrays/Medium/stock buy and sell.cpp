int maxProfit(vector<int>& prices) {
        int ans = INT_MIN;
        int price = INT_MAX;
        
        for(int i=0;i<prices.size();i++){
            price = min(price, prices[i]);
            ans = max(ans, prices[i]-price);
        }
        return ans;
    }
    
    //gfg
    
    void stockBuySell(int price[], int n) {
    bool transac=false;
    for(int i=0;i<n;i++){
        int buy=i,sell=i;
        //local minima
        while(i<n-1 && price[i]>=price[i+1]) i++;
        buy=i;
        //local maxima
        while(i<n-1 && price[i]<=price[i+1]) i++;
        sell=i;
        //check condition 
        if(sell-buy>0){
            cout<<"("<<buy<<" "<<sell<<")"<<" ";
            transac=true;
        }
    }
    if(transac==false){
        cout<<"No Profit";
        
    }
    cout<<endl;
}
