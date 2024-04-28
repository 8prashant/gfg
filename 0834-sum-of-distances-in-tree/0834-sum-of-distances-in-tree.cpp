class Solution {
public:
    vector<int> sumOfDistancesInTree(int n, vector<vector<int>>& edges) {
        vector<vector<int>> adj(n);
        for(auto& edge : edges) {
            adj[edge[0]].push_back(edge[1]);
            adj[edge[1]].push_back(edge[0]);
        }
        
        vector<int> count(n, 1); // Count of nodes in subtree rooted at i
        vector<int> res(n, 0);   // Result for each node
        vector<bool> visited(n, false);
        
        // First DFS to calculate counts and result for root 0
        dfs(0, adj, count, res, visited);
        
        // Second DFS to propagate counts and calculate results for all nodes
        visited.assign(n, false);
        dfs2(0, adj, count, res, visited, n);
        
        return res;
    }
    
    // DFS to calculate counts and results for root 0
    void dfs(int node, vector<vector<int>>& adj, vector<int>& count, vector<int>& res, vector<bool>& visited) {
        visited[node] = true;
        for(int neighbor : adj[node]) {
            if(!visited[neighbor]) {
                dfs(neighbor, adj, count, res, visited);
                count[node] += count[neighbor];
                res[node] += res[neighbor] + count[neighbor];
            }
        }
    }
    
    // DFS to propagate counts and calculate results for all nodes
    void dfs2(int node, vector<vector<int>>& adj, vector<int>& count, vector<int>& res, vector<bool>& visited, int n) {
        visited[node] = true;
        for(int neighbor : adj[node]) {
            if(!visited[neighbor]) {
                res[neighbor] = res[node] - count[neighbor] + n - count[neighbor];
                dfs2(neighbor, adj, count, res, visited, n);
            }
        }
    }
};
