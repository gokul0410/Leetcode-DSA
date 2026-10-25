class Solution {
private:
void dfs(vector<vector<int>> &grid,int row,int col){
    int R=grid.size();
    int C=grid[0].size();
    if(row<0||col<0||row>=R||col>=C||grid[row][col]==1)
    return;
    grid[row][col]=1;
    int dir[4][2]={{1,0},{0,1},{-1,0},{0,-1}};
    for(int i=0;i<4;i++){
        dfs(grid,row+dir[i][0],col+dir[i][1]);
    }
}

public:
    int closedIsland(vector<vector<int>>& grid) {
        int R=grid.size();
        int C=grid[0].size();
        for(int i=0;i<R;i++){
            if(grid[i][0]==0) dfs(grid,i,0);
            if(grid[i][C-1]==0)  dfs(grid,i,C-1);
        }
        for(int j=0;j<C;j++){
            if(grid[0][j]==0) dfs(grid,0,j);
            if(grid[R-1][j]==0) dfs(grid,R-1,j);
        }
        int count=0;
        for(int i=0;i<R;i++){
            for(int j=0;j<C;j++){
                if(grid[i][j]==0){
                    dfs(grid,i,j);
                    count++;
                }
            }
        }
    return count;
    }
};