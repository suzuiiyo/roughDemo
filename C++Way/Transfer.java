public class Transfer{

    public static void main(String[] args) {
        new Transfer().func();
    }

    public int change(int tmp_t){
        tmp_t = 1;
        return tmp_t;
    }

    public void func(){
        int tmp = 0;
        tmp = change(tmp);
        System.out.printf("%s", tmp);
    }
}