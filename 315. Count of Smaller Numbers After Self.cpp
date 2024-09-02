//O(N^2)
//TLE
//15 / 16 test cases passed.
class Solution {
public:
    vector<int> countSmaller(vector<int>& nums) {
        int n = nums.size();
        
        vector<int> ans(n);
        
        for(int i = 0; i < n; ++i){
            for(int j = i+1; j < n; ++j){
                if(nums[i] > nums[j]){
                    ++ans[i];
                }
            }
        }
        
        return ans;
    }
};

//Segment Tree
//TLE
//15 / 16 test cases passed.
class SegTree{
public:
    vector<int> arr;
    vector<int> tree;
    int n;
    
    SegTree(vector<int>& arr){
        this->arr = arr;
        this->n = arr.size();
        tree = vector<int>(this->n << 2, 0);
        //tree[0] is meaningful
        //left child: 2*i+1, right child: 2*i+2
    }
    
    void increase(int treeIdx, int l, int r, int ql, int qr, int num){
        //increase [ql, qr] by 1
        if(l > qr || ql > r){
            return;
        }
        
        if(l == r){
            if(arr[l] > num){
                ++tree[treeIdx];
                // cout << l << " : " << tree[treeIdx] << endl;
            }
            return;
        }
        
        int mid = (l+r) >> 1;
        
        if(qr <= mid){
            increase(treeIdx*2+1, l, mid, ql, qr, num);
        }else if(ql > mid){
            increase(treeIdx*2+2, mid+1, r, ql, qr, num);
        }else{
            increase(treeIdx*2+1, l, mid, ql, mid, num);
            increase(treeIdx*2+2, mid+1, r, mid+1, qr, num);
        }
        
        tree[treeIdx] = tree[treeIdx*2+1]+tree[treeIdx*2+2];
    }
    
    int query(int treeIdx, int l, int r, int q){
        if(l == r && l == q){
            return tree[treeIdx];
        }
        
        int mid = (l+r) >> 1;
        
        if(q <= mid){
            return query(treeIdx*2+1, l, mid, q);
        }else{
            return query(treeIdx*2+2, mid+1, r, q);
        }
    }
};

class Solution {
public:
    vector<int> countSmaller(vector<int>& nums) {
        int n = nums.size();
        
        SegTree st(nums);
        
        for(int i = 1; i < n; ++i){
            st.increase(0, 0, n-1, 0, i-1, nums[i]);
        }
        
        vector<int> ans(n);
        
        for(int i = 0; i < n; ++i){
            ans[i] = st.query(0, 0, n-1, i);
        }
        
        return ans;
    }
};

//Segment Tree with lazy propagation
//TLE
//15 / 16 test cases passed.
class SegTree{
public:
    vector<int> arr;
    vector<int> tree;
    vector<vector<int>> lazy;
    int n;
    
    SegTree(vector<int>& arr){
        this->arr = arr;
        this->n = arr.size();
        tree = vector<int>(this->n << 2, 0);
        lazy = vector<vector<int>>(this->n << 2);
        //tree[0] is meaningful
        //left child: 2*i+1, right child: 2*i+2
    }
    
    void increase(int treeIdx, int l, int r, int ql, int qr, int num){
        //increase [ql, qr] by 1
        if(l > qr || ql > r){
            return;
        }
        
        if(l == r){
            if(arr[l] > num){
                ++tree[treeIdx];
                // cout << l << " : " << tree[treeIdx] << endl;
            }
            return;
        }else if(ql == l && qr == r){
            //lazy propagation
            lazy[treeIdx].push_back(num);
            // cout << "[" << l << ", " << r << "] lazy: ";
            // for(int lznum : lazy[treeIdx]){
            //     cout << lznum << " ";
            // }
            // cout << endl;
            return;
        }
        
        int mid = (l+r) >> 1;
        
        if(qr <= mid){
            increase(treeIdx*2+1, l, mid, ql, qr, num);
        }else if(ql > mid){
            increase(treeIdx*2+2, mid+1, r, ql, qr, num);
        }else{
            increase(treeIdx*2+1, l, mid, ql, mid, num);
            increase(treeIdx*2+2, mid+1, r, mid+1, qr, num);
        }
        
        tree[treeIdx] = tree[treeIdx*2+1]+tree[treeIdx*2+2];
    }
    
