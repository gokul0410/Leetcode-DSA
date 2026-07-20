class Solution {
public:
    vector<vector<int>> shiftGrid(vector<vector<int>>& grid, int k) {
        int R=grid.size(),C=grid[0].size();
        int total_elements = R*C;
        k=k%total_elements;
        vector<vector<int>>result(R,vector<int>(C));
        for(int row=0;row<R;row++){
            for(int col=0;col<C;col++){
                int prev= row*C+col;
                int after=(prev+k)%total_elements;

                int newrow=after/C;
                int newcol=after%C;

                result[newrow][newcol]=grid[row][col];
            }
        }
        return result;
    }
};