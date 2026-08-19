class Solution {
public:
    int maxRotateFunction(vector<int>& nums) {
        int n=nums.size();
        int sum =0 ; long long prod = 0;
        for(int i=0;i<n;i++){
            sum+=nums[i];
            prod+=(i*nums[i]);
        }
        long long result = prod;
        vector<long long >dp(n);
        dp[0] = prod; 
        for(int i=1;i<n;i++){
            int diff = nums[n-i]*n;
            dp[i] =dp[i-1]+ 1LL*sum -1LL* diff;
            result = max(result,dp[i]);
        }
        return result;
    }
};