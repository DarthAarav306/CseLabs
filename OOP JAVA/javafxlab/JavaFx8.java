import javafx.application.Application;
import javafx.scene.Scene;
import javafx.scene.canvas.Canvas;
import javafx.scene.canvas.GraphicsContext;
import javafx.scene.control.Button;
import javafx.scene.control.Label;
import javafx.scene.control.RadioButton;
import javafx.scene.control.TextField;
import javafx.scene.control.ToggleGroup;
import javafx.scene.layout.FlowPane;
import javafx.stage.Stage;
import javafx.scene.paint.Color;
import javafx.event.ActionEvent;
import javafx.event.EventHandler;

class NewThread implements Runnable {
    GraphicsContext gc;
    String st;
    Thread t;
    int v;

    NewThread(GraphicsContext ob, String s, int m) {
        t = new Thread(this);
        gc = ob;
        v = m;
        st = s;
        t.start();
    }

    public void run() {
        if (v == 0) { // Scroll left
            for (;;) {
                gc.clearRect(0, 0, 400, 400);
                gc.setFill(Color.BLACK);
                gc.setFont(javafx.scene.text.Font.font(50));
                //import javafx.scene.*;  //Basic scene classes 
                //import javafx.scene.layout.*;  //Layout managers like FlowPane, GridPane, etc.
                //import javafx.scene.text.*;           // Text-related classes, like Font
                gc.fillText(st, 60, 40);
                st = st.substring(1) + st.charAt(0); // Move first character to end
                try {
                    Thread.sleep(500);
                } catch (InterruptedException e) {
                    System.out.println(e);
                }
            }
        } else { // Scroll right
            for (;;) {
                gc.clearRect(0, 0, 400, 400);
                gc.setFill(Color.BLACK);
                gc.setFont(javafx.scene.text.Font.font(50));
                gc.fillText(st, 60, 40);
                st = st.charAt(st.length() - 1) + st.substring(0, st.length() - 1); // Move last character to start
                try {
                    Thread.sleep(500);
                } catch (InterruptedException e) {
                    System.out.println(e);
                }
            }
        }
    }
}

public class JavaFx8 extends Application {
    public void start(Stage ps) {
        ps.setTitle("LEFT-RIGHT-LEFT");

        Label lb = new Label("INPUT TEXT: ");
        TextField tf = new TextField();

        // Using RadioButton for direction selection
        RadioButton left = new RadioButton("LEFT");
        RadioButton right = new RadioButton("RIGHT");
        ToggleGroup directionGroup = new ToggleGroup();
        left.setToggleGroup(directionGroup);
        right.setToggleGroup(directionGroup);

        Button m = new Button("DISPLAY");

        Canvas c = new Canvas(400, 400);
        GraphicsContext gc = c.getGraphicsContext2D();
        gc.setLineWidth(10.0);

        m.setOnAction(new EventHandler<ActionEvent>() {
            public void handle(ActionEvent ae) {
                String text = tf.getText();
                if (left.isSelected()) {
                    new NewThread(gc, text, 0);
                } else if (right.isSelected()) {
                    new NewThread(gc, text, 1);
                }
            }
        });

        FlowPane root = new FlowPane();
        root.setHgap(10);
        root.setVgap(10);
        root.getChildren().addAll(lb, tf, left, right, m, c);

        Scene myScene = new Scene(root, 700, 300);
        ps.setScene(myScene);
        ps.show();
    }

    public static void main(String[] args) {
        launch(args);
    }
}
