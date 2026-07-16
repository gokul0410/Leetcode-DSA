class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        unordered_set<int>st(nums.begin(),nums.end());
        int n=nums.size();
        int maxi = 0;
        for(auto it : st){
            if(!st.count(it-1)){
                int cnt=1, ptr=1;
                while(st.count(it+ptr)){
                    ptr++; cnt++;
                }
                 maxi = max(maxi,cnt);
            }
        }
        return maxi;
    }
};