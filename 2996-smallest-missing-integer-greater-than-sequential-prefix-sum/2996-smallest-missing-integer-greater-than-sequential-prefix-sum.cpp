class Solution {
public:
    int missingInteger(vector<int>& nums) {
        int n = nums.size();
        int  sum=nums[0];
        for(int i=1;i<n;i++){
            if(nums[i]==nums[i-1]+1){
                sum+=nums[i];
            }else break;
        }
        unordered_map<int,int>mp;
        for(auto it:nums) mp[it]++;
        while(true){
            if(mp.find(sum)==mp.end()) return sum;
            sum++;
        }
        return 0;
    }
};