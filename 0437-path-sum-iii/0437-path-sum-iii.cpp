class Solution {
public:

    int pathFromNode(TreeNode* root, long target)
    {
        if(root == nullptr)
            return 0;

        int count = 0;

        if(root->val == target)
            count++;

        count += pathFromNode(root->left,
                              target-root->val);

        count += pathFromNode(root->right,
                              target-root->val);

        return count;
    }

    int pathSum(TreeNode* root, int targetSum)
    {
        if(root == nullptr)
            return 0;

        return pathFromNode(root,targetSum)
             + pathSum(root->left,targetSum)
             + pathSum(root->right,targetSum);
    }
};