import javafx.application.*;
import javafx.scene.*;
import javafx.stage.*;
import javafx.scene.layout.*;
import javafx.scene.canvas.*;
import javafx.scene.paint.*;
import javafx.scene.control.*;
import javafx.collections.*;
import javafx.beans.value.*;
import javafx.geometry.*;

class Student {
    String name;
    String regNo;

    Student(String name, String regNo) {
        this.name = name;
        this.regNo = regNo;
    }

    @Override
    public String toString() {
        return regNo; // Display register number in ListView
    }
}

public class JavaFx9a extends Application {

    public static void main(String[] args) {
        launch(args);
    }

    public void start(Stage myStage) {
        myStage.setTitle("Students");
        FlowPane rootNode = new FlowPane(10, 10);
        Scene scene = new Scene(rootNode, 450, 450);
        rootNode.setAlignment(Pos.CENTER);

        // Create a Canvas for displaying details
        Canvas canvas = new Canvas(200, 200);
        GraphicsContext gc = canvas.getGraphicsContext2D();

        // Create a list of students
        ObservableList<Student> ob = FXCollections.observableArrayList(
                new Student("Aarav", "230905562"),
                new Student("Dhruv", "230911166"),
                new Student("Bob", "230900191")
        );

        // Create a ListView to display students
        ListView<Student> lv = new ListView<>(ob);
        lv.setPrefSize(80, 80);

        // Handle ListView item selection
        lv.getSelectionModel().selectedItemProperty().addListener(
                (ObservableValue<? extends Student> observable, Student oldValue, Student newStudent) -> {
                    // Clear canvas and display student details
                    gc.clearRect(0, 0, canvas.getWidth(), canvas.getHeight()); // Fix for clearRect
                    if (newStudent != null) {
                        gc.fillText("Name: " + newStudent.name + " RegNo: " + newStudent.regNo, 50, 100);
                    }
                });

        // Add ListView and Canvas to the layout
        rootNode.getChildren().addAll(lv, canvas);

        // Set the scene and show the stage
        myStage.setScene(scene);
        myStage.show();
    }
}
