/**
 *静态方法无法访问类上定义的泛型,如果静态方法操作的引用数据类型不确定的时候,必须将泛型定义在方法上
 * @author yangw
 */
public class GenericStatic<T> {
    /**
     * 如果在类中定义使用泛型的静态方法，需要添加额外的泛型声明（将这个方法定义成泛型方法）
     * 即使静态方法要使用泛型类中已经声明过的泛型也不可以。
     * 如：public static void show(T t){..},此时编译器会提示错误信息：
          "StaticGenerator cannot be refrenced from static context"
     */
    public static <T> void show(T t){

    }
}
