package DAO;

import bean.Product;

import java.sql.*;
import java.util.ArrayList;
import java.util.List;

public class ProductDAO {
    List<Product> products = new ArrayList<>();
    String        sql      = "select * from product limit ?, ?";
    public List<Product> listProduct(int start, int count){
        try{
            Class.forName("com.mysql.cj.jdbc.Driver");
            Connection conn = DriverManager.getConnection("jdbc:mysql://localhost:3306/cart?characterEncoding=UTF-8&serverTimezone=UTC", "root", "admin");
            PreparedStatement ps = conn.prepareStatement(sql);
            ps.setInt(1, start);
            ps.setInt(2, count);
            ResultSet rs = ps.executeQuery();
            while(rs.next()){
                Product product = new Product();
                product.setId(rs.getInt("id"));
                product.setName(rs.getString("name"));
                product.setPrice(rs.getFloat("price"));

                products.add(product);
            }
            ps.close();
            conn.close();
        }catch(ClassNotFoundException | SQLException e){
            e.printStackTrace();
        }
        return products;
    }

    public static void main(String[] args) {
        new ProductDAO().listProduct(0, Short.MAX_VALUE);
    }
}
