import DAO.HeroDAO;
import bean.Hero;

import javax.servlet.ServletException;
import javax.servlet.http.HttpServlet;
import javax.servlet.http.HttpServletRequest;
import javax.servlet.http.HttpServletResponse;
import java.io.IOException;

/**
 * @author yangw
 */
public class HeroEditServlet extends HttpServlet {
    @Override
    protected void service(HttpServletRequest req, HttpServletResponse resp) throws ServletException, IOException {
        int id = Integer.parseInt(req.getParameter("id"));
        Hero hero = new HeroDAO().get(id);

        req.setAttribute("hero", hero);
        req.getRequestDispatcher("editHero.jsp").forward(req, resp);
    }
}
