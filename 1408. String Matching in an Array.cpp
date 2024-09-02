//Runtime: 8 ms, faster than 40.00% of C++ online submissions for String Matching in an Array.
//Memory Usage: 8.6 MB, less than 100.00% of C++ online submissions for String Matching in an Array.
class Solution {
public:
    vector<string> stringMatching(vector<string>& words) {
        int n = words.size();
        
        set<string> ans;
        
        for(int i = 0; i < n; i++){
            for(int j = 0; j < n; j++){
                if(i != j && words[i].find(words[j]) != string::npos){
                    ans.insert(words[j]);
                }
            }
        }
        
        return vector<string>(ans.begin(), ans.end());
    }
};

class Node{
public:
    vector<Node*> children;
    
    Node(){
        children = vector<Node*>(26, nullptr);
    }
};

class SuffixTree{
public:
    Node* root = new Node();
    
    void add(string& word){
        Node* cur = root;
        for(char c: word){
            if(cur->children[c-'a'] == nullptr){
                cur->children[c-'a'] = new Node();
            }
            cur = cur->children[c-'a'];
        }
    };
    
    bool get(string& word){
        Node* cur = root;
        for(char c : word){
            if(cur->children[c-'a'] == nullptr){
                return false;
            }
            cur = cur->children[c-'a'];
        }
        return true;
    };
};

//Suffix tree
//https://leetcode.com/problems/string-matching-in-an-array/discuss/575147/Clean-Python-3-suffix-trie-O(NlogN-%2B-N-*-S2)
//Time: O(NlogN + N * S^2), where S is the max length of all words.
//NlogN for sorting and N * S^2 for build suffix trie.
//Space: O(N * S^2) for suffix trie
//Runtime: 28 ms, faster than 29.06% of C++ online submissions for String Matching in an Array.
//Memory Usage: 29.1 MB, less than 100.00% of C++ online submissions for String Matching in an Array.
class Solution {
public:
    vector<string> stringMatching(vector<string>& words) {
        SuffixTree* st = new SuffixTree();
        vector<string> ans;
        
        //sort by their length, descending
        //because the longer word cannot be a suffix of a shorter word
        sort(words.begin(), words.end(), [](string& a, string& b){
            return a.size() > b.size();
        });
        
        for(string& word : words){
            // cout << word << endl;
            if(st->get(word)){
                ans.push_back(word);
            }
            //add suffix of word into the suffix tree
            for(int i = 0; i < word.size(); i++){
                string suffix = word.substr(i, word.size()-i);
                st->add(suffix);
            }
        }
        
        return ans;
    }
};

//counting on trie nodes in suffix tree
//https://leetcode.com/problems/string-matching-in-an-array/discuss/575147/Clean-Python-3-suffix-trie-O(NlogN-%2B-N-*-S2)
//Runtime: 36 ms, faster than 23.11% of C++ online submissions for String Matching in an Array.
//Memory Usage: 29 MB, less than 100.00% of C++ online submissions for String Matching in an Array.
//time: O(N * S^2), space: O(N * S^2)
class Node{
public:
    vector<Node*> children;
    int count;
    
    Node(){
        children = vector<Node*>(26, nullptr);
        count = 0;
    }
};

class SuffixTree{
public:
    Node* root = new Node();
    
    void add(string& word){
        Node* cur = root;
        for(char c: word){
            if(cur->children[c-'a'] == nullptr){
                cur->children[c-'a'] = new Node();
            }
            cur = cur->children[c-'a'];
            //first go to that child and then increase its visit count
            cur->count += 1;
            // cout << c << " " << cur->count << " | ";
        }
        // cout << endl;
    };
    
    bool get(string& word){
        Node* cur = root;
        for(char c : word){
            if(cur->children[c-'a'] == nullptr){
                return false;
            }
            cur = cur->children[c-'a'];
        }
        // cout << word << " " << cur->count << endl;
        //if cur has been visited more than once, it's a suffix of others
        return cur->count > 1;
    };
};

class Solution {
public:
    vector<string> stringMatching(vector<string>& words) {
        SuffixTree* st = new SuffixTree();
        vector<string> ans;
        
        for(string& word : words){
            //add suffix of word into the suffix tree
            for(int i = 0; i < word.size(); i++){
                string suffix = word.substr(i, word.size()-i);
                st->add(suffix);
            }
        }
        
        for(string& word : words){
            if(st->get(word)){
                ans.push_back(word);
            }
        }
        
        return ans;
    }
};

//KMP
//https://leetcode.com/problems/string-matching-in-an-array/discuss/576070/C%2B%2B-concise-KMP-solution-beats-20!
//Runtime: 24 ms, faster than 32.68% of C++ online submissions for String Matching in an Array.
//Memory Usage: 10.8 MB, less than 100.00% of C++ online submissions for String Matching in an Array.
class Solution {
public:
    vector<int> build(string& pat){
        int n = pat.size();
        vector<int> lps(n, 0);
        
        for(int i = 1, len = 0; i < n; ){
            if(pat[i] == pat[len]){
                len++;
                lps[i] = len;
                i++;
            }else if(len > 0){
                //fallback to compare with a shorter prefix/suffix
                len = lps[len-1];
            }else{
                //len equals to 0 here
                lps[i] = 0;
                i++;
            }
        }
        
        return lps;
    };
    
    bool search(string& text, string& pat){
        int m = text.size(), n = pat.size();
        if(n == 0) return false;
        
        vector<int> lps = build(pat);
        
        for(int i = 0, j = 0; i < m; ){
            if(text[i] == pat[j]){
                i++;
                j++;
            }
            
            if(j == n){
                return true;
            }
            
            if(i < m && text[i] != pat[j]){
                if(j > 0){
                    //j now serves as len in bulid()
                    j = lps[j-1];
                }else{
                    i++;
                }
            }
        }
        
        return false;
    };
    
    vector<string> stringMatching(vector<string>& words) {
        vector<string> ans;
        
        //sort by length, ascending
        sort(words.begin(), words.end(), [](string& a, string& b){
            return a.size() < b.size();
        });
        
        for(int pi = 0; pi < words.size(); pi++){
            //examine pattern one by one
            for(int ti = pi+1; ti < words.size(); ti++){
                if(search(words[ti], words[pi])){
                    ans.push_back(words[pi]);
                    //if words[pi] is a substring of any longer words, break at once so that there won't be duplicate element in ans
                    break;
                }
            }
        }
        
        return ans;
    }
};
