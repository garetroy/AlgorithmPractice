import java.util.Scanner;
import java.io.File;
import java.util.NoSuchElementException;
import java.io.FileNotFoundException;


public class MatrixReader
{
    /*
        A public class in which it parses System.in for a given matrix.
        The format of the matrix being input must be as follows.
        
        Diminsion at the top of the input (ints) (must be equal)
        X X

        (must be ints)
        Then the rest is the values sepereated by spaces for colums
        New lines for rows..

        Ex:
        3 3
        1 3 4
        4 3 2
        4 3 3
    */

    Scanner  s; //scanner
    File     r; //file
    int      n; //n dim of matrix (rows)
    int      m; //m dim of matrix (cols)
    int      curr; //current line
    String[] splits; //Splitting line

    public MatrixReader(String f)
    {
        /*
            Initilizes the scanner and dimintions
            Exits on error
        */
        r = new File(f);
        try{
            s = new Scanner(r);
        } catch(FileNotFoundException e) {
            System.out.println("File not found... ");
            System.out.println(e);
            System.exit(0);
        }

        splits = (s.nextLine()).split(" ");

        if(splits.length != 2){
            System.out.println("Incorrect input, has to have two diminsions");
            System.exit(0);
        }
    
        try {
            n = Integer.parseInt(splits[0]);
            m = Integer.parseInt(splits[1]);
        } catch(NumberFormatException s) {
            System.out.println("Dimintions must be integers");
            System.exit(0);
        } 

        if(n < 1 || m < 1)
        {
            System.out.println("Cannot have dimintions less than one");
            System.exit(0);
        }

        curr = curr + 1;
    }

    public String[] nextLine()
    {
        /*
            Get's next line of values from matrix
            Returns result if successful
            Returns null if unsuccessful (or no new line)
        */

        if (curr < n+1)
        {
            try {
                splits = s.nextLine().split(" ");
            } catch(NoSuchElementException e) {
                System.out.println("Matrix not complete");
                return null;
            } catch(IllegalStateException e) {
                System.out.println("Scanner was closed");
                return null;
            }
        } else {
            System.out.println("Past number of rows for matrix");
            return null;
        }

        if (splits.length <= 0)
        {
            System.out.println("Bad matrix entry");
            return null;
        }
            
        if (splits.length < 0)
        {
            System.out.println("Line of matrix empty");
            return null;
        }
        
        curr = curr + 1;
        return splits;
    }

    @Override
    public void finalize()
    {
        /*
            The class destructor which closes the scanner
        */
        s.close();
    }
}
    
