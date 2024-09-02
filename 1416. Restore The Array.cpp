//TLE
//25 / 83 test cases passed.
class Solution {
public:
    int k;
    
    bool check(string& s, int idx){
        if(idx != 0){
            //reserve this case when "s" is at the front of the comb it belongs to
            //leading 0
            if(s.size() > 1 && s[0] == '0') return false;
        }
        
        //too large
        if(s.size() > 10 || (s.size() == 10 && s[0] != '1')) return false;
        
        if(idx != 0){
            if(stoi(s) >=1 && stoi(s) <= k){
                return true;
            }
        }else{
            //reserve the case when s is '0'
            if(stoi(s) <= k){
                return true;
            }
        }
        return false;
    };
    
    bool check(vector<string>& v){
        for(int i = 0; i < v.size(); i++){
            if(!check(v[i], i)) return false;
        }
        return true;
    };
    
    int numberOfArrays(string s, int k) {
        int n = s.size();
        this->k = k;
        
        vector<int> dp(n, 0);
        
        vector<vector<string>> combs, nextCombs;
        vector<string> comb;
        
        for(int i = n-1; i >= 0; i--){
            if(combs.size() == 0){
                //haven't found valid comb yet
                comb.clear();
                comb.push_back(s.substr(i));
                if(check(comb)){
                    combs.push_back(comb);
                }
            }else{
                //prefix current char to previous comb
                // cout << "before: " << endl;
                // for(vector<string> comb : combs){
                //     for(string& s : comb){
                //         cout << s << "/";
                //     }
                //     cout << " ";
                // }
                // cout << endl;
                for(vector<string> comb : combs){
                    //isolated token
                    vector<string> comb2 = comb;
                    comb2.insert(comb2.begin(), string(1, s[i]));
                    if(check(comb2)){
                        nextCombs.push_back(comb2);
                    }
                    //merge with first token in "combs[i]"
                    comb[0] = string(1, s[i]) + comb[0];
                    if(check(comb)){
                        nextCombs.push_back(comb);
                    }
                    // for(string& s : comb){
                    //     cout << s << "/";
                    // }
                    // cout << " ";
                    // for(string& s : comb2){
                    //     cout << s << "/";
                    // }
                    // cout << " ";
                }
                // cout << endl;
                combs = nextCombs;
                nextCombs.clear();
            }
        }
        
        // for(int i = 0; i < combs.size(); i++){
        //     for(string& s : combs[i]){
        //         cout << s << "/";
        //     }
        //     cout << " ";
        // }
        // cout << endl;
        
        return combs.size();
    }
};

//DP
//https://leetcode.com/problems/restore-the-array/discuss/585553/Python-DP-O(len(s)-*-10)-clean-code-with-explanations.
//Runtime: 980 ms, faster than 13.29% of C++ online submissions for Restore The Array.
//Memory Usage: 12 MB, less than 100.00% of C++ online submissions for Restore The Array.
class Solution {
public:
    int numberOfArrays(string s, int k) {
        int n = s.size();
        int t = to_string(k).size(); //max 10
        vector<int> count(n+1, 0);
        count[0] = count[1] = 1;
        int MOD = 1e9+7;
        int ans = 0;
        
        for(int i = 1; i < n ; i++){
            for(int j = 0; j <= min(i, t-1); j++){
            // for(int j = i; j >= 0; j--){
                //s[i-j:i]
                string sub = s.substr(i-j, j+1);
                // cout << i-j << " " << i << " sub: " << sub << endl;
                if(sub[0] == '0') continue;
                //avoid overflow
                if(sub.size() >= 10 && s[0] != '1') continue;
                if(stoi(sub) >= 1 && stoi(sub) <= k){
                    // cout << i+1 << " " << count[i+1] << " " << i-j << " " << count[i-j] << endl;
                    count[i+1] = (count[i+1]%MOD)+(count[i-j]%MOD);
                }
            }
        }
        
        return count[n] % MOD;
    }
};

//1-D DP
//https://leetcode.com/problems/restore-the-array/discuss/587726/Java-DP-(bottom-up)-16-line-solution-2x100-O(n-log-k)-time-O(n)-space-with-simple-explanation
//Runtime: 640 ms, faster than 19.77% of C++ online submissions for Restore The Array.
//Memory Usage: 12 MB, less than 100.00% of C++ online submissions for Restore The Array.
class Solution {
public:
    int numberOfArrays(string s, int k) {
        int n = s.size();
        //the max length of valid token
        int intMaxLen = to_string(INT_MAX).size();
        int maxLen = min((int)to_string(k).size(), intMaxLen);
        int MOD = 1e9 + 7;
        vector<int> dp(n, 0);  //count for s[0:end]
        for(int end = 0; end < n; end++){
            for(int start = end; start >= 0 && (end-start+1) <= maxLen; start--){
                //we are looking at s[start:end]
                
                //leading 0
                if(s[start] == '0') continue;
                //[start,end]
                string sub = s.substr(start, end-start+1);
                //stoi(sub) must >= 1, don't need to check
                //same digits as INT_MAX, first check its leading digit
                if(sub.size() == intMaxLen && sub[0] != '1') continue;
                //don't need to worry about overflow now
                if(stoi(sub) > k) continue;
                /*
                now s[start:end] is a valid token,
                meaning s[0:end] can be split into s[0:start-1] and s[start:end],
                so for s[0:end], its count is increased by the count of s[0:start-1]
                if start is 0, s[0:end] is a valid token by itself, we only find "one" valid token, so increase one
                */ 
                dp[end] += (start > 0) ? dp[start-1] : 1;
                dp[end] %= MOD;
            }
            // cout << "dp[" << end << "]: " << dp[end] << endl;
        }
        return dp[n-1];
    }
};
