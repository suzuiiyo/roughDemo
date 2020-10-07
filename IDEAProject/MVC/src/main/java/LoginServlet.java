import javax.servlet.ServletException;
import javax.servlet.http.HttpServlet;
import javax.servlet.http.HttpServletRequest;
import javax.servlet.http.HttpServletResponse;
import java.io.IOException;
import java.io.PrintWriter;

public class LoginServlet extends HttpServlet {
    @Override
    protected void service(HttpServletRequest req, HttpServletResponse resp) throws ServletException, IOException {
        String name = req.getParameter("name");
        String password = req.getParameter("password");

        if("admin".equals(name) && "123".equals(password)){
            req.getSession().setAttribute("userName", name);
            resp.sendRedirect("/listHero");
        }else {
            resp.setContentType("text/html; charset=UTF-8");
            PrintWriter out = resp.getWriter();
            out.println("<script language='javascript'>alert('账户密码不匹配，请重新登录'); window.location.href='login.html';</script>");
        }
    }
}
