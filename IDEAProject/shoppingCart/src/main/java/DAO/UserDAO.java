package DAO;

import bean.User;

import java.sql.*;

public class UserDAO {
    public static void main(String[] args) {
        System.out.println(new UserDAO().getUser("tom", "123").getId());
    }

    public User getUser(String name, String password){
        User result = null;
        try{
            Class.forName("com.mysql.cj.jdbc.Driver");
            Connection conn = DriverManager.getConnection("jdbc:mysql://localhost:3306/cart?characterEncoding=UTF-8&serverTimezone=UTC", "root", "admin");
            String sql = "select * from user where name = ? and password = ?";
            PreparedStatement ps = conn.prepareStatement(sql);
            ps.setString(1, name);
            ps.setString(2, password);
            ResultSet rs = ps.executeQuery();

            while(rs.next()){
                result = new User();
                result.setId(rs.getInt(1));
                result.setPassword(password);
                result.setName(name);
            }

        }catch(ClassNotFoundException | SQLException e){
            e.printStackTrace();
        }
        return result;
    }
}
