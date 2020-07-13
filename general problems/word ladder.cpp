class Solution {
public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        queue<string> todo;
        unordered_set<string>unseen(wordList.begin(),wordList.end());
        int res{1};
        todo.push(beginWord);
        while(!todo.empty())
        {
            int size=todo.size();
            for(int i=0;i<size;i++)
            {
                string word=todo.front();
                todo.pop();
                for(int j=0;j<word.size();j++)
                {
                    char c=word[j];
                    for(int k=0;k<26;k++)
                    {
                        word[j]='a'+k;
                        if(unseen.count(word))
                        {
                            todo.push(word);
                            unseen.erase(word);//mark as visited
                            if(word==endWord)
                                return res+1;
                        }
                    }
                    word[j]=c;
                }
            }
            res++;
        }
        return 0;
    }
};
