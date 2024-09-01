import java.util.*;


public class thread_part1 
{
    public static class Thread1 extends Thread
    {
        @Override
        public void run()
        {
            for (int i = 0; i <5; i++) {
                 System.out.println("inside "+ Thread.currentThread()+" "+i);
            }
        }
    }
   public static void main(String[] args) 
   {

      
    long t1 = System.nanoTime();

      Thread th =  new Thread1();
        th.start();
      System.out.println("I am out");
    
      long t2 = System.nanoTime();

      long elapsedTime = t2 - t1;
      double seconds = (double)elapsedTime / 1_000_000_000.0;
      System.out.println(seconds);
   }    
}
