class Solution {
public:
    int maxDiameter = 0;
    int diameterOfBinaryTree(TreeNode* root) {
        height(root);
        return maxDiameter;
    }
    int height(TreeNode* node) {
        if (node == NULL) return 0;
        int leftHeight = height(node->left);
        int rightHeight = height(node->right);
        maxDiameter = max(maxDiameter, leftHeight + rightHeight);
        return 1 + max(leftHeight, rightHeight);
    }
};
