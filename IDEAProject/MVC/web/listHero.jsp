<%@ page import="bean.Hero" %>
<%@ page import="java.lang.reflect.Array" %>
<%@ page import="java.util.ArrayList" %>
<%@ page import="java.util.List" %>
<%@ page import="DAO.HeroDAO" %><%--
  Created by IntelliJ IDEA.
  User: yangw
  Date: 2020/10/3
  Time: 12:02
  To change this template use File | Settings | File Templates.
--%>
<%@ page contentType="text/html;charset=UTF-8" language="java" %>
<html>
    <head>
        <meta http-equiv="Content-Type" content="text/html; charset=utf-8">
        <title>英雄列表</title>
    </head>
    <body>
        <table align="center" border="1" cellspacing="2">
            <tr><td>id</td><td>name</td><td>hp</td><td>attack</td><td>edit</td></tr>
            <%
                List<Hero> heroList = new HeroDAO().list();
                String strFormat = "<tr><td>%d</td><td>%s</td><td>%f</td><td>%f</td><td><a href='editHero?id=%d'>edit</a></td></tr>";
                for(Hero hero : heroList){
                    String str = String.format(strFormat, hero.getId(), hero.getName(), hero.getHp(), hero.getAttack(), hero.getId());
                    out.print(str);
                }
            %>
        </table>
    </body>
</html>
