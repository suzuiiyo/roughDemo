public class GenericExa4 {
    public static void main(String[] args) {
        Generic<Integer> gInteger = new Generic<Integer>(123);
        Generic<Number> gNumber = new Generic<Number>(456);

        new GenericExa4().showKeyValue(gNumber);
        //new GenericExa4().showKeyValue(gInteger);
        //new GenericExa4().showKeyValue1(gNumber);
        new GenericExa4().showKeyValue2(gNumber);
    }

    public void showKeyValue(Generic<Number> obj){
        System.out.println("泛型<Integer>测试: " + "key value is " + obj.getKey());
    }

    public void showKeyValue1(Generic<Integer> obj){
        System.out.println("泛型<Number>测试: " + "key value is " + obj.getKey());
    }
    //泛型通配符
    /**
     此处'?'是类型实参，而不是类型形参！再直白点的意思就是，此处的？和Number、String、Integer一样都是一种实际的类型，可以把？看成所有类型的父类。是一种真实的类型
    */
    public void showKeyValue2(Generic<?> obj){
        System.out.println("泛型<Number>测试: " + "key value is " + obj.getKey());
    }
}
