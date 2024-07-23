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
ListNode *reverserList(ListNode *head, ListNode *&prevNode)
{
    if (head == NULL)
    {
        return prevNode;
    }

    ListNode *currNode = head;
    ListNode *nextNode = currNode->next;

    currNode->next = prevNode;
    prevNode = currNode;
    return reverserList(nextNode, prevNode);
}

ListNode *addOne(ListNode *head, ListNode *&tail)
{
    ListNode *temp = head;
    ListNode *tailNode = NULL;
    int carry = 1;
    while (temp != NULL)
    {
        // adding one in current node
        int tempSum = temp->val + carry;
        int digit = tempSum % 10;
        carry = tempSum / 10;
        temp->val = digit;
        tailNode = temp;
        temp = temp->next;
    }
    if (carry == 1)
    {
        // add new node
        ListNode *newNode = new ListNode(1);
        tailNode->next = newNode;
        tail = newNode;
    }
    return head;
}
int main()
{
    system("cls");
    ListNode *head = NULL;
    ListNode *tail = NULL;
    insertAtHead(9, head, tail);
    insertAtHead(9, head, tail);
    insertAtHead(9, head, tail);
    insertAtHead(9, head, tail);

    print(head);
    ListNode *prevNode = NULL;
    head = reverserList(head, prevNode);
    print(head);
    head = addOne(head, tail);
    print(head);
    prevNode = NULL;
    head = reverserList(head, prevNode);
    print(head);
    return 0;
}