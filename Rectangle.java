public class Rectangle extends Shape {

    private double weight;

    private double height;

    public Rectangle(double weight, double height) {
        this.weight = weight;
        this.height = height;
    }

    @Override
    public void draw() {
        System.out.print("Drawing a rectangle");
    }

    @Override
    public double area() {
        return weight * height;
    }
}
