class Solution {
public:
    vector<bool> pathExistenceQueries(int n, vector<int>& nums, int maxDiff, vector<vector<int>>& queries) {
        //question if the u and v are connected (exists)
        vector<int>component_no(n);
        component_no[0]=0;
        int cnt=0;
        for(int i=1;i<n;i++){
            //since sorted array i+1 > i 
            if(nums[i]-nums[i-1]<=maxDiff)
                component_no[i]=cnt;
            else{
                cnt++;
                component_no[i]=cnt;
            }
        }
        vector<bool>result;
        for(auto q : queries){
            int u=q[0],v=q[1];
            result.push_back(component_no[u]==component_no[v]);
        }
        return result;
    }
};