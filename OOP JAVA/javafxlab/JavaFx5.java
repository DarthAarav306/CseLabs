// import javafx.application.*;         // To import all classes from javafx.application package (like Application)
// import javafx.scene.*;               // To import all classes from javafx.scene package (like Scene, Node, etc.)
// import javafx.scene.control.*;       // To import UI controls like Button, Label, TextField
// import javafx.scene.layout.*;        // To import layout managers like GridPane
// import javafx.stage.*;               // To import classes related to the application window (like Stage)
// import javafx.event.*;               // To import EventHandler classes for handling events like button clicks

import javafx.application.Application;
import javafx.event.ActionEvent;
import javafx.event.EventHandler;
import javafx.scene.Scene;
import javafx.scene.control.Button;
import javafx.scene.control.Label;
import javafx.scene.control.TextField;
import javafx.scene.layout.GridPane;
import javafx.stage.Stage;

public class JavaFx5 extends Application {
    public void start(Stage primaryStage) {
        Label firstNumLabel = new Label("First Number:");
        TextField firstNumField = new TextField();
        
        Label secondNumLabel = new Label("Second Number:");
        TextField secondNumField = new TextField();
        
        Label resultLabel = new Label("Result:");
        TextField resultField = new TextField();
        resultField.setEditable(false); 
        
        // Buttons for arithmetic operations
        Button addButton = new Button("+");
        Button subButton = new Button("-");
        Button mulButton = new Button("*");
        Button divButton = new Button("/");

        addButton.setOnAction(new EventHandler<ActionEvent>() {
            public void handle(ActionEvent event) {
                try {
                    double num1 = Double.parseDouble(firstNumField.getText());
                    double num2 = Double.parseDouble(secondNumField.getText());
                    resultField.setText(String.valueOf(num1 + num2));
                } catch (NumberFormatException e) {
                    resultField.setText("Invalid Input");
                }
            }
        });
        
        subButton.setOnAction(new EventHandler<ActionEvent>() {
            @Override
            public void handle(ActionEvent event) {
                try {
                    double num1 = Double.parseDouble(firstNumField.getText());
                    double num2 = Double.parseDouble(secondNumField.getText());
                    resultField.setText(String.valueOf(num1 - num2));
                } catch (NumberFormatException e) {
                    resultField.setText("Invalid Input");
                }
            }
        });

        mulButton.setOnAction(new EventHandler<ActionEvent>() {
            @Override
            public void handle(ActionEvent event) {
                try {
                    double num1 = Double.parseDouble(firstNumField.getText());
                    double num2 = Double.parseDouble(secondNumField.getText());
                    resultField.setText(String.valueOf(num1 * num2));
                } catch (NumberFormatException e) {
                    resultField.setText("Invalid Input");
                }
            }
        });

        divButton.setOnAction(new EventHandler<ActionEvent>() {
            @Override
            public void handle(ActionEvent event) {
                try {
                    double num1 = Double.parseDouble(firstNumField.getText());
                    double num2 = Double.parseDouble(secondNumField.getText());
                    if (num2 != 0) {
                        resultField.setText(String.valueOf(num1 / num2));
                    } else {
                        resultField.setText("Cannot Divide by Zero");
                    }
                } catch (NumberFormatException e) {
                    resultField.setText("Invalid Input");
                }
            }
        });

        // GridPane layout
        GridPane gridPane = new GridPane();
        gridPane.setHgap(10); // Horizontal spacing
        gridPane.setVgap(10); // Vertical spacing

        // Adding components to the grid
        gridPane.add(firstNumLabel, 0, 0);
        gridPane.add(firstNumField, 1, 0);
        gridPane.add(secondNumLabel, 0, 1);
        gridPane.add(secondNumField, 1, 1);
        gridPane.add(resultLabel, 0, 2);
        gridPane.add(resultField, 1, 2);
        gridPane.add(addButton, 0, 3);
        gridPane.add(subButton, 1, 3);
        gridPane.add(mulButton, 0, 4);
        gridPane.add(divButton, 1, 4);

        // Scene setup
        Scene scene = new Scene(gridPane, 300, 200);
        primaryStage.setTitle("Simple Calculator");
        primaryStage.setScene(scene);
        primaryStage.show();
    }

    public static void main(String[] args) {
        launch(args); // Launch the JavaFX application
    }
}
