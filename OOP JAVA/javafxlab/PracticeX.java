//Java Fx: two text field and a button  welcome when clicked displays welcome first name second name

import javafx.application.*;
import javafx.scene.*;
import javafx.stage.*;
import javafx.scene.layout.*;
import javafx.scene.control.*;
import javafx.event.*;


public class PracticeX extends Application
{

	public static void main(String[] args)
	{
		launch(args);
	}
	public void start(Stage myStage)
	{
		myStage.setTitle("JavaFX Lab Exam");
		FlowPane rootNode = new FlowPane(500,500);
		Scene scene = new Scene(rootNode,10,10);
		TextField firstName = new TextField();
		firstName.setPromptText("First Name");
		TextField lastName = new TextField();
		lastName.setPromptText("LastName");
		Button btn = new Button("Enter");
		Label response = new Label();
		btn.setOnAction(new EventHandler<ActionEvent>()
		{
			public void handle(ActionEvent ae)
			{
				response.setText("Welcome "+firstName.getText()+" "+lastName.getText());
			}
		});
		rootNode.getChildren().addAll(firstName,lastName,btn,response);
		myStage.setScene(scene);
		myStage.show();
	}
}