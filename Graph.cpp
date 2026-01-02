#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool isValid(vector<vector<int>>& grid, int i, int j, int row, int col){
        return (i >= 0 && i < row && j >= 0 && j < col && grid[i][j] == 1);
    }

    // void dfs(vector<vector<char>>& grid, int i, int j, int row, int col){
    //     // TC - 0(r x n)
    //     // SC - 0(r x n) worst case
    //     grid[i][j] = '0';

    //     if(isValid(grid, i-1, j, row, col))
    //         dfs(grid, i-1, j, row, col);

    //     if(isValid(grid, i, j+1, row, col))
    //         dfs(grid, i, j+1, row, col);

    //     if(isValid(grid, i+1, j, row, col))
    //         dfs(grid, i+1, j, row, col);

    //     if(isValid(grid, i, j-1, row, col))
    //         dfs(grid, i, j-1, row, col);
    // }

    // int numIslands(vector<vector<char>>& grid) {
    //     int row = grid.size();
    //     int col = grid[0].size();
    //     int ans = 0;

    //     for(int i = 0; i < row; i++){
    //         for(int j = 0; j < col; j++){
    //             if(grid[i][j] == '1'){
    //                 ans++;
    //                 dfs(grid, i, j, row, col);
    //             }
    //         }
    //     }
    //     return ans;
    // }

    int maxAreaOfIsland(vector<vector<int>>& grid) {
        int row = grid.size();
        int col = grid[0].size();
        int maxArea = 0;

        for(int i=0;i<row;i++){
            for(int j=0;j<col;j++){
                if(grid[i][j] == 1){
                    int ans = maxdfs(grid, i, j, row, col);
                    maxArea = max(ans, maxArea);
                }
            }
        }
        return maxArea;
    }

    int maxdfs(vector<vector<int>>& grid, int i, int j, int row, int col){
        grid[i][j] = 0;
        int ans = 1;

        // up
        if(isValid(grid, i-1, j, row, col)){
            ans += maxdfs(grid, i-1, j, row, col);
        }

        // right
        if(isValid(grid, i, j+1, row, col)){
            ans += maxdfs(grid, i, j+1, row, col);
        }

        // down
        if(isValid(grid, i+1, j, row, col)){
            ans += maxdfs(grid, i+1, j, row, col);
        }

        // left
        if(isValid(grid, i, j-1, row, col)){
            ans += maxdfs(grid, i, j-1, row, col);
        }

        return ans;
    }
};

int main() {
    Solution sol;

    vector<vector<int>> grid = {
        {1,1,0,0,0},
        {1,1,0,0,0},
        {0,0,1,0,0},
        {0,0,0,1,1}
    };

    cout << sol.maxAreaOfIsland(grid) << endl;
    return 0;
}
