/*Create a generic interface Stats with a method double avg() to compute and return the average of numeric values from the 
invoking object. Provide an implementation to this method through a class StatsImpl, with appropriate data member(s). 
This class must also provide another member function compareAvg() that compares the average of any two valid generic 
objects and returns true or false appropriately. Demonstrate instantiation, computation, and comparison of average of 
generic objects inside StatsDemo class by calling the above methods suitably*/

interface Stats<T extends Number>
{
    double avg();
}

public class StatsImpl<T extends Number> implements Stats<T>
{
    T[] arr;
    double avg;
    StatsImpl(T[] arr)
    {
        this.arr = arr;
        avg = this.avg();
    }

    public double avg()
    {
        double sum = 0;
        for(T ele: arr)
        {
            sum+= ele.doubleValue();  // Can I not do sum+=ele ??
        }
        return sum/arr.length;
    }

    public boolean compareAvg(StatsImpl<?> ob)
    {
        if(this.avg == ob.avg)
        {
            return true;
        }
        return false;
    }

}