class Solution {
public:
    
void dfs(int i,int &tr,vector<vector<int>>& am,vector<int> &vis,vector<int> &diff,vector<int> &lo,int n,vector<vector<int>> &sol,int parent){
        vis[i]=1;
        tr++;
        lo[i]=tr;
        diff[i]=tr;
        
        for(int j=0;j<am[i].size();j++ ){
            if(vis[am[i][j]]==0){
            dfs(am[i][j],tr,am,vis,diff,lo,n,sol,i);
            if(lo[am[i][j]]>diff[i]){
                vector<int> v;
                v.push_back(i);
                v.push_back(am[i][j]);
                sol.push_back(v);
             }
            }
            
        }
        
         for(int j=0;j<am[i].size();j++ ){
             if(am[i][j]!=parent)
             lo[i]=min(lo[i],lo[am[i][j]]);
             
         }
        
        
    }
    vector<vector<int>> criticalConnections(int n, vector<vector<int>>& c) {
        vector<vector<int>> am(n);
        
        for(int i=0;i<c.size();i++){
            
            am[c[i][0]].push_back(c[i][1]);
            am[c[i][1]].push_back(c[i][0]);
            
            
        }
        
        vector<int> vis(n,0),diff(n,0),lo(n,0);
        vector<vector<int>> sol;
        int tr=0;
        dfs(0,tr,am,vis,diff,lo,n,sol,0);
    
        return sol;
    }
};
