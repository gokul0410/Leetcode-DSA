class Solution {
public:
    int sumCounts(vector<int>& nums) {
        int n = nums.size();
        int result = 0;
        vector<vector<int>>sub;
        for(int i=0;i<n;i++){
            vector<int>temp;
            for(int j=i;j<n;j++){
                temp.push_back(nums[j]);
                sub.push_back(temp);
            }
        }
        for(int i=0;i<sub.size();i++){
            set<int> st(sub[i].begin(),sub[i].end());
            result+= (st.size()*st.size());
        }
        return result;
    }
};