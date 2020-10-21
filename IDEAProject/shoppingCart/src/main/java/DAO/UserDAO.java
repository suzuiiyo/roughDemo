package dao;

import bean.User;

import java.security.spec.NamedParameterSpec;
import java.sql.*;
import java.util.Collection;

public class UserDAO {
    public UserDAO() {
        try {
            Class.forName("com.mysql.cj.jdbc.Driver");
        } catch (ClassNotFoundException e) {
            e.printStackTrace();
        }
    }

    public Connection getConn(){
        Connection conn = null;
        try{
            conn = DriverManager.getConnection("jdbc:mysql://localhost:3306/cart?characterEncoding=UTF-8&serverTimezone=UTC", "root", "admin");
        }catch (SQLException e){
            e.printStackTrace();
        }
        return conn;
    }

    public User getUser(String name, String password){
        User user = null;
        try(Connection conn = getConn()){
            String sql = "select * from user where name = ? and password = ?";
            PreparedStatement ps = conn.prepareStatement(sql);
            ps.setString(1, name);
            ps.setString(2, password);
            ResultSet rs = ps.executeQuery();
            while(rs.next()){
                user = new User();
                int id = rs.getInt("id");

                user.setId(id);
                user.setName(name);
                user.setPassword(password);
            }
        }catch (SQLException e){
            e.printStackTrace();
        }
        return user;
    }

    public void insert(User user){
        try(Connection con = getConn()){
            String sql = "insert into user values(null, ?, ?)";
            PreparedStatement ps = con.prepareStatement(sql);
            ps.setString(1, user.getName());
            ps.setString(2, user.getPassword());
            ps.executeUpdate();

            ps.close();
        }catch (SQLException e){
            e.printStackTrace();
        }
    }
}
