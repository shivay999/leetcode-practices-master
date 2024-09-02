//Runtime: 904 ms, faster than 5.05% of C++ online submissions for Subarray Sum Equals K.
//Memory Usage: 9.3 MB, less than 100.00% of C++ online submissions for Subarray Sum Equals K.
//time: O(n^2), space: O(n)
class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        int ans = 0;
        int n = nums.size();
        
        //convert "nums" to prefix sum
        for(int i = 1; i < n; i++){
            nums[i] += nums[i-1];
        }
        
        for(int low = 0; low < n; low++){
            for(int high = low; high < n; high++){
                int cursum = nums[high] - ((low > 0) ? nums[low-1] : 0);
                if(cursum == k) ans++;
            }
        }
        
        return ans;
    }
};

//Approach #3 : calculate cumulative sum for every start point
//Runtime: 476 ms, faster than 24.49% of C++ online submissions for Subarray Sum Equals K.
//Memory Usage: 9.4 MB, less than 100.00% of C++ online submissions for Subarray Sum Equals K.
//time: O(n^2), space: O(1)
class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        int ans = 0, n = nums.size();
        for(int start = 0; start < n; start++){
            int sum = 0;
            for(int end = start; end < n; end++){
                sum += nums[end];
                if(sum == k) ans++;
            }
        }
        return ans;
    }
};

//Approach #4 Using hashmap
//Runtime: 44 ms, faster than 54.94% of C++ online submissions for Subarray Sum Equals K.
//Memory Usage: 13.8 MB, less than 70.67% of C++ online submissions for Subarray Sum Equals K.
//time: O(N), space: O(N)
class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        int ans = 0, sum = 0;
        
        //count the occurrence of cumulative sum
        map<int, int> counter;
        
        counter[0] = 1;
        
        for(int i = 0; i < nums.size(); i++){
            sum += nums[i];
            //"sum"(current cumulative sum) - last cumulative sum(counter[?]) = k
            //we can substract last cumulative sum from current cumulative sum to get k, and there are counter[sum - k] possibilities
            if(counter.find(sum - k) != counter.end()){
                ans += counter[sum - k];
            }
            //occurrence of prefix sum
            counter[sum]++;
        }
        
        return ans;
    }
};
