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
    int xDepth=0;
    int yDepth=0;
    TreeNode* xparent=nullptr;
    TreeNode* yparent=nullptr;
    void solve(TreeNode* root,TreeNode* parent,int depth,int x,int y)
    {
        if(root==nullptr)
         return;
        if(root->val==x)
        {
            xDepth=depth;
            xparent=parent;
        }
        if(root->val==y)
        {
            yDepth=depth;
            yparent=parent;
        }
        solve(root->left,root,depth+1,x,y);
        solve(root->right,root,depth+1,x,y);
    }
    bool isCousins(TreeNode* root, int x, int y) {
        solve(root,nullptr,0,x,y);
        return (xDepth==yDepth) && (xparent!=yparent);

        
    }
};