    int query(int treeIdx, int l, int r, int q){
        if(l == r){
            /*
            with lazy propagation, 
            we need to go to leaf node so the search is complete
            */
            return tree[treeIdx];
        }
        
        int mid = (l+r) >> 1;
        
        int res;
        
        if(q <= mid){
            res = query(treeIdx*2+1, l, mid, q);
        }else{
            res = query(treeIdx*2+2, mid+1, r, q);
        }
        
        /*
        after getting the result from leaf node,
        we cannot directly return, 
        we still need to "merge" that result with
        current internal node
        */
        // cout << "lz: ";
        for(int lznum : lazy[treeIdx]){
            // cout << lznum << " ";
            if(arr[q] > lznum){
                ++res;
            }
        }
        // cout << endl;
        
        return res;
    }
};

class Solution {
public:
    vector<int> countSmaller(vector<int>& nums) {
        int n = nums.size();
        
        SegTree st(nums);
        
        for(int i = 1; i < n; ++i){
            // cout << "adding " << nums[i] << endl;
            st.increase(0, 0, n-1, 0, i-1, nums[i]);
        }
        
        vector<int> ans(n);
        
        for(int i = 0; i < n; ++i){
            ans[i] = st.query(0, 0, n-1, i);
        }
        
        return ans;
    }
};

//Segment Tree
//use pointer rather than array, because treeIdx could be larger than n*4
//https://leetcode.com/problems/count-of-smaller-numbers-after-self/discuss/76674/3-Ways-(Segment-Tree-Binary-Indexed-Tree-Merge-Sort)-clean-Java-code
//Runtime: 36 ms, faster than 62.45% of C++ online submissions for Count of Smaller Numbers After Self.
//Memory Usage: 11.4 MB, less than 52.47% of C++ online submissions for Count of Smaller Numbers After Self.
class SegTreeNode{
public:
    //the values it covered's range: [vmin, vmax]
    int vmin, vmax;
    //how many values are covered
    int count;
    SegTreeNode *left, *right;
    
    SegTreeNode(int vmin, int vmax){
        this->vmin = vmin;
        this->vmax = vmax;
        count = 0;
        left = right = nullptr;
    }
};

class SegTree{
public:
    SegTreeNode* root;
    
	SegTree(int vmin, int vmax){
        root = new SegTreeNode(vmin, vmax);
    }
    
    void add(SegTreeNode* node, int val){
        //tree[treeIdx]'s coverage: [node->vmin, node->vmax]
        
        if(val < node->vmin || val > node->vmax){
            //val is not in current node's coverage
            return;
        }
        
        //add "val" to "node"'s coverage
        ++node->count;
        //it's leaf node
        if(node->vmin == node->vmax) return;
        
        //recursively update its descendants
        int vmid = node->vmin + ((node->vmax - node->vmin) >> 1);
        if(val <= vmid){
            //go to left subtree
            if(node->left == nullptr){
                node->left = new SegTreeNode(node->vmin, vmid);
            }
            add(node->left, val);
        }else{
            //go to right subtree
            if(node->right == nullptr){
                node->right = new SegTreeNode(vmid+1, node->vmax);
            }
            add(node->right, val);
        }
    }
    
    int find(SegTreeNode* node, int val){
        //find the count of values <= val
        
        if(node == nullptr){
            //stop condition: current node the child of leaf node
            return 0;
        }
        
        if(val >= node->vmax){
            //the max element covered by node <= val
            /*
            we want to find values <= val,
            and current node is in the range
            */
            return node->count;
        }else{
            //val < node->max
            int vmid = node->vmin + ((node->vmax - node->vmin) >> 1);
            
            if(val <= vmid){
                /*
                val falls in left subtree,
                so don't need to search right subtree
                */
                return find(node->left, val);
            }else{
                /*
                we are finding [INT_MIN, val],
                so we need to find in left subtree
                */
                return find(node->left, val) + find(node->right, val);
            }
        }
    }
};

