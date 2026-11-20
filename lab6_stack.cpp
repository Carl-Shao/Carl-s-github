#include <iostream>
#include <iomanip>

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

// Stack class
class Stack {
private:
    Node * top;

public:
    // construct function
    Stack() {
        top = nullptr;
    }

    // TODO 1: Add a new task to the top of the stack.
    void add (int task_id, string task_name, string assigned_to) {
        Node * node = new Node(task_id, task_name, assigned_to);
        node->next = top;
        top = node;
        cout << "Task has added.\n";
    }

    // TODO 2: Mark the most recent task as completed and remove it from the stack.
    void pop() {
        if (isEmpty()) {
            cout << "\nThe stack is empty. No task to complete.\n";
            return;
        }
        Node * temp = top;
        cout << "Completed Task:\n";
        printNode(temp);
        top = top->next;
        delete temp; 
    }

    // TODO 3: View the latest task without removing it.
    void peek() {
        if (isEmpty()) {
            cout << "\nThe stack is empty. No task to view.\n";
            return;
        }
        cout << "The Latest Task:\n";
        printNode(top);
    }

    // TODO 4: Show all tasks in the stack (from most recent to oldest).
    void display() {
        if (isEmpty()) {
            cout << "\nThe stack is empty. No task to display.\n";
            return;
        }

        cout << "\n-------- Show All Task --------\n";
        Node * current = top;
        while(current != nullptr) {
            printNode(current);
            current = current->next;
        }
        cout << "\n-------------------------------\n";
    }

    // TODO 5: Check if there are any tasks in the stack.
    bool isEmpty() {
        return top == nullptr;
    }

    // print current Node
    void printNode(Node * current) {
        cout << "Task ID: " << current->task_id;
        cout << " | Name: " << current->task_name;
        cout << " | Assigned to: " << current->assigned_to << "\n";
    }

    // Detruct to free memory
    ~Stack() {
        while(!isEmpty()) {
            Node * temp = top;
            top = top->next;
            delete temp;
        }
    }
};

int
main()
{
    Stack stack;
    short choice;
    do {
        cout << "============ Employee Task Management System (Part 1) ============\n";
        cout << "1. Add Task\n";
        cout << "2. Complete Last Task\n";
        cout << "3. Display All Tasks\n";
        cout << "4. Exit\n";
        cout << "Enter Choice: ";
        cin >> choice;
        cin.ignore();

        switch (choice) {
            case 1: {
                int id;
                string name, employee;
                cout << "\nEnter the task ID:";
                cin >> id;
                cin.ignore();
                cout << "Enter the name/description:";
                getline(std::cin, name);
                cout << "Enter employee name:";
                getline(std::cin, employee);
                stack.add(id, name, employee); 
                break;
            }
            case 2:
                stack.pop();
                break;
            case 3:
                stack.display();
                break;
            case 4:
                cout << "Bye.";
                break;
            default:
                cout << "Invalid Choice. Please enter again.\n"; 
        }
    } while(choice != 4);

    cin.get();
    cin.ignore();
    return 0;
}