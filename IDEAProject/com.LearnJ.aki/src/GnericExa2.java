import java.util.ArrayList;
import java.util.List;

/**
泛型只在编译阶段有效，Java中的泛型，只在编译阶段有效。在编译过程中，正确检验泛型结果后，会将泛型的相关信息擦出，并且在对象进入和离开方法的边界处添加类型检查和类型转换的方法。也就是说，泛型信息不会进入到运行时阶段
 */
public class GnericExa2 {
    public static void main(String[] args) {
        List<String> stringArrayList = new ArrayList<>();
        List<Integer> integerArrayList = new ArrayList<>();

        Class classStringArrayList = stringArrayList.getClass();
        Class classIntegerArrayList = integerArrayList.getClass();

        //类对象都是list对象,泛型类型在逻辑上看以看成是多个不同的类型，实际上都是相同的基本类型
        if (classStringArrayList.equals(classIntegerArrayList)) {
            System.out.println("泛型测试: " + "类型相同");
        }
    }
}
