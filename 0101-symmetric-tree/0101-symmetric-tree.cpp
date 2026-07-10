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
    bool compare(TreeNode* r1 , TreeNode* r2){
      if(r1 == nullptr && r2 == nullptr) return true;
      if(r1 == nullptr || r2 == nullptr) return false;
      if(r1->val != r2->val) return false;
      bool w1 = compare(r1->left , r2->right);
      bool w2 = compare(r1->right , r2->left);
       if(w1== true && w2 == true) return true;
      
      return false;
    } 
    bool isSymmetric(TreeNode* root) {
     return compare(root->left , root->right);
    }
};