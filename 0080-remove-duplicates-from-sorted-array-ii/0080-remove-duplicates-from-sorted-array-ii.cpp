class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int n = nums.size();
        if(n<=2) return n;
        int left =2, right;
        for(right = 2 ; right<n;right++){
            if(nums[right]!=nums[left-2]){
                nums[left] = nums[right];
                left++; 
            }
        }
        return left;
    }
};