public class Algorithm
{
    public static boolean DEBUG = false;

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

    public static int[] findLongest(Matrix m)
    {
        /*
            This creates a corresponding matrix with -1
            and goes through every entry in the matrix
            and checks possible maximum paths from it
            using checkFromVertex function returning
            the largest result
        */
        Matrix cmatrix = new Matrix(m.rows,m.cols,-1);
        int result     = 1;
        int temp       = 0;
        int slope      = 0;
        
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
                    
                    bot = m.matrix[i][j];

                    temp = checkFromVertex(i,j,m,cmatrix);
                    if(result < temp)
                    {
                        result = temp;
                        slope  = m.matrix[i][j]-bot;
                    } else if(result == temp){
                        slope = Math.max(slope,m.matrix[i][j]-bot);
                    }
                    
                    if(DEBUG)
                    {
                        System.out.print("\nResult - ");
                        System.out.print(result);
                        System.out.println();
                    }
                }
            }
        }

        int[] done = new int[2];
        done[0] = result;
        done[1] = slope;
        return done;
    }

    //For finding the bottom of the slope
    public static int bot = 0;

    public static int checkFromVertex(int i, int j, Matrix m, Matrix cmatrix)
    {
        /*
            This algorithm is recursive, it starts from i, j and checks
            left, right, up, and down. Making sure that the next element
            it checks is smaller than the current element (downwards slope)
            
            This rechecks paths, this is for the calculating the slope
        */

        if(i < 0 || i >= m.rows || j < 0 || j >= m.cols)
        {
            return 0;
        }

        if(DEBUG)
        {
            System.out.printf("--%d--",m.matrix[i][j]);
        } 


        bot = Math.min(bot,m.matrix[i][j]);
        
        int max = 1;
        int temp = 0;

        //First comparison is for bounds, the second is to see if there is a 
        //slope
        if(j < m.cols-1 && (m.matrix[i][j] > m.matrix[i][j+1]))
        {
            
            temp = 1 + checkFromVertex(i,j+1,m,cmatrix);
            if(max < temp)
            {
                max = temp;
                if(DEBUG)
                {
                    System.out.printf("--%d--",m.matrix[i][j]);
                }
            }
        }

        if(j > 0 && (m.matrix[i][j] > m.matrix[i][j-1]))
        {
            temp = 1 + checkFromVertex(i,j-1,m,cmatrix);
            if(max < temp)
            {
                max = temp;
                if(DEBUG)
                {
                    System.out.printf("--%d--",m.matrix[i][j]);
                }
            }
        }

        if(i > 0 && (m.matrix[i][j] > m.matrix[i-1][j]))
        {
            temp = 1 + checkFromVertex(i-1,j,m,cmatrix);
            if(max < temp)
            {
                max = temp;
                if(DEBUG)
                {
                    System.out.printf("--%d--",m.matrix[i][j]);
                }
            }
        }

        if(i < m.rows-1 && (m.matrix[i][j] > m.matrix[i+1][j]))
        {
            temp = 1 + checkFromVertex(i+1,j,m,cmatrix);
            if(max < temp)
            {
                max = temp;
                if(DEBUG)
                {
                    System.out.printf("--%d--",m.matrix[i][j]);
                }
            }
        }
        
        cmatrix.matrix[i][j] = max;
        return max;
    }
}
