class LRUCache{
public:
    LRUCache(int capacity) : _capacity(capacity) {}
    
    int get(int key) {
        if (cache.find(key) == cache.end()) return -1;
        visit(key);
        return cache[key].first;
    }
    
    void set(int key, int value) {
        if (cache.find(key) == cache.end()) {
            if (keys.size() == _capacity) {
                cache.erase(keys.back());
                keys.pop_back();
            }
            keys.push_front(key);
            cache[key] = make_pair(value, keys.begin());
        }
        else {
            visit(key);
            cache[key].first = value;
        }
    }
    
private:
    int _capacity;
    list<int> keys;
    unordered_map<int, pair<int, list<int>::iterator>> cache;
    
    void visit(int key) {
        list<int>::iterator it = cache[key].second;
        keys.push_front(*it);
        keys.erase(it);
        cache[key].second = keys.begin();   
    }
};
