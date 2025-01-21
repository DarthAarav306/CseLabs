// import javafx.application.*;         // To import all classes from javafx.application package (like Application)
// import javafx.scene.*;               // To import all classes from javafx.scene package (like Scene, Node, etc.)
// import javafx.scene.control.*;       // To import all UI controls like Button, Label, TextField
// import javafx.scene.layout.*;        // To import layout managers like GridPane, VBox, HBox
// import javafx.stage.*;               // To import classes related to the application window (like Stage)

import javafx.application.Application;
import javafx.scene.Scene;
import javafx.scene.control.Button;
import javafx.scene.control.Label;
import javafx.scene.control.TextField;
import javafx.scene.layout.GridPane;
import javafx.stage.Stage;
import javafx.event.*;
class Employee {
    String name;
    int empID;
    String designation;
    double basicPay, DA, HRA, PF, LIC, netSalary;

    Employee(String name, int empID, String designation, double basicPay) {
        this.name = name;
        this.empID = empID;
        this.designation = designation;
        this.basicPay = basicPay;
        calculateSalaries();
    }

    void calculateSalaries() {
        DA = 0.40 * basicPay;
        HRA = 0.15 * basicPay;
        PF = 0.12 * basicPay;
        LIC = 200; 
        netSalary = basicPay + DA + HRA - PF - LIC;
    }
}

public class JavaFx4 extends Application {
    public void start(Stage primaryStage) {
        GridPane gridPane = new GridPane();
        gridPane.setHgap(10); // Horizontal gap between elements
        gridPane.setVgap(10); // Vertical gap between elements
        Label nameLabel = new Label("Name:");
        TextField nameField = new TextField();
        
        Label empIDLabel = new Label("Employee ID:");
        TextField empIDField = new TextField();
        
        Label designationLabel = new Label("Designation:");
        TextField designationField = new TextField();
        
        Label basicPayLabel = new Label("Basic Pay:");
        TextField basicPayField = new TextField();

        Button calculateButton = new Button("Calculate Salary");
        Label resultLabel = new Label(); 
        calculateButton.setOnAction(new EventHandler<ActionEvent>() {
            public void handle(ActionEvent event) {
                try {
                    String name = nameField.getText();
                    int empID = Integer.parseInt(empIDField.getText());
                    String designation = designationField.getText();
                    double basicPay = Double.parseDouble(basicPayField.getText());
                    Employee employee = new Employee(name, empID, designation, basicPay);

                    String resultText = "Employee Name: " + employee.name +
                            "\nEmployee ID: " + employee.empID +
                            "\nDesignation: " + employee.designation +
                            "\nBasic Pay: $" + employee.basicPay +
                            "\nDA (40% of Basic Pay): $" + employee.DA +
                            "\nHRA (15% of Basic Pay): $" + employee.HRA +
                            "\nPF (12% of Basic Pay): $" + employee.PF +
                            "\nLIC: $" + employee.LIC +
                            "\nNet Salary: $" + employee.netSalary;

                    resultLabel.setText(resultText);
                } catch (NumberFormatException e) {
                    resultLabel.setText("Please enter valid numeric values for Employee ID and Basic Pay.");
                }
            }
        });

        gridPane.add(nameLabel, 0, 0);
        gridPane.add(nameField, 1, 0);
        gridPane.add(empIDLabel, 0, 1);
        gridPane.add(empIDField, 1, 1);
        gridPane.add(designationLabel, 0, 2);
        gridPane.add(designationField, 1, 2);
        gridPane.add(basicPayLabel, 0, 3);
        gridPane.add(basicPayField, 1, 3);
        gridPane.add(calculateButton, 1, 4);
        gridPane.add(resultLabel, 1, 5);

        Scene scene = new Scene(gridPane, 400, 400); 
        primaryStage.setTitle("Employee Salary Information");
        primaryStage.setScene(scene);
        primaryStage.show();
    }

    public static void main(String[] args) {
        launch(args); 
    }
}
