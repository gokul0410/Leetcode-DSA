class Solution {
public:
    int minMoves2(vector<int>& nums) {
        int n = nums.size();
        sort(nums.begin(),nums.end());
        int mid = n/2;
        int result = 0;
        for(auto it : nums){
            result+= abs(nums[mid]-it);
        }
        return result;
    }
};