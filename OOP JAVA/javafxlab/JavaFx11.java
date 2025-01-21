// Import necessary JavaFX packages
import javafx.application.Application;
import javafx.scene.Scene;
import javafx.scene.control.Button;
import javafx.scene.control.Label;
import javafx.scene.control.TextField;
import javafx.scene.control.ToggleButton;
import javafx.scene.layout.FlowPane;
import javafx.stage.Stage;

public class JavaFx11 extends Application {
    @Override
    public void start(Stage primaryStage) {
        primaryStage.setTitle("Simple Calculator using Toggle Buttons");

        // Create input fields for numbers
        TextField number1Field = new TextField();
        number1Field.setPromptText("Enter first number");
        TextField number2Field = new TextField();
        number2Field.setPromptText("Enter second number");

        // Toggle buttons for operations
        ToggleButton addToggle = new ToggleButton("+");
        ToggleButton subtractToggle = new ToggleButton("-");
        ToggleButton multiplyToggle = new ToggleButton("*");
        ToggleButton divideToggle = new ToggleButton("/");

        // Label to display the result
        Label resultLabel = new Label("Result:");

        // Button to perform the calculation
        Button calculateButton = new Button("Calculate");

        // Add action for calculateButton using an anonymous inner class
        calculateButton.setOnAction(new javafx.event.EventHandler<javafx.event.ActionEvent>() {
            public void handle(javafx.event.ActionEvent e) {
                try {
                    double num1 = Double.parseDouble(number1Field.getText());
                    double num2 = Double.parseDouble(number2Field.getText());
                    double result = 0;

                    // Check which toggle button is selected
                    if (addToggle.isSelected()) {
                        result = num1 + num2;
                    } else if (subtractToggle.isSelected()) {
                        result = num1 - num2;
                    } else if (multiplyToggle.isSelected()) {
                        result = num1 * num2;
                    } else if (divideToggle.isSelected()) {
                        if (num2 != 0) {
                            result = num1 / num2;
                        } else {
                            resultLabel.setText("Error: Cannot divide by zero");
                            return;
                        }
                    } else {
                        resultLabel.setText("Select an operation");
                        return;
                    }

                    resultLabel.setText("Result: " + result);

                } catch (NumberFormatException ex) {
                    resultLabel.setText("Invalid input, please enter numbers.");
                }
            }
        });

        // Layout setup
        FlowPane root = new FlowPane(10, 10);
        root.getChildren().addAll(number1Field, number2Field, addToggle, subtractToggle, multiplyToggle, divideToggle, calculateButton, resultLabel);

        // Set the scene
        Scene scene = new Scene(root, 300, 250);
        primaryStage.setScene(scene);
        primaryStage.show();
    }

    public static void main(String[] args) {
        launch(args);
    }
}
