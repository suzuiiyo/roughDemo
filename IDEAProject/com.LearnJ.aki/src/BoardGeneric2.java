/**
 * @author yangw
 */
public class BoardGeneric2<T extends Number> {
    private T key;

    public BoardGeneric2(T key){
        this.key = key;
    }

    public T getKey(){
        return key;
    }

    public void showKeyValue(BoardGeneric2<? extends Number> obj){
        System.out.println(obj.getKey());
    }

    /**
      * static BoardGeneric2<String> generic1 = new BoardGeneric2<String>("11111");
     */
    static BoardGeneric2<Integer> generic2 = new BoardGeneric2<Integer>(2222);
    static BoardGeneric2<Float> generic3 = new BoardGeneric2<Float>(2.4f);
    static BoardGeneric2<Double> generic4 = new BoardGeneric2<Double>(2.56);

    public static void main(String[] args) {
        float hp = 3.4f;
        new BoardGeneric2<>(hp).showKeyValue(generic2);
        new BoardGeneric2<>(hp).showKeyValue(generic3);
        new BoardGeneric2<>(hp).showKeyValue(generic4);
    }
}
