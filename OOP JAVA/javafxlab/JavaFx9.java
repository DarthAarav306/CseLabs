// Import necessary JavaFX packages
import javafx.application.Application;
import javafx.scene.Scene;
import javafx.scene.canvas.Canvas;
import javafx.scene.canvas.GraphicsContext;
import javafx.scene.control.*;
import javafx.scene.layout.FlowPane;
import javafx.scene.paint.Color;
import javafx.scene.text.Font;
import javafx.stage.Stage;
import javafx.collections.FXCollections;
import javafx.collections.ObservableList;

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

public class JavaFx9 extends Application {
    @Override
    public void start(Stage primaryStage) {
        primaryStage.setTitle("Student Details Viewer");

        ObservableList<Student> students = FXCollections.observableArrayList();
        
        Label instructionLabel = new Label("Add Student Details:");
        TextField regNumberField = new TextField();
        regNumberField.setPromptText("Registration Number");
        
        TextField nameField = new TextField();
        nameField.setPromptText("Name");
        
        TextField ageField = new TextField();
        ageField.setPromptText("Age");
        
        TextField gradeField = new TextField();
        gradeField.setPromptText("Grade");

        Button addButton = new Button("Add Student");
        
        ListView<Student> listView = new ListView<>(students);
        
        Canvas canvas = new Canvas(400, 200); // Canvas for displaying student details
        GraphicsContext gc = canvas.getGraphicsContext2D();
        gc.setFont(Font.font("Verdana", 14));
        gc.setFill(Color.DARKBLUE);

        listView.getSelectionModel().selectedItemProperty().addListener(new javafx.beans.value.ChangeListener<Student>() {
            @Override
            public void changed(javafx.beans.value.ObservableValue<? extends Student> observable, Student oldValue, Student newValue) {
                if (newValue != null) {
                    gc.clearRect(0, 0, canvas.getWidth(), canvas.getHeight());
                    gc.fillText(newValue.getDetails(), 10, 30);
                }
            }
        });

        addButton.setOnAction(new javafx.event.EventHandler<javafx.event.ActionEvent>() {
            @Override
            public void handle(javafx.event.ActionEvent e) {
                try {
                    String regNumber = regNumberField.getText();
                    String name = nameField.getText();
                    int age = Integer.parseInt(ageField.getText());
                    double grade = Double.parseDouble(gradeField.getText());

                    Student student = new Student(regNumber, name, age, grade);
                    students.add(student);
                    
                    // Clear input fields
                    regNumberField.clear();
                    nameField.clear();
                    ageField.clear();
                    gradeField.clear();
                    
                } catch (NumberFormatException ex) {
                    gc.clearRect(0, 0, canvas.getWidth(), canvas.getHeight());
                    gc.fillText("Invalid input. Please enter numeric values for age and grade.", 10, 30);
                }
            }
        });

        FlowPane root = new FlowPane(10, 10); // Set 10 px horizontal and vertical gap
        root.getChildren().addAll(instructionLabel, regNumberField, nameField, ageField, gradeField, addButton, listView, canvas);
        
        Scene scene = new Scene(root, 600, 400);
        primaryStage.setScene(scene);
        primaryStage.show();
    }

    public static void main(String[] args) {
        launch(args);
    }
}
