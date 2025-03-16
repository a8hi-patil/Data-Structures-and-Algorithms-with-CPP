#include <iostream>
#include <cstdlib>
using namespace std;
class Node
{
public:
    int data;
    Node *left;
    Node *rigth;

    Node(int val)
    {
        this->data = val;
        this->left = nullptr;
        this->rigth = nullptr;
    }
};
int morrisTraversal(Node *root)
{
    Node *curr = root;
    int n = 0;
    while (curr)
    {
        if (!curr->left)
        {
            n++;
            curr = curr->rigth;
        }
        else
        {
            Node *p = curr->left;
            while (p->rigth && p->rigth != curr)
            {
                p = p->rigth;
            }
            if (p->rigth == nullptr)
            {
                p->rigth = curr;
                curr = curr->left;
            }
            else
            {
                n++;
                p->rigth = nullptr;
                curr = curr->rigth;
            }
        }
    }
    return n;
}
float fidMed(Node *root, int n)
{
    int i = 0;
    int odd1 = (n + 1 / 2), odd1Val = -1;
    int even1 = (n / 2), even1Val = -1;
    int even2 = (n / 2) + 1, even2Val = -1;
    Node *curr = root;
    while (curr)
    {
        if (!curr->left)
        {
            i++;
            if (i == odd1)
                odd1Val = curr->data;
            if (i == even1)
                even1Val = curr->data;
            if (i == even2)
                even2Val = curr->data;

            curr = curr->rigth;
        }
        else
        {
            Node *p = curr->left;
            while (p->rigth && p->rigth != curr)
            {
                p = p->rigth;
            }
            if (!p->rigth)
            {
                p > right = curr;
                curr = curr->left;
            }
            else
            {
                i++;
                if (i == odd1)
                    odd1Val = curr->data;
                if (i == even1)
                    even1Val = curr->data;
                if (i == even2)
                    even2Val = curr->data;
                p->rigth = nullptr;
                curr = curr->rigth;
            }
        }
    }
    float med = 0;
    if (n & 1)
    {
        med = odd1Val;
    }
    else
    {
        med = (even1Val + even2Val) / 2.0;
    }
    return med;
}
int main()
{
    system("cls");
    Node *root = null;
    int n = morrisTraversal(root);
    fidMed(root, n);
    return 0;
}