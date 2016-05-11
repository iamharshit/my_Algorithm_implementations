import java.io.*;
import java.util.*;
import java.text.*;
import java.math.*;
import java.util.regex.*;

public class bubbleSort{
	 private static int[] bubbleSort(int[] arr){
        for(int i=1;i<=arr.length-1;i++ ){
            int last=arr.length-i;
            for(int j=1;j<=last;j++)
                if(arr[j-1]>arr[j]){
                    int temp=arr[j-1];
                    arr[j-1]=arr[j];
                    arr[j]=temp;
            }
        }
        return arr;
    }

    public static void main(String[] args) {
        Scanner scan = new Scanner(System.in);
        
        int size=scan.nextInt();
        
        int[] my_arr=new int[size];
        for(int i=0;i<size;i++){
            int x= scan.nextInt();
            my_arr[i]=x;    
        }

        my_arr=bubbleSort(my_arr);
        
        scan.close();
    }
}
