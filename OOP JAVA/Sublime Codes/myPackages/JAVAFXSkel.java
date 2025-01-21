import javafx.application;
import javafx.scene;
import javafx.stage;
import javafx.scene.layout;

public class JAVAFXSkel extends Application
{
	public static void main(String[] args) {
		System.out.println("Launching JavaFx application.");
		launch(args);
	}
	public void init()
	{
		System.out.println("Inside the init method");
	}
	public void start(Stage myStage)
	{
		System.out.println("Inside the start() method");
		myStage.setTitle("JavaFX skeleton");
		FlowPane rootNode = new FlowPane();
		Scene myScene = new Scene(rootNode,300,200);
		myStage.setScene(myScene);
		myStage.show();
	}
	public void stop()
	{
		System.out.println("Inside the stop() method");
	}
}