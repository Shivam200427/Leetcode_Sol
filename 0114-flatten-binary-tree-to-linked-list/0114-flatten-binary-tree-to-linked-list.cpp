class Solution {
public:

    void flatten(TreeNode* root) {

        if (root == NULL)
            return;

        flatten(root->left);
        flatten(root->right);

        TreeNode* left = root->left;
        TreeNode* right = root->right;

        root->left = NULL;
        if (left != NULL) {
            root->right = left;
            TreeNode* temp = left;
            while (temp->right != NULL) {
                temp = temp->right;
            }
            temp->right = right;
        }
    }
};