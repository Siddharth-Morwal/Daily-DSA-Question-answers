/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    // TreeNode* ans = nullptr;
    //   int lca(TreeNode* root, TreeNode* p, TreeNode* q){
    //     if(root ==nullptr ) return 0;
    //     int left = lca(root->left , p , q);
    //     int right = lca(root->right , p , q);
    //     int self = 0;
    //     if(root == p || root == q) self = 1;
    //     int total = self + left + right;
    //     if(total == 2 && ans == nullptr) ans = root;
    //     return total;
    //   }
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
    //    lca(root , p , q);
    //    return ans;
      if(root == nullptr || root == p || root == q ) return root;

      TreeNode* left = lowestCommonAncestor(root->left , p , q);
      TreeNode* right = lowestCommonAncestor(root->right , p , q);

      if(left == nullptr) return right;
      if(right == nullptr) return left;

      else return root;
    }
};