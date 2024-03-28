#include <iostream>
#include <stack>
#include <vector>

struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode()
        : val(0)
        , left(nullptr)
        , right(nullptr) {
    }
    TreeNode(int x)
        : val(x)
        , left(nullptr)
        , right(nullptr) {
    }
    TreeNode(int x, TreeNode* left, TreeNode* right)
        : val(x)
        , left(left)
        , right(right) {
    }
};

auto buildTree(std::vector<int> const& pre, std::vector<int> const& in) -> TreeNode* {
    size_t i = 0, j = 0;
    auto* root = new TreeNode(0x80000000);
    TreeNode *pp = nullptr;
    auto *ptr = root;
    std::stack<TreeNode*> sn;
    sn.push(root);
    while (j < in.size()) {
        if (sn.top()->val == in[j]) {
            pp = sn.top();
            sn.pop();
            j++;
        } else if (pp) {
            ptr = new TreeNode(pre[i]);
            pp->right = ptr;
            pp = nullptr;
            sn.push(ptr);
            i++;
        } else {
            ptr = new TreeNode(pre[i]);
            sn.top()->left = ptr;
            sn.push(ptr);
            i++;
        }
    }
    ptr = root->left;
    delete root;
    return ptr;
}
void PosOrderTraversal(TreeNode* root) {
    if (root == nullptr) {
        return;
    }
    PosOrderTraversal(root->left);
    PosOrderTraversal(root->right);
    std::cout << root->val << ' ';
}

auto main() -> int {
    int n;
    std::cin >> n;
    std::vector<int> in(n), pre(n);
    for (int& i : pre) std::cin >> i;
    for (int& i : in) std::cin >> i;
    auto* root = buildTree(pre, in);
    PosOrderTraversal(root);
}