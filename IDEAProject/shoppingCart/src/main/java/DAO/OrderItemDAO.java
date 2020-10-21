package dao;

import bean.OrderItem;
import bean.Product;
import com.mysql.cj.result.SqlDateValueFactory;

import java.sql.Connection;
import java.sql.DriverManager;
import java.sql.PreparedStatement;
import java.sql.SQLException;


/**
 * @author yangw
 */
public class OrderItemDAO {
    public void insert(OrderItem oi){
        try{
            Class.forName("com.mysql.jdbc.Driver");
            Connection conn = DriverManager.getConnection("jdbc:mysql://localhost:306/cart?characterEncoding=UTF-8", "root", "admin");
            String sql = "insert into orderitem values(null, ?, ?, ?)";
            PreparedStatement ps = conn.prepareStatement(sql);
            ps.setInt(1, oi.getProduct().getId());
            ps.setInt(2, oi.getNum());
            ps.setInt(3, oi.getOrder().getId());

            ps.execute();
            ps.close();
            conn.close();

        }catch(ClassNotFoundException | SQLException e){
            e.printStackTrace();
        }
    }

}
