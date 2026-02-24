class Solution {
public:
    int findCircleNum(vector<vector<int>>& isConnected) {
        int n = isConnected.size();

        vector<vector<int>> graph(n);
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                if(isConnected[i][j]){
                    graph[i].push_back(j);
                }
            }
        }

        vector<bool> isTraversed(n);

        int tbr = 0;

        for(int i=0; i<n; i++){
            if(!isTraversed[i]){
                tbr++;

                queue<int> myQ;
                myQ.push(i);
                isTraversed[i] = true;

                while(!myQ.empty()){
                    int crnt = myQ.front();
                    myQ.pop();

                    for(int j=0; j<graph[crnt].size();j++){
                        if(!isTraversed[graph[crnt][j]]){
                            isTraversed[graph[crnt][j]] = true;
                            myQ.push(graph[crnt][j]);
                        }
                    }
                }
            }
        }

        return tbr;
    }
};