MAXSIZE = 10

Queue = []
front = 0
rear = -1

def insert():
    global rear
    if rear == MAXSIZE - 1:
        print("\nQueue Overflow")
    else:
        n = int(input("Enter an element: "))
        rear += 1
        Queue.append(n)

def delete():
    global front
    if front > rear:
        print("\nQueue Underflow")  # Check if the queue is empty (underflow condition)
    else:
        print(f"\nDeleted element: {Queue[front]}")  # Remove and return the front element
        front += 1  # Increment the front index

def display():
    if front > rear:
        print("\nQueue is empty")
    else:
        print("\nQueue elements: ", end="")
        for i in range(front, rear + 1):
            print(Queue[i], end=" ")
        print()

def main():
    choice = 0
    while choice != 4:
        print("\n1. Insert\n2. Delete\n3. Display\n4. Exit")
        choice = int(input("Enter your choice: "))

        if choice == 1:
            insert()
        elif choice == 2:
            delete()
        elif choice == 3:
            display()
        elif choice == 4:
            print("Exiting...")
        else:
            print("Invalid choice, please try again.")

if __name__ == "__main__":
    main()
