class Solution {
public:
    int maximumSaleItems(vector<vector<int>>& items, int budget) {
        int N=items.size();
        vector<int>free(N,0);
        for(int i=0;i<N;i++){
            for(int j=0;j<N;j++){
                if(i==j) continue;
                if(items[j][0]%items[i][0]==0){
                    free[i]++;
                }
            }
        }
        int mini=INT_MAX;
        for(auto &it:items){
            mini=min(mini,it[1]);
        }
        vector<int>dp(budget+1,-1);
        dp[0]=0;
        for(int i=0;i<N;i++){
            int val=1+free[i];
            int cost=items[i][1];
            for(int j=budget;j>=cost;j--){
                if(dp[j-cost]!=-1){
                    dp[j]=max(dp[j],dp[j-cost]+val);
                }
            }
        }
        int ans=0;
        for(int i=0;i<=budget;i++){
            if(dp[i]==-1) continue;
            int copies=dp[i];
            int amt=budget-i;
            int extra=amt/mini;
            ans=max(ans,copies+extra);
        }
        return ans;
    }
};