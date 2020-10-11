package servlet;

import DAO.UserDAO;
import bean.User;

import javax.servlet.http.HttpServlet;
import javax.servlet.http.HttpServletRequest;
import javax.servlet.http.HttpServletResponse;
import java.io.IOException;

public class UserLoginServlet extends HttpServlet {
    @Override
    protected void service(HttpServletRequest request, HttpServletResponse response) throws IOException {
        String name = request.getParameter("name");
        String password = request.getParameter("password");

        User user = new UserDAO().getUser("name", "password");
        if(null != user){
            request.getSession().setAttribute("user", user);
            response.sendRedirect("/listProduct");
        }else{
            response.sendRedirect("/login.jsp");
        }
    }
}
