class Solution {
public:
    int numTrees(int n) {
        vector<int>dp (n+1,0);
        dp[0] = 1; dp[1] = 1; //base case 
        for(int node=2;node<=n;node++){
            for(int root=1;root<=node;root++){
                int left = root -1, right = node -root;
                dp[node] += dp[left]*dp[right];
            }
        } 
        return dp[n];
    }
};