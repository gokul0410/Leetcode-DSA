class Solution {
private:
    int reverse(int val){
        int rev = 0;
        while(val != 0){
            rev = (rev*10)+(val%10);
            val/=10;
        }
        return rev;
    }
public:
    int minMirrorPairDistance(vector<int>& nums) {
        int n = nums.size();
        unordered_map<int , vector<int>> mp;
        for(int i=0;i<n;i++){
            mp[nums[i]].push_back(i);
        }
        int mindiff = INT_MAX;
        for(int i=0;i<n;i++){
            int rev = reverse(nums[i]);
            if(mp.find(rev)!= mp.end()){
                auto it = upper_bound(mp[rev].begin(), mp[rev].end(),i);
                //cout<<"yes"<<" ";
                //if(it != mp[rev].end())cout<<*it<<" ";
                if(it != mp[rev].end()) mindiff = min(mindiff , abs(i-*it));
            }
        }
        return mindiff == INT_MAX?-1 : mindiff;
    }
};