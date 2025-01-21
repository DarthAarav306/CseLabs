import java.util.Scanner;

class Matrix {
    Scanner scanner = new Scanner(System.in);
    int[][] matrix;
    int m, n;

    // Constructor to initialize the matrix
    Matrix(int m, int n) {
        this.m = m;
        this.n = n;
        matrix = new int[m][n];
        System.out.println("Enter elements:");
        for (int i = 0; i < m; i++) { // Iterate over rows (m)
            for (int j = 0; j < n; j++) { // Iterate over columns (n)
                matrix[i][j] = scanner.nextInt();
            }
        }
    }

    // Display the matrix
    void display() {
        System.out.println("Matrix is:");
        for (int i = 0; i < m; i++) { // Iterate over rows (m)
            for (int j = 0; j < n; j++) { // Iterate over columns (n)
                System.out.print(matrix[i][j] + " ");
            }
            System.out.println();
        }
    }
}

// Class to calculate row sum using a separate thread
class RowSum implements Runnable {
    Thread t;
    int[] row;
    int rowSum = 0;
    int rowNum;

    // Constructor to initialize row, column size, and row number
    RowSum(int[] row, int rowNum) {
        this.row = row;
        this.rowNum = rowNum;
        t = new Thread(this);
        t.start();
    }

    public void run() {
        for (int ele : row) {
            rowSum += ele;
        }
        System.out.println("Row sum of row " + rowNum + " is " + rowSum);
    }
}

// Main class
public class MatrixSumNew {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        int m, n;

        // Get matrix dimensions from user
        System.out.println("Enter number of rows and columns:");
        m = scanner.nextInt();
        n = scanner.nextInt();

        // Initialize and display the matrix
        Matrix matrix = new Matrix(m, n);
        matrix.display();

        // Calculate row sums
        int sum = 0;
        RowSum[] rowSums = new RowSum[m];
        for (int i = 0; i < m; i++) {
            rowSums[i] = new RowSum(matrix.matrix[i], i);
        }

        // Wait for all threads to finish
        try {
            for (int i = 0; i < m; i++) {
                rowSums[i].t.join();
            }
        } catch (InterruptedException e) {
            e.printStackTrace();
        }

        // Calculate total matrix sum
        for (int i = 0; i < m; i++) {
            sum += rowSums[i].rowSum;
        }
        System.out.println("Sum of matrix is: " + sum);
    }
}
