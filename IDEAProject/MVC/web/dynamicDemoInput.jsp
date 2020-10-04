<%@ page language="java" contentType="text/html; charset=utf-8" pageEncoding="utf-8" import="java.util.*"%>
<%
    String path = request.getContextPath();
    String basePath = request.getScheme() + "://" + request.getServerName() + ":" +request.getServerPort() + path + "/";
%>

<!DOCTYPE HTML PUBLIC "-//W3C//DTD HTML 4.01 Transitional//EN">
<html>
    <head>
        <base href="<%=basePath%>">

        <title>My JSP 'input.jsp' starting page</title>

        <meta http-equiv="pragma" content="no-cache">
        <meta http-equiv="cache-control" content="no-cache">
        <meta http-equiv="expires" content="0">
        <meta http-equiv="keywords" content="keywarod1, keyword2, keyword3">
        <meta http-equiv="description" content="This is my page">
        <!--
            <link rel="stylesheet" type="text/css" href="style.css">
        -->
    </head>

    <body>
        <form action="dynamicDemoOut.jsp">
            row:<input type="text" name="row"><br>
            col:<input type="text" name="col"><br>
            <input type="submit" value="submit">
        </form>
    </body>
</html> 