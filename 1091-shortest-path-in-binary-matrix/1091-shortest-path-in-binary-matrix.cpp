class Solution {
public:
    int shortestPathBinaryMatrix(vector<vector<int>>& grid) {
        int R = grid.size(),C=grid[0].size();
         if(grid[0][0] == 1 || grid[R-1][C-1] == 1)
            return -1;
        queue<pair<int,int>>q;
        vector<vector<int>>visited(R,vector<int>(C,0));
        q.push({0,0}); visited[0][0]=1;
        int steps= 1;
        int dir[8][2]={{0,1},{1,0},{1,1},{-1,1},{1,-1},{-1,0},{0,-1},{-1,-1}};
        while(!q.empty()){
            int sz=q.size();
            while(sz--){
                auto it= q.front();
                int row=it.first,col=it.second;
                q.pop();
                if(row == R-1&& col==C-1) return steps;
                for(int d=0;d<8;d++){
                    int adjr= row+dir[d][0],adjc=col+dir[d][1];
                    if(adjr>=0 && adjc>=0 && adjr<R && adjc<C && grid[adjr][adjc]==0 && visited[adjr][adjc]==0){
                        q.push({adjr,adjc});
                        visited[adjr][adjc]=1;
                    }
                }
            }
            steps++;
        }
        return -1;
    }
};