 // Generic Node class
class Node<T> {
    T data;
    Node<T> next;

    Node(T data) {
        this.data = data;
        this.next = null;
    }

    void display() {
        System.out.print(data + " ");
    }
}

// Generic LinkedList class
class LinkedList<T> {
    private Node<T> head;

    LinkedList() {
        head = null;
    }

    // Insert a new node at the end of the list
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
    }

    // Insert a new node at the beginning of the list
    void insertAtBeginning(T data) {
        Node<T> newNode = new Node<>(data);
        newNode.next = head;
        head = newNode;
    }

    // Delete the first node and return it
    Node<T> deleteFirst() {
        if (head == null) {
            return null;
        }
        Node<T> temp = head;
        head = head.next;
        return temp;
    }

    // Display the list
    void display() {
        if (head == null) {
            System.out.println("List is empty.");
            return;
        }
        Node<T> temp = head;
        while (temp != null) {
            temp.display();
            temp = temp.next;
        }
        System.out.println();
    }
}

// Testing the LinkedList
public class GenericLL {
    public static void main(String[] args) {
        // Integer Linked List
        LinkedList<Integer> intList = new LinkedList<>();
        intList.insertAtEnd(10);
        intList.insertAtEnd(20);
        intList.insertAtEnd(30);
        System.out.println("Integer Linked List:");
        intList.display();

        intList.insertAtBeginning(5);
        System.out.println("After inserting at beginning:");
        intList.display();

        intList.deleteFirst();
        System.out.println("After deleting first element:");
        intList.display();

        // String Linked List
        LinkedList<String> strList = new LinkedList<>();
        strList.insertAtEnd("Alice");
        strList.insertAtEnd("Bob");
        strList.insertAtEnd("Charlie");
        System.out.println("String Linked List:");
        strList.display();

        strList.insertAtBeginning("Zara");
        System.out.println("After inserting at beginning:");
        strList.display();

        strList.deleteFirst();
        System.out.println("After deleting first element:");
        strList.display();
    }
}
