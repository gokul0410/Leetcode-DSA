class Solution {
public:
    int minSwaps(vector<int>& nums) {
        int n = nums.size();
        // digit sum store 
        vector<pair<int,int>>num;
        map<pair<int,int> , int> mp;
        vector<pair<int,int>>temp;
        for(int i=0;i<n;i++){
            int val = nums[i] , sum = 0;
            while(val!=0){
                sum+=(val%10);
                val/=10;
            }
            num.push_back({sum,nums[i]});
            mp[{sum,nums[i]}] = i;
            temp.push_back({sum , nums[i]});
        }
        // n log(n)
        sort(temp.begin(),temp.end());
        int result = 0;
        for(int i=0 ; i<n;i++){
            if(num[i] == temp[i]) continue;
            int pos = mp[temp[i]];
            swap(num[i] , num[pos]);
            mp[num[i]] = i;
            mp[num[pos]] = pos;
            result++;
        }
        return result;
    }
};