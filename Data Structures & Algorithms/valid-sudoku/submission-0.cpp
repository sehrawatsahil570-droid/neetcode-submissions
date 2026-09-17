class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {

        unordered_map<int, unordered_map<int, int>> row;
        unordered_map<int, unordered_map<int, int>> col;
        unordered_map<int, unordered_map<int, int>> box;

        for(int i = 0; i < 9; i++) {

            for(int j = 0; j < 9; j++) {

                if(board[i][j] == '.')
                    continue;

                int num = board[i][j] - '0';

                int b = (i / 3) * 3 + (j / 3);

                if(row[i][num] || 
                   col[j][num] || 
                   box[b][num]) {
                    return false;
                }

                row[i][num] = 1;
                col[j][num] = 1;
                box[b][num] = 1;
            }
        }

        return true;
    }
};