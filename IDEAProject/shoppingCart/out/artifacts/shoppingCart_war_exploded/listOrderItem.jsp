<%--
  Created by IntelliJ IDEA.
  User: yangw
  Date: 2020/10/15
  Time: 16:24
  To change this template use File | Settings | File Templates.
--%>
<%@ page contentType="text/html;charset=UTF-8" language="java" pageEncoding="UTF-8" import="java.util.*" %>
<%@ taglib uri="http://java.sun.com/jsp/jstl/core" prefix="c" %>

<script src="webjars/jquery/3.5.1/jquery.min.js"></script>
<script src="webjars/bootstrap/4.5.2/css/bootstrap.min.css" ></script>
<link rel="stylesheet" href="webjars/bootstrap/4.5.2/css/bootstrap.min.css" />

<html>
<head>
    <title>购物车展示</title>
</head>
<body>
<h1 align='center'>购物车</h1>
        <table style="width: 500px; margin: 44px auto">
            <tr>
                <td>商品名称</td>
                <td>单价</td>
                <td>数量</td>
                <td>小计</td>
                <td>删除</td>
            </tr>

            <c:forEach items="${ois}" var="oi" varStatus="st">
                <tr>
                    <td>${oi.product.name}</td>
                    <td>${oi.product.price}</td>
                    <td>${oi.num}</td>
                    <td>${oi.product.price*oi.num}</td>
                    <td><a href="deleteOrderItem?pid=${oi.product.id}">删除</a></td>
                </tr>
            </c:forEach>

            <c:if test="${!empty ois}">
                <tr>
                    <td colspan="4" align="right">
                        <a href="createOrder">生成订单</a>
                    </td>
                </tr>
            </c:if>
        </table>
</body>
</html>