//DFS + memo
//TLE
//76 / 176 test cases passed.
//Runtime: 140 ms, faster than 28.57% of C++ online submissions for Minimum Number of Days to Eat N Oranges.
//Memory Usage: 22.5 MB, less than 14.29% of C++ online submissions for Minimum Number of Days to Eat N Oranges.
class Solution {
public:
    unordered_map<int, int> memo;
    
    int dfs(int n){
        if(memo.find(n) != memo.end()){
            return memo[n];
        }
        
        int days = INT_MAX;
        
        days = min(days, dfs(n-1));
        if(!(n&1)) days = min(days, dfs(n>>1));
        if(n%3==0) days = min(days, dfs(n/3));
        
        return memo[n] = days+1;
    }
    int minDays(int n) {
        memo[0] = 0;
        return dfs(n);
    }
};

//Greedy + DFS + memo
//https://leetcode.com/problems/minimum-number-of-days-to-eat-n-oranges/discuss/794162/C%2B%2B-5-lines
//Runtime: 28 ms, faster than 42.86% of C++ online submissions for Minimum Number of Days to Eat N Oranges.
//Memory Usage: 10 MB, less than 57.14% of C++ online submissions for Minimum Number of Days to Eat N Oranges.
class Solution {
public:
    unordered_map<int, int> memo;
    
    int dfs(int n){
        if(memo.find(n) != memo.end()){
            return memo[n];
        }
        
        //eat one orange for n%2 days and then eat n/2 oranges
        //eat one orange for n%3 days and then eat n*2/3 oranges
        int days = min(n%2+dfs(n/2), n%3+dfs(n/3));
        
        // cout << n << ", " << days << endl;
        return memo[n] = days+1;
    };
    
    int minDays(int n) {
        memo[0] = 0;
        //this is also base case, o.w. memo[1] will be calculated as 2!
        memo[1] = 1;
        return dfs(n);
    }
};


//BFS
//Runtime: 140 ms, faster than 28.57% of C++ online submissions for Minimum Number of Days to Eat N Oranges.
//Memory Usage: 22.5 MB, less than 14.29% of C++ online submissions for Minimum Number of Days to Eat N Oranges.
class Solution {
public:
    int minDays(int n) {
        queue<int> q;
        
        q.push(n);
        int level = 0;
        
        unordered_set<int> visited;
        visited.insert(n);
        
        while(!q.empty()){
            int level_size = q.size();
            
            while(level_size-- > 0){
                int cur = q.front(); q.pop();
                
                if(cur == 0){
                    return level;
                }
                
                if(visited.find(cur-1) == visited.end()){
                    visited.insert(cur-1);
                    q.push(cur-1);
                }
                if(!(cur&1) && visited.find(cur>>1) == visited.end()){
                    visited.insert(cur>>1);
                    q.push(cur>>1);
                }
                if(cur%3==0 && visited.find(cur%3) == visited.end()){
                    visited.insert(cur/3);
                    q.push(cur/3);
                }
            }
            
            ++level;
        }
        
        return level;
    }
};
