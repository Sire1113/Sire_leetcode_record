/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* left;
    Node* right;
    Node* next;

    Node() : val(0), left(NULL), right(NULL), next(NULL) {}

    Node(int _val) : val(_val), left(NULL), right(NULL), next(NULL) {}

    Node(int _val, Node* _left, Node* _right, Node* _next)
        : val(_val), left(_left), right(_right), next(_next) {}
};
*/

class Solution {
public:
    Node* connect(Node* root) {
        queue<Node*> nodes;
        if (root)
            nodes.push(root);
        while (!nodes.empty()){
            int size = nodes.size();
            while (size--){
                auto node = nodes.front();
                nodes.pop();
                if (node->left)
                    nodes.push(node->left);
                if (node->right)
                    nodes.push(node->right);
                if (size > 0)
                    node->next = nodes.front();
            }
        }
        return root;
    }
};