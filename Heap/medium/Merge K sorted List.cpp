 ListNode* mergeKLists(vector<ListNode*>& lists) {
        vector<int>  ans;
        ListNode* temp;
        for(int i=0;i<lists.size();i++)
        {
            temp = lists[i];
            while(temp)
            {
                ans.push_back(temp->val);
                temp = temp->next;
            }
        }
        sort(ans.begin(), ans.end());
        ListNode* res = new ListNode();
        temp = res;
        for(int i=0;i<ans.size();i++)
        {
            ListNode* x = new ListNode(ans[i]);
            temp->next = x;
            temp = temp->next;
        }
        return res->next;
    }
};
