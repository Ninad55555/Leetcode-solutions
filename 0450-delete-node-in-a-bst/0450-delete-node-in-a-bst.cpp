class Solution {
public:
    TreeNode* deleteNode(TreeNode* root, int key) {
        if (root == NULL) return NULL;
        if (key < root->val) {
            root->left = deleteNode(root->left, key);
        } else if (key > root->val) {
            root->right = deleteNode(root->right, key);
        } else {
            if (root->left == NULL) {
                TreeNode* rightChild = root->right;
                delete root;
                return rightChild;
            } else if (root->right == NULL) {
                TreeNode* leftChild = root->left;
                delete root;
                return leftChild;
            } else {
                TreeNode* successor = root->right;
                while (successor->left != NULL) {
                    successor = successor->left;
                }
                root->val = successor->val;
                root->right = deleteNode(root->right, successor->val);
            }
        }
        return root;
    }
};
