// Import necessary JavaFX packages
import javafx.animation.KeyFrame;
import javafx.animation.Timeline;
import javafx.application.Application;
import javafx.scene.Scene;
import javafx.scene.canvas.Canvas;
import javafx.scene.canvas.GraphicsContext;
import javafx.scene.control.Button;
import javafx.scene.control.Label;
import javafx.scene.control.TextField;
import javafx.scene.layout.FlowPane;
import javafx.scene.paint.Color;
import javafx.scene.text.Font;
import javafx.stage.Stage;
import javafx.util.Duration;

import java.time.LocalTime;

public class JavaFx10 extends Application {
    private Canvas canvas;
    private GraphicsContext gc;
    private Label digitalClock;
    private boolean pauseRealTime = false; // Flag to control real-time update

    public static void main(String[] args) {
        launch(args);
    }

    @Override
    public void start(Stage primaryStage) {
        primaryStage.setTitle("Real-Time Analog and Digital Clock");

        // Digital Clock Label
        digitalClock = new Label();
        digitalClock.setFont(Font.font("Verdana", 24));
        digitalClock.setTextFill(Color.DARKBLUE);

        // Text fields to manually set the time
        TextField hourField = new TextField();
        hourField.setPromptText("Hour");
        TextField minuteField = new TextField();
        minuteField.setPromptText("Minute");
        TextField secondField = new TextField();
        secondField.setPromptText("Second");

        // Set Time Button
        Button setTimeButton = new Button("Set Time");
        
        // Canvas for Analog Clock
        canvas = new Canvas(400, 400);
        gc = canvas.getGraphicsContext2D();

        // Set Time Button Action (Update time on analog and digital clock)
        setTimeButton.setOnAction(e -> {
            try {
                int hours = Integer.parseInt(hourField.getText());
                int minutes = Integer.parseInt(minuteField.getText());
                int seconds = Integer.parseInt(secondField.getText());
                pauseRealTime = true; // Pause real-time update
                updateClocks(LocalTime.of(hours, minutes, seconds));
            } catch (Exception ex) {
                digitalClock.setText("Invalid Time Input");
            }
        });

        // Layout
        FlowPane root = new FlowPane(10, 10);
        root.getChildren().addAll(digitalClock, hourField, minuteField, secondField, setTimeButton, canvas);

        // Set up the real-time clock update using Timeline
        Timeline timeline = new Timeline(new KeyFrame(Duration.seconds(1), event -> {
            if (!pauseRealTime) { // Only update in real time if not paused
                LocalTime currentTime = LocalTime.now();
                updateClocks(currentTime);
            }
        }));
        timeline.setCycleCount(Timeline.INDEFINITE);
        timeline.play();

        // Set up the scene
        Scene scene = new Scene(root, 500, 500);
        primaryStage.setScene(scene);
        primaryStage.show();
    }

    // Method to update both analog and digital clocks
    private void updateClocks(LocalTime time) {
        int hours = time.getHour();
        int minutes = time.getMinute();
        int seconds = time.getSecond();

        // Update Digital Clock
        digitalClock.setText(String.format("Digital Clock: %02d:%02d:%02d", hours, minutes, seconds));

        // Update Analog Clock
        drawAnalogClock(hours, minutes, seconds);
    }

    // Method to draw the analog clock
    private void drawAnalogClock(int hours, int minutes, int seconds) {
        gc.clearRect(0, 0, canvas.getWidth(), canvas.getHeight());

        // Clock face
        gc.setStroke(Color.BLACK);
        gc.strokeOval(50, 50, 300, 300);

        // Draw hour, minute, and second hands based on the time
        double centerX = 200;
        double centerY = 200;

        // Hour hand
        double hourAngle = Math.toRadians((hours % 12 + minutes / 60.0) * 30 - 90);
        gc.setStroke(Color.BLUE);
        gc.setLineWidth(6);
        gc.strokeLine(centerX, centerY, centerX + 80 * Math.cos(hourAngle), centerY + 80 * Math.sin(hourAngle));

        // Minute hand
        double minuteAngle = Math.toRadians((minutes + seconds / 60.0) * 6 - 90);
        gc.setStroke(Color.GREEN);
        gc.setLineWidth(4);
        gc.strokeLine(centerX, centerY, centerX + 120 * Math.cos(minuteAngle), centerY + 120 * Math.sin(minuteAngle));

        // Second hand
        double secondAngle = Math.toRadians(seconds * 6 - 90);
        gc.setStroke(Color.RED);
        gc.setLineWidth(2);
        gc.strokeLine(centerX, centerY, centerX + 140 * Math.cos(secondAngle), centerY + 140 * Math.sin(secondAngle));
    }
}
