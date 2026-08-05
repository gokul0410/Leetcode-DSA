class Solution {
    void suspect(vector<bool>&sus,vector<vector<int>>&adj,int src){
        if(sus[src]) return;
        sus[src]=true;
        if(adj[src].size()==0) return;
        for(int i=0;i<adj[src].size();i++){
            suspect(sus,adj,adj[src][i]);
        }
    }
public:
    vector<int> remainingMethods(int n, int k, vector<vector<int>>& invocations) {
        int edge = invocations.size();
        vector<vector<int>>adj(n);
        for(int i=0;i<edge;i++){
            adj[invocations[i][0]].push_back(invocations[i][1]);
        }
        vector<bool>sus(n,false);
        vector<int>result;
        for(int i=0;i<n;i++) result.push_back(i);
        suspect(sus,adj,k);
        bool found =false;
        for(int i=0;i<adj.size();i++){
            for(int j=0;j<adj[i].size();j++){
                if(sus[i]==false && sus[adj[i][j]]==true){
                    found=true;
                    break;
                }
            }
            if(found) return result;
        }
        
        vector<int>val;
        for(int i=0;i<n;i++)
            if(!sus[i]) val.push_back(i);
        return val;
    }
};