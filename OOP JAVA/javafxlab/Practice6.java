import javafx.application.*;
import javafx.scene.*;
import javafx.scene.layout.*;
import javafx.stage.*;
import javafx.scene.control.*;
import javafx.event.*;
import javafx.scene.image.*;
import javafx.scene.canvas.*;

public class Practice6 extends Application
{
	public static void main(String[] args) {
		launch(args);
	}
	
	public void start(Stage myStage)
	{
		myStage.setTitle("Calculator");
		FlowPane rootNode = new FlowPane(10,10);
		Scene scene = new Scene(rootNode, 500, 500);
		
		Image image = new Image("calculator.png");
		ImageView imv = new ImageView(image);
		
		TextField num1 = new TextField();
		num1.setPromptText("Enter first floating point number");
		
		TextField num2 = new TextField();
		num2.setPromptText("Enter second floating point number");
		
		Button btn = new Button("Calculate", imv);
		
		Canvas canvas = new Canvas(300, 300);
		GraphicsContext gc = canvas.getGraphicsContext2D();
		
		btn.setOnAction(new EventHandler<ActionEvent>() 
		{
			public void handle(ActionEvent ae)
			{
				float n1 = Float.parseFloat(num1.getText());
				float n2 = Float.parseFloat(num2.getText());
				float sum = n1 + n2;
				float diff = n1 - n2;
				float prod = n1 * n2;
				float quotient = n1 / n2;
				
				String s  = "Sum: " + Float.toString(sum);
				String d = "Difference: " + Float.toString(diff);
				String p = "Product: " + Float.toString(prod);
				String q = "Quotient: " + Float.toString(quotient);
				
				// Clear the canvas before displaying results
				gc.clearRect(0, 0, canvas.getWidth(), canvas.getHeight());
				
				// Set adjusted coordinates for better spacing
				gc.fillText(s, 50, 80);
				gc.fillText(d, 50, 110);
				gc.fillText(p, 50, 140);
				gc.fillText(q, 50, 170);
			}
		});
		
		rootNode.getChildren().addAll(num1, num2, btn, canvas);
		myStage.setScene(scene);
		myStage.show();
	}
}
