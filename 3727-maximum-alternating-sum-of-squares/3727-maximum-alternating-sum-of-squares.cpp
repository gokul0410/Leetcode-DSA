class Solution {
public:
    long long maxAlternatingSum(vector<int>& nums) {
        int n = nums.size();
        long long int result = 0;
        for(int i=0;i<n;i++){
            int val = nums[i]*nums[i];
            nums[i] = val;
        }
        sort(nums.begin(),nums.end());
        int start = 0 , end = n-1;
        while(start<=end){
            result+=(1LL*nums[end]);
            end--;
            if(start<=end){
                result-=(1LL*nums[start]);
                start++;
            }
        }
        return result;
    }
};