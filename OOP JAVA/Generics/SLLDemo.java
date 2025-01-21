// Generic Node Class
class Node<T> {
    T data;
    Node<T> next;

    public Node(T data) {
        this.data = data;
        this.next = null;
    }
}

// Generic Singly Linked List Class
class LinkedList<T> {
    private Node<T> head;

    public LinkedList() {
        head = null;
    }

    // Insert a new node at the end of the list
    public void insert(T data) {
        Node<T> newNode = new Node<>(data);
        if (head == null) {
            head = newNode;
        } else {
            Node<T> temp = head;
            while (temp.next != null) {
                temp = temp.next;
            }
            temp.next = newNode;
        }
    }

    // Display the entire linked list
    public void display() {
        if (head == null) {
            System.out.println("List is empty");
        } else {
            Node<T> temp = head;
            while (temp != null) {
                System.out.print(temp.data + " -> ");
                temp = temp.next;
            }
            System.out.println("null");
        }
    }

    // Delete the first occurrence of the given data
    public void delete(T data) {
        if (head == null) {
            System.out.println("List is empty");
            return;
        }

        if (head.data.equals(data)) {
            head = head.next;
            return;
        }

        Node<T> temp = head;
        while (temp.next != null && !temp.next.data.equals(data)) {
            temp = temp.next;
        }

        if (temp.next == null) {
            System.out.println("Data not found");
        } else {
            temp.next = temp.next.next;
        }
    }
}

// Main Class to Demonstrate the Generic Linked List
public class SLLDemo {
    public static void main(String[] args) {
        // Integer Linked List
        LinkedList<Integer> intList = new LinkedList<>();
        intList.insert(10);
        intList.insert(20);
        intList.insert(30);
        System.out.println("Integer Linked List:");
        intList.display(); // Output: 10 -> 20 -> 30 -> null

        // String Linked List
        LinkedList<String> stringList = new LinkedList<>();
        stringList.insert("Hello");
        stringList.insert("World");
        System.out.println("String Linked List:");
        stringList.display(); // Output: Hello -> World -> null

        // Delete from Integer List
        intList.delete(20);
        System.out.println("After Deleting 20:");
        intList.display(); // Output: 10 -> 30 -> null
    }
}
