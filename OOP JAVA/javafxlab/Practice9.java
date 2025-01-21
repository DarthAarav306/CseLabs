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
import javafx.beans.value.ChangeListener;
import javafx.beans.value.ObservableValue;
import javafx.event.ActionEvent;
import javafx.event.EventHandler;

class Student {
    String name;
    int regNum;
    float gpa;

    Student(String name, int regNum, float gpa) {
        this.name = name;
        this.regNum = regNum;
        this.gpa = gpa;
    }

    @Override
    public String toString() {
        return Integer.toString(regNum); // Display only registration number in ListView
    }

    public String getDetails() {
        return "Name: " + name + "\nReg No: " + regNum + "\nGPA: " + gpa;
    }
}

public class Practice9 extends Application {
    @Override
    public void start(Stage myStage) {
        FlowPane rootNode = new FlowPane(10, 10);
        Scene scene = new Scene(rootNode, 500, 500);
        myStage.setTitle("Student Details");

        // Canvas for displaying student details
        Canvas canvas = new Canvas(300, 200);
        GraphicsContext gc = canvas.getGraphicsContext2D();
        gc.setFill(Color.RED);
        gc.setStroke(Color.RED);
        gc.setFont(new Font(20));

        // Input fields and button
        TextField nameTf = new TextField();
        nameTf.setPromptText("Enter name");
        TextField regNumTf = new TextField();
        regNumTf.setPromptText("Enter registration number");
        TextField gpaTf = new TextField();
        gpaTf.setPromptText("Enter GPA");
        Button addBtn = new Button("Add");

        // ObservableList for ListView
        ObservableList<Student> stuList = FXCollections.observableArrayList();
        ListView<Student> stuListView = new ListView<>(stuList);
        stuListView.setPrefSize(150, 100);

        // Selection model for ListView to show selected student's details
        MultipleSelectionModel<Student> lvModel = stuListView.getSelectionModel();
        lvModel.selectedItemProperty().addListener(new ChangeListener<Student>() {
            @Override
            public void changed(ObservableValue<? extends Student> observable, Student oldVal, Student newVal) {
                if (newVal != null) {
                    gc.clearRect(0, 0, canvas.getWidth(), canvas.getHeight()); // Clear canvas
                    gc.fillText(newVal.getDetails(), 10, 50); // Display selected student details
                }
            }
        });

        // Button action to add new student
        addBtn.setOnAction(new EventHandler<ActionEvent>() {
            @Override
            public void handle(ActionEvent ae) {
                try {
                    String name = nameTf.getText();
                    int regNum = Integer.parseInt(regNumTf.getText());
                    float gpa = Float.parseFloat(gpaTf.getText());

                    // Create and add student to the ObservableList
                    Student student = new Student(name, regNum, gpa);
                    stuList.add(student);

                    // Clear input fields after adding
                    nameTf.clear();
                    regNumTf.clear();
                    gpaTf.clear();

                } catch (NumberFormatException e) {
                    gc.clearRect(0, 0, canvas.getWidth(), canvas.getHeight());
                    gc.fillText("Invalid input. Please enter valid numbers for Reg No and GPA.", 10, 50);
                }
            }
        });

        // Add all components to the root node
        rootNode.getChildren().addAll(nameTf, regNumTf, gpaTf, addBtn, stuListView, canvas);
        myStage.setScene(scene);
        myStage.show();
    }

    public static void main(String[] args) {
        launch(args);
    }
}
