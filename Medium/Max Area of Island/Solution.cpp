class Solution {
public:
// Concept is same as Qs 200 only we have to update ans(here mini)...
    bool chk(int i,int j,int m,int n,vector<vector<int>>& grid){
        if(i>=0 && i<m && j>=0 && j<n && grid[i][j]==1) return true;
        return false;
    }
    void dfs(int i,int j,int m,int n,vector<vector<int>>& grid,int& ans){
        grid[i][j] = 0;
        ans++;
        if(chk(i+1,j,m,n,grid)) dfs(i+1,j,m,n,grid,ans);
        if(chk(i,j+1,m,n,grid)) dfs(i,j+1,m,n,grid,ans);
        if(chk(i-1,j,m,n,grid)) dfs(i-1,j,m,n,grid,ans);
        if(chk(i,j-1,m,n,grid)) dfs(i,j-1,m,n,grid,ans);
    }
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        int mini = 0;
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(grid[i][j] == 1){
                    int ans = 0;
                    dfs(i,j,m,n,grid,ans);
                    mini = max(mini,ans);
                }
            }
        }
        return mini;
    }
};
