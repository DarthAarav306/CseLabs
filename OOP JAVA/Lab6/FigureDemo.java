import java.util.Scanner;

// Abstract class Figure
abstract class Figure {
    int dimension1;
    int dimension2;

    // Constructor for dimensions
    Figure(int dimension1, int dimension2) {
        this.dimension1 = dimension1;
        this.dimension2 = dimension2;
    }

    // Abstract method area
    abstract double area();
}

// Rectangle class extends Figure
class Rectangle extends Figure {

    // Constructor for Rectangle
    Rectangle(int length, int width) {
        super(length, width);
    }

    // Implement the area method
    @Override
    double area() {
        return dimension1 * dimension2;
    }
}

// Triangle class extends Figure
class Triangle extends Figure {

    // Constructor for Triangle
    Triangle(int base, int height) {
        super(base, height);
    }

    // Implement the area method
    @Override
    double area() {
        return 0.5 * dimension1 * dimension2;
    }
}

// Square class extends Figure
class Square extends Figure {

    // Constructor for Square
    Square(int side) {
        super(side, side);
    }

    // Implement the area method
    @Override
    double area() {
        return dimension1 * dimension2;
    }
}

// Main class to demonstrate dynamic polymorphism
public class FigureDemo {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);

        // Input for Rectangle
        System.out.println("Enter length and width of the rectangle:");
        int length = scanner.nextInt();
        int width = scanner.nextInt();
        Figure rectangle = new Rectangle(length, width);

        // Input for Triangle
        System.out.println("Enter base and height of the triangle:");
        int base = scanner.nextInt();
        int height = scanner.nextInt();
        Figure triangle = new Triangle(base, height);

        // Input for Square
        System.out.println("Enter side of the square:");
        int side = scanner.nextInt();
        Figure square = new Square(side);

        // Demonstrating dynamic polymorphism
        System.out.println("\nCalculating areas using dynamic polymorphism:");
        System.out.println("Area of Rectangle: " + rectangle.area());
        System.out.println("Area of Triangle: " + triangle.area());
        System.out.println("Area of Square: " + square.area());

        scanner.close();
    }
}
