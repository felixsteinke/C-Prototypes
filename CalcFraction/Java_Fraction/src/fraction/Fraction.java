package fraction;

public class Fraction {
    private int counter;
    private int denominator;

    public static void main(String[] args) {
        // TODO code application logic here
        System.out.println(new Fraction(Math.PI, 100));
        System.out.println(new Fraction(2, 6).add(new Fraction(2, 3)));
        System.out.println(new Fraction(2, 6).sub(new Fraction(3, 9)));
        System.out.println(new Fraction(2, 6).mul(new Fraction(3, 9)));
        System.out.println(new Fraction(2, 6).div(new Fraction(3, 9)));
    }

    public Fraction() {
        this(0, 1);
    }

    public Fraction(int counter) {
        this(counter, 1);
    }

    public Fraction(int counter, int denominator) {
        this.counter = counter;
        this.denominator = denominator;
        reduce();
    }

    public Fraction(double value, int maxdenom) {
        this.counter = (int) (value*maxdenom);
        this.denominator = maxdenom;
        reduce();
    }

    public Fraction add(Fraction other) {
        return new Fraction(this.counter*other.denominator + other.counter*this.denominator,
                this.denominator*other.denominator);
    }

    public Fraction sub(Fraction other) {
        return new Fraction(this.counter*other.denominator - other.counter*this.denominator,
                this.denominator*other.denominator);
    }

    public Fraction mul(Fraction other) {
        return new Fraction(this.counter*other.counter, this.denominator*other.denominator);
    }

    public Fraction div(Fraction other) {
        return new Fraction(this.counter*other.denominator, this.denominator*other.counter);
    }

    public double toDouble() {
        return 1.0 * this.counter / this.denominator;
    }

    public String toString() {
        return String.format("(%d, %d)", counter, denominator);
    }

    private void reduce() {
        int gcd = gcd(counter, denominator);
        if ( gcd != 0 ) {
            counter /= gcd;
            denominator /= gcd;
        }
        if ( denominator < 0 ) {
            counter *= -1;
            denominator *= -1;
        }
    }

    private static int gcd(int a, int b) {
        int h;
        if (a == 0) return Math.abs(b);
        if (b == 0) return Math.abs(a);

        do {
            h = a % b;
            a = b;
            b = h;
        } while (b != 0);

        return Math.abs(a);
    }
}

