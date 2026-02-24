class Solution {
public:
    void DFSTraversal(vector<vector<int>>& isConnected, vector<bool>& isVisited, int crnt){
        for(int j=0; j<isConnected.size(); j++){
            if(!isVisited[j] && isConnected[crnt][j]){
                isVisited[j] = true;
                DFSTraversal(isConnected, isVisited, j);
            }
        }
    }
    
    int findCircleNum(vector<vector<int>>& isConnected) {
        int provs = 0;

        vector<bool> isVisited(isConnected.size(), false);

        for(int i=0; i<isConnected.size(); i++){
            if(!isVisited[i]){
                provs++;
                isVisited[i] = true;
                DFSTraversal(isConnected, isVisited, i);
            }
        }

        return provs;
    }
};