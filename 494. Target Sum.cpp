//recursion
//Runtime: 1452 ms, faster than 10.35% of C++ online submissions for Target Sum.
//Memory Usage: 9.2 MB, less than 38.46% of C++ online submissions for Target Sum.
//time: O(2^N), space: O(N)
class Solution {
public:
    int findTargetSumWays(vector<int>& nums, int S, int start) {
        if(start == nums.size() || S == INT_MAX) return S == 0;
        
        //nums[i] >= 0 for all i
        //sum of nums <= 1000
        //add this determination to avoid overflow
        return findTargetSumWays(nums, S <= 1000 ? S+nums[start] : INT_MAX, start+1) + 
            findTargetSumWays(nums, S-nums[start], start+1);
    }
    
    int findTargetSumWays(vector<int>& nums, int S) {
        return findTargetSumWays(nums, S, 0);
    }
};

//recursion + memorization
//Runtime: 20 ms, faster than 75.18% of C++ online submissions for Target Sum.
//Memory Usage: 38.2 MB, less than 23.08% of C++ online submissions for Target Sum.
//time: O(sum*N), space: O(sum*N)
class Solution {
public:
    vector<vector<int>> memo;
    
    int findTargetSumWays(vector<int>& nums, int S, int start) {
        /*
        change the condition to S > 1000, so that 
        memo[start][S+1000] is always valid
        */
        if(start == nums.size() || S > 1000) return S == 0;
        
        if(memo[start][S+1000] != INT_MAX) return memo[start][S+1000];
        
        // cout << S << endl;
        //nums[i] >= 0 for all i
        //sum of nums <= 1000
        //add this determination to avoid overflow
        memo[start][S+1000] = findTargetSumWays(nums, S <= 1000 ? S+nums[start] : INT_MAX, start+1) + 
            findTargetSumWays(nums, S-nums[start], start+1);
        
        return memo[start][S+1000];
    }
    
    int findTargetSumWays(vector<int>& nums, int S) {
        /*
        sum of nums <= 1000,
        so the possible range after adding + or - is [-1000, 1000],
        we map [-1000,1000] to [0,2000] as the index of memo
        */
        memo = vector<vector<int>>(nums.size(), vector(2001, INT_MAX));
        findTargetSumWays(nums, S, 0);
        //if S > 1000, it's impossible for us to make up S by nums
        return S <= 1000 ? memo[0][S+1000] : 0;
    }
};

//2D DP
//Runtime: 32 ms, faster than 66.46% of C++ online submissions for Target Sum.
//Memory Usage: 38.2 MB, less than 23.08% of C++ online submissions for Target Sum.
//time: O(sum*N), space: O(sum*N)
class Solution {
public:
    int findTargetSumWays(vector<int>& nums, int S) {
        int n = nums.size();
        /*
        dp[i][j]: sum start from nums[i], sum to j, the count is dp[i][j]
        */
        vector<vector<int>> dp(n, vector(2001, 0));
        
        //base case
        dp[n-1][nums[n-1]+1000] = 1;
        /*
        here we should use += !!!
        because nums[n-1] may be 0!!!
        */
        dp[n-1][-nums[n-1]+1000] += 1;
        
        for(int i = n-2; i >= 0; i--){
            //try all possible sum!
            for(int sum = -1000; sum <= 1000; sum++){
                if(dp[i+1][sum+1000] > 0){
                    dp[i][sum+nums[i]+1000] += dp[i+1][sum+1000];
                    dp[i][sum-nums[i]+1000] += dp[i+1][sum+1000];
                    // cout << "(" << i << ", " << sum+nums[i] << "): " << dp[i][sum+nums[i]+1000] << endl;
                    // cout << "(" << i << ", " << sum-nums[i] << "): " << dp[i][sum-nums[i]+1000] << endl;
                }
            }
        }
        return (S <= 1000) ? dp[0][S+1000] : 0;
    }
};

//DP, O(N) space
//Runtime: 56 ms, faster than 60.66% of C++ online submissions for Target Sum.
//Memory Usage: 13.7 MB, less than 38.46% of C++ online submissions for Target Sum.
class Solution {
public:
    int findTargetSumWays(vector<int>& nums, int S) {
        int n = nums.size();
        vector<vector<int>> dp(2, vector(2001, 0));
        
        //base case
        dp[(n-1)%2][nums[n-1]+1000] = 1;
        dp[(n-1)%2][-nums[n-1]+1000] += 1;
        
        for(int i = n-2; i >= 0; i--){
            for(int sum = -1000; sum <= 1000; sum++){
                if(dp[(i+1)%2][sum+1000] > 0){
                    dp[i%2][sum+nums[i]+1000] += dp[(i+1)%2][sum+1000];
                    dp[i%2][sum-nums[i]+1000] += dp[(i+1)%2][sum+1000];
                }
                //need to reset it, it will be used in next iteration
                dp[(i+1)%2][sum+1000] = 0;
            }
        }
        return (S <= 1000) ? dp[0][S+1000] : 0;
    }
};

