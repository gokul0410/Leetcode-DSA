class Solution {
public:
    int largestInteger(vector<int>& nums, int k) {
        int n = nums.size();
        unordered_map<int,int>mp;
        int start =0 ;
        for(int end=k-1;end<n;end++){
            unordered_set<int>st;
            for(int i = start ; i<=end;i++){
                st.insert(nums[i]);
            }
            start++;
            for(auto &it : st){
                mp[it]++;
            }
        }
        int result=-1;
        for(auto it:mp){
            if(it.second == 1){
                result=max(result,it.first);
            }
        }
       return result;
    }
};