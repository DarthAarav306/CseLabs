import javafx.application.Application;
import javafx.scene.Scene;
import javafx.scene.control.*;
import javafx.scene.layout.FlowPane;
import javafx.stage.Stage;

public class JavaFx11Alt extends Application {
    @Override
    public void start(Stage primaryStage) {
        primaryStage.setTitle("Simple Calculator");

        // Text fields for user input
        TextField num1Field = new TextField();
        num1Field.setPromptText("Enter first number");

        TextField num2Field = new TextField();
        num2Field.setPromptText("Enter second number");

        // Label to display the result
        Label resultLabel = new Label("Result will be displayed here");

        // Toggle buttons for operations
        ToggleButton addButton = new ToggleButton("Add");
        ToggleButton subtractButton = new ToggleButton("Subtract");
        ToggleButton multiplyButton = new ToggleButton("Multiply");
        ToggleButton divideButton = new ToggleButton("Divide");

        // Anonymous inner class for Add button
        addButton.setOnAction(new EventHandler<ActionEvent>() {
            @Override
            public void handle(ActionEvent event) {
                try {
                    double num1 = Double.parseDouble(num1Field.getText());
                    double num2 = Double.parseDouble(num2Field.getText());
                    double result = num1 + num2;
                    resultLabel.setText("Result: " + result);
                } catch (NumberFormatException e) {
                    resultLabel.setText("Please enter valid numbers.");
                }
            }
        });

        // Anonymous inner class for Subtract button
        subtractButton.setOnAction(new EventHandler<ActionEvent>() {
            @Override
            public void handle(ActionEvent event) {
                try {
                    double num1 = Double.parseDouble(num1Field.getText());
                    double num2 = Double.parseDouble(num2Field.getText());
                    double result = num1 - num2;
                    resultLabel.setText("Result: " + result);
                } catch (NumberFormatException e) {
                    resultLabel.setText("Please enter valid numbers.");
                }
            }
        });

        // Anonymous inner class for Multiply button
        multiplyButton.setOnAction(new EventHandler<ActionEvent>() {
            @Override
            public void handle(ActionEvent event) {
                try {
                    double num1 = Double.parseDouble(num1Field.getText());
                    double num2 = Double.parseDouble(num2Field.getText());
                    double result = num1 * num2;
                    resultLabel.setText("Result: " + result);
                } catch (NumberFormatException e) {
                    resultLabel.setText("Please enter valid numbers.");
                }
            }
        });

        // Anonymous inner class for Divide button
        divideButton.setOnAction(new EventHandler<ActionEvent>() {
            @Override
            public void handle(ActionEvent event) {
                try {
                    double num1 = Double.parseDouble(num1Field.getText());
                    double num2 = Double.parseDouble(num2Field.getText());
                    if (num2 != 0) {
                        double result = num1 / num2;
                        resultLabel.setText("Result: " + result);
                    } else {
                        resultLabel.setText("Error: Cannot divide by zero.");
                    }
                } catch (NumberFormatException e) {
                    resultLabel.setText("Please enter valid numbers.");
                }
            }
        });

        // FlowPane layout for arranging controls
        FlowPane root = new FlowPane(10, 10);
        root.getChildren().addAll(num1Field, num2Field, addButton, subtractButton, multiplyButton, divideButton, resultLabel);

        // Set the scene and stage
        Scene scene = new Scene(root, 400, 200);
        primaryStage.setScene(scene);
        primaryStage.show();
    }

    public static void main(String[] args) {
        launch(args);
    }
}
