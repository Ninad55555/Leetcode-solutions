class Solution {
public:
    bool validPath(int n, vector<vector<int>>& edges, int source, int destination) {
        vector<vector<int>> adj(n);
        for (auto& e : edges) {
            adj[e[0]].push_back(e[1]);
            adj[e[1]].push_back(e[0]);
        }
        vector<bool> visited(n, false);
        return dfs(adj, visited, source, destination);
    }
    bool dfs(vector<vector<int>>& adj, vector<bool>& visited, int curr, int destination) {
        if (curr == destination) return true;
        visited[curr] = true;
        for (int next : adj[curr]) {
            if (!visited[next]) {
                if (dfs(adj, visited, next, destination)) return true;
            }
        }
        return false;
    }
};

