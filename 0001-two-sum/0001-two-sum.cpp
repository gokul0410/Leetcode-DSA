class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int,int>num;
        for(int i=0;i<nums.size();i++){
            int need=target-nums[i];
            if(num.find(need)!=num.end()){
                return {num[need],i};
            }
            num[nums[i]]=i;
        }
        return {};
      
      
    }
};  