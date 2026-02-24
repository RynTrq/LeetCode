class Solution {
public:
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        const int n = grid.size();
        const int m = grid[0].size();

        const int directions[4][2] = {{0,1}, {0,-1}, {1,0}, {-1,0}};

        int maxArea = 0;

        for(int i=0; i<n; i++){
            for(int j=0; j<m; j++){
                if(grid[i][j]){
                    int area = 1;

                    queue<pair<int, int>> Q;
                    grid[i][j] = 0;
                    Q.emplace(i, j);

                    while(!Q.empty()){
                        int crntRow = Q.front().first;
                        int crntColumn = Q.front().second;
                        Q.pop();

                        for(auto el:directions){
                            int row = el[0];
                            int column = el[1];
                            row += crntRow;
                            column += crntColumn;

                            if(row>=0 && row<n && column>=0 && column<m && grid[row][column]==1){
                                area++;
                                grid[row][column] = 0;
                                Q.emplace(row, column);
                            }
                        }
                    }
                    maxArea = max(area, maxArea);
                }
            }
        }

        return maxArea;
    }
};