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
ListNode *reverserList(ListNode *head)
{
    if (head == NULL || head->next == NULL)
    {
        return head;
    }
    ListNode *curr = head;
    ListNode *prev = NULL;
    while (curr)
    {

        ListNode *nextNode = curr->next;
        curr->next = prev;
        prev = curr;
        curr = nextNode;
    }
    return prev;
}

ListNode *addOne(ListNode *head)
{
    if (head == NULL)
    {
        return head;
    }
    int carry = 1;
    ListNode *temp = head;
    ListNode *prev = NULL;
    while (temp)
    {
        int sum = temp->val + carry;
        int digit = sum % 10;
        temp->val = digit;
        carry = sum / 10;
        prev = temp;
        temp = temp->next;
    }
    if (carry)
    {
        ListNode *carryNode = new ListNode(carry);
        prev->next = carryNode;
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
    head = reverserList(head);
    print(head);
    head = addOne(head);
    print(head);
    prevNode = NULL;
    head = reverserList(head);
    print(head);
    return 0;
}