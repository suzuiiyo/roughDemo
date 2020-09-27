/**
 * @author yangw
 */
public class BoardGeneric {
    public static void showKeyValue(Generic<? extends Number> obj){
        System.out.println();
    }

    static Generic<String> generic1 = new Generic<String>("11111");
    static Generic<Integer> generic2 = new Generic<Integer>(2222);
    static Generic<Float> generic3 = new Generic<Float>(2.4f);
    static Generic<Double> generic4 = new Generic<Double>(2.56);

    public static void main(String[] args) {
        //这一行代码编译器会提示错误，因为String类型并不是Number类型的子类
        //showKeyValue(generic1);
        showKeyValue(generic2);
        showKeyValue(generic3);
        showKeyValue(generic4);
    }
}
