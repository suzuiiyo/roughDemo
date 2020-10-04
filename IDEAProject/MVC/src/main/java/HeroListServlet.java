import DAO.HeroDAO;
import bean.Hero;

import javax.servlet.ServletException;
import javax.servlet.http.HttpServlet;
import javax.servlet.http.HttpServletRequest;
import javax.servlet.http.HttpServletResponse;
import java.io.IOException;
import java.util.List;

public class HeroListServlet extends HttpServlet {
    @Override
    protected void service(HttpServletRequest req, HttpServletResponse reps) throws ServletException, IOException {
        int start = 0;
        int count = 10;

        try{
            start = Integer.parseInt(req.getParameter("start"));
        }catch (NumberFormatException e){
            //当浏览器没有传参数start时
        }
        HeroDAO heroDAO = new HeroDAO();
        int next = start + count;
        int pre = start - count;
        int total = heroDAO.getTotal();
        int maxId = heroDAO.getMaxId();
        int last;
        //假设总数是50，是能够被5整除的，那么最后一页的开始就是45
        if(0 == total % count) {
            last = total - count;
        } else {
            last = total - total % count;
        }

        pre = pre < 0 ? 0 : pre;
        //last和maxId功能有重叠
        //next = next > last ? last : next;
        List<Hero> heroes = heroDAO.list(start, count);
        req.setAttribute("next", next);
        req.setAttribute("pre", pre);
        req.setAttribute("maxId", maxId);
        req.setAttribute("last", last);
        req.setAttribute("heroes", heroes);
        req.getRequestDispatcher("list2Hero.jsp").forward(req, reps);
    }
}
