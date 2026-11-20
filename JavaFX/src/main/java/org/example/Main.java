package org.example;


import javafx.application.Application;
import javafx.scene.Scene;
import javafx.scene.control.Button;
import javafx.scene.control.Label;
import javafx.scene.layout.VBox;
import javafx.stage.Stage;

public class Main extends Application {

    @Override
    public void start(Stage primaryStage) {
        // 1. Create a VBox as the root container
        VBox root = new VBox();

        // 2. Add two Label components
        Label welcomeLabel = new Label("Welcome to the App");
        Label instructionLabel = new Label("Please press the button below");

        // 3. Add one Button with the text "Start"
        Button startButton = new Button("Start");

        // 4. Add all components to the VBox
        root.getChildren().addAll(welcomeLabel, instructionLabel, startButton);

        // 5. Create a Scene with size 300 × 200 and set it on the Stage
        Scene scene = new Scene(root, 300, 200);

        primaryStage.setTitle("Simple JavaFX App");
        primaryStage.setScene(scene);

        // 6. Display the Stage
        primaryStage.show();
    }

    public static void main(String[] args) {
        launch(args);
    }
}
