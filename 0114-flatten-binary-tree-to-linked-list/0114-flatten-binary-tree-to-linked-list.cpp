class Solution {
public:
    void preo(TreeNode* root, vector<TreeNode*>& node) {
        if(root == NULL) return;

        node.push_back(root);

        preo(root->left, node);
        preo(root->right, node);
    }

    void flatten(TreeNode* root) {

        vector<TreeNode*> node;  

        preo(root, node);

        for(int i = 0; i + 1 < node.size(); i++){
            node[i]->left = NULL;
            node[i]->right = node[i + 1];
        }

        if(!node.empty()) {
            node[node.size() - 1]->left = NULL;
            node[node.size() - 1]->right = NULL;
        }
    }
};