// import javafx.application.*;         // To import all classes from javafx.application package (like Application)
// import javafx.scene.*;               // To import all classes from javafx.scene package (like Scene, Node, etc.)
// import javafx.scene.control.*;       // To import all UI controls like Button, Label, TextField
// import javafx.scene.layout.*;        // To import layout managers like FlowPane, VBox, HBox
// import javafx.stage.*;               // To import classes related to the application window (like Stage)
// import javafx.event.*;               // Importing all event-related classes like EventHandler and ActionEvent

import javafx.application.Application;
import javafx.scene.Scene;
import javafx.scene.control.Button;
import javafx.scene.control.Label;
import javafx.scene.control.TextField;
import javafx.scene.layout.FlowPane;
import javafx.stage.Stage;
import javafx.event.EventHandler;
import javafx.event.ActionEvent;

public class JavaFx2 extends Application {

    @Override/**/
    public void start(Stage primaryStage) {
        // Creating a Label to display instructions
        Label instructionLabel = new Label("Enter an integer: ");
        
        // Creating a TextField where the user will input the number
        TextField inputField = new TextField();
        
        // Creating a Button to trigger the calculation of the multiplication table
        Button calculateButton = new Button("Show Multiplication Table");
        
        // Creating a Label to display the result (multiplication table)
        Label resultLabel = new Label();

        // Setting an action using an Anonymous Inner Class for the button click
        calculateButton.setOnAction(new EventHandler<ActionEvent>() {
            @Override
            public void handle(ActionEvent event) {
                try {
                    // Getting the input value from the TextField
                    int number = Integer.parseInt(inputField.getText());
                    // Creating the multiplication table string using concatenation
                    String result = "Multiplication Table for " + number + ":\n";
                    for (int i = 1; i <= 10; i++) {
                        result += number + " * " + i + " = " + (number * i) + "\n";
                    }
                    // Displaying the result in the resultLabel
                    resultLabel.setText(result);
                } catch (NumberFormatException ex) {
                    // Handling the case where the user doesn't enter a valid integer
                    resultLabel.setText("Please enter a valid integer.");
                }
            }
        });

        // Create a FlowPane layout and set its properties
        FlowPane flowPane = new FlowPane();
        flowPane.setHgap(10);    // Horizontal gap between elements
        flowPane.setVgap(10);    // Vertical gap between elements
        flowPane.getChildren().addAll(instructionLabel, inputField, calculateButton, resultLabel);

        // Set up the scene and stage
        Scene scene = new Scene(flowPane, 400, 300);    // Setting scene size to 400x300
        primaryStage.setTitle("Multiplication Table App");
        primaryStage.setScene(scene);
        primaryStage.show();
    }

    public static void main(String[] args) {
        launch(args);    // Launches the JavaFX application
    }
}
