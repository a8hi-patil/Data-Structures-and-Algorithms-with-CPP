class Solution
{
public:
    bool checkIsBalancedTree(Node *root)
    {
        queue<Node *> q;
        q.push(root);
        bool isNullFound = false;
        while (!q.empty())
        {
            auto front = q.front();
            q.pop();
            if (!front)
            {
                isNullFound = true;
            }
            else
            {
                if (isNullFound)
                    return false;
                q.push(front->left);
                q.push(front->right);
            }
        }
        return true;
    }
    bool isRootGreaterTree(Node *root)
    {
        if (!root)
            return true;
        if (!root->left && !root->right)
            return true;

        bool leftAns = isRootGreaterTree(root->left);
        ;
        bool rightAns = isRootGreaterTree(root->right);

        bool currAns = root->left && root->left->data < root->data && root->right && root->right->data < root->data;
        // bool option1 = true;
        // if(root->left && root->left->data > root->data  ){
        //     option1 = false;
        // }
        // bool option2 = true;
        // if(root->right && root->right->data > root->data  ){
        //     option2 = false;
        // }
        // bool currAns =option1  &&option2 ;
        return leftAns && rightAns && currAns;
    }
    bool isHeap(struct Node *tree)
    {
        bool checkIsBalanced = checkIsBalancedTree(tree);
        bool isRootGreater = isRootGreaterTree(tree);
        return checkIsBalanced && isRootGreater;
    }
};