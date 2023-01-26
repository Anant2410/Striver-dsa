/* isme bass print krana hai*/

vector<vector<string>> findLadders(string beginWord, string endWord, vector<string>& wordList) {
        //create a set that acts as visited array
        set<string> st(wordList.begin(), wordList.end());
        //declare a queue to store the sequence
        queue<vector<string>> q;
        q.push({beginWord});
        //declare a vector to store the string used on particular level
        vector<string> used;
        int level = 0;
        used.push_back(beginWord);
        //to store the answer
        vector<vector<string>> ans;
        while(!q.empty())
        {
            vector<string> vec = q.front();
            q.pop();
            //erase all words that has been used
            //in previous level to transform
            if(vec.size() > level)
            {
                level++;
                for(auto it: used)
                {
                    st.erase(it);
                }
            }

            string word = vec.back();
            if(word == endWord)
            {
                ans.push_back(vec);
            }
            for(int i=0;i<word.size();i++)
            {
                char org = word[i];
                for(char ch = 'a';ch<='z';ch++)
                {
                    word[i] = ch;
                    if(st.find(word) != st.end())
                    {
                        vec.push_back(word);
                        q.push({vec});
                        //mark as visited
                        used.push_back(word);
                        vec.pop_back();
                    }
                }
                word[i] = org;
            }
        }
        return ans;
    }
