class Solution {
    using ll = long long;
    const ll lmax = LLONG_MAX;
public:
    long long minimumCost(string source, string target, vector<char>& original, vector<char>& changed, vector<int>& cost) {
        vector<vector<ll>>distance(26,vector<ll>(26,lmax));
        for(int i=0;i<26;i++){
            for(int j=0;j<26;j++){
                if(i==j) distance[i][j]=0;
            }
        }
        for(int i=0;i<original.size();i++){
            int u = original[i]-'a';
            int v = changed[i]-'a';
            distance[u][v]=min(distance[u][v],1LL*cost[i]);
        }
        for(int via=0;via<26;via++){
            for(int i=0;i<26;i++){
                //since adding inf with any no is inf so reducing iter 
                if(distance[i][via]==lmax) continue;
                for(int j=0;j<26;j++){
                    if(distance[via][j]!=lmax)
                        distance[i][j]=min(distance[i][j],distance[i][via]+distance[via][j]);
                }
            }
        }
        long long amt =0;
        for(int i=0;i<source.size();i++){
            int u = source[i]-'a';
            int v =target[i]-'a';
            if(u==v) continue;  //element is same no replacement
            if(distance[u][v]==lmax) return -1;
            amt += distance[u][v];
        }
        return amt;
    }
};