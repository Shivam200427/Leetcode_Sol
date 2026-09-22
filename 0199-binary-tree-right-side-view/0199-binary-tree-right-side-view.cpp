class Solution {
public:
    void solve (TreeNode* node,int level,vector<int>&ans){
        if(node == NULL) return;

        if(level == ans.size()){
            ans.push_back(node->val);
        }
        else{
            ans[level] = node->val;
        }

        solve(node->left,level+1,ans);
        solve(node-> right, level+1,ans);
    }


    vector<int> rightSideView(TreeNode* root) {
        vector<int>ans;
        solve(root,0,ans);
        return ans;
        
    }
};