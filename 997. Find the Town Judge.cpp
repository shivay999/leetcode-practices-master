/**
In a town, there are N people labelled from 1 to N.  There is a rumor that one of these people is secretly the town judge.

If the town judge exists, then:

The town judge trusts nobody.
Everybody (except for the town judge) trusts the town judge.
There is exactly one person that satisfies properties 1 and 2.
You are given trust, an array of pairs trust[i] = [a, b] representing that the person labelled a trusts the person labelled b.

If the town judge exists and can be identified, return the label of the town judge.  Otherwise, return -1.

 

Example 1:

Input: N = 2, trust = [[1,2]]
Output: 2
Example 2:

Input: N = 3, trust = [[1,3],[2,3]]
Output: 3
Example 3:

Input: N = 3, trust = [[1,3],[2,3],[3,1]]
Output: -1
Example 4:

Input: N = 3, trust = [[1,2],[2,3]]
Output: -1
Example 5:

Input: N = 4, trust = [[1,3],[1,4],[2,3],[2,4],[4,3]]
Output: 3
 

Note:

1 <= N <= 1000
trust.length <= 10000
trust[i] are all different
trust[i][0] != trust[i][1]
1 <= trust[i][0], trust[i][1] <= N
**/

//better
//Runtime: 196 ms, faster than 49.32% of C++ online submissions for Find the Town Judge.
//Memory Usage: 50.5 MB, less than 100.00% of C++ online submissions for Find the Town Judge.

class Solution {
public:
    int findJudge(int N, vector<vector<int>>& trust) {
        //directed graph
        //find a node whose in-degree is N-1 and out-degree is 0
        
        vector<int> in(N), out(N);
        
        for(vector<int> edge : trust){
            //1-based -> 0-based
            int from = edge[0]-1, to = edge[1]-1;
            out[from]++;
            in[to]++;
        }
        
        for(int i = 0; i < N; i++){
            if(in[i] == N-1 && out[i] == 0){
                //0-based -> 1-based
                return i+1;
            }
        }
        
        return -1;
    }
};

//Runtime: 356 ms, faster than 23.27% of C++ online submissions for Find the Town Judge.
//Memory Usage: 60.9 MB, less than 12.50% of C++ online submissions for Find the Town Judge.
class Solution {
public:
    int findJudge(int N, vector<vector<int>>& trust) {
        if(trust.size() == 0) return (N == 1) ? 1 : -1;
        //index 0 for padding
        vector<int> indegrees(N+1, 0);
        vector<int> outdegrees(N+1, 0);
        //assume judge candidate not work!
        // int judge = trust[0][1]; //candidate judge
        
        for(vector<int>& v : trust){
            //judge doesn't trust anyone
            // if(v[0] == judge) return -1;
            outdegrees[v[0]]++;
            indegrees[v[1]]++;
        }
        
        set<int> cands;
        
        for(int i = 1; i <= N; i++){
            //there is a person trusted by N-1 person and not judge
            if(indegrees[i] == N-1 && outdegrees[i] == 0){
                cands.insert(i);
                if(cands.size() > 1) return -1;
            }
        }
        
        return cands.empty() ? -1 : *cands.begin();
    }
};
