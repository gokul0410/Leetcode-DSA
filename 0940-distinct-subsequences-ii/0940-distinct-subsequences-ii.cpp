class Solution {
#define ll long long
int MOD = 1e9+7;
public:
    int distinctSubseqII(string s) {
        int Total = 0;
        ll freq_ending[26] = {0};
        
        for(auto ch : s){
            int idx = ch-'a';
            ll sum = Total+1;
            ll old_count = freq_ending[idx];
            ll new_count = (sum - old_count+MOD)%MOD;
            freq_ending[idx] = Total+1;
            Total+=new_count;
            Total%=MOD;  
        }
        return Total;
    }
};