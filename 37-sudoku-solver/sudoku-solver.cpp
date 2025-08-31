class Solution {
public:
//     // This is throw the TLE:
//     bool backtrack(vector<vector<char>>& board, unordered_set<string> &st, int i, int j){
//         // Base Case:
//         if(i == 9) return true;
//         if(j == 9) return backtrack(board, st, i+1, 0);

//         if(board[i][j] != '.'){
//             return backtrack(board, st, i, j+1);
//         }

//         for(int c = '1'; c<='9'; c++){
//             string row = string(1, c) + "_Row_" + to_string(i);
//             string col = string(1, c) + "_Col_" + to_string(j);
//             string box = string(1, c) + "_Box_" + to_string(i/3) + "_" + to_string(j/3);

//             if(st.find(row) == st.end() && st.find(col) == st.end() && st.find(box) == st.end()){
//                 board[i][j] = c;
//                 st.insert(row);
//                 st.insert(col);
//                 st.insert(box);

//                 if(backtrack(board, st, i, j+1)) return true;

//                 // If fails then undo the pushed value
//                 board[i][j] = '.';
//                 st.erase(row);
//                 st.erase(col);
//                 st.erase(box);
//             }
//         }

//         return false;
//     }


//     void solveSudoku(vector<vector<char>>& board) {
//         unordered_set<string> st;

//         for(int i = 0; i<9; i++){
//             for(int j= 0; j<9; j++){
//                 if(board[i][j] != '.'){
//                     string row = string(1, board[i][j]) + "_Row_" + to_string(i);
//                     string col = string(1, board[i][j]) + "_Col_" + to_string(j);
//                     string box = string(1, board[i][j]) + "_Box_" + to_string(i/3) + "_" + to_string(j/3);

//                     st.insert(row);
//                     st.insert(col);
//                     st.insert(box);
//                 }
//             }
//         }

//         backtrack(board, st, 0, 0);
//     }
// };










// try using memoize/simple array storing approach:
    bool row[9][10] = {}, col[9][10] = {}, box[9][10] = {};
    bool backtrack(vector<vector<char>>& board, int i, int j){
        // Base Case:
        if(i == 9) return true;
        if(j == 9) return backtrack(board, i+1, 0);

        if(board[i][j] != '.'){
            return backtrack(board, i, j+1);
        }

        int b = (i/3) * 3 + (j/3); //unique id for each cell in sub-boxes

        for(int d = 1; d<=9; d++){
            

            if(!row[i][d] && !col[j][d] && !box[b][d]){
                board[i][j] = d + '0';
                row[i][d] = col[j][d] = box[b][d] = true;

                if(backtrack(board, i, j+1)) return true;

                // If fails then undo the pushed value
                board[i][j] = '.';
                row[i][d] = col[j][d] = box[b][d] = false;
            }
        }

        return false;
    }


    void solveSudoku(vector<vector<char>>& board) {
        for(int i = 0; i<9; i++){
            for(int j= 0; j<9; j++){
                if(board[i][j] != '.'){
                    int d = board[i][j] - '0';
                    int b = (i/3) * 3 + (j/3);

                    row[i][d] = col[j][d] = box[b][d] = true;
                }
            }
        }

        backtrack(board, 0, 0);
    }
};