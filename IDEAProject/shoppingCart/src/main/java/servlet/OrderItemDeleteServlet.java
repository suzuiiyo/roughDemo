package servlet;

import bean.OrderItem;

import javax.servlet.RequestDispatcher;
import javax.servlet.ServletException;
import javax.servlet.http.HttpServlet;
import javax.servlet.http.HttpServletRequest;
import javax.servlet.http.HttpServletResponse;
import java.io.IOException;
import java.net.ResponseCache;
import java.util.ArrayList;
import java.util.List;

public class OrderItemDeleteServlet extends HttpServlet {
    @Override
    protected void service(HttpServletRequest req, HttpServletResponse resp) throws ServletException, IOException {
        List<OrderItem> ois = (List<OrderItem>) req.getSession().getAttribute("ois");
        List<OrderItem> ois4Delete = new ArrayList<>();

        int pid = Integer.parseInt(req.getParameter("pid"));
        for(OrderItem oi : ois){
            if(oi.getProduct().getId() == pid){
                ois4Delete.add(oi);
            }
        }
        ois.removeAll(ois4Delete);
        resp.sendRedirect("/listOrderItem");
    }
}
