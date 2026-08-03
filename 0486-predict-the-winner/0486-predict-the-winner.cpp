class Solution {
private:
    //so the move that player1 creates the big impact 
    int solve(vector<int>& nums,vector<vector<int>>&dp, int left,int right){
        if(left==right) return nums[left];
        if(dp[left][right]!=INT_MIN) return dp[left][right];
        int l= nums[left]-solve(nums,dp,left+1,right);
        int r=nums[right]-solve(nums,dp,left,right-1);
        return dp[left][right]=max(l,r);
    }
public:
    bool predictTheWinner(vector<int>& nums) {
        int n= nums.size();
        //player one has adv of making move first
        vector<vector<int>>dp(n,vector<int>(n,INT_MIN));
        //points diff og player1 if two of them plays optimally
        int points=solve(nums,dp,0,n-1);
        if(points>=0) return true;
        return false;  //even after the adv if player 1 fails
    }
};