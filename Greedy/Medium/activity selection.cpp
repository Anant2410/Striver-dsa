int maxMeetings(int start[], int end[], int n)
    {
        vector<pair<int,int>>vec;
        for(int i=0;i<n;i++)
        {
            vec.push_back(make_pair(end[i],start[i]));
        }
        sort(vec.begin(),vec.end());
        int ans = 0,count=0;
        for(int i=0;i<n;i++)
        {
            if(vec[i].second > ans)
            {
                ans = vec[i].first;
                count++;
            }
        }
        return count;
    }
