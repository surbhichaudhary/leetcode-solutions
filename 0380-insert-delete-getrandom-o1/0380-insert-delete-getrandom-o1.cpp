#include<unordered_map>

class RandomizedSet {
public:
    unordered_map<int, int> s;
    vector<int> v;
    RandomizedSet() {
        
    }
    
    bool insert(int val) {
        bool ans = s.count(val);
        if( !ans ){
            v.push_back( val );
            int n = v.size();
            s[val] = n-1;
        }
        return (!ans);
    }
    
    bool remove(int val) {
        bool ans = s.count(val);
        if( ans ){
            int ind = s[val];
            int n = v.size();
            s.erase(val);
            
            swap( v[ind], v[n-1] );
            v.pop_back();
            if( ind < n-1 ){
                s[v[ind]] = ind;
            }
        }
        
        return (ans);
    }
    
    int getRandom() {
        int n = rand() % v.size();
        return v[n];
    }
};
/**
 * Your RandomizedSet object will be instantiated and called as such:
 * RandomizedSet* obj = new RandomizedSet();
 * bool param_1 = obj->insert(val);
 * bool param_2 = obj->remove(val);
 * int param_3 = obj->getRandom();
 */