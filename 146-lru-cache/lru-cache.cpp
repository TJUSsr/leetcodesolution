//
// Design and implement a data structure for Least Recently Used (LRU) cache. It should support the following operations: get and put.
//
//
//
// get(key) - Get the value (will always be positive) of the key if the key exists in the cache, otherwise return -1.
// put(key, value) - Set or insert the value if the key is not already present. When the cache reached its capacity, it should invalidate the least recently used item before inserting a new item.
//
//
// Follow up:
// Could you do both operations in O(1) time complexity?
//
// Example:
//
// LRUCache cache = new LRUCache( 2 /* capacity */ );
//
// cache.put(1, 1);
// cache.put(2, 2);
// cache.get(1);       // returns 1
// cache.put(3, 3);    // evicts key 2
// cache.get(2);       // returns -1 (not found)
// cache.put(4, 4);    // evicts key 1
// cache.get(1);       // returns -1 (not found)
// cache.get(3);       // returns 3
// cache.get(4);       // returns 4
//
//


static const auto _=[](){
    std::ios::sync_with_stdio(false);
    cin.tie(nullptr);
    return nullptr;
}();

class LRUCache {
public:
    typedef pair<int, list<int>::iterator> v_h;
    
    LRUCache(int c):capacity(c) {}
    
    int get(int key) {
        if(hash.count(key)){
            cache.erase(hash[key].second);
            cache.push_front(key);
            hash[key]=make_pair(hash[key].first,cache.begin());
            return hash[key].first;
        }
        else
            return -1;
    }
    
    void put(int key, int value) {
        if(hash.count(key)){
            cache.erase(hash[key].second);
        }else if(cache.size()==capacity){
            int temp_key=cache.back();
            hash.erase(temp_key);
            cache.pop_back();
        }
        cache.push_front(key);
        hash[key]=make_pair(value,cache.begin());
        return;
    }
private:
    int capacity;
    unordered_map<int,v_h> hash;
    list<int> cache;
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache obj = new LRUCache(capacity);
 * int param_1 = obj.get(key);
 * obj.put(key,value);
 */
