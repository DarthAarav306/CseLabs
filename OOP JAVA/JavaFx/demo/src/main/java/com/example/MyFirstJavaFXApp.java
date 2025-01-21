import javafx.application.Application;
import javafx.scene.Scene;
import javafx.scene.control.Label;
import javafx.scene.layout.FlowPane;
import javafx.scene.paint.Color;
import javafx.stage.Stage;

public class MyFirstJavaFXApp extends Application {
    @Override
    public void start(Stage primaryStage) {
        // Create a Label with the desired message
        Label label = new Label("Welcome to JavaFX programming");

        // Set the text color to Magenta
        label.setTextFill(Color.MAGENTA);

        // Create a FlowPane layout and set hgap and vgap
        FlowPane flowPane = new FlowPane();
        flowPane.setHgap(10); // Horizontal gap between elements
        flowPane.setVgap(20); // Vertical gap between elements
        flowPane.getChildren().add(label);

        // Create a Scene and set the width and height
        Scene scene = new Scene(flowPane, 500, 200);

        // Set the title of the Stage
        primaryStage.setTitle("This is the first JavaFX Application");

        // Set the Scene and display the Stage
        primaryStage.setScene(scene);
        primaryStage.show();
    }

    public static void main(String[] args) {
        launch(args);
    }
}
