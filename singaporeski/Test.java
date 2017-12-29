import java.util.ArrayList;
public class Test
{
    ArrayList<Tripair> tests;

    public Test()
    {
        tests = new ArrayList<Tripair>();
    }

    public void addTests(String s, int elen, int eslope)
    {
        /*
            Adds the filename, the expected length, and expected slope
            to the tests ArrayList
        */
        Tripair in = new Tripair(s,elen,eslope);
        tests.add(in);
    }

    public boolean runTests()
    {
        /*
            Runs all the tests in the ArrayList and checks
            against actual vs expected
        */
        boolean successful = true;
        for(int i = 0; i < tests.size(); i++)
        {
            MatrixReader r = new MatrixReader(tests.get(i).file);    
            Matrix m       = new Matrix(r.n,r.m);

            Algorithm.loadMatrix(r,m);

            int[] results  = Algorithm.findLongest(m);
            if(tests.get(i).length == results[0] && 
                tests.get(i).slope == results[1])
            {
                System.out.printf("%s was succesful\n",tests.get(i).file); 
            } else {
                System.out.printf("%s failed\n",tests.get(i).file);
                successful = false;
            }
        }

        if(successful)
        {
            System.out.println("All test passed");
            return true;
        } else {
            System.out.println("Failed tests");
            return false;
        }
    }
    
} 
