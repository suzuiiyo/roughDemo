import DAO.HeroDAO;
import bean.Hero;

import javax.servlet.ServletException;
import javax.servlet.http.HttpServlet;
import javax.servlet.http.HttpServletRequest;
import javax.servlet.http.HttpServletResponse;
import java.io.IOException;

public class HeroAddServlet extends HttpServlet {
    @Override
    protected void service(HttpServletRequest req, HttpServletResponse resp) throws ServletException, IOException {
        HeroDAO heroDAO = new HeroDAO();
        String name = req.getParameter("name");
        float hp = Float.parseFloat(req.getParameter("hp"));
        float attack = Float.parseFloat(req.getParameter("attack"));

        Hero hero = new Hero();
        hero.setName(name);
        hero.setAttack(attack);
        hero.setHp(hp);

        heroDAO.add(hero);
        resp.sendRedirect("/listHero");
    }
}
