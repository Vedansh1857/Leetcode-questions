class Solution {
public:
    bool chk(vector<int> base_box , vector<int> new_box){
        if(new_box[0]<=base_box[0] && new_box[1]<=base_box[1] && new_box[2]<=base_box[2]) return true;
        return false;
    }
    int space_optimization_lis(int n,vector<vector<int>>& cuboids){
        vector<int> currRow(n+1,0);
        vector<int> nextRow(n+1,0);
        for(int curr = n-1;curr>=0;curr--){
            for(int prev = n-1;prev>=-1;prev--){
                int incl = 0;
                if(prev == -1 || chk(cuboids[curr],cuboids[prev])) incl = cuboids[curr][2] + nextRow[curr+1];
                int excl = 0 + nextRow[prev+1];
                currRow[prev+1] = max(incl,excl);
            }
            nextRow = currRow; // Shifting Logic...
        }
        return currRow[0];
    }
    int maxHeight(vector<vector<int>>& cuboids){
        // Sort each cuboid's dimension to get the max element at the end and consider that to be the height of the cuboid.
        for(auto& i : cuboids) sort(i.begin(),i.end());
        // Now sort the updated cuboids array on the basis of width and length to get the cuboid of min dimensions on the top.
        sort(cuboids.begin(),cuboids.end());
        // Now apply the logic of LIS(Longest increasing subsequence)
        return space_optimization_lis(cuboids.size(),cuboids);
    }
};
