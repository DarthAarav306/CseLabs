import javafx.application.*;
import javafx.scene.*;
import javafx.stage.*;
import javafx.scene.layout.*;
import javafx.scene.control.*;
import javafx.scene.canvas.*;
import javafx.scene.text.*;
import javafx.scene.paint.*;
import javafx.event.*;

public class Practice8 extends Application {

    // Nested class to handle scrolling logic
    class Scroll implements Runnable {
        String message;
        Thread t;
        int direction;
        GraphicsContext gc;
        
        Scroll(GraphicsContext gc, String message, int direction) {
            this.gc = gc;
            this.message = message;
            this.direction = direction;
            t = new Thread(this);
            t.start();
        }

        public void run() {
            String scrollText = message;
            while (true) {
                gc.clearRect(0, 0, 300, 300);  // Clear canvas before redrawing
                
                // Adjust text scrolling based on direction
                if (direction == 1) {  // Scroll right
                    scrollText = scrollText.charAt(scrollText.length() - 1) + scrollText.substring(0, scrollText.length() - 1);
                } else {  // Scroll left
                    scrollText = scrollText.substring(1) + scrollText.charAt(0);
                }

                gc.fillText(scrollText, 50, 150);

                try {
                    Thread.sleep(500);
                } catch (InterruptedException exc) {
                    exc.printStackTrace();
                }
            }
        }
    }

    public static void main(String[] args) {
        launch(args);
    }

    public void start(Stage myStage) {
        FlowPane rootNode = new FlowPane(10, 10);
        Scene scene = new Scene(rootNode, 500, 300);
        myStage.setTitle("Scroll");

        TextField tf = new TextField();
        tf.setPromptText("Enter message:");

        RadioButton rightButton = new RadioButton("Scroll Right");
        RadioButton leftButton = new RadioButton("Scroll Left");
        ToggleGroup tg = new ToggleGroup();
        rightButton.setToggleGroup(tg);
        leftButton.setToggleGroup(tg);

        Canvas canvas = new Canvas(400, 200);
        GraphicsContext gc = canvas.getGraphicsContext2D();
        gc.setFill(Color.BLUE);
        gc.setFont(new Font(25));

        // Event handlers for radio buttons to start scrolling
        rightButton.setOnAction(new EventHandler<ActionEvent>() {
            public void handle(ActionEvent ae) {
                new Scroll(gc, tf.getText(), 1);
            }
        });

        leftButton.setOnAction(new EventHandler<ActionEvent>() {
            public void handle(ActionEvent ae) {
                new Scroll(gc, tf.getText(), 0);
            }
        });

        rootNode.getChildren().addAll(tf, rightButton, leftButton, canvas);
        myStage.setScene(scene);
        myStage.show();
    }
}
