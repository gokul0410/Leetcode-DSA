class Solution {
using ll = long long;
const int MOD=1e9 + 7;
public:
    vector<int> sumAndMultiply(string s, vector<vector<int>>& queries) {
        int q=queries.size();
        int len=s.length();
        vector<int>ans;
        vector<int>prefix(len+1,0);
        for(int i=1;i<=len;i++)  prefix[i]=prefix[i-1]+(s[i-1]-'0');
        vector<int>non_zero(len+1,0);
        for(int i=1;i<=len;i++){
            int nonzero=0;
            if(s[i-1]!='0') nonzero++;
            non_zero[i]=non_zero[i-1]+nonzero;
        }
        vector<ll>pow10(len+1,0);
        pow10[0]=1;
        for(int i=1;i<=len;i++) pow10[i]=(pow10[i-1]*10)%MOD;
        vector<ll>pre_str(len+1,0);
        for(int i=1;i<=len;i++){
            int val=s[i-1]-'0';
            if(val!=0) pre_str[i]=((pre_str[i-1]*10)+val)%MOD;
            else pre_str[i]=pre_str[i-1];
        }
        for(auto it : queries){
            int left=it[0],right=it[1];
            int digit_sum=prefix[right+1]-prefix[left];
            int n_z = non_zero[right+1]-non_zero[left];
            ll x=(pre_str[right+1]-(pre_str[left]*pow10[n_z]%MOD)+MOD);
            ans.push_back((x*digit_sum)%MOD);
        }
        return ans;
    }
};