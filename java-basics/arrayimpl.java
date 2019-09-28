import java.util.Scanner;

class arrayimpl{
    public static Scanner sc = new Scanner(System.in);

    static void fun(int[] arr)
    {
        for(int i = 0 ; i  < arr.length; i++)
        {
            arr[i] = i+1;
        }
    }

    public static void display(int[] arr)
    {
        // for(int i = 0 ; i < arr.length;i++)
        // {
        //     System.out.println(i + " th value is : " + arr[i]);
        // }

        for(int i  : arr)
        {
            System.out.print(i + " ");
        }
    }

    public static void input(int[] arr)
    {
        for(int i = 0 ; i < arr.length ; i++)
        {
            arr[i] = sc.nextInt();
        }
    }
    public static void main(String[] args) {
        int[] arr = new int[5];
        //fun(arr);
        input(arr);
        display(arr);
    }
}
// array initialised by def value - int mei 0
// array ko sath mein decalre and initialise nhi kr skte