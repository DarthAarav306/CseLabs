import javafx.application.*;
import javafx.scene.*;
import javafx.stage.*;
import javafx.scene.layout.*;
import javafx.scene.control.*;
import javafx.event.*;
import javafx.geometry.*;
import javafx.scene.shape.*;
import javafx.scene.canvas.*;
import javafx.scene.paint.*;
import javafx.scene.text.*;

public class DirectDrawDemo extends Application
{
	int colorIdx = 0;
	public static void main(String[] args) {
		launch(args);
	}

	public void start(Stage myStage)
	{
		Color[] colors = {Color.RED,Color.BLUE,Color.GREEN,Color.BLACK};
		myStage.setTitle("Draw Directly to Canvas");
		FlowPane rootNode = new FlowPane();
		rootNode.setAlignment(Pos.CENTER);
		Scene myScene = new Scene(rootNode,400,450);
		myStage.setScene(myScene);
		Canvas myCanvas = new Canvas(400,400);
		GraphicsContext gc = myCanvas.getGraphicsContext2D();
		Button btnChangeColor = new Button("Change Color");
		btnChangeColor.setOnAction(new EventHandler<ActionEvent>()
		{
			public void handle(ActionEvent ae)
			{
				gc.setStroke(colors[colorIdx]);
				gc.setFill(colors[colorIdx]);
				gc.strokeLine(0,0,200,200);
				gc.fillText("This is draw on the canvas",60,50);
				gc.fillRect(100,320,300,40);
				colorIdx++;
				if(colorIdx==colors.length)
				{
					colorIdx = 0;
				}
			}
		});
		gc.strokeLine(0,0,200,200);
		gc.strokeOval(100,100,200,200);
		gc.strokeRect(0,200,50,200);
		gc.fillOval(0,0,20,20);
		gc.fillRect(100,320,300,40);
		gc.setFont(new Font(20));
		gc.fillText("This is draw on the canvas.",60,50);
		rootNode.getChildren().addAll(myCanvas,btnChangeColor);
		myStage.show();
	}
}