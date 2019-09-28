class array2d{
    
    public static void main(String[] args)
    {
        int [][] arr = new int[][] {{3,4},{5,6},{7,8}};
        int [][] a = new int[4][5];

        for(int [] x : arr)
        {
            for(int y : x)
            {
                System.out.print( y + " ");
            }
            System.out.println();
        }
    }
}

// by default array mei new to null value