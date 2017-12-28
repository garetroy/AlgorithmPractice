public class Main 
{
    public static void main(String[] args)
    {
        Reader r = new Reader();
        if(r.n != r.m)
        {
            System.out.println("Have to have equal dimentions");
            return;
        }
        Matrix m = new Matrix(r.n,r.m);
        loadMatrix(r,m);
        int result = findLongest(m);
        System.out.println("Longest path was " + result);
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

    public static int findLongest(Matrix m)
    {
        Matrix cmatrix = new Matrix(m.rows,m.cols,-1);
        int    result  = 1;
        
        for(int i = 0; i < m.rows-1; i++)
        {
            for(int j = 0; j < m.cols-1; j++)
            {
                if(cmatrix.matrix[i][j] == -1)
                {
                    checkFromVertex(i,j,m,cmatrix); 
                }

                result = Math.max(result,cmatrix.matrix[i][j]);
            }
        }
        
        return result;
    }

    public static int checkFromVertex(int i, int j, Matrix m, Matrix cmatrix)
    {
        if(i < 0 || i >= m.rows || j < 0 || j >= m.cols)
        {
            return 0;
        }

        if(cmatrix.matrix[i][j] != -1)
        {
            return cmatrix.matrix[i][j];
        }

        if(j < m.rows-1 && (m.matrix[i][j] > m.matrix[i][j+1]))
        {
            return cmatrix.matrix[i][j] = 1 + checkFromVertex(i,j+1,m,cmatrix);

        }else if(j > 0 && (m.matrix[i][j] > m.matrix[i][j-1])){

            return cmatrix.matrix[i][j] = 1 + checkFromVertex(i,j-1,m,cmatrix);

        }else if(i > 0 && (m.matrix[i][j] > m.matrix[i][i-1])){

            return cmatrix.matrix[i][j] = 1 + checkFromVertex(i-1,j,m,cmatrix);

        }else  if(i < m.rows-1 && (m.matrix[i][j] > m.matrix[i][i+1])){
            
            return cmatrix.matrix[i][j] = 1 + checkFromVertex(i+1,j,m,cmatrix);
        }
        
        return cmatrix.matrix[i][j];
    }
}
