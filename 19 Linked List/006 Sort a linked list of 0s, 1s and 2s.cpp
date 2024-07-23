#include <iostream>
#include <cstdlib>
#include <unordered_map>
using namespace std;
class ListNode
{
public:
    int val;
    ListNode *next;

    ListNode(int value)
    {
        this->val = value;
        this->next = NULL;
    }
};
void insertAtHead(int value, ListNode *&head, ListNode *&tail)
{
    if (head == NULL && tail == NULL)
    {
        ListNode *newNode = new ListNode(value);
        head = newNode;
        tail = newNode;
    }
    else
    {
        ListNode *newNode = new ListNode(value);
        newNode->next = head;
        head = newNode;
    }
}
void insertAtHead2(ListNode *temp, ListNode *&head, ListNode *&tail)
{
    temp->next = NULL;
    if (head == NULL && tail == NULL)
    {
        head = temp;
        tail = temp;
    }
    else
    {
        temp->next = head;
        head = temp;
    }
}
void print(ListNode *head)
{
    ListNode *currentNode = head;
    while (currentNode != NULL)
    {
        cout << currentNode->val << "->";
        currentNode = currentNode->next;
    }
    cout << "NULL" << endl;
}

ListNode *sort(ListNode *head)
{
    if (head == NULL || head->next == NULL)
    {
        return head;
    }
    ListNode *onesHead = NULL;
    ListNode *onesTail = NULL;
    ListNode *twosHead = NULL;
    ListNode *twosTail = NULL;
    ListNode *threesHead = NULL;
    ListNode *threesTail = NULL;
    ListNode *temp = head;
    while (temp != NULL)
    {
        ListNode *next = temp->next;
        switch (temp->val)
        {
        case 1:

            insertAtHead2(temp, onesHead, onesTail);
            break;
        case 2:
            insertAtHead2(temp, twosHead, twosTail);
            break;
        case 3:
            insertAtHead2(temp, threesHead, threesTail);
            break;

        default:
            break;
        }
        temp = next;
    }

    if (onesHead != NULL)
    {
        if (twosHead != NULL)
        {
            onesTail->next = twosHead;
            if (threesHead != NULL)
            {
                twosTail->next = threesHead;
            }
            else
            {

                onesTail->next = twosHead;
            }
        }
        else
        {
            onesTail->next = threesHead;
        }
        return onesHead;
    }
    else if (twosHead != NULL)
    {
        twosTail->next = threesHead;
        return twosHead;
    }
    else
    {
        return threesHead;
    }
    return NULL;
}
int main()
{
    system("cls");
    ListNode *head = NULL;
    ListNode *tail = NULL;
    insertAtHead(1, head, tail);
    insertAtHead(1, head, tail);
    // insertAtHead(2, head, tail);
    // insertAtHead(2, head, tail);
    insertAtHead(3, head, tail);
    insertAtHead(3, head, tail);

    print(head);
    head = sort(head);

    print(head);

    return 0;
}