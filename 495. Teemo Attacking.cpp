//Runtime: 92 ms, faster than 92.37% of C++ online submissions for Teemo Attacking.
//Memory Usage: 26 MB, less than 37.20% of C++ online submissions for Teemo Attacking.
class Solution {
public:
    int findPoisonedDuration(vector<int>& timeSeries, int duration) {
        int ans = 0;
        int cur_end;
        int last_end = INT_MIN;
         
        for(const int& start : timeSeries){
            cur_end = start+duration-1;
            if(last_end >= start){
                ans += (cur_end - last_end);
            }else{
                ans += duration;
            }
            
            last_end = cur_end;
            // cout << last_end << ", " << ans << endl;
        }
        
        return ans;
    }
};

//Approach 1: One pass
//Runtime: 92 ms, faster than 92.37% of C++ online submissions for Teemo Attacking.
//Memory Usage: 26.2 MB, less than 10.17% of C++ online submissions for Teemo Attacking.
//time: O(N), space: O(1)
class Solution {
public:
    int findPoisonedDuration(vector<int>& timeSeries, int duration) {
        int n = timeSeries.size();
        //edge case
        if(n == 0) return 0;
        
        int ans = 0;
        
        for(int i = 1; i < n; ++i){
            ans += min(duration, timeSeries[i]-timeSeries[i-1]);
        }
        
        //last attack: duration
        return ans + duration;
    }
};
