import java.util.Scanner;

class Building {
    private double squareFootage;
    private int stories;

    // Constructor
    Building(double squareFootage, int stories) {
        this.squareFootage = squareFootage;
        this.stories = stories;
    }

    // Getters and Setters
    public double getSquareFootage() {
        return squareFootage;
    }

    public void setSquareFootage(double squareFootage) {
        this.squareFootage = squareFootage;
    }

    public int getStories() {
        return stories;
    }

    public void setStories(int stories) {
        this.stories = stories;
    }

    // Display details
    public void displayDetails() {
        System.out.println("Square Footage: " + squareFootage);
        System.out.println("Stories: " + stories);
    }
}

class House extends Building {
    private int bedrooms;
    private int baths;

    // Constructor
    House(double squareFootage, int stories, int bedrooms, int baths) {
        super(squareFootage, stories);
        this.bedrooms = bedrooms;
        this.baths = baths;
    }

    // Getters and Setters
    public int getBedrooms() {
        return bedrooms;
    }

    public void setBedrooms(int bedrooms) {
        this.bedrooms = bedrooms;
    }

    public int getBaths() {
        return baths;
    }

    public void setBaths(int baths) {
        this.baths = baths;
    }

    // Display details
    @Override
    public void displayDetails() {
        super.displayDetails();
        System.out.println("Bedrooms: " + bedrooms);
        System.out.println("Baths: " + baths);
    }
}

class School extends Building {
    private int classrooms;
    private String gradeLevel;

    // Constructor
    School(double squareFootage, int stories, int classrooms, String gradeLevel) {
        super(squareFootage, stories);
        this.classrooms = classrooms;
        this.gradeLevel = gradeLevel;
    }

    // Getters and Setters
    public int getClassrooms() {
        return classrooms;
    }

    public void setClassrooms(int classrooms) {
        this.classrooms = classrooms;
    }

    public String getGradeLevel() {
        return gradeLevel;
    }

    public void setGradeLevel(String gradeLevel) {
        this.gradeLevel = gradeLevel;
    }

    // Display details
    @Override
    public void displayDetails() {
        super.displayDetails();
        System.out.println("Classrooms: " + classrooms);
        System.out.println("Grade Level: " + gradeLevel);
    }
}

public class BuildingDemo {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);

        // Input for Building
        System.out.println("Enter Building Details:");
        System.out.print("Square Footage: ");
        double bSquareFootage = scanner.nextDouble();
        System.out.print("Stories: ");
        int bStories = scanner.nextInt();
        Building building = new Building(bSquareFootage, bStories);

        // Input for House
        System.out.println("\nEnter House Details:");
        System.out.print("Square Footage: ");
        double hSquareFootage = scanner.nextDouble();
        System.out.print("Stories: ");
        int hStories = scanner.nextInt();
        System.out.print("Bedrooms: ");
        int hBedrooms = scanner.nextInt();
        System.out.print("Baths: ");
        int hBaths = scanner.nextInt();
        House house = new House(hSquareFootage, hStories, hBedrooms, hBaths);

        // Input for School
        System.out.println("\nEnter School Details:");
        System.out.print("Square Footage: ");
        double sSquareFootage = scanner.nextDouble();
        System.out.print("Stories: ");
        int sStories = scanner.nextInt();
        System.out.print("Classrooms: ");
        int sClassrooms = scanner.nextInt();
        scanner.nextLine(); // consume the leftover newline
        System.out.print("Grade Level (e.g., Elementary, Junior High): ");
        String sGradeLevel = scanner.nextLine();
        School school = new School(sSquareFootage, sStories, sClassrooms, sGradeLevel);

        // Displaying Details
        System.out.println("\nBuilding Details:");
        building.displayDetails();

        System.out.println("\nHouse Details:");
        house.displayDetails();

        System.out.println("\nSchool Details:");
        school.displayDetails();

        scanner.close();
    }
}
