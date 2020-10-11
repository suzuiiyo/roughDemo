package DAO;

public class HelloWorld {
    public static void main(String[] args) {
        System.out.println("Hello World");
        System.out.println("DROP TABLE IF EXISTS product;" + " CREATE TABLE product (id int(11) DEFAULT NULL," + " name varchar(50) DEFAULT NULL," + " price float DEFAULT NULL)" + " DEFAULT CHARSET=utf8");
    }
}
