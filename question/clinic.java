import java.util.*;
 
public class clinic 
{
    static  boolean valid(int arr[], int mid, int m)
 {
     
     int count = 0;

     for (int i = 0; i < arr.length; i++) 
     {
          if(arr[i] <= mid)count++;
          else{
              if (arr[i] % mid ==0) 
              {
                  count = count + (arr[i] / mid);  
              }
              else{
                count = count + (arr[i] / mid);  
                count++;
              }
          }   
     }

     if (count <= m) 
     {
        return true;   
     }
     return false;
 }

   public static void main(String[] args) 
   {
     100 50 200 
        Scanner sc = new Scanner(System.in);
        int n = sc.nextInt();   // n 
        int arr[] = new int[n];
        

        for (int i = 0; i < arr.length; i++) 
        {
           arr[i] = sc.nextInt();    
        }
       int m = sc.nextInt(); // ----------------- Hospital number 
       int ans = 0;     // ---------------> for storing answer

       int l = 1;  
       int r = arr[n - 1];
       for (int i = 0; i < arr.length; i++) 
       {
           l = Math.min(arr[i], l);
           r = Math.max(arr[i], r);   
       }

       while (l<=r) 
       {
          int mid = l + ((r-l)/2);
          
          if (valid(arr, mid, m)) 
          {
              ans  = mid;
              r  = mid - 1;  
          }
          else{
            l = mid + 1;
          }
       }
 
       System.out.println(ans);
      
   }
    
}