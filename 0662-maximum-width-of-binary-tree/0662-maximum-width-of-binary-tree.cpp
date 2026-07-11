/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    int widthOfBinaryTree(TreeNode* root) {
        if(root == nullptr) return 0;
      int res = 0;
      queue<pair<TreeNode* , long long>> q;
      q.push({root , 0});
      while(!q.empty()){
        long long n = q.size();
        long long first = q.front().second;
        long long last = first;
      for(int i = 0; i < n; i++){
        auto it = q.front();
        q.pop();
        TreeNode* node = it.first;
        long long load = it.second - first;
        if(i == n-1) last = load;
       if(node->left) q.push({node->left , 2*load + 1});
       if(node->right) q.push({node->right , 2*load + 2});
       } 
        res = max(res , (int)last + 1);
      }
      return res;
    }
};