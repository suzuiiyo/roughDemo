package dao;

import bean.Order;

import java.sql.*;

public class OrderDAO {
    public void insert(Order o){
        try{
            Class.forName("com.mysql.jdbc.Driver");
            Connection        conn = DriverManager.getConnection("jdbc.mysql://127.0.0.1:3306/cart?characterEncoding=UTF-8&serverTimezone=UTC&", "root", "admin");
            String            sql  = "insert into order_ values(null, ?)";
            PreparedStatement ps   = conn.prepareStatement(sql, Statement.RETURN_GENERATED_KEYS);
            ps.setInt(1, o.getUser().getId());
            ps.execute();

            ResultSet rs = ps.getGeneratedKeys();
            if(rs.next()){
                int id = rs.getInt(1);
                o.setId(id);
            }
            ps.close();
            conn.close();
        }catch(ClassNotFoundException | SQLException e){
            e.printStackTrace();
        }
    }
}
