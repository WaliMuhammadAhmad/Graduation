import static org.junit.Assert.*;
import org.junit.Test;

public class CalTest {
    private final Calculator calculator = new Calculator();

    @Test
    public void testAdd() {
        assertEquals(5.0, calculator.add(2.0, 3.0), 0.0001);
    }

    @Test
    public void testSubtract() {
        assertEquals(1.0, calculator.subtract(3.0, 2.0), 0.0001);
    }

    @Test
    public void testMultiply() {
        assertEquals(6.0, calculator.multiply(2.0, 3.0), 0.0001);
    }

    @Test
    public void testDivide() {
        assertEquals(2.0, calculator.divide(6.0, 3.0), 0.0001);
    }

    @Test
    public void testPower() {
        assertEquals(8.0, calculator.power(2.0, 3.0), 0.0001);
    }

    @Test
    public void testAssertNotEquals() {
        assertNotEquals(7.0, calculator.add(2.0, 3.0), 0.0001);
    }

    @Test
    public void testAssertTrue() {
        assertTrue(calculator.add(2.0, 3.0) == 5.0);
    }

    @Test
    public void testAssertFalse() {
        assertFalse(calculator.add(2.0, 3.0) == 6.0);
    }

    @Test
    public void testAssertNull() {
        // assertNull(calculator);
    }

    @Test
    public void testAssertNotNull() {
        assertNotNull(calculator);
    }

    @Test(expected = ArithmeticException.class)
    public void testAssertThrows() {
        calculator.divide(1.0, 0.0);
    }
}