class Solution {
public:
    vector<int> countSmaller(vector<int>& nums) {
        int n = nums.size();
        vector<int> ans(n);
        
        if(n == 0) return ans;
        
        // cout << "n: " << n << endl;
        
        int vmin = *min_element(nums.begin(), nums.end());
        int vmax = *max_element(nums.begin(), nums.end());
        
        SegTree* st = new SegTree(vmin, vmax);
        
        /*
        in each iteration, 
        find nums[i]-1 before adding it to segment tree,
        so when we find nums[i] in st,
        all the elements in st are all after nums[i]
        */
        for(int i = n-1; i >= 0; --i){
            //find count of values <= nums[i]-1
            /*
            now elements in st are nums[i+1:],
            all behind current element,
            so when searching in st,
            we only care about elements' values,
            don't need to care about their positions
            */
            ans[i] = st->find(st->root, nums[i]-1);
            //add current element into st
            //root's coverage: [vmin, vmax]
            st->add(st->root, nums[i]);
        }
        
        return ans;
    }
};

//Binary Indexed Tree
//https://leetcode.com/problems/count-of-smaller-numbers-after-self/discuss/76674/3-Ways-(Segment-Tree-Binary-Indexed-Tree-Merge-Sort)-clean-Java-code
//Runtime: 16 ms, faster than 96.71% of C++ online submissions for Count of Smaller Numbers After Self.
//Memory Usage: 10.1 MB, less than 97.84% of C++ online submissions for Count of Smaller Numbers After Self.
class BIT{
public:
    int n;
    vector<int> tree;
    
    BIT(int n){
        //the index: 0 is meaningless
        //the indices: [1,n] are meaningful
        //we can retrieve count of values from the tree
        this->n = n;
        tree = vector<int>(n+1);
    }
    
    void increase(int i){
        while(i <= n){
            ++tree[i];
            //left child is covered by its parent
            //go to the upper node to its right
            i += i&-i;
        }
    }
    
    int get(int i){
        //get count of numbers in [1, i]
        int count = 0;
        
        while(i > 0){
            count += tree[i];
            //go to the upper node just to its left
            i -= i&-i;
        }
        
        return count;
    }
};

class Solution {
public:
    vector<int> countSmaller(vector<int>& nums) {
        int n = nums.size();
        vector<int> ans(n);
        if(n == 0) return ans;
        
        /*
        suppose nums's range is [a, b],
        convert it to [1, b-a+1]
        */
        int minv = *min_element(nums.begin(), nums.end());
        transform(nums.begin(), nums.end(), nums.begin(),
                  [&minv](int num){return num - minv + 1;});
        
        int maxv = *max_element(nums.begin(), nums.end());
        
        BIT* bit = new BIT(maxv);
        
        for(int i = n-1; i >= 0; --i){
            ans[i] = bit->get(nums[i]-1);
            bit->increase(nums[i]);
        }
        
        return ans;
    }
};

//mergesort
//https://leetcode.com/problems/count-of-smaller-numbers-after-self/discuss/76674/3-Ways-(Segment-Tree-Binary-Indexed-Tree-Merge-Sort)-clean-Java-code
//not understand
//Runtime: 48 ms, faster than 51.32% of C++ online submissions for Count of Smaller Numbers After Self.
//Memory Usage: 31.2 MB, less than 20.26% of C++ online submissions for Count of Smaller Numbers After Self.
class Pair{
public:
    int idx;
    int val;
    Pair(int i, int v) : idx(i), val(v){};
};

