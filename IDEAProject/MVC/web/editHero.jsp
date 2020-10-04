<%--
  Created by IntelliJ IDEA.
  User: yangw
  Date: 2020/9/29
  Time: 22:05
  To change this template use File | Settings | File Templates.
--%>
<%@ page language="java" contentType="text/html; charset=utf-8" pageEncoding="utf-8" import ="java.util.*, bean.Hero, java.sql.*"%>
<html>
<head>
    <title>编辑英雄</title>
</head>
<body>
    <div style="width: 100%; text-align: center">
    <form action="updateHero" method="post">
        名字: <input type='text' name='name' value='${hero.name}'><br>
        血量: <input type='text' name='hp' value=''${hero.hp}'><br>
        伤害: <input type='text' name='attack' value='${hero.attack}'><br>
        <input type='hidden' name='id' value='${hero.id}'>
        <input type='submit' value="更新">
    </form>
    </div>
</body>
</html>
