import javafx.application.Application;
import javafx.scene.Scene;
import javafx.scene.canvas.Canvas;
import javafx.scene.canvas.GraphicsContext;
import javafx.scene.control.Button;
import javafx.scene.control.CheckBox;
import javafx.scene.control.Label;
import javafx.scene.control.TextField;
import javafx.scene.layout.GridPane;
import javafx.stage.Stage;
import javafx.event.ActionEvent;
import javafx.event.EventHandler;
import javafx.scene.paint.Color;

public class JavaFx7 extends Application {
   public void start(Stage primaryStage) {
       Label nameLabel = new Label("Name:");
       TextField nameField = new TextField();
      
       Label ageLabel = new Label("Age:");
       TextField ageField = new TextField();


       Label qualificationLabel = new Label("Qualification:");
       TextField qualificationField = new TextField();


       // Checkboxes for languages
       Label languagesLabel = new Label("Languages Spoken:");
       CheckBox englishBox = new CheckBox("English");
       CheckBox frenchBox = new CheckBox("French");
       CheckBox germanBox = new CheckBox("German");
       CheckBox hindiBox = new CheckBox("Hindi");


       // Button to submit the resume details
       Button submitButton = new Button("Submit");


       // Canvas to display the resume
       Canvas resumeCanvas = new Canvas(400, 400);
       GraphicsContext gc = resumeCanvas.getGraphicsContext2D();
      
       // Action to be taken when the "Submit" button is clicked
       submitButton.setOnAction(new EventHandler<ActionEvent>() {
           @Override
           public void handle(ActionEvent e) {
               // Clear the canvas
               gc.clearRect(0, 0, resumeCanvas.getWidth(), resumeCanvas.getHeight());


               // Draw text on the canvas to display resume details
               gc.setFill(Color.BLACK);
               gc.fillText("Resume", 50, 50);
               gc.fillText("Name: " + nameField.getText(), 50, 80);
               gc.fillText("Age: " + ageField.getText(), 50, 110);
               gc.fillText("Qualification: " + qualificationField.getText(), 50, 140);
              
               // Display selected languages
               gc.fillText("Languages Spoken:", 50, 170);
               int yPos = 200;
               if (englishBox.isSelected()) {
                   gc.fillText("- English", 50, yPos);
                   yPos += 30;
               }
               if (frenchBox.isSelected()) {
                   gc.fillText("- French", 50, yPos);
                   yPos += 30;
               }
               if (germanBox.isSelected()) {
                   gc.fillText("- German", 50, yPos);
                   yPos += 30;
               }
               if (hindiBox.isSelected()) {
                   gc.fillText("- Hindi", 50, yPos);
               }
           }
       });


       // Set up the layout using GridPane
       GridPane gridPane = new GridPane();
       gridPane.setVgap(10);
       gridPane.setHgap(10);
       gridPane.add(nameLabel, 0, 0);
       gridPane.add(nameField, 1, 0);
       gridPane.add(ageLabel, 0, 1);
       gridPane.add(ageField, 1, 1);
       gridPane.add(qualificationLabel, 0, 2);
       gridPane.add(qualificationField, 1, 2);
       gridPane.add(languagesLabel, 0, 3);
       gridPane.add(englishBox, 1, 3);
       gridPane.add(frenchBox, 1, 4);
       gridPane.add(germanBox, 1, 5);
       gridPane.add(hindiBox, 1, 6);
       gridPane.add(submitButton, 1, 7);
       gridPane.add(resumeCanvas, 0, 8, 2, 1);


       // Set up the scene and the stage
       Scene scene = new Scene(gridPane, 500, 600);
       primaryStage.setTitle("Resume Creator");
       primaryStage.setScene(scene);
       primaryStage.show();
   }


   public static void main(String[] args) {
       launch(args);
   }
}
