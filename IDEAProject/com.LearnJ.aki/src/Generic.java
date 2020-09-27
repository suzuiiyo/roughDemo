public class Generic<T> {
    private T key;

    public Generic(T key){
        //泛型构造方法形参key的类型也为T， T的类型由外部指定
        this.key = key;
    }

    public T getKey(){
        return key;
    }
}
