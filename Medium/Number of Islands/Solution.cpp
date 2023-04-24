class Solution {
public:
    bool chk(int i,int j,int m,int n,vector<vector<char>>& grid){
        if(i>=0 && i<m && j>=0 && j<n && grid[i][j]=='1') return true;
        return false;
    }
    void noOfIsland(int i,int j,int m,int n,vector<vector<char>>& grid){
        grid[i][j] = 0; // Set 0 that grid value which u encountered as 1 bcz that square is already counted. When we further travel in all four directions, it should not be taken again.
        if(chk(i+1,j,m,n,grid)) noOfIsland(i+1,j,m,n,grid); // Check if the down square is a 1 through the chk function which returns a boolean value then consider that and move further down(through recursion) untill we get a 0
        if(chk(i,j+1,m,n,grid)) noOfIsland(i,j+1,m,n,grid);// Check if the right square is a 1 through the chk function which returns a boolean value then consider that and move further right(through recursion) untill we get a 0
        if(chk(i-1,j,m,n,grid)) noOfIsland(i-1,j,m,n,grid); // Check if the up square is a 1 through the chk function which returns a boolean value then consider that and move further up(through recursion) untill we get a 0
        if(chk(i,j-1,m,n,grid)) noOfIsland(i,j-1,m,n,grid); // Check if the left square is a 1 through the chk function which returns a boolean value then consider that and move further left(through recursion) untill we get a 0
    }
    int numIslands(vector<vector<char>>& grid) {
        int m = grid.size(); // rows
        int n = grid[0].size(); // columns
        int ans = 0;
        for(int i=0;i<m;i++){ // Start from the element[0][0]
            for(int j=0;j<n;j++){
                if(grid[i][j] == '1'){ // As u will find an island i.e. a "1"
                    ans++; // Increment ur answer by one and perform dfs for rest islands
                    noOfIsland(i,j,m,n,grid); //DFS
                }
            }
        }
        return ans;
    }
};
