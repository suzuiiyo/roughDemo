package dao;

import bean.Product;
import org.apache.taglibs.standard.tag.common.core.CatchTag;

import java.security.DrbgParameters;
import java.sql.*;
import java.util.ArrayList;
import java.util.List;

public class ProductDAO {
   public ProductDAO() {
      try{
         Class.forName("com.mysql.cj.jdbc.Driver");
      }catch (ClassNotFoundException e){
         e.printStackTrace();
      }
   }

   public Connection getConn() throws SQLException {
      Connection conn = null;
      try {
         conn = DriverManager.getConnection("jdbc:mysql://localhost:3306/cart?characterEncoding=UTF-8&serverTimezone=UTC", "root", "admin");
      } catch (SQLException e) {
         e.printStackTrace();
      }
      return conn;
   }

   public List<Product> listProduct(){
      return listProduct(0, Short.MAX_VALUE);
   }

   public List<Product> listProduct(int start, int count) {
      List<Product> products = new ArrayList<>();
      String        sql      = "select * from product order by id desc limit ?, ?";
      try (Connection conn = getConn()) {
         PreparedStatement ps = conn.prepareStatement(sql);
         ps.setInt(1, start);
         ps.setInt(2, count);
         ResultSet rs = ps.executeQuery();
         while (rs.next()) {
            Product product = new Product();
            int     id      = rs.getInt("id");
            String  name    = rs.getString("name");
            float   price   = rs.getFloat("price");

            product.setId(id);
            product.setName(name);
            product.setPrice(price);

            products.add(product);
         }
      } catch (SQLException e) {
         e.printStackTrace();
      }
      return products;
   }

   public Product getProduct(int id){
      Product product = null;
      try(Connection conn = getConn(); Statement s = conn.createStatement()){
         String sql = "select * from product where id =" + id;
         ResultSet rs = s.executeQuery(sql);
         while(rs.next()){
            product = new Product();
            String name = rs.getString("name");
            Float price = rs.getFloat("price");

            product.setName(name);
            product.setPrice(price);
         }
      }catch (SQLException e){
         e.printStackTrace();
      }
      return product;
   }
}
