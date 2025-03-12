// User function Template for C++

/*
struct Node {
    int data;
    Node *left;
    Node *right;

    Node(int val) {
        data = val;
        left = right = NULL;
    }
};
*/
class Solution
{
public:
    Node *makeMappingAndFindTargetNode(Node *root, int target, unordered_map<Node *, Node *> &map)
    {
        queue<Node *> q;
        Node *targetNode = nullptr;
        if (!root)
            return nullptr;
        q.push(root);
        map[root] = nullptr;
        while (!q.empty())
        {
            auto front = q.front();
            q.pop();
            if (front->data == target)
            {
                targetNode = front;
            }
            if (front->left)
            {
                q.push(front->left);
                map[front->left] = front;
            }
            if (front->right)
            {
                q.push(front->right);
                map[front->right] = front;
            }
        }
        return targetNode;
    }
    int burnTheTree(Node *targetNode, unordered_map<Node *, Node *> &map)
    {
        unordered_map<Node *, bool> visited;
        queue<Node *> q;
        q.push(targetNode);
        visited[targetNode] = true;
        int T = 0;
        while (!q.empty())
        {
            int size = q.size();
            bool flag = false;
            for (int i = 0; i < size; i++)
            {
                Node *front = q.front();
                q.pop();
                if (front->left && !visited[front->left])
                {
                    visited[front->left] = true;
                    q.push(front->left);
                    flag = true;
                }
                if (front->right && !visited[front->right])
                {
                    visited[front->right] = true;
                    q.push(front->right);
                    flag = true;
                }
                if (map[front] && !visited[map[front]])
                {
                    visited[map[front]] = true;
                    q.push(map[front]);
                    flag = true;
                }
            }
            if (flag)
                ++T;
        }
        return T;
    }
    int minTime(Node *root, int target)
    {
        unordered_map<Node *, Node *> map;
        Node *targetNode = makeMappingAndFindTargetNode(root, target, map);
        return burnTheTree(targetNode, map);
    }
};