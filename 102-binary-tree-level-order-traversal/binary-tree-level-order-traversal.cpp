const auto _ = std::cin.tie(nullptr)->sync_with_stdio(false);
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left),
 * right(right) {}
 * };
 */
class Solution {
public:
    vector<vector<int>> levelOrder(TreeNode* root) {
        vector<vector<int>> answer;
        if (root == nullptr) {
            return answer;
        }

        queue<TreeNode*> que;
        que.push(root);

        while (!que.empty()) {
            int queSize = que.size();
            vector<int> level;

            while (queSize--) {
                TreeNode* curr = que.front();
                que.pop();
                level.emplace_back(curr->val);

                if (curr->left) {
                    que.push(curr->left);
                }
                if (curr->right) {
                    que.push(curr->right);
                }
            }

            answer.emplace_back(level);
        }

        return answer;
    }
};