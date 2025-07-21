def show_menu():
    print("\nTo-Do List Menu:" )
    print("1. View Tasks")
    print("2. Add Task")
    print("3. Remove Task")
    print("4. Exit")

def view_tasks(tasks):
    if not tasks:
        print("No tasks available.")
    else:
        print("\nCurrent Tasks:")
        for index, task in enumerate(tasks, start=1):
            print(f"{index}. {task}")

def add_task(tasks):
    task = input("Enter the task to add: ")
    tasks.append(task)
    print("Task added. ")

def remove_task(tasks):
    view_tasks(tasks)
    try:
        task_num= int(input("Enter the task number to remove: "))
        if 1 <= task_num <= len(tasks):
            removed_task = tasks.pop(task_num - 1)
            print(f"Removed task: {removed_task}")
        else:
            print("Invalid task number.")
    except ValueError:
        print("Please enter a valid number.")

def main():
    tasks = []
    while True:
        show_menu()
        choice = input("Choose an option (1-4): ")
        if choice == '1':
            view_tasks(tasks)
        elif choice == '2':
            add_task(tasks)
        elif choice == '3':
            remove_task(tasks)
        elif choice == '4':
            print("Exiting the To-Do List application. Goodbye!")
            break
        else:
            print("Invalid choice. Please try again.")

if __name__ == "__main__":
    main()          
