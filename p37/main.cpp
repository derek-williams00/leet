#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool is_possible(vector<vector<char>>& board, int x, int y, char n) {
        if(board[y][x] == n) return true;
        int x0=(x/3)*3, y0=(y/3)*3;
        for(int i=0; i<9; i++) {
            // check rows
            if(board[y][i] == n) return false;
            // check columns
            if(board[i][x] == n) return false;
            // check squares
            for(int j=0; j<3; j++) {
                for(int k=0; k<3; k++) {
                    if(board[y0+j][x0+k] == n) return false;
                }
            }
        }
        return true;
    }
    
    bool solve(vector<vector<char>>& board) {
        for(int i=0; i<9; i++) {
            for(int j=0; j<9; j++) {
                if(board[i][j] == '.') {
                    for(char n='1'; n<='9'; n++) {
                        if(is_possible(board, i, j, n)) {
                            board[i][j] = n;
                            bool suc = solve(board);
                            
                        }
                    } 
                    if(board[i][j] == '.') return false;
                }   
            }
        }
        return true;
    }
    
    // main
    void solveSudoku(vector<vector<char>>& board) {
        solve(board);
    }
};
