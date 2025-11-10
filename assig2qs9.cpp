#include <iostream>
#include <string>
using namespace std;

struct Patient {
    int id;
    string name;
    string condition;
    int priority;
};

class ERQueue {
private:
    Patient* arr;
    int capacity;
    int size;

public:
    ERQueue(int cap = 10) {
        capacity = cap;
        arr = new Patient[capacity];
        size = 0;
    }

    ~ERQueue() {
        delete[] arr;
    }

    bool isEmpty() {
        return size == 0;
    }

    bool isFull() {
        return size == capacity;
    }

    void enqueue(Patient p) {
        if (isFull()) {
            cout << "Queue is full!" << endl;
            return;
        }

        int i = size - 1;
        while (i >= 0 && arr[i].priority > p.priority) {
            arr[i + 1] = arr[i];
            i--;
        }
        arr[i + 1] = p;
        size++;
    }

    Patient dequeue() {
        if (isEmpty()) {
            cout << "Queue is empty!" << endl;
            return {0, "", "", 0};
        }
        Patient p = arr[0];
        for (int i = 0; i < size - 1; i++) {
            arr[i] = arr[i + 1];
        }
        size--;
        return p;
    }

    void display() {
        if (isEmpty()) {
            cout << "Queue is empty!" << endl;
            return;
        }
        cout << "Current Patients in Queue:\n";
        for (int i = 0; i < size; i++) {
            cout << "ID: " << arr[i].id
                 << ", Name: " << arr[i].name
                 << ", Condition: " << arr[i].condition
                 << ", Priority: " << arr[i].priority << endl;
        }
    }
};

int main() {
    ERQueue er;

    Patient p1 = {101, "Alice", "Minor Injury", 4};
    Patient p2 = {102, "Bob", "Heart Attack", 1};
    Patient p3 = {103, "Charlie", "Broken Arm", 3};
    Patient p4 = {104, "Diana", "Stroke", 2};

    er.enqueue(p1);
    er.enqueue(p2);
    er.enqueue(p3);
    er.enqueue(p4);

    er.display();

    cout << "\nTreating Patients:\n";
    while (!er.isEmpty()) {
        Patient treated = er.dequeue();
        cout << "Treating: " << treated.name
             << " Priority " << treated.priority << "" << endl;
    }

    return 0;
}
