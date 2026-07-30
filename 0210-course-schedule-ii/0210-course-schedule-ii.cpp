class Solution {
public:
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        //adj mat -> adj list
        vector<vector<int>>list(numCourses);
        for(auto p:prerequisites)
            list[p[1]].push_back(p[0]);
        //Solving using Kahn's Algorithm
        queue<int>q;
        vector<int>Indegree(numCourses,0);
        for(auto node:list){
            for(auto n:node)
                Indegree[n]++;   //incoming node count
        }
        vector<int>topo;
        for(int i=0;i<numCourses;i++){
            if(Indegree[i]==0) q.push(i);   //if to is DAG then atleast one val will be zero 
        }
        while(!q.empty()){
            int val=q.front();
            q.pop();
            topo.push_back(val);  //bcuz its indegree is 0 
            for(auto v:list[val]){
                Indegree[v]--;     //cutting off the nodes 
                if(Indegree[v]==0) q.push(v);
            }
        }
        //if no of elements is equal to courses then it is possible
        return topo.size()==numCourses?topo:vector<int>{}; 
    }
};