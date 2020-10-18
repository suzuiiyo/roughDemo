package bean;

public class OrderItem {
    private int id;
    private Product product;
    private int num;

    public int getId(){
        return id;
    }

    public void setId(int id){
        this.id = id;
    }

    public Product getProduct(){
        return product;
    }

    public void setProduct(Product product){
        this.product = product;
    }

    public int getNum(){
        return num;
    }

    public void setNum(int num){
        this.num = num;
    }
}
