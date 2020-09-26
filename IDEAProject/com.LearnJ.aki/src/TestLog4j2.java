import org.apache.log4j.LogManager;
import org.apache.log4j.Logger;

public class TestLog4j2 {
    String name;
    private static Logger logger = LogManager.getLogger(TestLog4j2.class.getName());

    public static void main(String[] args) {
        TestLog4j2 fairChild = new TestLog4j2();
        fairChild.name = "仙童";

        logger.debug("修改前的名字为: " + fairChild.name);
        fairChild.name = "神祗";
        logger.trace("修改后的名字为：" + fairChild.name);
        logger.debug("修改后的名字为：" + fairChild.name);
        logger.info("修改后的名字为：" + fairChild.name);
        logger.warn("修改后的名字为：" + fairChild.name);
        logger.fatal("修改后的名字为：" + fairChild.name);
    }
}