class Solution {
public:
    void merge(vector<Pair*>& pairs, int start, int end, vector<int>& ans){
        int mid = (start+end) >> 1;
        vector<Pair*> newpairs(end-start+1);
        
        // cout << "[" << start << ", " << mid << ", " << end << "]" << endl;
        // for(int i = 0; i < pairs.size(); ++i){
        //     cout << pairs[i]->idx << " " << pairs[i]->val << " | ";
        // }
        // cout << endl;
        
        //the index to left subarray
        int lix = start;
        //the index to right subarray
        int rix = mid+1;
        //the index to the new array: newpairs
        int nix = 0;
        
        while(nix < newpairs.size()){
            // cout << lix << ", " << rix << ", " << nix << endl;
            if(lix > mid || (rix <= end && pairs[rix]->val < pairs[lix]->val)){
                /*
                when lix == mid, it is still in the valid range of 
                left subarray,
                only when lix > mid: we can say that 
                left subarray is totally visited
                */
                //choose from right subarray
                // cout << "pick " << rix << endl;
                newpairs[nix] = pairs[rix];
                ++nix;
                ++rix;
            }else{
                //choose from left subarray
                /*
                in right subarray,
                [mid+1, rix-1] is already moved 
                to somewhere before nix,
                their count is rix-mid-1
                */
                // cout << "pick " << lix << endl;
                // cout << pairs[lix]->idx << " add " << rix-mid-1 << endl;
                ans[pairs[lix]->idx] += rix - mid - 1;
                newpairs[nix] = pairs[lix];
                ++nix;
                ++lix;
            }
        }
        // cout << lix << ", " << rix << ", " << nix << endl;
        
        copy_n(newpairs.begin(), end-start+1, pairs.begin()+start);
    };
    
    void mergesort(vector<Pair*>& pairs, int start, int end, vector<int>& ans){
        if(end-start+1 <= 1) return;
        int mid = (start+end) >> 1;
        
        // cout << start << ", " << mid << ", " << end << endl;
        
        mergesort(pairs, start, mid, ans);
        mergesort(pairs, mid+1, end, ans);
        
        merge(pairs, start, end, ans);
    };
    
    vector<int> countSmaller(vector<int>& nums) {
        int n = nums.size();
        vector<int> ans(n, 0);
        if(n == 0) return ans;
        
        vector<Pair*> pairs(n);
        
        for(int i = 0; i < n; ++i){
            pairs[i] = new Pair(i, nums[i]);
        }
        
        mergesort(pairs, 0, n-1, ans);
        
        return ans;
    }
};

//Binary Search Tree
//https://leetcode.com/problems/count-of-smaller-numbers-after-self/discuss/76580/9ms-short-Java-BST-solution-get-answer-when-building-BST
//Runtime: 16 ms, faster than 96.71% of C++ online submissions for Count of Smaller Numbers After Self.
//Memory Usage: 20.4 MB, less than 37.38% of C++ online submissions for Count of Smaller Numbers After Self.
class Node{
public:
    Node *left, *right;
    
    int val, count, lbCount;
    
    Node(int v, int lbc){
        val = v;
        //current node is inserted into the BST for "count" times
        count = 1;
        //count of nodes to the left and below current node
        lbCount = lbc;
        /*
        to deal with the error:
        member access within misaligned address ... for type 'Node', 
        which requires 8 byte alignment
        */
        left = right = nullptr;
    }
};

class Solution {
public:
    Node* insert(Node* node, int cur, int num, int smallerCount, vector<int>& ans){
        if(node == nullptr){
            node = new Node(num, 0);
            ans[cur] = smallerCount;
        }else if(node->val == num){
            ++node->count;
            ans[cur] = smallerCount + node->lbCount;
        }else if(num < node->val){
            ++node->lbCount;
            node->left = insert(node->left, cur, num, smallerCount, ans);
        }else{
            /*
            because num > node->val,
            (the num to be inserted is larger than current node),
            so we accumulate node->count and node->lbCount to smallerCount
            */
            node->right = insert(node->right, cur, num, 
                                 smallerCount+node->count+node->lbCount , ans);
        }
        
        return node;
    };
    
    vector<int> countSmaller(vector<int>& nums) {
        int n = nums.size();
        Node* root = nullptr;
        
        vector<int> ans(n);
        
        for(int i = n-1; i >= 0; --i){
            root = insert(root, i, nums[i], 0, ans);
        }
        
        return ans;
    }
};
