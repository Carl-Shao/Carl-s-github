#include <iostream>
#include <string>
#include <limits>

using namespace std;

// Node class
class Node {
public:
    int task_id; // unique integer representing the task
    string task_name; // name or description of the task
    string assigned_to; // employee name
    Node * next; // pointer to the next node

    // construct function
    Node(int task_id, string task_name, string assigned_to) {
        this->task_id = task_id;
        this->task_name = task_name;
        this->assigned_to = assigned_to;
        this->next = nullptr;
    }
};

// print current Node (shared by Stack and Queue)
void printTask(Node * current) {
    cout << "Task ID: " << current->task_id;
    cout << " | Name: " << current->task_name;
    cout << " | Assigned to: " << current->assigned_to << "\n";
}

// Stack class (active tasks, LIFO)
class Stack {
private:
    Node * top;

public:
    // construct function
    Stack() {
        top = nullptr;
    }

    // Add a new task to the top of the stack.
    void add (int task_id, string task_name, string assigned_to) {
        Node * node = new Node(task_id, task_name, assigned_to);
        pushNode(node);
        cout << "Task has added.\n";
    }

    // Push an existing node onto the top of the stack (used when moving from Queue).
    void pushNode(Node * node) {
        if (node == nullptr) return;
        node->next = top;
        top = node;
    }

    // Detach and return the top node WITHOUT deleting it (ownership is transferred).
    Node * detachTop() {
        if (isEmpty()) return nullptr;
        Node * temp = top;
        top = top->next;
        temp->next = nullptr;
        return temp;
    }

    // Mark the most recent task as completed and remove it from the stack.
    void pop() {
        if (isEmpty()) {
            cout << "\nThe stack is empty. No task to complete.\n";
            return;
        }
        Node * temp = detachTop();
        cout << "Completed Task:\n";
        printTask(temp);
        delete temp;
    }

    // View the latest task without removing it.
    void peek() {
        if (isEmpty()) {
            cout << "\nThe stack is empty. No task to view.\n";
            return;
        }
        cout << "The Latest Task:\n";
        printTask(top);
    }

    // Show all tasks in the stack (from most recent to oldest).
    void display() {
        if (isEmpty()) {
            cout << "\nThe stack is empty. No task to display.\n";
            return;
        }

        cout << "\n-------- Show All Active Tasks --------\n";
        Node * current = top;
        while(current != nullptr) {
            printTask(current);
            current = current->next;
        }
        cout << "\n---------------------------------------\n";
    }

    // Check if there are any tasks in the stack.
    bool isEmpty() {
        return top == nullptr;
    }

    // Destructor to free memory
    ~Stack() {
        while(!isEmpty()) {
            Node * temp = top;
            top = top->next;
            delete temp;
        }
    }
};

// Queue class (pending tasks, FIFO)
class Queue {
private:
    Node * front;
    Node * rear;

public:
    // construct function
    Queue() {
        front = nullptr;
        rear = nullptr;
    }

    // Add a deferred task to the end of the queue.
    void enqueue(int task_id, string task_name, string assigned_to) {
        enqueue(new Node(task_id, task_name, assigned_to));
    }

    // Enqueue an existing node (ownership is transferred).
    void enqueue(Node * node) {
        if (node == nullptr) return;
        node->next = nullptr;
        if (rear == nullptr) {
            front = rear = node;
        } else {
            rear->next = node;
            rear = node;
        }
    }

    // Detach and return the first node WITHOUT deleting it (ownership is transferred).
    Node * dequeueNode() {
        if (isEmpty()) return nullptr;
        Node * temp = front;
        front = front->next;
        if (front == nullptr) rear = nullptr;
        temp->next = nullptr;
        return temp;
    }

    // Remove the first task from the queue for processing.
    void dequeue() {
        if (isEmpty()) {
            cout << "\nThe pending queue is empty. No task to process.\n";
            return;
        }
        Node * temp = dequeueNode();
        cout << "Processed Task:\n";
        printTask(temp);
        delete temp;
    }

