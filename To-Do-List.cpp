#include<iostream>
#include<vector>
#include<string>
#include<algorithm>
using namespace std;

struct Task{
    string taskname;
    string dueDate; 
};

void addTask(vector<Task>& todoList){
    Task newtask;
    cout << "Enter task name: ";
    getline(cin >> ws, newtask.taskname);
    cout << "Enter task due (YYYY-MM-DD): ";
    getline(cin, newtask.dueDate);
    todoList.push_back(newtask);
    cout << "Task added successfully." << endl;
}
void removeTask(vector<Task>& todoList){
    if (todoList.empty())
    {
        cout << "No tasks to remove." << endl;
    }
    else
    {
        cout << "Enter task Number: ";
        int index;
        cin >> index;
        if (index < 0 || index >= todoList.size())
        {
            cout << "Invalid task number." << endl;
        }
        todoList.erase(todoList.begin() + index);
        cout << "Task removed successfully." << endl;
    }
}
void viewTask(const vector<Task>& todoList){
    if (todoList.empty())
    {
        cout << "No tasks to view." << endl;
    }
    else
    {
        cout << "Tasks: ";
        for (size_t i = 1; i < todoList.size(); i++)
        {
            cout << i << "." << todoList[i].taskname << " (Due: " << todoList[i].dueDate << ")" << endl;
        }
    }
    
}
int main()
{
    vector<Task> todolist;
    int choice;
    do {
        cout << "To-Do-List Program" << endl;
        cout << "   1.Add task" << endl;
        cout << "   2.Delete task" << endl;
        cout << "   3.View task" << endl;
        cout << "   4.Quit" << endl;
        cout << "Enter your choice: ";
        cin >> choice;
        cin.ignore();

        switch (choice)
        {
        case 1:
            addTask(todolist);
            break;
        case 2:
            removeTask(todolist);
            break;
        case 3:
            viewTask(todolist);
            break;
        case 4:
            cout << "Exiting......" << endl;
            break;
        default:
            cout << "Entered wrong choice, please try again" << endl;
        }

    }while(choice!=4);
    return 0;
}
