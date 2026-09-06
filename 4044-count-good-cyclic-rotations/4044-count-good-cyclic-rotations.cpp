class Solution {
public:
    int countGoodRotations(vector<int>& nums) {
        int n = nums.size();
        int mid = n/2;
        long long total = accumulate(nums.begin(),nums.end(),0LL);
        long long first_half = 0, second_half = 0;
        for(int i =0 ;i<mid;i++) first_half+=(1LL*nums[i]);
        second_half = total - first_half;
        int Cycle = 0;
        //if(first_half > second_half) Cycle++;
        int left = 0 ;
        while(left<n){
            if(first_half > second_half) Cycle++;
            
            first_half -= (1LL*nums[left]);
            first_half+= (1LL*nums[mid%n]);

            second_half-=(1LL*nums[mid%n]);
            second_half+=(1LL*nums[left]);

            left++; mid++;
        }
        return Cycle;
    }
};