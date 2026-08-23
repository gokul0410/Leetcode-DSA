class Solution {
public:
    int longestSubarray(vector<int>& nums, int k) {
        int n = nums.size(),maxi = *max_element(nums.begin(),nums.end());
        //finding all the prime factor 1 -> maxi  //using  Sieve of Eratosthenes
        vector<bool> isprime(maxi+1,true);
        isprime[0] = false ;if(maxi>=1)isprime[1] = false;
        for(int i=2;1LL*i*i<=maxi;i++){
            if(isprime[i]){
                for(int j=i*i;j<=maxi;j+=i){isprime[j] = false;
                }}}
        long long left =0 , maxiLen = INT_MIN,currVal = 0 ;vector<int>cnt(maxi+1,0);
        for(int right =0 ; right<n;right++){
            int val = nums[right];
            for(int i=2;1LL*i*i<=maxi;i++){
                if(isprime[i] && val%i ==0){
                       if(cnt[i] == 0) currVal++;cnt[i]++;
                       while(val%i == 0) val/=i;
                }} //remaining is prime or not;
            if(val>1){if(cnt[val] == 0) currVal++;cnt[val]++;}
            while(currVal > k){
                val= nums[left]; //overwrite
                for(int i=2;1LL*i*i <=val ;i++){
                    if(isprime[i] && val%i == 0){cnt[i]--;
                        if(cnt[i] == 0) currVal--;
                        while(val%i == 0) val/=i; // distinct values 
                    }}
                if(val>1){cnt[val]--; if(cnt[val]==0 ) currVal--;}  left++;
            }
            maxiLen = max(maxiLen, right - left+1);
        }
        return maxiLen;
    }
};