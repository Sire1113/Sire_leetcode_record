/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> children;

    Node() {}

    Node(int _val) {
        val = _val;
    }

    Node(int _val, vector<Node*> _children) {
        val = _val;
        children = _children;
    }
};
*/

class Solution {
public:
    vector<vector<int>> levelOrder(Node* root) {
        queue<Node*> nodes;
        vector<vector<int>> res;
        if (root)
            nodes.push(root);
        while (!nodes.empty()){
            int size = nodes.size();
            vector<int> layer;
            while (size--){
                auto node = nodes.front();
                for (auto& sub_node: node->children){
                    if (sub_node)
                        nodes.push(sub_node);
                }
                nodes.pop();
                layer.push_back(node->val);
            }
            res.push_back(layer);
        }
        return res;
    }
};