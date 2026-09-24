class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        int n = nums.size();
        //boyer moree voting algorithm 
        int maj1 = INT_MAX , maj2 = INT_MAX;
        int cnt1 = 0 , cnt2 = 0;
        for(int i=0;i<n;i++){
            // existing num is maj 
            if(nums[i] == maj1) cnt1++;
            else if(nums[i] == maj2 ) cnt2++;
            //change the maj if cnt == 0 
            else if(cnt1 == 0 ){
                maj1 = nums[i];
                cnt1++;
            }else if(cnt2 ==0 ){
                maj2 = nums[i];
                cnt2++;
            }else{
                cnt1--; cnt2--;
            }
        }
        vector<int>result;
        cnt1 = 0 , cnt2 = 0;
        //verification whether it occurs n/3 times
        for(int i=0;i<n;i++){
            if(nums[i] == maj1) cnt1++;
            if(nums[i] == maj2) cnt2++;
        }
        if(cnt1 > n/3) result.push_back(maj1);
        //whether it is duplicate or not , maj duplicates are not allowed 
        if(cnt2 > n/3 && maj1!=maj2) result.push_back(maj2);
        return result;
     }
};