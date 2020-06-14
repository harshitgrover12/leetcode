class RandomizedSet {
public:
    /** Initialize your data structure here. */
     
    unordered_map < int, int > mp;
    vector<int> v;
    RandomizedSet() {
        
    }
    
    /** Inserts a value to the set. Returns true if the set did not already contain the specified element. */
    bool insert(int val) {
        if(mp.find(val) != mp.end()) return false;
            v.emplace_back(val);
            mp[val] = v.size() - 1;
            return true;
    }
    
    /** Removes a value from the set. Returns true if the set contained the specified element. */
    bool remove(int val) {
        if(mp.find(val) == mp.end()) return false;
        mp[v.back()] = mp[val];       // replacing the value at index containing val to last value
        v[mp[val]] = v.back();
        v.pop_back();                  // erasing the last value from vector
        mp.erase(val);
        return true;
    }
    
    /** Get a random element from the set. */
    int getRandom() {
        if(v.size() == 0) return 0;
        return (v[rand()%(v.size())]);
        return 0;
    }
    };

/**
 * Your RandomizedSet object will be instantiated and called as such:
 * RandomizedSet* obj = new RandomizedSet();
 * bool param_1 = obj->insert(val);
 * bool param_2 = obj->remove(val);
 * int param_3 = obj->getRandom();
 */
