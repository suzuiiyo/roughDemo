public class Swap {
    public static void main(String[] args) {
        int a = 11;
        int b = 22;
        new Swap().swap(a, b);
        System.out.printf("a=%d, b=%d\n", a, b);

        int temp = 0;
        temp = a;
        a = b;
        b = temp;
        System.out.printf("a=%d, b=%d", a, b);
    }
    
    public void swap(int a, int b) {
        int temp = a;
        a = b;
        b = temp;
    }
}