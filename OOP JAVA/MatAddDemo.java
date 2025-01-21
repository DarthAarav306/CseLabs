import java.util.Scanner;

class MatAdd {
    int m, n;

    int[][] inputMat() {
        Scanner scanner = new Scanner(System.in);
        System.out.println("Enter number of rows: ");
        this.m = scanner.nextInt();
        System.out.println("Enter number of columns: ");
        this.n = scanner.nextInt();
        int[][] Matrix = new int[m][n];
        
        System.out.println("Enter matrix elements: ");
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                Matrix[i][j] = scanner.nextInt();
            }
        }

        // Display the matrix
        System.out.println("Matrix:");
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                System.out.print(Matrix[i][j] + " ");
            }
            System.out.println();
        }
        return Matrix;
    }

    int[][] AddMat(int[][] mat1, int[][] mat2) {
        // Check if the matrices have the same dimensions
        if (mat1.length != mat2.length || mat1[0].length != mat2[0].length) {
            System.out.println("Matrices cannot be added due to different dimensions.");
            return null; // Return null if matrices cannot be added
        }

        int m = mat1.length;
        int n = mat1[0].length;
        int[][] mat3 = new int[m][n];

        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                mat3[i][j] = mat1[i][j] + mat2[i][j];
            }
        }
        return mat3;
    }

    void displayMatrix(int[][] matrix) {
        if (matrix == null) {
            return;
        }
        System.out.println("Resultant Matrix:");
        for (int i = 0; i < matrix.length; i++) {
            for (int j = 0; j < matrix[0].length; j++) {
                System.out.print(matrix[i][j] + " ");
            }
            System.out.println();
        }
    }
}

class MatAddDemo {
    public static void main(String[] args) {
        MatAdd obj1 = new MatAdd();
        int[][] mat1 = obj1.inputMat();

        MatAdd obj2 = new MatAdd();
        int[][] mat2 = obj2.inputMat();

        int[][] mat3 = obj1.AddMat(mat1, mat2);
        if (mat3 != null) {
            obj1.displayMatrix(mat3);
        }
    }
}









