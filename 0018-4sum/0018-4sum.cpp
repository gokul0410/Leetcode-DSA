class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        int n=nums.size();
        sort(nums.begin(),nums.end());
        set<vector<int>>st;
        vector<vector<int>>result;
        for(int i=0;i<n-3;i++){
            for(int j=i+1;j<n-2;j++){
                long long  tar = 1LL*target - 1LL*nums[i]- 1LL*nums[j];
                int low=j+1,high=n-1;
                while(low<high){
                    if(nums[low]+nums[high]<tar) low++;
                    else if(nums[low]+nums[high]>tar) high--;
                    else{
                        st.insert({nums[i],nums[j],nums[low],nums[high]});
                        low++; high--;
                    }
                }
            }
        }
        for(auto it:st) result.push_back(it);
        return result;
    }
};