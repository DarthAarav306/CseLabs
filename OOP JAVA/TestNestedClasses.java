class Outer {
    // Static Nested Class
    static class StaticNested {
        void display() {
            System.out.println("Inside Static Nested Class.");
        }
    }

    // Non-Static Inner Class
    class Inner {
        void display() {
            System.out.println("Inside Non-Static Inner Class.");
        }
    }
}

public class TestNestedClasses {
    public static void main(String[] args) {
        // Instantiating Static Nested Class
        Outer.StaticNested staticNested = new Outer.StaticNested();
        staticNested.display();

        // Instantiating Non-Static Inner Class
        Outer outer = new Outer(); // First create an instance of the outer class
        Outer.Inner inner = outer.new Inner(); // Then create the inner class instance
        inner.display();
    }
}
