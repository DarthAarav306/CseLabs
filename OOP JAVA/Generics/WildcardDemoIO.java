import java.util.Scanner;

class NumericFns<T extends Number> {
    private T num;

    public NumericFns(T num) {
        this.num = num;
    }

    public double reciprocal() {
        return 1 / num.doubleValue();
    }

    public double fraction() {
        return num.doubleValue() - num.intValue();
    }

    public boolean absEqual(NumericFns<?> ob) {
        if (Math.abs(num.doubleValue()) == Math.abs(ob.num.doubleValue())) {
            return true;
        }
        return false;
    }
}

public class WildcardDemoIO {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);

        // Take Integer input from the user
        System.out.print("Enter an integer: ");
        int intVal = scanner.nextInt();
        NumericFns<Integer> intOb = new NumericFns<>(intVal);

        // Take Double input from the user
        System.out.print("Enter a double: ");
        double doubleVal = scanner.nextDouble();
        NumericFns<Double> doubleOb = new NumericFns<>(doubleVal);

        // Take Float input from the user
        System.out.print("Enter a float: ");
        float floatVal = scanner.nextFloat();
        NumericFns<Float> floatOb = new NumericFns<>(floatVal);

        // Display the reciprocal and fraction
        System.out.println("Reciprocal of intOb: " + intOb.reciprocal());
        System.out.println("Fraction of doubleOb: " + doubleOb.fraction());

        // Checking if absolute values are equal using wildcard
        if (intOb.absEqual(doubleOb)) {
            System.out.println("Absolute values of intOb and doubleOb are equal.");
        } else {
            System.out.println("Absolute values of intOb and doubleOb are not equal.");
        }

        if (intOb.absEqual(floatOb)) {
            System.out.println("Absolute values of intOb and floatOb are equal.");
        } else {
            System.out.println("Absolute values of intOb and floatOb are not equal.");
        }

        scanner.close();
    }
}
