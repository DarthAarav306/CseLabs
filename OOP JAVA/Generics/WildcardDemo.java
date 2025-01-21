// A generic class that operates on Number types
class NumericFns<T extends Number> {
    private T num; // num is an object of a type that extends Number

    // Constructor
    public NumericFns(T num) {
        this.num = num;
    }

    // Return the reciprocal of num
    public double reciprocal() {
        return 1 / num.doubleValue();
    }

    // Return the fractional component of num
    public double fraction() {
        return num.doubleValue() - num.intValue();
    }

    // Demonstrate the use of a wildcard argument
    // Check if the absolute values of two numbers are the same
    public boolean absEqual(NumericFns<?> ob) {
        if (Math.abs(num.doubleValue()) == Math.abs(ob.num.doubleValue())) {
            return true;
        }
        return false;
    }
}

// Demonstrating the use of NumericFns with wildcards
public class WildcardDemo {
    public static void main(String[] args) {
        NumericFns<Integer> intOb = new NumericFns<>(6);
        NumericFns<Double> doubleOb = new NumericFns<>(-6.0);
        NumericFns<Float> floatOb = new NumericFns<>(-6.0f);

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
    }
}
