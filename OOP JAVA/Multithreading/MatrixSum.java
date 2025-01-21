import java.util.Scanner;

class RowSumCalculator implements Runnable {
    private int[] row;
    private int rowIndex;
    private int[] partialSums;
    Thread t;

    RowSumCalculator(int[] row, int rowIndex, int[] partialSums) {
        this.row = row;
        this.rowIndex = rowIndex;
        this.partialSums = partialSums;
        t = new Thread(this);
        t.start();
    }

    // Override
    public void run() {
        int sum = 0;
        for (int i = 0; i < row.length; i++) {
            sum += row[i];
        }
        partialSums[rowIndex] = sum;
        System.out.println("Sum of row " + rowIndex + " is " + sum);
    }
}

public class MatrixSum {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        System.out.println("Enter number of rows:");
        int numRows = scanner.nextInt();
        System.out.println("Enter number of columns:");
        int numCols = scanner.nextInt();
        int[][] matrix = new int[numRows][numCols];
        System.out.println("Enter matrix elements:");
        for (int i = 0; i < numRows; i++) {
            for (int j = 0; j < numCols; j++) {
                matrix[i][j] = scanner.nextInt();
            }
        }

        int[] partialSums = new int[numRows];
        RowSumCalculator[] rowCalculators = new RowSumCalculator[numRows];

        // Create and start a thread for each row, handled inside the RowSumCalculator
        for (int i = 0; i < numRows; i++) {
            rowCalculators[i] = new RowSumCalculator(matrix[i], i, partialSums);
        }

        for (int i = 0; i < numRows; i++) {
            try {
                rowCalculators[i].t.join(); // Wait for each thread to finish
            } catch (InterruptedException e) {
                e.printStackTrace();
            }
        }

        int totalSum = 0;
        for (int i = 0; i < partialSums.length; i++) {
            totalSum += partialSums[i];
        }

        System.out.println("Total sum of matrix: " + totalSum);
    }
}
