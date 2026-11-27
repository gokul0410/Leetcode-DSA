class Solution {
public:
    int maxOperations(vector<int>& nums, int k) {
        int n = nums.size();
        unordered_map<int,int> mp;
        for(auto it : nums) mp[it]++;
        int operation = 0;
        for(auto it : nums){
            if(mp[it] == 0) continue;
            int compliment = k-it;
            if(mp.find(compliment)!= mp.end()){
                if(mp[compliment] == 0) continue;
                if(compliment == it){
                    if(mp[compliment] ==1) continue;
                }
                cout<<it<<" "<<compliment<<endl;
                mp[compliment]--;
                mp[it]--;
                operation++;
            }
        }
        return operation;
    }
};