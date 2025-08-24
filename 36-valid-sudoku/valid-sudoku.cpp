class Solution {
public:
    vector<vector<char>> clockWiseRotation(vector<vector<char>>& board){
        vector<vector<char>> rotatedBoard(9, vector<char>(9, '.'));

        for(int i = 0; i<9; i++){
            for(int j = 0; j<9; j++){
                rotatedBoard[j][9-i-1] = board[i][j];
            }
        }

        return rotatedBoard;
    }

    bool checkRowValidity(vector<vector<char>>& board){
        unordered_map<char, int> mpp;

        for(auto &vec: board){
            for(auto &it: vec){
                if(it != '.'){
                    mpp[it]++;
                }

                if(mpp[it] > 1){
                    return false;
                }
            }

             mpp.clear();
        }

        return true;
    }

    bool validateSubBoxes(vector<vector<char>>& board, int rowStart, int rowEnd, int colStart, int colEnd){
        unordered_map<char, int> mpp;

        for(int i = rowStart; i<rowEnd; i++){
            for(int j = colStart; j < colEnd; j++){
                if(board[i][j] != '.'){
                    mpp[board[i][j]]++;
                }

                if(mpp[board[i][j]] > 1){
                    return false;
                }
            }
        }

        mpp.clear();

        return true;
    }

    bool isValidSudoku(vector<vector<char>>& board) {
        // Case 1:
        if(!checkRowValidity(board)) return false;

        //Case 2:
        vector<vector<char>> rotatedBoard = clockWiseRotation(board);
        if(!checkRowValidity(rotatedBoard)) return false;

        //case 3: check all sub-boxes
        if(!validateSubBoxes(board, 0, 3, 0, 3)) return false;
        if(!validateSubBoxes(board, 0, 3, 3, 6)) return false;
        if(!validateSubBoxes(board, 0, 3, 6, 9)) return false;
        if(!validateSubBoxes(board, 3, 6, 0, 3)) return false;
        if(!validateSubBoxes(board, 3, 6, 3, 6)) return false;
        if(!validateSubBoxes(board, 3, 6, 6, 9)) return false;
        if(!validateSubBoxes(board, 6, 9, 0, 3)) return false;
        if(!validateSubBoxes(board, 6, 9, 3, 6)) return false;
        if(!validateSubBoxes(board, 6, 9, 6, 9)) return false;

        return true;
    }
};