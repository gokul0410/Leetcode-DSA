class Solution {
public:
    int lastStoneWeight(vector<int>& stones) {
        int n = stones.size();
        priority_queue<int>pq;
        for(int i=0;i<n;i++){
            pq.push(stones[i]);
        }
        while(pq.size()>1){
            int maxi1=pq.top();pq.pop();
            int maxi2=pq.top();pq.pop();
            if(maxi1==maxi2) continue;
            int y = maxi1-maxi2;
            pq.push(y);
        }
        if(pq.empty()) return 0;
        return pq.top();
    }
};