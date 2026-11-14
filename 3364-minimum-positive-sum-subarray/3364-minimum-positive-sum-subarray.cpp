class Solution {
public:
    int minimumSumSubarray(vector<int>& nums, int l, int r) {
        int n = nums.size();
        int mini = INT_MAX; 
        for(int i=0;i<n;i++){
            int curr = 0;
            for(int j=i;j<n;j++){
                curr+=nums[j];
                int len = j-i+1;
                if(len>=l && len<=r && curr>0)
                    mini = min(mini , curr);
            }
            int len = n-i;
            if(len>=l && len<=r && curr>0)
                    mini = min(mini , curr);
        }
        return mini==INT_MAX?-1:mini;
    }
};