package bean;

public class User {
    private int id;
    private String name;
    private String password;

    public User() {
    }
    public User(String name, String password) {
        this.name = name;
        this.password = password;
    }

    public void setId(int id){
        this.id = this.id;
    }

    public int getId(){
        return id;
    }

    public void setName(String name){
        this.name = this.name;
    }

    public String getName(){
        return name;
    }

    public void setPassword(String password){
        this.password = this.password;
    }

    public String getPassword(){
        return password;
    }
}
