import bean.Hero;
import DAO.HeroDAO;

import javax.servlet.http.HttpServlet;
import javax.servlet.http.HttpServletRequest;
import javax.servlet.http.HttpServletResponse;
import java.io.IOException;
/**
 * @author yangw
 */
public class HeroUpdateServlet extends HttpServlet {
    @Override
    protected void service(HttpServletRequest req, HttpServletResponse resp) throws IOException {
        int id = Integer.parseInt(req.getParameter("id"));
        String name = req.getParameter("name");
        float hp = Float.parseFloat(req.getParameter("hp"));
        float attack = Float.parseFloat(req.getParameter("attack"));

        Hero hero = new Hero();
        hero.setId(id);
        hero.setName(name);
        hero.setHp(hp);
        hero.setAttack(attack);

        System.out.println(hero.getId() + " " + hero.getName() + " " + hero.getHp() + hero.getAttack());
        new HeroDAO().update(hero);

        resp.sendRedirect("/listHero");
    }
}
