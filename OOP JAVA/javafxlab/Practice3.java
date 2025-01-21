import javafx.application.*;
import javafx.scene.*;
import javafx.stage.*;
import javafx.scene.layout.*;
import javafx.scene.control.*;
import javafx.geometry.*;
import javafx.event.*;

public class Practice3 extends Application
{
	public static void main(String[] args) {
		launch(args);
	}
	public void start(Stage myStage)
	{
		GridPane rootNode = new GridPane(10,10);
		Scene scene = new Scene(rootNode,500,500);
		myStage.setScene(scene);
		myStage.setTitle("JavaFX Welcome");
		Label label = new Label("Welcome");
		Label userName = new Label("User Name:- ");
		Label passWord = new Label("Password:- ");
		TextField tf = new TextField();
		tf.setPromptText("Enter name");
		PasswordField passwordField = new PasswordField();
		Label welcomeLabel = new Label();
		Button signIn = new Button("Sign in");
		signIn.setOnAction(new EventHandler<ActionEvent>()
		{
			public void handle(ActionEvent ae)
			{
				welcomeLabel.setText("Welcome "+tf.getText());
			}
		});
		rootNode.add(label,0,0);
		rootNode.add(userName,0,1);
		rootNode.add(tf,1,1);
		rootNode.add(passWord,0,2);
		rootNode.add(passwordField,1,2);
		rootNode.add(welcomeLabel,1,3);
		rootNode.add(signIn,3,3);
		myStage.show();
	}
}