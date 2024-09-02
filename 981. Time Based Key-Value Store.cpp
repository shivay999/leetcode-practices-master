//Approach 1: HashMap + Binary Search
//TLE
//44 / 45 test cases passed.
//time: O(1) for set, O(logN) for get, space: O(N)
class TimeMap {
public:
    map<string, vector<pair<int, string>>> db;
    
    /** Initialize your data structure here. */
    TimeMap() {
        
    }
    
    void set(string key, string value, int timestamp) {
        db[key].push_back(make_pair(timestamp, value));
        //actually the input is already sorted by timestamp, so we don't this
        // sort(db[key].begin(), db[key].end());
    }
    
    string get(string key, int timestamp) {
        // cout << "finding " << timestamp << endl;
        if(db.find(key) == db.end()){
            return "";
        }else{
            vector<pair<int, string>> values = db[key];
            int l = 0, r = values.size()-1;
            while(l <= r){
                int mid = (l+r)/2;
                // cout << l << " " << mid << " " << r << endl;
                if(timestamp == values[mid].first){
                    return values[mid].second;
                }else if(timestamp < values[mid].first){
                    //values[r] becomes the largest value < values[mid]
                    r = mid-1;
                }else {
                    //when mid and r are N-1, l will become N and break the loop
                    l = mid+1;
                }
            }
            // cout << "ends at " << r << endl;
            if(r < 0) return "";
            return values[r].second;
        }
    }
};

/**
 * Your TimeMap object will be instantiated and called as such:
 * TimeMap* obj = new TimeMap();
 * obj->set(key,value,timestamp);
 * string param_2 = obj->get(key,timestamp);
 */
 
//Approach 2: TreeMap
//TLE
//44 / 45 test cases passed.
//time: O(1) for set, O(logN) for get, space: O(N)
class TimeMap {
public:
    template<typename Key, typename Value>
    using MapIterator = typename std::map<Key,Value>::const_iterator;

    //https://codereview.stackexchange.com/questions/222587/java-treemap-floorkey-equivalent-for-stdmap
    template<typename Key, typename Value>
    Value floorValue(const std::map<Key,Value>& input, const Key& key){
        MapIterator<Key, Value> it = input.upper_bound(key);
        if (it != input.begin()) {
            return (--it)->second;
        } else {
            //assume Value is string
            return "";
        }
    }
    
    map<string, map<int, string>> db;
    
    /** Initialize your data structure here. */
    TimeMap() {
        
    }
    
    void set(string key, string value, int timestamp) {
        db[key][timestamp] = value;
    }
    
    string get(string key, int timestamp) {
        if(db.find(key) == db.end()){
            return "";
        }
        map<int, string> innermap = db[key];
        return floorValue(innermap, timestamp);
    }
};

/**
 * Your TimeMap object will be instantiated and called as such:
 * TimeMap* obj = new TimeMap();
 * obj->set(key,value,timestamp);
 * string param_2 = obj->get(key,timestamp);
 */

//hash map + map
//https://leetcode.com/problems/time-based-key-value-store/discuss/226664/C%2B%2B-3-lines-hash-map-%2B-map
//suppose there are n set and m get operations
//time: set O(1) each, O(n) total/ get O(logn) each, O(mlogn) total
//space: O(n)
class TimeMap {
public:
    /*
    the outer map uses unordered_map to speed up
    if we change the outer map into map, the running time will be:
    Runtime: 420 ms, faster than 39.75% of C++ online submissions for Time Based Key-Value Store.
    */
    //the inner map should be in order, so that we can use std::map::upper_bound!
    unordered_map<string, map<int, string>> db;
    
    /** Initialize your data structure here. */
    TimeMap() {
        
    }
    
    void set(string key, string value, int timestamp) {
        //both work
        db[key][timestamp] = value;
        // db[key].insert({timestamp, value});
    }
    
    string get(string key, int timestamp) {
        auto it = db[key].upper_bound(timestamp);
        if(it == db[key].begin()) return "";
        it--; //get previous pair
        return it->second;
    }
};

/**
 * Your TimeMap object will be instantiated and called as such:
 * TimeMap* obj = new TimeMap();
 * obj->set(key,value,timestamp);
 * string param_2 = obj->get(key,timestamp);
 */

//hash map + vector of pair
//https://leetcode.com/problems/time-based-key-value-store/discuss/226664/C%2B%2B-3-lines-hash-map-%2B-map
//Runtime: 388 ms, faster than 85.11% of C++ online submissions for Time Based Key-Value Store.
//Memory Usage: 133.1 MB, less than 100.00% of C++ online submissions for Time Based Key-Value Store.
class TimeMap {
public:
    unordered_map<string, vector<pair<int, string>>> db;
    
    /** Initialize your data structure here. */
    TimeMap() {
        
    }
    
    void set(string key, string value, int timestamp) {
        db[key].push_back({timestamp, value});
    }
    
    string get(string key, int timestamp) {
        auto it = upper_bound(begin(db[key]), end(db[key]), 
            pair<int, string>(timestamp, ""), 
            [](const pair<int, string>& a, const pair<int, string>& b) { 
                return a.first < b.first; 
            });
        return it == db[key].begin() ? "" : prev(it)->second;
    }
};

/**
 * Your TimeMap object will be instantiated and called as such:
 * TimeMap* obj = new TimeMap();
 * obj->set(key,value,timestamp);
 * string param_2 = obj->get(key,timestamp);
 */
