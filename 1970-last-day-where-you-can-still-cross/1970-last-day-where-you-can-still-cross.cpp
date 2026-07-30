class Solution {
private:
class Disjointset{  vector<int>parent;
public:
    Disjointset(int n){
        parent.resize(n+1); /*based*/ for(int i=0;i<=n;i++) parent[i]=i;}
    int find(int node)
        {if(parent[node]==node) return node; return parent[node]=find(parent[node]);}
    void join(int u , int v){
        int l = find(u), r=find(v);  if(l==r) return; if(l!=r) parent[r]=l;
    }};
public:
    int latestDayToCross(int row, int col, vector<vector<int>>& cells) {
        int n = row*col; Disjointset DSU(n+1);
        auto getId =[&] (int r, int c){
            return r*col+c+1;};
        vector<vector<bool>>water(row,vector<bool>(col,false));
        int dir[4][2]={{1,0},{-1,0},{0,1},{0,-1}};
        for(int i=cells.size()-1;i>=0;i--){
            int r = cells[i][0]-1 , c=cells[i][1]-1;
            water[r][c] = true; int node=getId(r,c);
            if(r==0) DSU.join(node,0);
            if(r==row-1) DSU.join(node,n+1);
            for(int d=0;d<4;d++){
                int adjr=r+dir[d][0],adjc=c+dir[d][1];
                if(adjr>=0 && adjc>=0 && adjr<row && adjc<col && water[adjr][adjc])
                   { int neighbour=getId(adjr,adjc); DSU.join(node,neighbour);}}
             if(DSU.find(0)==DSU.find(n+1)) return i;}
        return 0;
    }
};