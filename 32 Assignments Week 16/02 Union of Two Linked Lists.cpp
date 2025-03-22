class Solution
{
public:
    void addToMap(Node *root, map<int, Node *> &Omap)
    {
        Node *temp = root;
        while (temp)
        {
            Omap[temp->data] = temp;
            temp = temp->next;
        }
    }
    void createList(Node *&head, Node *&tail, map<int, Node *> &Omap)
    {
        for (auto el : Omap)
        {
            Node *newNode = new Node(el.first);

            if (!head && !tail)
            {
                head = el.second;
                tail = el.second;
            }
            else
            {
                tail->next = el.second;
                tail = el.second;
            }
        }

        tail->next = NULL;
    }
    struct Node *makeUnion(struct Node *head1, struct Node *head2)
    {
        // code here
        map<int, Node *> Omap;
        addToMap(head1, Omap);
        addToMap(head2, Omap);
        Node *root = nullptr;
        Node *tail = nullptr;
        createList(root, tail, Omap);
        return root;
    }
};