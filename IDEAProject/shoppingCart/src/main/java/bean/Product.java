package bean;

/**
 * @author yangw
 */
public class Product {
    private int id;
    private String name;
    private float price;

    public int getId(){
        return id;
    }

    public void setId(int id){
        this.id = id;
    }

    public void setName(String name){
        this.name = name;
    }

    public String getName(){
        return name;
    }

    public void setPrice(float price){
        this.price = price;
    }

    public float getPrice(){
        return price;
    }
}
