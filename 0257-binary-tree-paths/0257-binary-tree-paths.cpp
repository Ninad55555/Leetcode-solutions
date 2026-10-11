class Solution {
public:
    vector<string> binaryTreePaths(TreeNode* root) {
        vector<string> result;
        dfs(root, "", result);
        return result;
    }
    void dfs(TreeNode* node, string path, vector<string>& result) {
        if (node == NULL) return;
        path += to_string(node->val);
        if (node->left == NULL && node->right == NULL) {
            result.push_back(path);
            return;
        }
        path += "->";
        dfs(node->left, path, result);
        dfs(node->right, path, result);
    }
};
