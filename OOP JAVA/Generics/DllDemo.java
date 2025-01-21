import java.util.Scanner;

class Node<T> {
    T data;
    Node<T> next;
    Node<T> prev;

    Node(T data) {
        this.data = data;
        next = null;
        prev = null;
    }

    void display() {
        System.out.print(data + " ");
    }
}

class DoublyLinkedList<T> {
    Node<T> head;

    DoublyLinkedList() {
        head = null;
    }

    void insertAtEnd(T data) {
        Node<T> newNode = new Node<>(data);
        if (head == null) {
            head = newNode;
            return;
        }
        Node<T> temp = head;
        while (temp.next != null) {
            temp = temp.next;
        }
        temp.next = newNode;
        newNode.prev = temp;
    }

    void insertAtFront(T data) {
        Node<T> newNode = new Node<>(data);
        if (head == null) {
            head = newNode;
            return;
        }
        newNode.next = head;
        head.prev = newNode;
        head = newNode;
    }

    T deleteFromFront() {
        if (head == null) {
            System.out.println("The list is empty. Nothing to delete.");
            return null;
        }
        Node<T> deleted = head;
        head = head.next;
        if (head != null) {
            head.prev = null;
        }
        return deleted.data;
    }

    void display() {
        if (head == null) {
            System.out.println("The list is empty.");
            return;
        }
        Node<T> temp = head;
        while (temp != null) {
            temp.display();
            System.out.print("->");
            temp = temp.next;
        }
        System.out.print("null\n");
    }
}

public class DllDemo {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        DoublyLinkedList<Integer> dll = new DoublyLinkedList<>();

        while (true) {
            System.out.println("\nDoubly Linked List Operations:");
            System.out.println("1. Insert at End");
            System.out.println("2. Insert at Front");
            System.out.println("3. Delete from Front");
            System.out.println("4. Display List");
            System.out.println("5. Exit");
            System.out.print("Enter your choice: ");
            int choice = scanner.nextInt();

            switch (choice) {
                case 1:
                    System.out.print("Enter the integer to insert at the end: ");
                    int dataEnd = scanner.nextInt();
                    dll.insertAtEnd(dataEnd);
                    System.out.println("Inserted " + dataEnd + " at the end.");
                    break;

                case 2:
                    System.out.print("Enter the integer to insert at the front: ");
                    int dataFront = scanner.nextInt();
                    dll.insertAtFront(dataFront);
                    System.out.println("Inserted " + dataFront + " at the front.");
                    break;

                case 3:
                    Integer deletedData = dll.deleteFromFront();
                    if (deletedData != null) {
                        System.out.println("Deleted " + deletedData + " from the front.");
                    }
                    break;

                case 4:
                    System.out.println("Displaying the doubly linked list:");
                    dll.display();
                    break;

                case 5:
                    System.out.println("Exiting program.");
                    scanner.close();
                    return;

                default:
                    System.out.println("Invalid choice. Please try again.");
            }
        }
    }
}
