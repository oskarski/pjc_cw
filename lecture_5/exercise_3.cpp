#include <iostream>

struct Node {
    int data;
    Node *next;
};

bool add(Node *&head, int data);

size_t size(const Node *head);

void clear(Node *&head);

void printList(Node *head);

int exercise_3() {
    int tab[] = {1, 4, 1, 3, 5};
    Node *head = 0;

    for (size_t i = 0, e = std::size(tab); i != e; ++i) {
        bool b = add(head, tab[i]);

        int k = 0;

        cout << tab[i] << (b ? " " : " NOT ")
             << "added" << endl;
    }

    cout << "Size of the list: " << size(head) << endl;
    printList(head);
    clear(head);

    return 0;
}

bool add(Node *&head, int data) {
    if (head == nullptr) {
        head = new Node{data, nullptr};

        return true;
    }

    Node *next_node = head;

    while (next_node != nullptr) {
        if (next_node->data == data) return false;

        next_node = next_node->next;
    }

    head = new Node{data, head};

    return true;
}

size_t size(const Node *head) {
    const Node *next_node = head;
    int size = 0;

    while (next_node != nullptr) {
        size++;
        next_node = next_node->next;
    }

    return size;
}

void printList(Node *head) {
    Node *next_node = head;

    while (next_node != nullptr) {
        cout << next_node->data << " ";
        next_node = next_node->next;
    }
}

void clear(Node *&head) {
    while (head != nullptr) {
        cout << "DEL: " << head->data << " ";
        head = head->next;
    }
}