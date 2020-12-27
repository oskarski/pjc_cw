#include <iostream>
#include <string>

template<typename T>
struct Node {
    T data;
    Node<T> *next;
};

template<typename T>
Node<T> *arrayToList(const T tab[], size_t size);

template<typename T>
void showList(const Node<T> *head);

template<typename T, typename Pred>
Node<T> *extract(Node<T> *&head, Pred pred);

template<typename T>
void deleteList(Node<T> *&head);

bool isLong(const std::string &s) { return s.size() >= 5; }

int exercise_4() {
    int tabi[] = {2, 1, 4, 3, 6, 5, 7, 8};
    size_t sizei = sizeof(tabi) / sizeof(tabi[0]);
    Node<int> *listAi = arrayToList(tabi, sizei);
    showList(listAi);
    Node<int> *listBi = extract(listAi,
                                [](int n) {
                                    return n % 2 == 0;
                                });
    showList(listBi);
    showList(listAi);
    deleteList(listBi);
    deleteList(listAi);
    std::string tabs[]{"Kasia", "Ola", "Ala",
                       "Zosia", "Ela", "Basia"};
    size_t sizes = sizeof(tabs) / sizeof(tabs[0]);
    Node<std::string> *listAs = arrayToList(tabs, sizes);
    showList(listAs);
    Node<std::string> *listBs = extract(listAs, isLong);
    showList(listBs);
    showList(listAs);
    deleteList(listBs);
    deleteList(listAs);

    return 0;
}

template<typename T>
Node<T> *arrayToList(const T tab[], size_t size) {
    Node<T> *head = nullptr;
    Node<T> *current_node = head;

    for (int i = 0; i < size; i++) {
        if (current_node == nullptr) {
            current_node = new Node<T>{tab[i], nullptr};
            head = current_node;
        } else {
            current_node->next = new Node<T>{tab[i], nullptr};
            current_node = current_node->next;
        }
    }

    return head;
}

template<typename T>
void showList(const Node<T> *head) {
    const Node<T> *current_node = head;

    while (current_node != nullptr) {
        cout << current_node->data << " ";
        current_node = current_node->next;
    }

    cout << endl;
}

template<typename T, typename Pred>
Node<T> *extract(Node<T> *&head, Pred pred) {
    Node<T> *truthy_nodes_head = nullptr;
    Node<T> *current_truthy_node = truthy_nodes_head;
    Node<T> *falsy_nodes_head = nullptr;
    Node<T> *current_falsy_node = truthy_nodes_head;

    Node<T> *current_node = head;

    while (current_node != nullptr) {
        Node<T> *next_node = current_node->next;

        if (pred(current_node->data)) {
            if (current_truthy_node == nullptr) {
                current_truthy_node = current_node;
                truthy_nodes_head = current_truthy_node;
                current_truthy_node->next = nullptr;
            } else {
                current_truthy_node->next = current_node;
                current_truthy_node->next->next = nullptr;
                current_truthy_node = current_truthy_node->next;
            }
        } else {
            if (current_falsy_node == nullptr) {
                current_falsy_node = current_node;
                falsy_nodes_head = current_falsy_node;
                current_falsy_node->next = nullptr;
            } else {
                current_falsy_node->next = current_node;
                current_falsy_node->next->next = nullptr;
                current_falsy_node = current_falsy_node->next;
            }
        }

        current_node = next_node;
    }

    head = falsy_nodes_head;

    return truthy_nodes_head;
}

template<typename T>
void deleteList(Node<T> *&head) {
    while (head != nullptr) {
        cout << "DEL: " << head->data << "; ";

        head = head->next;
    }

    cout << endl;
}