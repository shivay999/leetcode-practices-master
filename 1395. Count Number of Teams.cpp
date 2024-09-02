//Runtime: 344 ms, faster than 5.07% of C++ online submissions for Count Number of Teams.
//Memory Usage: 7.7 MB, less than 100.00% of C++ online submissions for Count Number of Teams.
class Solution {
public:
    vector<int> rating;
    int ans;
    
    bool isValid(vector<int>& comb){
        int i = comb[0], j = comb[1], k = comb[2];
        //0 <= i < j < k < n must hold
        if(rating[i] > rating[j] && rating[j] > rating[k]){
            return true;
        }
        if(rating[i] < rating[j] && rating[j] < rating[k]){
            return true;
        }
        return false;
    };
    
    void backtrack(vector<int>& comb, int start, int end){
        if(comb.size() == 3){
            if(isValid(comb)){
                ans++;
            }
            return;
        }
        for(int i = start; end-i+1 >= 3-comb.size(); i++){
            // cout << "aaa: " << end-i+1 << ", " << 3-comb.size() << endl;
            // cout << start << ", " << end << endl;
            comb.push_back(i);
            backtrack(comb, i+1, end);
            comb.pop_back();
        }
    };
    
    int numTeams(vector<int>& rating) {
        ans = 0;
        this->rating = rating;
        
        vector<int> comb;
        
        backtrack(comb, 0, rating.size()-1);
        
        return ans;
    }
};

//https://leetcode.com/problems/count-number-of-teams/discuss/554795/C%2B%2BJava-O(n-*-n)
//Runtime: 8 ms, faster than 87.37% of C++ online submissions for Count Number of Teams.
//Memory Usage: 7.8 MB, less than 100.00% of C++ online submissions for Count Number of Teams.
//time: O(N^2), space: O(1)
class Solution {
public:
    int numTeams(vector<int>& rating) {
        int N = rating.size();
        int ans = 0;
        
        for(int i = 1; i < N-1; i++){
            vector<int> smaller(2), larger(2);
            
            for(int j = 0; j < N; j++){
                //whether j is at the left of i
                int left = (j < i);
                if(rating[i] < rating[j]){
                    smaller[left]++;
                }
                if(rating[i] > rating[j]){
                    larger[left]++;
                }
            }
            
            ans += smaller[0]*larger[1] + smaller[1]*larger[0];
        }
        
        return ans;
    }
};

//Binary Indexed Tree, BIT
//https://leetcode.com/problems/count-number-of-teams/discuss/554907/Java-Detailed-Explanation-TreeSet-greater-BIT-(Fenwick-Tree)-O(NlogN)
//Runtime: 16 ms, faster than 73.69% of C++ online submissions for Count Number of Teams.
//Memory Usage: 55.6 MB, less than 100.00% of C++ online submissions for Count Number of Teams.
class Solution {
public:
    void update(vector<int>& BIT, int idx, int val){
        while(idx < BIT.size()){
            BIT[idx] += val;
            idx += idx & (-idx);
        }
    };
    
    int getPrefixSum(vector<int>& BIT, int idx){
        int sum = 0;
        
        while(idx > 0){
            sum += BIT[idx];
            idx -= idx & (-idx);
        }
        
        return sum;
    };
    
    int getSuffixSum(vector<int>& BIT, int idx){
        return getPrefixSum(BIT, BIT.size()-1) - getPrefixSum(BIT, idx-1);
    };
    
    int numTeams(vector<int>& rating) {
        int N = rating.size();
        if(N < 3) return 0;
        
        //rating's range: [1, 1e5]
        //use rating as index, and count as value
        vector<int> leftTree(1e5+1, 0);
        vector<int> rightTree(1e5+1, 0);
        
        for(int r : rating){
            update(rightTree, r, 1);
        }
        
        int ans = 0;
        
        //store the count of each rating into rightTree
        for(int r : rating){
            //rightTree contains the info of soldiers to the right of current soldier, so we need to remove the info of current soldier from rightTree
            update(rightTree, r, -1);
            
            ans += getPrefixSum(leftTree, r-1)*getSuffixSum(rightTree,r+1);
            ans += getSuffixSum(leftTree, r+1)*getPrefixSum(rightTree, r-1);
            
            //record current soldier's info into leftTree
            update(leftTree, r, 1);
        }
        
        return ans;
    }
};
