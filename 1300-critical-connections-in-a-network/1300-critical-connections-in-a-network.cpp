class Solution {
public:
    int timer = 0;
    vector<vector<int>> bridges;
    void dfs(int node, int parNode, vector<int> &vis, vector<int> &time, vector<int> &mnTime, vector<int> adj[]) {
        vis[node] = 1;
        time[node] = timer;
        mnTime[node] = time[node];
        ++timer;
        for(int &itr : adj[node]) {
            if(itr == parNode) continue;
            if(!vis[itr]) {
                dfs(itr, node, vis, time, mnTime, adj);
                mnTime[node] = min(mnTime[itr], mnTime[node]);
                if(mnTime[itr] > time[node]) {
                    bridges.push_back({node, itr});
                }
            }
            else {
                mnTime[node] = min(mnTime[itr], mnTime[node]);
            }
        }

    }
    vector<vector<int>> criticalConnections(int n, vector<vector<int>>& connections) {
        vector<int> adj[n];
        for(auto &itr : connections) {
            adj[itr[0]].push_back(itr[1]);
            adj[itr[1]].push_back(itr[0]);
        }
        vector<int> vis(n), time(n), mnTime(n);
        dfs(0, -1, vis, time, mnTime, adj);
        return bridges;
    }
};