public class Main 
{
    public static void main(String[] args)
    {
        Reader r = new Reader();
        Matrix m = new Matrix(r.n,r.m);
        loadMatrix(r,m);
        System.out.println(m);
    }

    public static int[] toIntArr(String[] in)
    {
        int[] newarray = new int[in.length];

        for(int i = 0; i < in.length-1; i++)
        {
            try{
                newarray[i] = Integer.valueOf(in[i]);
            } catch (NumberFormatException e) {
                System.out.println("Array dosen't contain just ints");
                return null;
            }
        }

        return newarray;
    }
                
    public static void loadMatrix(Reader r, Matrix m)
    {
        String[] temp;
        int[]    inttemp;

        for(int i = 0; i < r.n-1; i++)
        {
            if((temp = r.nextLine()) == null)
            {
                System.out.println("Could not load matrix");
                System.exit(0);
            }
            
            if((inttemp = toIntArr(temp)) == null)
            {
                System.out.println("Could not load matrix");
                System.exit(0);
            }

            if((m.replaceRow(i,inttemp)) == -1)
            {
                System.out.println("Could not load matrix");
                System.exit(0);
            }
        }
    }
}
