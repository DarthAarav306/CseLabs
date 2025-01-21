public class TriangularArray {
    public static void main(String[] args) {
        // Step 1: Create a "triangular" two-dimensional array
        int[][] A = new int[10][];

        // Step 2: Initialize the array where the i-th row has i+1 elements
        for (int i = 0; i < A.length; i++) {
            A[i] = new int[i + 1];
        }

        // Step 3: Fill the array such that A[i][j] = i + j
        for (int i = 0; i < A.length; i++) {
            for (int j = 0; j < A[i].length; j++) {
                A[i][j] = i + j;
            }
        }

        // Step 4: Print the array in a triangular form
        System.out.println("Triangular Array:");
        for (int i = 0; i < A.length; i++) {
            for (int j = 0; j < A[i].length; j++) {
                System.out.print(A[i][j] + " ");
            }
            System.out.println();  // Move to the next line after each row
        }
    }
}
