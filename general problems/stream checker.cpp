class StreamChecker {
public:
    struct Trie{
        struct  Trie *children[26];
        bool isEnd;


    };
    Trie *getNode()
    {
            Trie *temp=new Trie;
            for(int i=0;i<26;i++)
                temp->children[i]=NULL;
        temp->isEnd=false;
        return temp;
    }
    struct Trie *root;
    vector<char> s;
    void insert(Trie* root,string key)
    {
         Trie* p=root;
        reverse(key.begin(),key.end());
        for(int i=0;i<key.length();i++)
        {
            if(p->children[key[i]-'a']==NULL)
                p->children[key[i]-'a']=getNode();
            p=p->children[key[i]-'a'];
        }
        p->isEnd=true;
    }
    vector<string> v;
    StreamChecker(vector<string>& words) {
        v=words;
       root=getNode();
        int n=words.size();
        for(int i=0;i<n;i++)
        {
            
                insert(root,words[i]);
            
            
        }
        
        
    }
    
    bool query(char letter) {
         s.push_back(letter);
        Trie *cur =root;
        int siz=s.size();
        for(int i=siz-1;i>=0;i--)
        {
            if(!cur->children[s[i]-'a'])
                return false;
            cur=cur->children[s[i]-'a'];
            if(cur->isEnd)
                return true;
        }
        
            return false;
        
        
    
    }
};

/**
 * Your StreamChecker object will be instantiated and called as such:
 * StreamChecker* obj = new StreamChecker(words);
 * bool param_1 = obj->query(letter);
 */
