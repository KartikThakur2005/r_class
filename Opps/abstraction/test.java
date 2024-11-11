public class test 
{

   public static void main(String[] args) 
   {
       car nano = new car(4);
       nano.start();

   }    
}



abstract class vechicle
{
    int tyre;
    abstract void start();
}

class car extends vechicle
{
   int  tyre;
     car(int x)
     {
        this.tyre = x;
     }

    void start()
    {
       System.out.println("Starting by key" + " having "+ tyre);
    }
}

class scooter extends vechicle
{
    int tyre;
    scooter(int x)
    {
       this.tyre = x;
    }
     void start()
     {
        System.out.println("Start by kick havong "+ tyre);
     }
}