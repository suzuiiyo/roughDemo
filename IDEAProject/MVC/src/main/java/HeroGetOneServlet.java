import DAO.HeroDAO;
import bean.Hero;

import javax.servlet.http.HttpServlet;
import javax.servlet.http.HttpServletRequest;
import javax.servlet.http.HttpServletResponse;
import java.io.IOException;
import java.util.Random;

/**
 * @author yangw
 */
public class HeroGetOneServlet extends HttpServlet {
    @Override
    protected void service(HttpServletRequest req, HttpServletResponse resp) throws IOException {
        Random rand = new Random();
        int i = (rand.nextInt(1+99))+1;
        HeroDAO heroDAO = new HeroDAO();
        Hero hero = heroDAO.get(i);

        String heroStr = hero.toString();
        resp.setContentType("text/html; charset=UTF-8");
        resp.getWriter().print(heroStr);
    }
}
