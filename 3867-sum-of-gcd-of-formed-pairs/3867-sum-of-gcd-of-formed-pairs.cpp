class Solution {
    using ll = long long;
public:
    long long gcdSum(vector<int>& nums) {
        int n = nums.size();
        vector<ll>prefixGcd(n,0);
        int prefix_maxi = nums[0];
        prefixGcd[0]=gcd(nums[0],prefix_maxi);
        for(int i=1;i<n;i++){
            prefix_maxi = max(nums[i],prefix_maxi);
            prefixGcd[i]= gcd(nums[i],prefix_maxi);
        }
        sort(prefixGcd.begin(),prefixGcd.end());
        int start =0 , end=prefixGcd.size()-1;
        ll TotalGcd =0;
        while(start<end){
            int val =gcd(prefixGcd[start],prefixGcd[end]);
            TotalGcd+=val;
            start++; end --;
        }
        return TotalGcd;
    }
};