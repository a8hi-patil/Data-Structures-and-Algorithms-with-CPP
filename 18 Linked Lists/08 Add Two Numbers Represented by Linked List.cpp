#include <iostream>
#include <cstdlib>
using namespace std;

class ListNode
{
public:
    int val;
    ListNode *next;

    ListNode(int data)
    {
        this->val = data;
        this->next = NULL;
    }
};

ListNode *insertAtTail(int val, ListNode *&head, ListNode *&tail)
{
    ListNode *newNode = new ListNode(val);
    if (head == NULL && tail == NULL)
    {
        head = newNode;
        tail = newNode;
    }
    else
    {
        tail->next = newNode;
        tail = newNode;
    }
    return head;
}
void print(ListNode *head)
{
    ListNode *temp = head;
    while (temp)
    {
        cout << temp->val << "->";
        temp = temp->next;
    }
    cout << "NULL" << endl;
}
ListNode *add(ListNode *l1, ListNode *l2)
{

    ListNode *head = NULL;
    ListNode *tail = NULL;
    int carry = 0;
    while (l1 || l2)
    {

        int digi1 = l1 ? l1->val : 0;
        int digi2 = l2 ? l2->val : 0;
        int sum = digi1 + digi2 + carry;
        int ansDigit = sum % 10;
        carry = sum / 10;
        head = insertAtTail(ansDigit, head, tail);

        l1 = l1 ? l1->next : NULL;
        l2 = l2 ? l2->next : NULL;
    }
    if (carry)
    {
        head = insertAtTail(carry, head, tail);
    }
    return head;
}
int main()
{
    system("cls");
    ListNode *headl1 = NULL;
    ListNode *headl2 = NULL;
    ListNode *taill1 = NULL;
    ListNode *taill2 = NULL;
    headl1 = insertAtTail(9, headl1, taill1);
    headl1 = insertAtTail(9, headl1, taill1);
    headl1 = insertAtTail(9, headl1, taill1);
    headl1 = insertAtTail(9, headl1, taill1);
    headl1 = insertAtTail(9, headl1, taill1);
    headl1 = insertAtTail(9, headl1, taill1);
    headl1 = insertAtTail(9, headl1, taill1);
    headl2 = insertAtTail(9, headl2, taill2);
    headl2 = insertAtTail(9, headl2, taill2);
    headl2 = insertAtTail(9, headl2, taill2);
    headl2 = insertAtTail(9, headl2, taill2);
    headl2 = insertAtTail(9, headl2, taill2);
    // print();
    print(add(headl1, headl2));
    return 0;
}