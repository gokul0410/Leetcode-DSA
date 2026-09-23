class Solution {
public:
    int minOperations(vector<int>& nums, int x) {
        int n = nums.size();
        int total = accumulate(nums.begin(),nums.end(),0);
        int rem = total - x;
        if(rem<0) return -1 ; //if x is greater than total sum
        if(rem == 0) return n; 
        //finding the maximum length of remaining 
        int best_len = INT_MIN, left = 0,curr = 0;
        //using silding window
        for(int right = 0;right<n;right++){
            curr+=nums[right];
            while(left<=right && curr>rem){
                curr -= nums[left++];
            }
            if(curr == rem) best_len = max(right-left+1,best_len);
        }
        return best_len == INT_MIN ? -1 : n-best_len;
    }
};