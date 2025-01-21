
class CurrentThreadDemo {
    public static void main(String[] args) {
        Thread t = Thread.currentThread();
        System.out.println("Current thread:- " + t);
        System.out.println("Name:- " + t.getName());
        t.setName("Aaarav");
        t.setPriority(Thread.MAX_PRIORITY);
        System.out.println("After name change:- ");
        System.out.println("Current thread:- " + t);
        System.out.println("Name:- " + t.getName());
    }
}