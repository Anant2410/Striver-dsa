class LRUCache
{
    private:

    public:
    //Constructor for initializing the cache capacity with the given value.
    class node{
        public:
            int key,value;
            node* next;
            node* prev;
            
            node(int key1, int value1)
            {
                key = key1;
                value = value1;
            }
    };
    int capacity;
    node* head = new node(-1,-1);
    node* tail = new node(-1,-1);
    unordered_map<int,node*>mp;
    LRUCache(int cap)
    {
        capacity = cap;
        head->next = tail;
        tail->prev = head;
    }
    
    //Function to return value corresponding to the key.
    void addnode(node* curr)
    {
        node* temp = head->next;
        curr->next = temp;
        curr->prev = head;
        head->next = curr;
        temp->prev = curr;
    }
    void deletenode(node* curr)
    {
        node* dp = curr->prev;
        node* dn = curr->next;
        dp->next = dn;
        dn->prev = dp;
    }
    int get(int key1)               // agar mp me key hai to use delete krke add kro aur mp me update kro
    {
        if(mp.find(key1)!= mp.end())
        {
            node* curr = mp[key1];
            int res = curr->value;
            mp.erase(key1);                 //erase
            deletenode(curr);               // 1
            addnode(curr);               // 2
            mp[key1] = head->next;     //3
            return res;
        }
        return -1;
    }
    
    //Function for storing key-value pair.
    void set(int key1, int value)       
    {
        if(mp.find(key1) != mp.end())     // agar mp me hai to mpse erase krke delete kro 
        {
            node* curr = mp[key1];            
            mp.erase(key1);                //1
            deletenode(curr);                // 2
        }
        if(capacity == mp.size())               // agar size full hai to tail se pehli vali delete kro//
        {
            mp.erase(tail->prev->key);                    //1
            deletenode(tail->prev);                     // 2
        }
        
        addnode(new node(key1,value));                // add kro aur phir update kro//
        mp[key1] = head->next;
    }
};
