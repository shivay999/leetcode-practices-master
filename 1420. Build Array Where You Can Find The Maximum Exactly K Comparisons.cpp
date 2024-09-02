//Runtime: 160 ms, faster than 45.75% of C++ online submissions for Build Array Where You Can Find The Maximum Exactly K Comparisons.
//Memory Usage: 10.2 MB, less than 100.00% of C++ online submissions for Build Array Where You Can Find The Maximum Exactly K Comparisons.
//https://leetcode.com/problems/build-array-where-you-can-find-the-maximum-exactly-k-comparisons/discuss/586576/C%2B%2B-Bottom-Up-Dynamic-Programming-with-Explanation
//time: O(NKM*M), space:O(NMK)
class Solution {
public:
    int numOfArrays(int n, int m, int k) {
        //+1 for padding because we want to use 1-based index
        vector<vector<vector<int>>> dp(n+1, vector(m+1, vector(k+1, 0)));
        int MOD = 1e9+7;
        
        /*
        base case
        length 1, max element ?, cost 1
        */
        for(int j = 1; j <= m; j++){
            //we have only one way to construct a length 1 array
            dp[1][j][1] = 1;
        }
        
        for(int a = 1; a <= n; a++){
            for(int b = 1; b <= m; b++){
                for(int c = 1; c <= k; c++){
                    //base case
                    // if(a == 1 && c == 1) continue;
                    
                    /*
                    case 1: search cost not increase
                    we have an array of length a-1, max element b, and cost c,
                    if we append an element in [1, b], the length will increase by 1,
                    and the cost will not change
                    */
                    //the *b means we can append "b" kinds of element
                    int S = 0;
                    //to avoid overflow, equivalent to S += dp[a-1][b][c]*b % MOD;
                    for(int x = 1; x <= b; x++){
                        S = (S + dp[a-1][b][c]) % MOD;
                    }
                    
                    /*
                    case 2: search cost increase
                    we have an array of length a-1, max element [1,b-1], and cost c-1,
                    if we add the element "b", the length will increase by 1,
                    and the cost will also increase by 1
                    */
                    for(int x = 1; x < b; x++){
                        S = (S + dp[a-1][x][c-1]) % MOD;
                    }
                    
                    // dp[a][b][c] = S % MOD;
                    dp[a][b][c] = (dp[a][b][c] + S) % MOD;
                }
                
            }
        }
        
        int ans = 0;
        
        for(int b = 1; b <= m; b++){
            ans = (ans + dp[n][b][k]) % MOD;
        }
        
        return ans;
    }
};

//O(NKM) solution
//Runtime: 28 ms, faster than 87.67% of C++ online submissions for Build Array Where You Can Find The Maximum Exactly K Comparisons.
//Memory Usage: 13.8 MB, less than 100.00% of C++ online submissions for Build Array Where You Can Find The Maximum Exactly K Comparisons.
//https://leetcode.com/problems/build-array-where-you-can-find-the-maximum-exactly-k-comparisons/discuss/586576/C++-Bottom-Up-Dynamic-Programming-with-Explanation/509746
//time: O(NKM), space:O(NMK)
class Solution {
public:
    int numOfArrays(int n, int m, int k) {
        //+1 for padding because we want to use 1-based index
        vector<vector<vector<int>>> dp(n+1, vector(m+1, vector(k+1, 0)));
        /*
        prefix sum, 
        pre[a][b][c] corresponds to the sum of ways when max element is in the range [1,b]
        meaning of a, c are still the same
        */
        vector<vector<vector<int>>> pre(n+1, vector(m+1, vector(k+1, 0)));
        int MOD = 1e9+7;
        
        /*
        base case
        length 1, max element ?, cost 1
        */
        for(int j = 1; j <= m; j++){
            //we have only one way to construct a length 1 array
            dp[1][j][1] = 1;
            //ways of just smaller element plus current array 
            pre[1][j][1] = pre[1][j-1][1] + 1;
        }
        
        for(int a = 1; a <= n; a++){
            for(int b = 1; b <= m; b++){
                for(int c = 1; c <= k; c++){
                    //base case
                    if(a == 1 && c == 1) continue;
                    
                    /*
                    case 1: search cost not increase
                    we have an array of length a-1, max element b, and cost c,
                    if we append an element in [1, b], the length will increase by 1,
                    and the cost will not change
                    */
                    //the *b means we can append "b" kinds of element
                    long long S = 0;
                    S += (1LL*dp[a-1][b][c]*b) % MOD;
                    
                    /*
                    case 2: search cost increase
                    we have an array of length a-1, max element [1,b-1], and cost c-1,
                    if we add the element "b", the length will increase by 1,
                    and the cost will also increase by 1
                    */
                    //prefix sum, max element range from 1 to b-1
                    S = (S + pre[a-1][b-1][c-1]) % MOD;
                    
                    //this should be used when base case is skipped!
                    dp[a][b][c] = S % MOD;
                    //safe when base case is not skipped
                    // dp[a][b][c] = (dp[a][b][c] + S) % MOD;
                    // prefix sum whose max element is b-1, plus current number of ways
                    pre[a][b][c] = (pre[a][b-1][c] + dp[a][b][c]) % MOD;
                }
                
            }
        }
        
        int ans = 0;
        
        for(int b = 1; b <= m; b++){
            ans = (ans + dp[n][b][k]) % MOD;
        }
        
        return ans;
    }
};


