/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> neighbors;
    Node() {
        val = 0;
        neighbors = vector<Node*>();
    }
    Node(int _val) {
        val = _val;
        neighbors = vector<Node*>();
    }
    Node(int _val, vector<Node*> _neighbors) {
        val = _val;
        neighbors = _neighbors;
    }
};
*/

class Solution {
public:
    Node* cloneGraph(Node* node) {
        Node* newNode;
        if(!node){
            return nullptr;
        }

        newNode = new Node(node->val);

        queue<Node*> que;
        unordered_map<Node*, Node*> mpp; // for tacking of visited node
        que.push(node);
        mpp[node] = newNode;

        while(!que.empty()){
            Node* node = que.front(); que.pop();

            for(auto &neighNode : node->neighbors){
                if(!mpp[neighNode]){
                    que.push(neighNode);

                    Node* cloned = new Node(neighNode->val);
                    mpp[neighNode] = cloned;
                }

                // Connect cloned neighbour
                mpp[node]->neighbors.push_back(mpp[neighNode]);
            }
        }

        return newNode; 
    }
};