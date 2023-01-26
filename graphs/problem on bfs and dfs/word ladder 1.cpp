/* take a queue<string,int> and push the  
starting word with 1 to it
declare a set ds = wordlist and remove the begin word fvrom it
now iterate till the length of the word and replace
each character with a to z and check wheter word exist or not
at last mark the word with original character */

int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        queue<pair<string,int>> q;
        q.push({beginWord,1});
        set<string> st(wordList.begin(), wordList.end());
        st.erase(beginWord);
        while(!q.empty())
        {
            string word = q.front().first;
            int steps = q.front().second;
            q.pop();
            // if the word = endword then the steps is the answer
            if(word == endWord) return steps;
            //iterate till the size aof the word
            //and replace each char from a to z
            //if word find in set erase it and push to queue
            //at end, replace the word[i] with original char
            for(int i=0;i<word.size();i++)
            {
                char org = word[i];
                for(char ch = 'a';ch<='z';ch++)
                {
                    word[i] = ch;
                    if(st.find(word)!= st.end())
                    {
                        st.erase(word);
                        q.push({word,steps+1});
                    }
                }
                word[i] = org;
            }
        }
        return 0;
    }
