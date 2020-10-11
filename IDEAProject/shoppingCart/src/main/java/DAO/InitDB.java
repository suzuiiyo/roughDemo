package DAO;

import java.sql.Connection;
import java.sql.DriverManager;
import java.sql.SQLException;
import java.sql.Statement;

/**
 * @author yangw
 */
public class InitDB {
    String drive = "com.mysql.cj.jdbc.Driver";
    String url = "jdbc:mysql://localhost:3306/";
    String factor = "?characterEncoding=utf-8&serverTimezone=UTC";
    String user = "root";
    String password = "admin";

    public InitDB() {
        try{
            Class.forName(drive);
        }catch (ClassNotFoundException e){
            e.printStackTrace();
        }
    }

    public Connection getConn(String database){
        Connection conn = null;
        try{
            conn = DriverManager.getConnection(url + database + factor, user, password);
        }catch (SQLException e){
            e.printStackTrace();
        }
        return conn;
    }

    public void createDatabase(){
        String databasesql = "CREATE DATABASE cart;";
        String createTable = "DROP TABLE IF EXISTS product;" + " CREATE TABLE product (id int(11) DEFAULT NULL," + " name varchar(50) DEFAULT NULL," + " price float DEFAULT NULL)" + " DEFAULT CHARSET=utf8";

        try{
            Connection conn = getConn("hero");
            if(null != conn){
                System.out.println("连接数据库hero成功");
                Statement smt = conn.createStatement();
                smt.executeUpdate(databasesql);

                try{
                    Connection newConn = getConn("cart");
                    if(null != newConn){
                        System.out.println("连接到数据库cart成功");
                        Statement s = newConn.createStatement();
                        int i = s.executeUpdate(createTable);
                        if(i==0){
                            System.out.println("创建表product成功");
                        }
                    }
                }catch (SQLException e){
                    e.printStackTrace();
                }
            }
        }catch (SQLException e){
            e.printStackTrace();
        }
    }

    public static void main(String[] args) {
        new InitDB().createDatabase();
    }
}
