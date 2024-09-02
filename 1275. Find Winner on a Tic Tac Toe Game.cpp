//Runtime: 8 ms, faster than 5.13% of C++ online submissions for Find Winner on a Tic Tac Toe Game.
//Memory Usage: 9.4 MB, less than 100.00% of C++ online submissions for Find Winner on a Tic Tac Toe Game.

class Solution {
public:
    bool isWin(set<vector<int>>& one_moves){
        set<vector<int>> line;
        vector<vector<int>> vec(max(3, (int)one_moves.size()));
        vector<vector<int>>::iterator v_it;
        
        // sort(one_moves.begin(), one_moves.end());
        
        //horizontal line
        for(int i = 0; i < 3; i++){
            line = {{i, 0}, {i, 1}, {i, 2}};
            
            v_it = set_intersection(one_moves.begin(), one_moves.end(), line.begin(), line.end(), vec.begin());
            if(v_it-vec.begin() == 3) return true;
        }
        
        //vertical line
        for(int j = 0; j < 3; j++){
            line = {{0,j},{1,j},{2,j}};
            v_it = set_intersection(one_moves.begin(), one_moves.end(), line.begin(), line.end(), vec.begin());
            if(v_it-vec.begin() == 3) return true;
        }
        
        //diagonal
        line = {{0,0},{1,1},{2,2}};
        v_it = set_intersection(one_moves.begin(), one_moves.end(), line.begin(), line.end(), vec.begin());
        if(v_it-vec.begin() == 3) return true;
        
        line = {{0,2},{1,1},{2,0}};
        v_it = set_intersection(one_moves.begin(), one_moves.end(), line.begin(), line.end(), vec.begin());
        if(v_it-vec.begin() == 3) return true;
        
        return false;
    }
    
    string tictactoe(vector<vector<int>>& moves) {
        set<vector<int>> a_moves, b_moves;
        for(int i = 0; i < moves.size(); i++){
            if(i%2 == 0){
                a_moves.insert(moves[i]);
            }else{
                b_moves.insert(moves[i]);
            }
        }
        
        if(isWin(a_moves)) return "A";
        if(isWin(b_moves)) return "B";
        return moves.size() == 9 ? "Draw" : "Pending";
    }
};

//https://leetcode.com/problems/find-winner-on-a-tic-tac-toe-game/discuss/441319/JavaPython-3-Check-rows-columns-and-two-diagonals-w-brief-explanation-and-analysis.
//Runtime: 4 ms, faster than 59.83% of C++ online submissions for Find Winner on a Tic Tac Toe Game.
//Memory Usage: 8.6 MB, less than 100.00% of C++ online submissions for Find Winner on a Tic Tac Toe Game.

class Solution {
public:
    string tictactoe(vector<vector<int>>& moves) {
        vector<int> a_row(3), a_col(3), b_row(3), b_col(3);
        int aD1 = 0, aD2 = 0, bD1 = 0, bD2 = 0;
        for(int i = 0; i < moves.size(); i++){
            vector<int> move = moves[i];
            int r = move[0], c = move[1];
            if(i % 2 == 0){
                //A
                if(++a_row[r] == 3 || ++a_col[c] == 3 ||
                  r == c && ++aD1 == 3 || r + c == 2 && ++aD2 == 3) return "A";
            }else{
                //B
                if(++b_row[r] == 3 || ++b_col[c] == 3 || 
                  r == c && ++bD1 == 3 || r + c == 2 && ++bD2 == 3) return "B";
            }
        }
        return moves.size() == 9 ? "Draw" : "Pending";
    }
};
