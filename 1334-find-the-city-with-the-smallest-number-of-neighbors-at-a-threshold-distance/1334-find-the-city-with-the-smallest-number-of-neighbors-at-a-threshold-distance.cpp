class Solution {
using int2 = pair<int,int>;
public:
    int findTheCity(int n, vector<vector<int>>& edges, int distanceThreshold) {
        vector<vector<int2>>list(n);
        for(auto it : edges){
            list[it[0]].push_back({it[1],it[2]});
            list[it[1]].push_back({it[0],it[2]});
        }
        int mini_result=INT_MAX,result=-1;
        for(int i=0;i<n;i++){
            priority_queue<int2,vector<int2>,greater<int2>>pq;
            vector<int>distance(n,INT_MAX);
            pq.push({0,i}); //{distance , src }
            distance[i] =0;
            while(!pq.empty()){
                auto it = pq.top(); int dist=it.first,node =it.second;
                pq.pop();
                for(auto val:list[node]){
                    int adjnode = val.first, wt = val.second;
                    if(dist+wt < distance[adjnode]){
                        pq.push({dist+wt , adjnode});
                        distance[adjnode]= dist +wt;
                    }
                }
            }
            int count=0;
            for(int j=0;j<n;j++){
                if(i!=j && distance[j]<=distanceThreshold){
                    count++;
                }
            }
            if(mini_result>=count){
                mini_result = count;
                result=max(i,result);
            }
        }
        return result;
    }
};