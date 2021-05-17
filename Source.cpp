#include <iostream>

using namespace std;

template<class T>
struct Node {
    T data;
    Node<T>* next;
};

template<class T>
class List {
private:
    Node<T>* first;
    int size;
public:

    List()
    {
        first = nullptr;
        size = 0;
    }

    ~List() {
        Node<T>* current = first;
        while (size != 0)
        {
            Node<T>* next = current->next;
            delete current;
            current = next;
            size--;
        }
        cout << "Deleted" << endl;
    }

    void add(int pos, T d) {
        // pos validation
        if (pos < 0 || pos > size)
            return;

        // create and init new node
        Node<T>* newNode = new Node<T>;
        newNode->data = d;
        newNode->next = nullptr;

        // increase size
        size++;

        // if it first element, so do it:
        if (size == 1) {
            first = newNode;
            newNode->next = first;
            return;
        }

        // previous for element, that we will insert
        int prev = pos - 1;
        // store first
        Node<T>* curr = first;
        // if we insert first element, update first and prev for first was old size(size - 1) - 1 == size - 2
        if (pos == 0) {
            first = newNode;
            prev = size - 2;
        }

        for (int i = 0; i < prev; i++)
            curr = curr->next;

        // update list pointers
        newNode->next = curr->next;
        curr->next = newNode;
    }

    void del(int pos) {
        if (pos < 0 || pos >= size) {
            return;
        }
        size--;

        if (size == 0) {
            delete first;
            first = nullptr;
            return;
        }

        int prev = pos - 1;
        Node<T>* curr = first;
        if (pos == 0) {
            prev = size;
            first = first->next;
        }
        for (int i = 0; i < prev; i++)
        {
            curr = curr->next;
        }
        Node<T>* tmp = curr->next->next;
        delete curr->next;
        curr->next = tmp;
    }

    int get_size()
    {
        return size;
    }

    void show(int count) {
        if (count < 0) {
            return;
        }
        Node<T>* node = first;
        for (int i = 0; i < count; i++) {
            cout << node->data << " ";
            node = node->next;
        }
        cout << endl;
    }
};


int main()
{
    List<double>* m = new List<double>();
    double a, b, c, d;
    cout << "Enter data" << endl;
    cin >> a >> b >> c >> d;
    m->add(m->get_size(), a);
    // a
    m->add(0, b);
    // b a
    m->add(m->get_size(), c);
    // b a c
    m->del(1);
    // b c
    m->add(1, d);
    // b d c
    cout << "Count of elements which were added to list:" << endl;
    cout << m->get_size() << endl;
    m->show(m->get_size());

    delete m;

    return 0;
}