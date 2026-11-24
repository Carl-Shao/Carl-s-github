# SceneBuilder Conversion Activity

A JavaFX version of the "Red / Green button" task, built with FXML and a
controller instead of writing the UI entirely in Java code.

## Project structure

```
scenebuilder-activity/
├── pom.xml
└── src/main/
    ├── java/org/example/
    │   ├── Main.java          # starts the app, loads main.fxml
    │   └── Controller.java    # @FXML fields + button handlers
    └── resources/org/example/
        └── main.fxml          # the SceneBuilder layout
```

## Requirements covered

- Root `VBox` centered with `Alignment = CENTER` and spacing/padding.
- One centered `Label` (`fx:id="label"`).
- Two buttons below the label (`fx:id="redButton"` and
  `fx:id="greenButton"`), labeled **Red** and **Green**.
- `Red` sets the label text to `Red button clicked!` and the text fill to
  `Color.RED`.
- `Green` sets the label text to `Green button clicked!` and the text fill to
  `Color.GREEN`.

`Controller.java` injects all three controls with `@FXML` and uses FXML event
handler methods (`onAction="#handleRedButton"` in the FXML). If you prefer, the
same thing can be done in an `initialize()` method with
`redButton.setOnAction(e -> ...)`.

## Open the layout in SceneBuilder

Open `src/main/resources/org/example/main.fxml` in SceneBuilder. You should see:

1. A `VBox` root with alignment `CENTER`.
2. A `Label` with the **fx:id** `label`.
3. An `HBox` containing the two buttons, each with an **fx:id** and an
   `On Action` handler:

   | Button | fx:id         | On Action            |
   |--------|---------------|----------------------|
   | Red    | `redButton`   | `handleRedButton`    |
   | Green  | `greenButton` | `handleGreenButton`  |

If you rebuild the screen from scratch in SceneBuilder, drag a `VBox`, set
**Alignment → CENTER**, add the label and buttons, then set the fx:id values in
the **Code** section of the Inspector and pick the handler methods under
**On Action**.

## Run

Requires JDK 17+ and Maven.

```bash
cd scenebuilder-activity
mvn clean javafx:run
```

Click **Red** or **Green** to change the label text and color.
