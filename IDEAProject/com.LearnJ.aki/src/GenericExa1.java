
import org.apache.log4j.LogManager;
import org.apache.log4j.Logger;

import java.util.ArrayList;
import java.util.List;

public class GenericExa1 {
    private static Logger logger = LogManager.getLogger(TestLog4j2.class.getName());
    public static void main(String[] args) {
        List arrayList = new ArrayList();
        arrayList.add("aaa");
        arrayList.add(100);

        for (int i = 0; i < arrayList.size(); i++) {
            String item = (String) arrayList.get(i);
        }
    }
}
