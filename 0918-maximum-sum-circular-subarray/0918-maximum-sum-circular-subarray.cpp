class Solution {
private:
    int kadanemax(vector<int>&nums){
        int n = nums.size();
        int curr=nums[0];
        int maxi = nums[0];
        for(int i=1;i<n;i++){
            curr= max(curr+nums[i],nums[i]);
            maxi = max(curr, maxi);
        }
        return maxi;
    }
    int kadanemin(vector<int>&nums){
        int n = nums.size();
        int curr=nums[0];
        int mini = nums[0];
        for(int i=1;i<n;i++){
            curr= min(curr+nums[i],nums[i]);
            mini = min(curr, mini);
        }
        return mini;
    }
public:
    int maxSubarraySumCircular(vector<int>& nums) {
        int n = nums.size();
        int total = 0;
        for(auto it : nums) total+=it;
        int maxi=kadanemax(nums),mini=kadanemin(nums);
        if(total == mini) return maxi;
        int circularmaxi=total - mini;
        return max(circularmaxi,maxi);
    }
};