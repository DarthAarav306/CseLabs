import javafx.application.*;
import javafx.scene.*;
import javafx.scene.layout.*;
import javafx.stage.*;
import javafx.scene.control.*;
import javafx.event.*;
import javafx.scene.image.*;
import javafx.scene.canvas.*;

public class Practice7 extends Application
{
	public static void main(String[] args) {
		launch(args);
	}
	
	public void start(Stage myStage)
	{
		myStage.setTitle("Resume");
		FlowPane rootNode = new FlowPane(10,10);
		Scene scene = new Scene(rootNode,500,500);
		Label nameLabel = new Label("Enter name:- ");
		Label ageLabel = new Label("Enter age:- ");
		TextField nameTf = new TextField();
		TextField ageTf = new TextField();
		CheckBox englishCb = new CheckBox("English");
		CheckBox hindiCb = new CheckBox("Hindi");
		CheckBox spanishCb = new CheckBox("Spanish");
		Button button  = new Button("Submit");
		Label resumeLabel = new Label();
		button.setOnAction(new EventHandler<ActionEvent>()
		{
			public void handle(ActionEvent ae)
			{
				String resume = "Resume is:- \n";
				resume+="Name:- "+nameTf.getText() + "\n";
				resume+="Age:- "+ ageTf.getText() + "\n";
				resume+= "Languages spoken:- ";
				if(englishCb.isSelected())
				{
					resume+="English ";
				}
				if(hindiCb.isSelected())
				{
					resume+="Hindi ";
				}
				if(spanishCb.isSelected())
				{
					resume+="Spanish ";
				}
				resumeLabel.setText(resume);
			}
		});
		rootNode.getChildren().addAll(nameLabel,nameTf,ageLabel,ageTf,englishCb,hindiCb,spanishCb,button,resumeLabel);
		myStage.setScene(scene);
		myStage.show();
	}
}
