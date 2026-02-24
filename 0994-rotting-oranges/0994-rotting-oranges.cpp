class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        const int m = grid.size();
        const int n = grid[0].size();

        const int directions[4][2] = {{0,1}, {0,-1}, {1,0}, {-1,0}};
        
        queue<pair<pair<int, int>, int>> Q;

        int fresh = 0;
        int time = 0;

        for(int i=0; i<m; i++){
            for(int j=0; j<n; j++){
                if(grid[i][j]==2){
                    Q.push({{i,j},0});
                }else if(grid[i][j]==1){
                    fresh++;
                }
            }
        }

        while(!Q.empty()){
            auto crntEl = Q.front();
            Q.pop();

            time = max(time, crntEl.second);

            for(auto dir:directions){
                int row = crntEl.first.first + dir[0];
                int col = crntEl.first.second + dir[1];

                if(row>=0 && row<m && col>=0 && col<n && grid[row][col]==1){
                    fresh--;
                    grid[row][col] = 2;
                    Q.push({{row, col}, crntEl.second+1});
                }
            }
        }

        if(fresh>0){
            return -1;
        }else{
            return time;
        }
    }
};