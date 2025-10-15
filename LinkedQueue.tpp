#include <stdexcept> // For std::runtime_error


template <typename T>
LinkedQueue<T>::LinkedQueue() {
    this->head = nullptr;
    this->last = nullptr;
    this->length = 0; // Initialize length from base class
}


template <typename T>
T LinkedQueue<T>::back() const {
    if (isEmpty()) {
        throw std::runtime_error("back() called on an empty queue.");
    }
    return this->last->value;
}


template <typename T>
void LinkedQueue<T>::clear() {
    // Repeatedly remove the front element until the queue is empty
    while (!isEmpty()) {
        dequeue();
    }
}


template <typename T>
void LinkedQueue<T>::copy(const LinkedQueue<T>& copyObj) {

    this->head = nullptr;
    this->last = nullptr;
    this->length = 0;

    // Traverse the queue to be copied
    Node* current = copyObj.head;
    while (current != nullptr) {
      
        enqueue(current->value);
        current = current->next;
    }
}


template <typename T>
void LinkedQueue<T>::dequeue() {
    if (isEmpty()) {
        return; // Nothing to do
    }

    Node* temp = this->head; // Node to be deleted
    this->head = this->head->next; // Advance head

    // If the queue is now empty, the last pointer must also be null
    if (this->head == nullptr) {
        this->last = nullptr;
    }

    delete temp;
    this->length--; // Decrement the length
}


template <typename T>
void LinkedQueue<T>::enqueue(const T& elem) {
    Node* newNode = new Node(elem);

    if (isEmpty()) {
        // If empty, the new node is both the head and the last
        this->head = newNode;
        this->last = newNode;
    } else {
        // Otherwise, link the current last node to the new one
        this->last->next = newNode;
        // Update the last pointer to be the new node
        this->last = newNode;
    }

    this->length++; // Increment the length
}


template <typename T>
T LinkedQueue<T>::front() const {
    if (isEmpty()) {
        throw std::runtime_error("front() called on an empty queue.");
    }
    return this->head->value;
}
