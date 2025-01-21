import java.util.Scanner;

class Customer{
    int custid;
    String name;
    double credlim;
    Customer(int custid,String name, double credlim)
    {
        this.custid = custid;
        this.name = name;
        this.credlim = credlim;
    }
}
class Customerdemo{
    public static void main(String[] args) {
        String name;
        int custid;
        double credlim;
        Scanner scanner = new Scanner(System.in);
        Customer[] customers = new Customer[5];
        for(int i=0;i<5;i++)
        {
            System.out.println("Ebter details for customer "+(i+1)+":-");
            System.out.println("Enter Id");
            custid = scanner.nextInt();
            
        }
    }
}