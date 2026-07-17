class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        int n = nums.size();
        unordered_map<int,int>mp;
        mp[0]=1;
        int result=0,sum=0;
        for(int i=0;i<n;i++){
            //prefix sum of everything
            sum+=nums[i];
            int need = sum-k;
            // this need is need to be removed 
            result+=mp[need];
            mp[sum]++; 
        }
        return result;
    }
};