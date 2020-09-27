import java.util.ArrayList;

public class GenericExa3 {
    public static void main(String[] args) {
        Generic generic = new Generic("1111111");
        Generic generic1 = new Generic(4444);
        Generic generic2 = new Generic(55.55);
        Generic generic3 = new Generic(false);

        System.out.println("∑∫–Õ≤‚ ‘:" + "key is " + generic.getKey());
        System.out.println("∑∫–Õ≤‚ ‘:" + "key is " + generic1.getKey());
        System.out.println("∑∫–Õ≤‚ ‘:" + "key is " + generic2.getKey());
        System.out.println("∑∫–Õ≤‚ ‘:" + "key is " + generic3.getKey());
    }
}
