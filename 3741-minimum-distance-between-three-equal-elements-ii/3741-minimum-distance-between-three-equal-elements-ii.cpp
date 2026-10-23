class Solution {
public:
    int minimumDistance(vector<int>& nums) {
        int n = nums.size();
        unordered_map<int, vector<int>> mp;
        for(int i=0;i<n;i++)
            mp[nums[i]].push_back(i);

        int dist = INT_MAX;
        for(auto m : mp){
            if(m.second.size()<3 ) continue;
            int i =0 , j = 1, k = 2;
            while(k<m.second.size()){
                int d = abs(m.second[i]-m.second[j])+abs(m.second[j]-m.second[k])+abs(m.second[k]-m.second[i]);
                dist = min(dist,d);
                i++; j++; k++;
            }
        }
        return dist == INT_MAX ? -1 : dist;
    }
};