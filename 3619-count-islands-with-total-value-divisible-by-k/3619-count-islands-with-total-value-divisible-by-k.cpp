class Solution {
private:
    int dir[4][2] ={{0,1},{1,0},{-1,0},{0,-1}};
    void dfs(int row , int col ,vector<vector<int>>&grid , vector<vector<bool>>&vis ,long long &sum){
        vis[row][col] = true;
        sum+= (1LL*grid[row][col]);
        for(int d =0 ;d<4;d++){
            int Adjr = row+dir[d][0];
            int Adjc = col+dir[d][1];
            if(Adjr>=0 && Adjc>=0 && Adjc<grid[0].size()&&Adjr<grid.size() && grid[Adjr][Adjc]!=0){
                if(!vis[Adjr][Adjc]) dfs(Adjr,Adjc,grid,vis,sum);
            }
        }
    }
public:
    int countIslands(vector<vector<int>>& grid, int k) {
        int R = grid.size() , C = grid[0].size();
        vector<vector<bool>>vis(R,vector<bool>(C,false));
        int result = 0;
        for(int i=0;i<R;i++){
            for(int j = 0;j<C;j++){
                if(grid[i][j] != 0 &&!vis[i][j]){
                    long long int sum = 0;
                    dfs(i,j,grid,vis,sum);
                    if(sum%k == 0) result++;
                }
            }
        }
        return result;
    }
};