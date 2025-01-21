import javafx.application.Application;
import javafx.scene.Scene;
import javafx.scene.canvas.Canvas;
import javafx.scene.canvas.GraphicsContext;
import javafx.scene.paint.Color;
import javafx.stage.Stage;

public class DirectDrawDemo1 extends Application {
    public static void main(String[] args) {
        launch(args);
    }

    @Override
    public void start(Stage primaryStage) {
        // Canvas and graphics context setup
        Canvas canvas = new Canvas(300, 500);
        GraphicsContext gc = canvas.getGraphicsContext2D();

        // Body (Yellow Rectangle with Rounded Corners)
        gc.setFill(Color.YELLOW);
        gc.fillRoundRect(75, 100, 150, 250, 50, 50);

        // Goggles Strap (Black Rectangle)
        gc.setFill(Color.BLACK);
        gc.fillRect(75, 180, 150, 20);

        // Goggles (Gray Circles)
        gc.setFill(Color.GRAY);
        gc.fillOval(100, 160, 50, 50); // Left goggle
        gc.fillOval(150, 160, 50, 50); // Right goggle

        // Eyes (White Circles with Black Pupils)
        gc.setFill(Color.WHITE);
        gc.fillOval(110, 170, 30, 30); // Left eye
        gc.fillOval(160, 170, 30, 30); // Right eye

        gc.setFill(Color.BLACK);
        gc.fillOval(120, 180, 10, 10); // Left pupil
        gc.fillOval(170, 180, 10, 10); // Right pupil

        // Mouth (Basic Smiley Line)
        gc.setStroke(Color.BLACK);
        gc.setLineWidth(2);
        gc.strokeLine(120, 250, 180, 250); // Simple straight mouth

        // Overalls (Blue Rectangle)
        gc.setFill(Color.BLUE);
        gc.fillRect(85, 300, 130, 70);

        // Legs (Blue Rectangles)
        gc.fillRect(100, 370, 20, 50); // Left leg
        gc.fillRect(180, 370, 20, 50); // Right leg

        // Shoes (Black Rectangles)
        gc.setFill(Color.BLACK);
        gc.fillRect(95, 420, 30, 10); // Left shoe
        gc.fillRect(175, 420, 30, 10); // Right shoe

        // Arms (Yellow Rectangles)
        gc.setFill(Color.YELLOW);
        gc.fillRect(40, 200, 30, 70); // Left arm
        gc.fillRect(230, 200, 30, 70); // Right arm

        // Hands (Black Circles)
        gc.setFill(Color.BLACK);
        gc.fillOval(35, 260, 40, 40); // Left hand
        gc.fillOval(225, 260, 40, 40); // Right hand

        // Add canvas to scene
        Scene scene = new Scene(new javafx.scene.layout.Pane(canvas), 300, 500);
        primaryStage.setTitle("Minion Drawing");
        primaryStage.setScene(scene);
        primaryStage.show();
    }
}
