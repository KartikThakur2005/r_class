import java.util.ArrayList;
import java.util.List;

public class RaceConditionExample {
    public static void main(String[] args) {
        // Shared list between multiple threads
        List<Integer> sharedList = new ArrayList<>();
        
        // Creating multiple threads to add elements to the shared list
        // Thread thread1 = new Thread(new ListAdder(sharedList,1));
        // Thread thread2 = new Thread(new ListAdder(sharedList,2));
        // Thread thread3 = new Thread(new ListAdder(sharedList,3));
        // Thread thread4 = new Thread(new ListAdder(sharedList,4));
        // Thread thread5 = new Thread(new ListAdder(sharedList,5));
       
        
        // // Starting the threads
        // long t1 = System.nanoTime();
        // thread1.start();
        // thread2.start();
        // thread3.start();
        // thread4.start();
        // thread5.start();

        // //    thread1.run();
        // //    thread2.run();
        // //    thread3.run();
        //    sharedList.add(6);
        // long t2 = System.nanoTime();


        // // long elapsedTime = t2 - t1;
        // // double seconds = (double)elapsedTime / 1_000_000_000.0;
        // // System.out.println(seconds);
        
        // // // Wait for the threads to finish execution
        // // try {
        // //     thread1.join();
        // //     thread2.join();
        // //     thread3.join();
        // // } catch (InterruptedException e) {
        // //     e.printStackTrace();
        // // }
        
        // // for (int i = 0; i < sharedList.size(); i++) 
        // // {
        // //    System.out.println(sharedList.get(i));    
        // // }

        // long elapsedTime = t2 - t1;
        // double seconds = (double)elapsedTime / 1_000_000_000.0;
        // System.out.println(seconds);


        for (int i = 0; i < 20; i++) 
        {
         sharedList = new ArrayList<Integer>();
            Thread thread1 = new Thread(new ListAdder(sharedList,1));
            Thread thread2 = new Thread(new ListAdder(sharedList,2));
            Thread thread3 = new Thread(new ListAdder(sharedList,3));
            Thread thread4 = new Thread(new ListAdder(sharedList,4));
            Thread thread5 = new Thread(new ListAdder(sharedList,5));
            thread1.start();
            thread2.start();
            thread3.start();
            thread4.start();
            thread5.start();
    
               sharedList.add(6);
          
    
            if (sharedList.size()<6) 
            {
                 
                  for (int j = 0; i < sharedList.size(); j++) 
         {
            System.out.print(sharedList.get(j)+" ");    
         }
          System.out.println();
                
            }
            
       }
    }
}

class ListAdder implements Runnable {
    private final List<Integer> list;
    private int num;
    public ListAdder(List<Integer> list , int num) {
        this.list = list;
        this.num = num;
    }

    @Override
    public void run() {
        list.add(num);
    
   }
}
