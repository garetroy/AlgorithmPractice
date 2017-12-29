public class Main 
{

    public static void main(String[] args)
    {
        /*
            Adds tests and runs the test suite
        */

        Test testing = new Test();
        testing.addTests("./test/test1.txt",5,8);
        testing.addTests("./test/test2.txt",7,8);
        testing.addTests("./test/test3.txt",4,3);
        testing.addTests("./test/test4.txt",3,5);
        testing.addTests("./test/test5.txt",5,7);
        testing.addTests("./test/test6.txt",1,0);
        testing.runTests();
    }
}