    // View the next pending task without removing it.
    void peek() {
        if (isEmpty()) {
            cout << "\nThe pending queue is empty. No task to view.\n";
            return;
        }
        cout << "The Next Pending Task:\n";
        printTask(front);
    }

    // Show all pending tasks (FIFO order: first in -> first shown).
    void display() {
        if (isEmpty()) {
            cout << "\nThe pending queue is empty. No task to display.\n";
            return;
        }

        cout << "\n-------- Show All Pending Tasks --------\n";
        Node * current = front;
        while(current != nullptr) {
            printTask(current);
            current = current->next;
        }
        cout << "\n----------------------------------------\n";
    }

    // Check if there are any pending tasks.
    bool isEmpty() {
        return front == nullptr;
    }

    // Destructor to free memory
    ~Queue() {
        while(!isEmpty()) {
            Node * temp = front;
            front = front->next;
            delete temp;
        }
        rear = nullptr;
    }
};

int main()
{
    Stack stack;
    Queue queue;
    int choice;

    do {
        cout << "============ Employee Task Management System (Part 2) ============\n";
        cout << "1. Add Task\n";
        cout << "2. Complete Last Task\n";
        cout << "3. Defer Task (Move to Pending)\n";
        cout << "4. Process Pending Task\n";
        cout << "5. Display All Active Tasks\n";
        cout << "6. Display Pending Tasks\n";
        cout << "7. Exit\n";
        cout << "Enter Choice: ";

        if (!(cin >> choice)) {
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cout << "Invalid input. Please enter a number.\n\n";
            continue;
        }
        cin.ignore(numeric_limits<streamsize>::max(), '\n');

        switch (choice) {
            case 1: {
                int id;
                string name, employee;
                cout << "\nEnter the task ID: ";
                if (!(cin >> id)) {
                    cin.clear();
                    cin.ignore(numeric_limits<streamsize>::max(), '\n');
                    cout << "Invalid task ID.\n";
                    break;
                }
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
                cout << "Enter the name/description: ";
                getline(cin, name);
                cout << "Enter employee name: ";
                getline(cin, employee);
                stack.add(id, name, employee);
                break;
            }
            case 2: {
                // Complete the most recent task; optionally defer it to the queue.
                Node * task = stack.detachTop();
                if (task == nullptr) {
                    cout << "\nThe stack is empty. No task to complete.\n";
                    break;
                }
                cout << "\nCompleted Task:\n";
                printTask(task);

                char answer;
                cout << "Do you want to defer this task to the pending queue? (y/n): ";
                cin >> answer;
                cin.ignore(numeric_limits<streamsize>::max(), '\n');

                if (answer == 'y' || answer == 'Y') {
                    queue.enqueue(task);
                    cout << "Task deferred to pending queue.\n";
                } else {
                    cout << "Task completed and removed from the system.\n";
                    delete task;
                }
                break;
            }
            case 3: {
                // Defer the most recent active task by moving it to the pending queue.
                Node * task = stack.detachTop();
                if (task == nullptr) {
                    cout << "\nThe stack is empty. No task to defer.\n";
                    break;
                }
                queue.enqueue(task);
                cout << "\nTask deferred to pending queue:\n";
                printTask(task);
                break;
            }
            case 4: {
                // Process the first pending task and push it back into the stack.
                Node * task = queue.dequeueNode();
                if (task == nullptr) {
                    cout << "\nThe pending queue is empty. No task to process.\n";
                    break;
                }
                stack.pushNode(task);
                cout << "\nTask reassigned to active stack:\n";
                printTask(task);
                break;
            }
            case 5:
                stack.display();
                break;
            case 6:
                queue.display();
                break;
            case 7:
                cout << "Bye.\n";
                break;
            default:
                cout << "Invalid Choice. Please enter again.\n";
        }
        cout << "\n";
    } while(choice != 7);

    cin.get();
    cin.ignore();
    return 0;
}
