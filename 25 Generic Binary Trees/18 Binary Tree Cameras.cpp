#include <iostream>
#include <cstdlib>
using namespace std;

int solve(TreeNode *root, int &cams)
{
    if (!root)
        return 1;
    int left = solve(root->left, cams);
    int right = solve(root->right, cams);
    if (left == 0 || right == 0)
    {
        cams++;
        return true;
    }
    if (left == 2 || right == 2)
    {
        return 1;
    }
    return 0;
}

int minCameraCover(TreeNode *root)
{
    int cams = 0;
    int rootCam = solve(root, cams);
    if (rootCam == 0)
        cams++;
    return cams;
}

int main()
{
    system("cls");
    return 0;
}