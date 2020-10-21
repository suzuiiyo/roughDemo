package servlet;

import bean.Order;
import bean.OrderItem;
import bean.User;
import dao.OrderDAO;
import dao.OrderItemDAO;
import dao.UserDAO;

import javax.servlet.ServletException;
import javax.servlet.http.HttpServlet;
import javax.servlet.http.HttpServletRequest;
import javax.servlet.http.HttpServletResponse;
import java.io.IOException;
import java.time.temporal.Temporal;
import java.util.List;

public class OrderCreateServlet extends HttpServlet {
    @Override
    protected void service(HttpServletRequest req, HttpServletResponse resp) throws ServletException, IOException {
        User u = (User) req.getSession().getAttribute("user");
        if(null == u){
            resp.sendRedirect("/login.jsp");
            return;
        }
        Order o = new Order();
        o.setUser(u);

        new OrderDAO().insert(o);
        List<OrderItem> ois = (List<OrderItem>) req.getSession().getAttribute("ois");
        for(OrderItem oi : ois){
            oi.setOrder(o);
            new OrderItemDAO().insert(oi);
        }
        ois.clear();

        resp.setContentType("text/html; charset=UTF-8");
        resp.getWriter().println("订单创建成功");
    }
}
