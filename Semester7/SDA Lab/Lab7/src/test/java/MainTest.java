import org.junit.*;
import static org.junit.Assert.*;

public class MainTest {

    private Calculator calculator;

    @BeforeClass
    public static void setUpBeforeClass() {
        System.out.println("BeforeClass: Runs once before all tests in this class.");
    }

    @AfterClass
    public static void tearDownAfterClass() {
        System.out.println("AfterClass: Runs once after all tests in this class.");
    }

    @Before
    public void setUp() {
        System.out.println("Before: Runs before each test method.");
        calculator = new Calculator();
    }

    @After
    public void tearDown() {
        System.out.println("After: Runs after each test method.");
        calculator = null;
    }

    @Test
    public void testMethod1() {
        System.out.println("Test Method 1");
        double result = calculator.add(2.0, 3.0);
        assertEquals(5.0, result, 0.0001);
    }

    @Test
    public void testMethod2() {
        System.out.println("Test Method 2");
        double result = calculator.subtract(5.0, 3.0);
        assertEquals(2.0, result, 0.0001);
    }

    @Ignore
    @Test
    public void testMethod3() {
        System.out.println("This test is skip.");
        double result = calculator.multiply(2.0, 3.0);
        assertEquals(6.0, result, 0.0001);
    }

    @Test
    public void testMethod4() {
        System.out.println("Test Method 4");
        double result = calculator.multiply(2.0, 3.0);
        assertNotEquals(7.0, result, 0.0001);
    }

    @Test
    public void testMethod5() {
        System.out.println("Test Method 7");
        assertNull(null);
    }

    @Test
    public void testMethod6() {
        System.out.println("Test Method 8");
        assertNotNull(calculator);
    }

    @Test(expected = ArithmeticException.class)
    public void testMethod7() {
        System.out.println("Test Method 9");
        calculator.divide(1.0, 0.0);
    }
}