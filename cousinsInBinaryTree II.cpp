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
    TreeNode* replaceValueInTree(TreeNode* root) {
        std::deque<TreeNode*> q;
        q.push_back(root);
        root->val = 0;

        while (!q.empty()) {
            int nextLevelSum = 0;
            int levelSize = q.size();

            // First pass: calculate the sum of the next level
            for (int i = 0; i < levelSize; ++i) {
                TreeNode* node = q[i];
                if (node->left) nextLevelSum += node->left->val;
                if (node->right) nextLevelSum += node->right->val;
            }

            // Second pass: process current level nodes
            for (int i = 0; i < levelSize; ++i) {
                TreeNode* node = q.front();
                q.pop_front();

                int siblingSum = 0;
                if (node->left) siblingSum += node->left->val;
                if (node->right) siblingSum += node->right->val;

                if (node->left) {
                    node->left->val = nextLevelSum - siblingSum;
                    q.push_back(node->left);
                }
                if (node->right) {
                    node->right->val = nextLevelSum - siblingSum;
                    q.push_back(node->right);
                }
            }
        }

        return root;
    }
};
   