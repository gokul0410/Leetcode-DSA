class Solution {
public:
    using ll=long long ; int MOD =1e9+7;
    const ll lmax=LLONG_MAX;
    int countPaths(int n, vector<vector<int>>& roads) {
        vector<vector<pair<int,int>>>list(n);
        for(auto it : roads){
            list[it[0]].push_back({it[1],it[2]});
            list[it[1]].push_back({it[0],it[2]});
        }
        priority_queue<pair<long long,int>,vector<pair<long long,int>>,
        greater<pair<long long,int>>> pq;
        vector<ll>distance(n,lmax); vector<ll>ways(n,0);
        ways[0]=1; distance[0]=0 ; pq.push({0,0});
        while(!pq.empty()){
            int node=pq.top().second ; ll weight=pq.top().first; pq.pop();
            if(weight>distance[node]) continue;
            for(auto it : list[node]){
                int adjnode=it.first, wt = it.second;
                if(wt+weight <distance[adjnode]){
                    distance[adjnode] = wt+weight;
                    ways[adjnode]=ways[node];
                    pq.push({wt+weight,adjnode});
                }else if(wt+weight == distance[adjnode]){
                    //if there is another way with same short dis 
                    ways[adjnode] = (ways[adjnode]+ways[node])%MOD;
                }
            }
        }
        return ways[n-1];
    }
};