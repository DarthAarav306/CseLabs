import javafx.application.*;
import javafx.scene.*;
import javafx.stage.*;
import javafx.scene.layout.*;
import javafx.scene.control.*;
import javafx.geometry.*;
import javafx.event.*;

public class Practice2 extends Application {
    public void start(Stage myStage) {
        myStage.setTitle("Multiplication Tables");
        FlowPane rootNode = new FlowPane(10, 10);
        rootNode.setAlignment(Pos.CENTER);
        Scene scene = new Scene(rootNode, 200, 200);
        myStage.setScene(scene);
        Label label = new Label("Enter integer:");
        TextField tf = new TextField();
        tf.setPromptText("Enter an integer here");
        Label tableLabel = new Label();
        Button btn = new Button("Submit");
        btn.setOnAction(new EventHandler<ActionEvent>() {
            public void handle(ActionEvent ae) {
            int n = Integer.parseInt(tf.getText());
            String table = "Table is:- \n";
            for(int i=0;i<10;i++)
            {
                table+= n+"*"+i+"="+n*i+"\n";
            }
            tableLabel.setText(table);            
        }}
        );

        // Adding components to the root node
        rootNode.getChildren().addAll(label, tf, btn, tableLabel);
        
        myStage.show();
    }

    public static void main(String[] args) {
        launch(args);
    }
}

