package org.example;

import javafx.event.ActionEvent;
import javafx.fxml.FXML;
import javafx.scene.control.Button;
import javafx.scene.control.Label;
import javafx.scene.paint.Color;

public class Controller {

    @FXML
    private Label label;

    @FXML
    private Button redButton;

    @FXML
    private Button greenButton;

    @FXML
    private void handleRedButton(ActionEvent event) {
        label.setText("Red button clicked!");
        label.setTextFill(Color.RED);
    }

    @FXML
    private void handleGreenButton(ActionEvent event) {
        label.setText("Green button clicked!");
        label.setTextFill(Color.GREEN);
    }
}
