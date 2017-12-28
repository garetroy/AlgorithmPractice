public class Matrix
{
    /*
        A class that represents a matrix.
    */
    int     rows;
    int     cols;
    int[][] matrix; 

    public Matrix(int r, int c)
    {
        /*
            Constructor here, takes in numbers of rows and columns for
            a given matrix and initilizes this matrix class
        */
        if(r <= 0 || c <= 0)
        {
            System.out.println("Dimintions of matrix must be greater than 0");
            System.exit(0);
        }
        rows   = r;
        cols   = c;
        matrix = new int[rows][cols]; 
    }

    public Matrix(int r, int c, int v)
    {
        /*
            Initilizes a r by c matrix with the value v
        */

        if(r <= 0 || c <= 0)
        {
            System.out.println("Dimentions of matrix must be greater than 0");
            System.exit(0);
        }
        rows   = r;
        cols   = c;
        matrix = new int[rows][cols];

        for(int i = 0; i < rows-1; i++)
        {
            for(int k = 0; k < cols-1; k++)
            {
                matrix[i][k] = v;
            }
        }
    }

    public String toString()
    {
        /*
            Converts the matrix to a string
        */
        String line = "\n";
        for(int i = 0; i < rows-1; i++)
        {
            for(int k = 0; k < cols-1; k++)
            {
                line += Integer.toString(matrix[i][k]) + " ";
            }
            
            line += "\n";
        }

        return line;
    }

    public int replaceRow(int row, int[] in)
    {
        /*
            Replaces a given row of the matrix
            
                row - the row to replace
                in  - the values to replace the row with
        
            Returns -1 if error
            Returns 0  if success
        */
        if(row > rows || row < 0)
        {
            String line = String.format("Row %d does not exist",row);
            System.out.println(line);
            return -1;
        }

        if(in.length != rows)
        {
            System.out.println("Size of in row is bigger than matrix rows");
            return -1;
        }

        for(int i = 0; i < cols-1; i++)
        {
            matrix[row][i] = in[i];
        }
        
        return 0;
    }
        
}
