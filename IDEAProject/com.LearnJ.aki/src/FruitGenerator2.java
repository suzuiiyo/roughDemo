import java.util.Random;

public class FruitGenerator2 implements Generator<String>{
    private String[] fruits = new String[]{"Apple", "Banana", "Pear"};

    @Override
    public String next(){
        Random rand = new Random();
        return fruits[rand.nextInt(3)];
    }

    public static void main(String[] args) {
        System.out.println(new FruitGenerator2().next());
    }
}
