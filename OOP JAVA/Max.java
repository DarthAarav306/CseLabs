public class Max {
    public static int max(int x, int y, int z) {
        if (x >= y && x >= z) {
            return x;
        } else if (y >= x && y >= z) {
            return y;
        } else {
            return z;
        }
    }

    public static void main(String[] args) {
        int maxVal = max(10, 20, 30);
        System.out.println("Max value (using if-else-if): " + maxVal);
    }
}
