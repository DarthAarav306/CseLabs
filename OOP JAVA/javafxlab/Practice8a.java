import javafx.application.*;
import javafx.scene.*;
import javafx.stage.*;
import javafx.scene.layout.*;
import javafx.scene.canvas.*;
import javafx.scene.paint.*;
import javafx.scene.control.*;
import javafx.event.ActionEvent;
import javafx.event.EventHandler;
import javafx.geometry.*;

class ScrollThread implements Runnable {
    Thread t;
    int direction;
    GraphicsContext gc;
    String message;

    ScrollThread(String message, int direction, GraphicsContext gc) {
        this.message = message;
        this.direction = direction;
        this.gc = gc;
        t = new Thread(this);
        t.start();
    }

    public void run() {
        String scrollText = message; // Initialize with the original message
        while (true) {
            gc.clearRect(0, 0, 400, 400); // Clear canvas before redrawing

            // Adjust text scrolling based on direction
            if (direction == 1) { // Scroll right
                scrollText = scrollText.charAt(scrollText.length() - 1) + scrollText.substring(0, scrollText.length() - 1);
            } else { // Scroll left
                scrollText = scrollText.substring(1) + scrollText.charAt(0);
            }

            gc.fillText(scrollText, 50, 150); // Draw the scrolling text

            try {
                Thread.sleep(500); // Pause for a smooth scrolling effect
            } catch (InterruptedException exc) {
                exc.printStackTrace();
            }
        }
    }
}

public class Practice8a extends Application {
    public static void main(String[] args) {
        launch(args);
    }

    public void start(Stage myStage) {
        myStage.setTitle("Thread");
        FlowPane rootNode = new FlowPane(10, 10);
        Scene scene = new Scene(rootNode, 450, 450);
        myStage.setScene(scene); // Fixed the incorrect method name

        // TextField for user input
        TextField tf = new TextField();
        tf.setPromptText("Enter Text here");

        // Canvas for drawing
        Canvas canvas = new Canvas(400, 400);
        GraphicsContext gc = canvas.getGraphicsContext2D();

        // Radio buttons for scrolling direction
        RadioButton right = new RadioButton("Scroll Right");
        RadioButton left = new RadioButton("Scroll Left");
        ToggleGroup tg = new ToggleGroup();
        right.setToggleGroup(tg);
        left.setToggleGroup(tg);

        // Action for the "Scroll Right" button
        right.setOnAction(new EventHandler<ActionEvent>() {
            public void handle(ActionEvent e) {
                new ScrollThread(tf.getText(), 1, gc); // Create thread to scroll right
            }
        });

        // Action for the "Scroll Left" button
        left.setOnAction(new EventHandler<ActionEvent>() {
            public void handle(ActionEvent e) {
                new ScrollThread(tf.getText(), 0, gc); // Create thread to scroll left
            }
        });

        // Add components to the layout
        rootNode.getChildren().addAll(tf, right, left, canvas);

        // Show the stage
        myStage.show();
    }
}
