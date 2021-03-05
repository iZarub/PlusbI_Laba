#include <iostream>
#include <string>
using namespace std;

struct Node {
    int value;
    Node* next;
};


void push_right(Node** head, int value)
{
    Node* a = (Node*)malloc(sizeof(Node));
    if (*head == NULL)
    {
        *head = a;
        a->next = NULL;
        a->value = value;
    }
    else
    {
        Node* i = *head;
        while (i->next != NULL)
        {
            i = i->next;
        }
        i->next = a;
        a->value = value;
        a->next = NULL;
    }
}

void push_mid(Node** head, int value, int length)
{
    if (length == 0 or length == 1)
    {
        push_right(head, value);
    }
    if (length % 2 == 0 && length > 1) {
        Node* a = (Node*)malloc(sizeof(Node));
        Node* i = *head;
        for (int j = 0; j < length / 2 - 1; j++)
        {
            i = i->next;
        }
        a->next = i->next;
        i->next = a;
        a->value = value;
    }
    if (length % 2 == 1 && length > 1)
    {
        Node* a = (Node*)malloc(sizeof(Node));
        Node* i = *head;
        for (int j = 0; j < length / 2; j++)
        {
            i = i->next;
        }
        a->next = i->next;
        i->next = a;
        a->value = value;
    }
}

int pop(Node** head)
{

    int a = (*head)->value;
    Node* i = (*head);
    (*head) = (*head)->next;
    free(i);
    return a;
}

void clear_list(Node** head)
{
    while ((*head)->next != NULL)
    {
        Node* i = *head;
        (*head) = (*head)->next;
        free(i);
    }
    free(*head);
    *head = NULL;
}


struct queue
{
private:
    Node* data;
    int size;

public:

    queue() {
        size = 0;
        data = NULL;
    }

    ~queue() {
        if (data != NULL)
        {
            clear_list(&data);
        }
    }

    void queue_push(int n) {
        push_right(&data, n);
        size++;
    }

    void queue_push_mid(int n) {
        push_mid(&data, n, size);
        size++;
    }

    int queue_pop() {
        if (data != NULL)
        {
            size--;
            return pop(&data);
        }
    }


};
int main()
{   queue stack;
    int N;
    
    cin >> N;
    for (int i = 0; i < N; i++)
    {
        char gob_stat;
        cin >> gob_stat;
        if (gob_stat == '+')
        {
            int gob_num;
            cin >> gob_num;
            stack.queue_push(gob_num);
        }
        else if (gob_stat == '*')
        {
            int gob_num;
            cin >> gob_num;
            stack.queue_push_mid(gob_num);
        }
        else if (gob_stat == '-')
        {
            cout << stack.queue_pop() << '\n';
        }
    }
}
