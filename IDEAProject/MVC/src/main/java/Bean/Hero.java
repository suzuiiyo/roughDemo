package bean;

/**
 * @author yangw
 */
public class Hero {
    private int id;
    private String name;
    private float hp;
    private float attack;

    public int getId(){
        return id;
    }

    public void setId(int id){
        this.id = id;
    }

    public String getName(){
        return name;
    }

    public void setName(String name){
        this.name = name;
    }
    public float getHp(){
        return hp;
    }

    public void setHp(float hp){
        this.hp = hp;
    }
    public float getAttack(){
        return attack;
    }

    public void setAttack(float attack){
        this.attack = attack;
    }

    @Override
    public String toString() {
        return "Hero{" +
                "id=" + id +
                ", name='" + name + '\'' +
                ", hp=" + hp +
                ", attack=" + attack +
                '}';
    }
}
