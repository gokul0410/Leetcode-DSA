class Solution {
public:
    int countSpecialIntegers(vector<int>& nums) {
        int n = nums.size();
        //map to store the idx of val 
        map<int,vector<int>>mp;
        for(int i=0;i<n;i++)
            mp[nums[i]].push_back(i);
        int result = 0 ;
        for(auto it : mp){
            int key = it.first;
            auto idx = it.second;
            if(idx.size()<3) continue;
            int diff = idx[1] - idx[0];
            bool found = true;
            for(int i=2;i<idx.size();i++){
                if(idx[i]-idx[i-1] != diff){
                    found = false;
                    break;
                }
            }
            if(found) result++;
        }
        return result;
    }
};