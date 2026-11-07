class Solution {
public:
    vector<string> buildArray(vector<int>& target, int n) {
        unordered_set<int> nums(target.begin(), target.end());
        vector<string> result;
        int maxi = *max_element(target.begin(), target.end());
        for(int i=1;i<=n;i++){
            if(nums.count(i)) result.push_back("Push");
            else{
                result.push_back("Push");
                result.push_back("Pop");
            }
            if(i==maxi) break;
        }
        return result;
    }
};