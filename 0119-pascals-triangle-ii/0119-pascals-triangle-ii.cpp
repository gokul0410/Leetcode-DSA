class Solution {
public:
    vector<int> getRow(int rowIndex) {
        vector<vector<int>>pas(rowIndex+1);
        pas[0].resize(1);
        pas[0][0]=1;
        for(int i=1;i<rowIndex+1;i++){
            pas[i].resize(i+1);
            pas[i][0]=1; pas[i][i]=1;
            for(int j=1;j<i;j++){
                pas [i][j]= pas[i-1][j-1]+pas[i-1][j];
            }
        }
        for(int i=0;i<pas.size();i++){
            for(int j=0;j<pas[i].size();j++)
                cout<<pas[i][j]<<" ";
            cout<<endl;
        }
        return pas[rowIndex];
    }
};