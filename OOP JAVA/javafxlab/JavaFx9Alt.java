// Import necessary JavaFX packages
import javafx.application.Application;
import javafx.scene.Scene;
import javafx.scene.canvas.Canvas;
import javafx.scene.canvas.GraphicsContext;
import javafx.scene.control.Label;
import javafx.scene.control.ListView;
import javafx.scene.layout.FlowPane;
import javafx.scene.paint.Color;
import javafx.scene.text.Font;
import javafx.stage.Stage;
import javafx.collections.FXCollections;
import javafx.collections.ObservableList;
import javafx.beans.value.ChangeListener;
import javafx.beans.value.ObservableValue;

class Student {
    String regNumber;
    String name;
    int age;
    double grade;

    Student(String regNumber, String name, int age, double grade) {
        this.regNumber = regNumber;
        this.name = name;
        this.age = age;
        this.grade = grade;
    }

    public String getDetails() {
        return "Reg No: " + regNumber + "\nName: " + name + "\nAge: " + age + "\nGrade: " + grade;
    }

    @Override
    public String toString() {
        return regNumber;  // Only display the register number in ListView
    }
}

public class JavaFx9Alt extends Application {
    @Override
    public void start(Stage primaryStage) {
        primaryStage.setTitle("Student Details Viewer");

        // Sample list of students
        ObservableList<Student> students = FXCollections.observableArrayList(
            new Student("2023001", "Alice", 20, 8.5),
            new Student("2023002", "Bob", 21, 9.0),
            new Student("2023003", "Charlie", 22, 8.8),
            new Student("2023004", "Diana", 19, 9.2)
        );

        Label instructionLabel = new Label("Select a student by registration number:");
        ListView<Student> listView = new ListView<>(students);
        
        Canvas canvas = new Canvas(400, 200); // Canvas for displaying student details
        GraphicsContext gc = canvas.getGraphicsContext2D();
        gc.setFont(Font.font("Verdana", 14));
        gc.setFill(Color.DARKBLUE);

        // Non-lambda event listener for ListView selection
        listView.getSelectionModel().selectedItemProperty().addListener(
            new ChangeListener<Student>() {
                @Override
                public void changed(ObservableValue<? extends Student> observable, Student oldValue, Student newValue) {
                    if (newValue != null) {
                        gc.clearRect(0, 0, canvas.getWidth(), canvas.getHeight());
                        gc.fillText(newValue.getDetails(), 10, 30);
                    }
                }
            }
        );

        FlowPane root = new FlowPane(20, 20); // 20 px horizontal and vertical gap
        root.getChildren().addAll(instructionLabel, listView, canvas);
        
        Scene scene = new Scene(root, 500, 300);
        primaryStage.setScene(scene);
        primaryStage.show();
    }

    public static void main(String[] args) {
        launch(args);
    }
}
