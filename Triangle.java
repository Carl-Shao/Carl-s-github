import java.util.Scanner;


public class Triangle {
    public static void main(String[] args) {
        Scanner input = new Scanner(System.in);

        // input three side
        System.out.println("Enter side a: ");
        double a = input.nextDouble();
        System.out.println("Enter side b: ");
        double b = input.nextDouble();
        System.out.println("Enter side c: ");
        double c = input.nextDouble();

        // judge these three sides whether they are greater than 0
        if(a <= 0 || b <= 0 || c <= 0) {
            System.out.println("Invalid Side values");
            return;
        }

        if(a + b <= c || b + c <= a || a + c <= b){
            System.out.println("Invalid Side values");
            return;
        }

        // compute the s and area
        double s = (a + b + c) / 2;
        double area = Math.sqrt(s * (s - a) * (s - b) * (s - c));

        // show result
        System.out.println("Side a: " + a);
        System.out.println("Side b: " + b);
        System.out.println("Side c: " + c);
        System.out.printf("Area: %.2f", area);

        input.close();
    }
}
