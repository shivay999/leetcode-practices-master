//WA
class MyCalendarTwo {
public:
    multimap<int, int> sgl;
    map<int, int> dbl;
    
    MyCalendarTwo() {
        
    }
    
    bool book(int start, int end) {
        auto it = dbl.upper_bound(start);
        int prev = (it != dbl.begin()) ? (--it)->first : -1;
        it = dbl.lower_bound(start);
        int next = (it != dbl.end()) ? it->first : -1;
        
        // if(prev == -1) cout << "-1 ";
        // else cout << dbl[prev] << "<= ";
        // cout << start << " <= " << end;
        // if(next == -1) cout << " -1 ?" << endl;
        // else cout << " <= " << next << " ?" << endl;
        
        if((prev == -1 || dbl[prev] < start) &&
          (next == -1 || end <= next)){
            //update dbl
            /*if current booking have no intersection with previous bookings in sgl, 
            then we don't need to update dbl,
            o.w., we need to add their intersection into dbl
            */
            auto itPrev = sgl.upper_bound(start);
            if(itPrev != sgl.begin()){
                itPrev--;
            }else{
                itPrev = sgl.end();
            }
            auto itNext = sgl.lower_bound(start);
            if(!((itPrev == sgl.end() || itPrev->second < start) &&
                (itNext == sgl.end() || end <= itNext->first))){
                //if there is an intersection
                if(itPrev != sgl.end() && start < itPrev->second){
                    //intersect with previous
                    // cout << "[" << start << "," << end << ")" << " intersect with " << "[" << itPrev->first << ", " << itPrev->second << ")" << endl;
                    // cout << "[" << start << ", " << itPrev->second << ") in dbl." << endl;
                    dbl[start] = min(end, itPrev->second);
                }
                if(itNext != sgl.end() && itNext != itPrev && itNext->first < end){
                    //intersect with next
                    // cout << "[" << start << "," << end << ")" << " intersect with " << "[" << itNext->first << ", " << itNext->second << ")" << endl;
                    // cout << "[" << itNext->first << ", " << end << ") in dbl." << endl;
                    dbl[max(start, itNext->first)] = end;
                }
            }
            //update sgl
            sgl.insert({start, end});
        
            for(auto it = sgl.begin(); it != sgl.end(); it++){
                cout << it->first << " " << it->second << " | ";
            }
            cout << endl;

            for(auto it = dbl.begin(); it != dbl.end(); it++){
                cout << it->first << " " << it->second << " | ";
            }
            cout << endl;
            return true;
        }
        
        for(auto it = sgl.begin(); it != sgl.end(); it++){
            cout << it->first << " " << it->second << " | ";
        }
        cout << endl;
        
        for(auto it = dbl.begin(); it != dbl.end(); it++){
            cout << it->first << " " << it->second << " | ";
        }
        cout << endl;
        
        return false;
    }
};

/**
 * Your MyCalendarTwo object will be instantiated and called as such:
 * MyCalendarTwo* obj = new MyCalendarTwo();
 * bool param_1 = obj->book(start,end);
 */
 
//Approach #1: Brute Force
//Runtime: 216 ms, faster than 39.61% of C++ online submissions for My Calendar II.
//Memory Usage: 31.3 MB, less than 100.00% of C++ online submissions for My Calendar II.
//time: O(N^2), space: O(N)
class MyCalendarTwo {
public:
    vector<vector<int>> sgl, dbl;
    
    MyCalendarTwo() {
        
    }
    
    bool book(int start, int end) {
        for(vector<int>& event : dbl){
            if(event[0] < end && event[1] > start){
                return false;
            }
        }
        for(vector<int>& event : sgl){
            if(event[0] < end && start < event[1]){
                //current booking may overlap with multiple previous events, so no break here!
                dbl.push_back({max(start, event[0]), min(end, event[1])});
            }
        }
        sgl.push_back({start, end});
        return true;
    }
};

/**
 * Your MyCalendarTwo object will be instantiated and called as such:
 * MyCalendarTwo* obj = new MyCalendarTwo();
 * bool param_1 = obj->book(start,end);
 */
