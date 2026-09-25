class Solution {
public:
    vector<int> findPeakGrid(vector<vector<int>>& mat) {
        int r = mat.size(), c= mat[0].size();
        int low = 0 , high = c-1; 
        while(low<=high){
            //overflow condition
            int mid = low+(high - low )/2;
            int maxi = -1 , idx;
            //max in the col .
            // so top & bottom  and need not be chked
            for(int row = 0 ; row<r;row++){
                if(maxi<mat[row][mid]){
                    maxi = mat[row][mid];
                    idx = row;
                }
            }
            //inc edge cases 
            int left = (mid>0)?mat[idx][mid-1] : -1;
            int right =(mid<c-1)? mat[idx][mid+1]:-1;
            //peak element
            if(mat[idx][mid]> left && mat[idx][mid]>right) return {idx , mid};
            if(left>mat[idx][mid]) high = mid-1;
            else low = mid+1;
        }
        return {};
    }
};