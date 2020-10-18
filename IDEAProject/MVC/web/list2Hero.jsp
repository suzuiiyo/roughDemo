<%--
  Created by IntelliJ IDEA.
  User: yangw
  Date: 2020/10/3
  Time: 20:22
  To change this template use File | Settings | File Templates.
--%>
<%@ page contentType="text/html; charset=utf-8" language="java" pageEncoding="utf-8" import="java.util.*" %>
<%@ taglib uri="http://java.sun.com/jsp/jstl/core" prefix="c" %>
<html>
    <script src="${pageContext.request.contextPath}/webjars/jquery/3.5.1/jquery.min.js"></script>
    <script src="webjars/bootstrap/4.5.2/js/bootstrap.min.js"></script>
    <link rel="stylesheet" href="webjars/bootstrap/4.5.2/css/bootstrap.min.css" />
<head>
    <title>英雄2列表</title>
</head>
<body style="background: url(backgroundImagie.jpg); background-size: 100% 100%; background-attachment: fixed">
    <script>
        $(function (){
            $("a").addClass("btn btn-default btn-light");
        });
    </script>
    <table style="width:650px; margin: 44px auto" class="table table-striped table-bordered table-hover table-light" align="center" border="1" cellspacing="0">
        <tr>
            <td>id</td>
            <td>name</td>
            <td>hp</td>
            <td>attack</td>
            <td>edit</td>
            <td>delete</td>
        </tr>
        <c:forEach items="${heroes}" var="hero" varStatus="st">
            <tr>
                <td>${hero.id}</td>
                <td>${hero.name}</td>
                <td>${hero.hp}</td>
                <td>${hero.attack}</td>
                <td><a href="editHero?id=${hero.id}">编辑</a></td>
                <td><a href="deleteHero?id=${hero.id}">删除</a></td>
            </tr>
        </c:forEach>
        <c:choose>
            <c:when test="${next <= maxId}">
                <tr>
                    <td colspan="6" align="center">
                        <a href="?start=0">【首页】</a>
                        <a href="?start=${pre}">【上一页】</a>
                        <a href="?start=${next}">【下一页】</a>
                        <a href="?start=${last}">【末页】</a>
                    </td>
                </tr>
            </c:when>
            <c:otherwise>
                <script type="text/javascript">
                    alert("数据已列完,点击确认跳转到首页");
                    window.location.href = "/listHero";
                </script>
            </c:otherwise>
        </c:choose>
    </table>
</body>
</html>
