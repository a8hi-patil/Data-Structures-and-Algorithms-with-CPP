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
void insertAtTail(int value, ListNode *&head, ListNode *&tail)
{
    if (tail == NULL)
    {
        ListNode *newNode = new ListNode(value);
        head = newNode;
        tail = newNode;
    }
    else
    {
        ListNode *newNode = new ListNode(value);
        tail->next = newNode;
        tail = newNode;
    }
}
ListNode *addTwoNumbers(ListNode *firstList, ListNode *SecondList)
{
    ListNode *i = firstList;
    ListNode *j = SecondList;
    ListNode *newHead = NULL;
    ListNode *newTail = NULL;
    int carry = 0;
    while (!(i == NULL && j == NULL))
    {

        int firstData = i == NULL ? 0 : i->val;
        int secondData = j == NULL ? 0 : j->val;
        int sum = firstData + secondData + carry;
        int digit = sum % 10;
        carry = sum / 10;
        insertAtTail(digit, newHead, newTail);
        i = i == NULL ? NULL : i->next;
        j = j == NULL ? NULL : j->next;
    }
    if (carry)
    {
        insertAtTail(carry, newHead, newTail);
    }
    return newHead;
}

void solve(ListNode *l1, ListNode *l2, int &carry, ListNode *&ans)
{
    if (l1 == NULL && l2 == NULL)
    {
        if (carry)
        {
            ans->next = new ListNode(carry);
            // cout<<it->val<<endl;
        }
        return;
    }
    int sum = (l1 ? l1->val : 0) + (l2 ? l2->val : 0) + carry;
    int digit = sum % 10;
    carry = sum / 10;
    ans->next = new ListNode(digit);
    solve(l1 ? l1->next : NULL, l2 ? l2->next : NULL, carry, ans->next);
}
ListNode *addTwoNumbersRec(ListNode *l1, ListNode *l2)
{

    ListNode *ans = new ListNode(-1);
    ListNode *it = ans;
    int carry = 0;
    solve(l1, l2, carry, it);

    return ans->next;
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
    insertAtHead(9, head, tail);
    insertAtHead(9, head, tail);
    insertAtHead(9, head, tail);
    print(head);
    ListNode *head1 = NULL;
    ListNode *tail1 = NULL;
    insertAtHead(9, head1, tail1);
    insertAtHead(9, head1, tail1);
    insertAtHead(9, head1, tail1);
    insertAtHead(9, head1, tail1);
    // insertAtHead(5, head1, tail1);
    print(head1);
    ListNode *newHead = addTwoNumbersRec(head, head1);
    print(newHead);

    return 0;
}