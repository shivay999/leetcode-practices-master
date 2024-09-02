//Union find
//Runtime: 352 ms, faster than 40.00% of C++ online submissions for Find Latest Group of Size M.
//Memory Usage: 89.7 MB, less than 20.00% of C++ online submissions for Find Latest Group of Size M.
class DSU{
public:
    int n;
    vector<int> parent;
    vector<int> gsize;
    vector<int> gsize2count;
    
    DSU(int n){
        this->n = n;
        //initially there are no unions
        //so every union's parent is -1
        parent = vector<int>(n, -1);
        // iota(parent.begin(), parent.end(), 0);
        gsize = vector<int>(n, 0);
        gsize2count = vector<int>(n+1, 0);
    }
    
    int find(int x){
        //added stop condition for uninitialized parent
        if(x == -1) return -1;
        if(parent[x] != x){
            parent[x] = find(parent[x]);
        }
        return parent[x];
    }
    
    void unite(int x, int y){
        //merge y into x
        int px = find(x);
        int py = find(y);
        
        int gsizex = gsize[px];
        int gsizey = gsize[py];
        int gsizenew = gsizex + gsizey;
        parent[py] = px;
        gsize[px] = gsize[py] = gsizenew;
        --gsize2count[gsizex];
        --gsize2count[gsizey];
        ++gsize2count[gsizenew];
    }
    
    void add(int x){
        //add a element to dsu
        parent[x] = x;
        ++gsize[x];
        ++gsize2count[gsize[x]];
    }

    void print(){
        cout << "ancestor: " << endl;
        for(int i = 0; i < n; ++i){
            cout << find(i) << " ";
        }
        cout << endl;
        cout << "gsize: " << endl;
        for(int i = 0; i < n; ++i){
            /*
            look at (the group containing i)'s size,
            so not gsize[i]
            */
            cout << ((find(i) != -1) ? gsize[find(i)] : 0) << " ";
        }
        cout << endl;
        cout << "gsize2count: " << endl;
        for(int gsize = 0; gsize <= n; ++gsize){
            cout << gsize2count[gsize] << " ";
        }
        cout << endl;
    }
};

class Solution {
public:
    int findLatestStep(vector<int>& arr, int m) {
        int n = arr.size();
        //group size -> count
        vector<int> counter(n+1, 0);
        
        transform(arr.begin(), arr.end(), arr.begin(), [](int& x){return x-1;});
        
        int ans = -1;
        string s(n, '0');
        DSU dsu(n);
        
        for(int i = 0; i < n; ++i){
            int num = arr[i];
            s[num] = '1';
            //add a new group
            dsu.add(num);
            if(num-1 >= 0 && s[num-1] == '1' && num+1 < n && s[num+1] == '1'){
                // cout << "both sides 1" << endl;
                //merge the two groups at num's two sides
                dsu.unite(num-1, num+1);
                dsu.unite(num-1, num);
            }else if(num-1 >= 0 && s[num-1] == '1'){
                // cout << "left side 1" << endl;
                //merge current position into the group at its front
                dsu.unite(num-1, num);
            }else if(num+1 < n && s[num+1] == '1'){
                // cout << "right side 1" << endl;
                //merge the group behind to itself
                dsu.unite(num, num+1);
            }

            // dsu.print();

            if(dsu.gsize2count[m] > 0){
                //i is 0-based, step is 1-based
                ans = i+1;
            }
        }
        
        return ans;
    }
};

//count the length of groups
//Runtime: 320 ms, faster than 40.00% of C++ online submissions for Find Latest Group of Size M.
//Memory Usage: 82.7 MB, less than 20.00% of C++ online submissions for Find Latest Group of Size M.
//https://leetcode.com/problems/find-latest-group-of-size-m/discuss/806786/JavaC%2B%2BPython-Count-the-Length-of-Groups-O(N)
class Solution {
public:
    int findLatestStep(vector<int>& arr, int m) {
        int n = arr.size();
        
        //padding 0 left and padding n+1 right
        vector<int> length(n+2, 0);
        //range: [0,n]
        vector<int> counter(n+1, 0);
        int ans = -1;
        
        for(int i = 0; i < n; ++i){
            int num = arr[i];
            
            //the length of "1" groups to its left and right
            int left_len = length[num-1];
            int right_len = length[num+1];
            
            /*
            we only update "length" value for those who are boundary of "1" groups,
            so the element in the middle of "1" group's "length" value could be outdated, 
            but that's fine,
            because we won't access middle element's "length" value
            */
            length[num-left_len] = length[num+right_len] = left_len + right_len + 1;
            
            --counter[left_len];
            --counter[right_len];
            ++counter[length[num-left_len]];
            
            if(counter[m] > 0){
                ans = i+1;
            }
        }
        
        return ans;
    }
};

