class Solution {
public:
    int sumCounts(vector<int>& nums) {
        int n = nums.size();
        int result = 0;
        for(int i=0;i<n;i++){
            set<int>temp;
            for(int j=i;j<n;j++){
                temp.insert(nums[j]);
                result+= (temp.size()*temp.size());
            }
        }
        return result;
    }
};