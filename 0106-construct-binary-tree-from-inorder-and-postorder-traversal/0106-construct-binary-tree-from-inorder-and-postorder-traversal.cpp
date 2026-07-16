class Solution {
public:

    unordered_map<int,int> mp;
    int index;

    TreeNode* solve(vector<int>& postorder,
                    vector<int>& inorder,
                    int left,
                    int right)
    {
        if(left > right)
            return NULL;

        int rootVal = postorder[index--];

        TreeNode* root = new TreeNode(rootVal);

        int mid = mp[rootVal];

        // Build RIGHT first
        root->right = solve(postorder, inorder, mid+1, right);

        root->left = solve(postorder, inorder, left, mid-1);

        return root;
    }

    TreeNode* buildTree(vector<int>& inorder,
                        vector<int>& postorder)
    {
        index = postorder.size()-1;

        for(int i=0;i<inorder.size();i++)
            mp[inorder[i]] = i;

        return solve(postorder, inorder, 0, inorder.size()-1);
    }
};