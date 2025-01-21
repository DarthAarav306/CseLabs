import java.util.Scanner;
// Thread to check uniqueness of matrix elements

class UniqueCheck implements Runnable {
    int[][] matrix;
    boolean unique = true;
    Thread t;

    UniqueCheck(int[][] matrix) {
        this.matrix = matrix;
        t = new Thread(this, "UniqueCheck");
        t.start(); // Starting the thread inside the constructor
    }

    @Override
    public void run() {
        int n = matrix.length;
        int[] flatArray = new int[n * n];
        int index = 0;

        // Flatten the matrix into a 1D array
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                flatArray[index++] = matrix[i][j];
            }
        }

        // Check for duplicates
        for (int i = 0; i < flatArray.length; i++) {
            for (int j = i + 1; j < flatArray.length; j++) {
                if (flatArray[i] == flatArray[j]) {
                    unique = false;
                    break;
                }
            }
        }

        if (!unique) {
            System.out.println("Matrix elements are not unique.");
        } else {
            System.out.println("Matrix elements are unique.");
        }
    }

    public boolean isUnique() {
        return unique;
    }
}

// Thread to calculate row sums
class RowSum implements Runnable {
    int[][] matrix;
    int[] rowSums;
    Thread t;

    RowSum(int[][] matrix) {
        this.matrix = matrix;
        rowSums = new int[matrix.length];
        t = new Thread(this, "RowSum");
        t.start(); // Starting the thread inside the constructor
    }

    @Override
    public void run() {
        for (int i = 0; i < matrix.length; i++) {
            int sum = 0;
            for (int j = 0; j < matrix[i].length; j++) {
                sum += matrix[i][j];
            }
            rowSums[i] = sum;
            System.out.println("Row " + i + " sum: " + sum);
        }
    }

    public int[] getRowSums() {
        return rowSums;
    }
}

// Thread to calculate column sums
class ColSum implements Runnable {
    int[][] matrix;
    int[] colSums;
    Thread t;

    ColSum(int[][] matrix) {
        this.matrix = matrix;
        colSums = new int[matrix[0].length];
        t = new Thread(this, "ColSum");
        t.start(); // Starting the thread inside the constructor
    }

    @Override
    public void run() {
        for (int i = 0; i < matrix[0].length; i++) {
            int sum = 0;
            for (int j = 0; j < matrix.length; j++) {
                sum += matrix[j][i];
            }
            colSums[i] = sum;
            System.out.println("Column " + i + " sum: " + sum);
        }
    }

    public int[] getColSums() {
        return colSums;
    }
}

// Thread to calculate principal diagonal sum
class PrincipalDiagonalSum implements Runnable {
    int[][] matrix;
    int sum = 0;
    Thread t;

    PrincipalDiagonalSum(int[][] matrix) {
        this.matrix = matrix;
        t = new Thread(this, "PrincipalDiagonalSum");
        t.start(); // Starting the thread inside the constructor
    }

    @Override
    public void run() {
        for (int i = 0; i < matrix.length; i++) {
            sum += matrix[i][i];
        }
        System.out.println("Principal Diagonal sum: " + sum);
    }

    public int getSum() {
        return sum;
    }
}

// Thread to calculate secondary diagonal sum
class SecondaryDiagonalSum implements Runnable {
    int[][] matrix;
    int sum = 0;
    Thread t;

    SecondaryDiagonalSum(int[][] matrix) {
        this.matrix = matrix;
        t = new Thread(this, "SecondaryDiagonalSum");
        t.start(); // Starting the thread inside the constructor
    }

    @Override
    public void run() {
        int n = matrix.length;
        for (int i = 0; i < n; i++) {
            sum += matrix[i][n - 1 - i];
        }
        System.out.println("Secondary Diagonal sum: " + sum);
    }

    public int getSum() {
        return sum;
    }
}

// Main class to check for magic square
public class MagicSquareChecker {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);

        // Input the matrix size and elements
        System.out.println("Enter the size of the square matrix:");
        int n = scanner.nextInt();
        int[][] matrix = new int[n][n];

        System.out.println("Enter the matrix elements:");
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                matrix[i][j] = scanner.nextInt();
            }
        }

        // Create Runnable objects
        UniqueCheck uniqueCheck = new UniqueCheck(matrix);
        RowSum rowSum = new RowSum(matrix);
        ColSum colSum = new ColSum(matrix);
        PrincipalDiagonalSum principalDiagonalSum = new PrincipalDiagonalSum(matrix);
        SecondaryDiagonalSum secondaryDiagonalSum = new SecondaryDiagonalSum(matrix);

        // Wait for threads to complete
        try {
            uniqueCheck.t.join();
            rowSum.t.join();
            colSum.t.join();
            principalDiagonalSum.t.join();
            secondaryDiagonalSum.t.join();
        } catch (InterruptedException e) {
            e.printStackTrace();
        }

        // Magic Square check based on sums from the threads
        int magicSum = principalDiagonalSum.getSum();
        boolean isMagicSquare = true;

        // Check row sums
        for (int sum : rowSum.getRowSums()) {
            if (sum != magicSum) {
                isMagicSquare = false;
                break;
            }
        }

        // Check column sums
        for (int sum : colSum.getColSums()) {
            if (sum != magicSum) {
                isMagicSquare = false;
                break;
            }
        }

        // Check secondary diagonal sum
        if (secondaryDiagonalSum.getSum() != magicSum) {
            isMagicSquare = false;
        }

        // Check uniqueness
        if (!uniqueCheck.isUnique()) {
            isMagicSquare = false;
        }

        // Output whether it's a magic square or not
        if (isMagicSquare) {
            System.out.println("The matrix is a Magic Square!");
        } else {
            System.out.println("The matrix is NOT a Magic Square.");
        }
    }
}
