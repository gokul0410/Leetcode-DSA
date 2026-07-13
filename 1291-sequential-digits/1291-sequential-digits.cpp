class Solution {
public:
    vector<int> sequentialDigits(int low, int high) {
        queue<int>q; vector<int>result;
        for(int i=1;i<=9;i++) q.push(i);
        while(!q.empty()){
            int num=q.front(); q.pop();
            if(num>=low && num<=high)
                result.push_back(num);
            int last= num%10;
            //because 9 will not give sequential num
            if(last<9){
                int val = num*10 +last +1;
                q.push(val);
            }
        }
        return result;
    }
};