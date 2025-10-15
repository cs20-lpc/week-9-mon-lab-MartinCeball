#include <iostream>
#include <string>
#include <cassert>
#include "LinkedQueue.hpp"

using namespace std;

template <typename T>
void printQueueStatus(const LinkedQueue<T>& q, const string& name) {
    cout << "--- Status of Queue '" << name << "' ---" << endl;
    if (q.isEmpty()) {
        cout << "  State: Empty" << endl;
        cout << "  Length: " << q.getLength() << endl;
        assert(q.getLength() == 0);
    } else {
        cout << "  State: Not Empty" << endl;
        cout << "  Length: " << q.getLength() << endl;
        cout << "  Front: " << q.front() << endl;
        cout << "  Back: " << q.back() << endl;
    }
    cout << "---------------------------------" << endl << endl;
}

int main() {
    cout << "Starting LinkedQueue Driver Program..." << endl;
    cout << "=======================================" << endl << endl;

    cout << ">>>> SECTION 1: Basic Operations with Integers <<<<" << endl;
    LinkedQueue<int> iq;

    printQueueStatus(iq, "iq (initial)");

    cout << "Enqueuing 10, 20, 30..." << endl;
    iq.enqueue(10);
    iq.enqueue(20);
    iq.enqueue(30);
    printQueueStatus(iq, "iq (after 3 enqueues)");
    assert(iq.getLength() == 3);
    assert(iq.front() == 10);
    assert(iq.back() == 30);

    cout << "Dequeuing one element..." << endl;
    iq.dequeue();
    printQueueStatus(iq, "iq (after 1 dequeue)");
    assert(iq.getLength() == 2);
    assert(iq.front() == 20);

    cout << "Clearing the queue..." << endl;
    iq.clear();
    printQueueStatus(iq, "iq (after clear)");
    assert(iq.isEmpty());

    cout << ">>>> SECTION 2: Copy Constructor and Assignment Operator <<<<" << endl;
    iq.enqueue(100);
    iq.enqueue(200);
    cout << "Repopulated 'iq' for copy tests." << endl;
    printQueueStatus(iq, "iq");

    cout << "Creating 'iq_copy' from 'iq' via copy constructor..." << endl;
    LinkedQueue<int> iq_copy = iq;
    printQueueStatus(iq_copy, "iq_copy");
    
    cout << "Modifying original 'iq' by dequeuing..." << endl;
    iq.dequeue();
    printQueueStatus(iq, "iq (modified)");
    printQueueStatus(iq_copy, "iq_copy (should be unchanged)");
    assert(iq_copy.getLength() == 2 && iq_copy.front() == 100);

    LinkedQueue<int> iq_assign;
    iq_assign.enqueue(999);
    cout << "Created 'iq_assign' with its own data." << endl;
    printQueueStatus(iq_assign, "iq_assign (before)");
    
    cout << "Assigning 'iq_copy' to 'iq_assign'..." << endl;
    iq_assign = iq_copy;
    printQueueStatus(iq_assign, "iq_assign (after)");
    assert(iq_assign.getLength() == 2 && iq_assign.front() == 100);

    cout << ">>>> SECTION 3: Testing with std::string <<<<" << endl;
    LinkedQueue<string> sq;
    sq.enqueue("Apple");
    sq.enqueue("Banana");
    sq.enqueue("Cherry");
    printQueueStatus(sq, "string_queue");

    cout << "Processing all elements in string_queue until empty:" << endl;
    while (!sq.isEmpty()) {
        cout << "  Processing and dequeuing: " << sq.front() << endl;
        sq.dequeue();
    }
    cout << endl;
    printQueueStatus(sq, "string_queue (after processing)");

    cout << ">>>> SECTION 4: Testing Exception Handling <<<<" << endl;
    LinkedQueue<int> empty_q;
    try {
        cout << "Attempting to call front() on an empty queue..." << endl;
        empty_q.front();
    } catch (const runtime_error& e) {
        cout << "  SUCCESS: Caught expected exception -> " << e.what() << endl;
    }
    try {
        cout << "Attempting to call back() on an empty queue..." << endl;
        empty_q.back();
    } catch (const runtime_error& e) {
        cout << "  SUCCESS: Caught expected exception -> " << e.what() << endl;
    }
    cout << "Attempting to dequeue() from an empty queue (should not throw)..." << endl;
    empty_q.dequeue();
    cout << "  SUCCESS: dequeue() on empty queue completed without error." << endl;

    cout << endl;
    cout << "=======================================" << endl;
    cout << "Driver Program Finished. All tests passed." << endl;

    return 0;
}
