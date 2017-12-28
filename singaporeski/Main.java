public class Main 
{
    public static boolean DEBUG = false;

    public static void main(String[] args)
    {
        /*
            This main function starts the reader, checks if it's n by n
            then loads the matrix and runs findLongest
        */
        MatrixReader r = new MatrixReader();
        if(r.n != r.m)
        {
            System.out.println("Has to have equal dimentions");
            return;
        }
        Matrix m = new Matrix(r.n,r.m);
        loadMatrix(r,m);
        System.out.println(m);
        int result = findLongest(m);
        System.out.println("Longest path was " + result);
    }

    public static int[] toIntArr(String[] in)
    {
        /*
            Converts an array of strings to 
            an array of ints
        */
        int[] newarray = new int[in.length];

        for(int i = 0; i < in.length; i++)
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
                
    public static void loadMatrix(MatrixReader r, Matrix m)
    {
        /*
            This loads the input of the reader into
            a givem matrix m by getting next line of the
            reader, then converting the line to an int array
            and lastly, replacing the matrix m rows with
            the newly converted int array
        */
        String[] temp;
        int[]    inttemp;

        for(int i = 0; i < r.n; i++)
        {
            if((temp = r.nextLine()) == null)
            {
                System.out.println("Could not load matrix, nextLine");
                System.exit(0);
            }
            
            if((inttemp = toIntArr(temp)) == null)
            {
                System.out.println("Could not load matrix, toIntArr");
                System.exit(0);
            }

            if((m.replaceRow(i,inttemp)) == -1)
            {
                System.out.println("Could not load matrix, replaceRow");
                System.exit(0);
            }

        }
    }

    public static int findLongest(Matrix m)
    {
        /*
            This creates a corresponding matrix with -1
            and goes through every entry in the matrix
            and checks possible maximum paths from it
            using checkFromVertex function returning
            the largest result
        */
        Matrix cmatrix = new Matrix(m.rows,m.cols,-1);
        int    result  = 1;
        
        for(int i = 0; i < m.rows; i++)
        {
            for(int j = 0; j < m.cols; j++)
            {
                if(cmatrix.matrix[i][j] == -1)
                {
                    if(DEBUG)
                    {
                        System.out.println();
                    }
                    
                    result = Math.max(result,checkFromVertex(i,j,m,cmatrix));
                    if(DEBUG)
                    {
                        System.out.print("\nResult - ");
                        System.out.print(result);
                        System.out.println();
                    }
                }

            }
        }
        
        System.out.println(cmatrix);
        return result;
    }

    public static int checkFromVertex(int i, int j, Matrix m, Matrix cmatrix)
    {
        /*
            This algorithm is recursive, it starts from i, j and checks
            left, right, up, and down. Making sure that the next element
            it checks is smaller than the current element (downwards slope)
        */

        if(DEBUG)
        {
            System.out.printf("%d",m.matrix[i][j]);
        }

        if(i < 0 || i >= m.rows || j < 0 || j >= m.cols)
        {
            return 0;
        }

        if(cmatrix.matrix[i][j] != -1)
        {
            return cmatrix.matrix[i][j];
        }
    
        int max = 1;

        //First comparison is for bounds, the second is to see if there is a 
        //slope
        if(j < m.cols-1 && (m.matrix[i][j] > m.matrix[i][j+1]))
        {
            if(DEBUG)
            {
                System.out.printf("-(1,%d,%d)>",i,j);
            }
            max = Math.max(max,1 + checkFromVertex(i,j+1,m,cmatrix));
        }
        if(j > 0 && (m.matrix[i][j] > m.matrix[i][j-1]))
        {
            if(DEBUG)
            {
                System.out.printf("-(2,%d,%d)>",i,j);
            }
            max = Math.max(max,1 + checkFromVertex(i,j-1,m,cmatrix));
        }
        if(i > 0 && (m.matrix[i][j] > m.matrix[i-1][j]))
        {
            if(DEBUG)
            {
                System.out.printf("-(3,%d,%d)>",i,j);
            }
            max = Math.max(max,1 + checkFromVertex(i-1,j,m,cmatrix));
        }
        if(i < m.rows-1 && (m.matrix[i][j] > m.matrix[i+1][j]))
        {
            if(DEBUG)
            {
                System.out.printf("-(4,%d,%d)>",i,j);
            }
            max = Math.max(max,1 + checkFromVertex(i+1,j,m,cmatrix));
        }
        
        if(DEBUG)
        {
            System.out.printf("(5,%d,%d)",i,j);
        }
        cmatrix.matrix[i][j] = max;
        return max;
    }
}
