class Counter{
    static int count=0;
    Counter()
    {
        count++;
    }
    void showCount()
    {
        System.out.println("Count is:- "+count);
    }
}
class CounterDemo{
    public static void main(String[] args) {
    for(int i=0;i<5;i++)
    {
        Counter c = new Counter();
        c.showCount();
    }
}
}