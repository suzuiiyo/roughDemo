<%--
  Created by IntelliJ IDEA.
  User: yangw
  Date: 2020/10/15
  Time: 10:38
  To change this template use File | Settings | File Templates.
--%>
<%@ page contentType="text/html;charset=UTF-8" language="java" pageEncoding="UTF-8" import="java.util.*" isELIgnored="false" %>
<%@ taglib uri="http://java.sun.com/jsp/jstl/core" prefix="c" %>
<html>
    <script src="webjars/jquery/3.5.1/jquery.min.js"></script>
    <script src="webjars/bootstrap/4.5.2/js/bootstrap.min.js"></script>
    <link rel="stylesheet" href="webjars/bootstrap/4.5.2/css/bootstrap.min.css" />
<script>
    $(function() {
        $("input.addCartButton").removeAttr("disabled");
        $("input.addCartButton").click(function () {
            $(this).attr("disabled", "disabled");
            var button = $(this);
            var pid = $(this).attr("pid");
            var number = $("input.number[pid=" + pid + "]").val();
            var page = " /addOrderItem";
            $.get(
                page,
                {"num": number, "pid": pid},
                function (result) {
                    $("#addCartSuccessMessage").fadeIn(1200);
                    $("#addCartSuccessMessage").fadeOut(1200, function () {
                        button.removeAttr("disabled");
                    });
                }
            );
        });

        $("#addCartSuccessMessage").hide();
    });
</script>
<head>
    <title>商品展示</title>
</head>
<body>
    <c:if test="${!empty user}">
        <div align="center">
            当前用户: ${user.name}
        </div>
    </c:if>

    <div align='center' style="height:20px; margin:20px;">
        <span style="color: aquamarine" id="addCartSuccessMessage">加入购物车成功</span>
    </div>

    <table style="width:530px; margin: 44px auto" class="table table-striped table-bordered table-hover table-light" align="center" border="1" cellspacing="0">
        <tr>
            <td>id</td>
            <td>名称</td>
            <td>价格</td>
            <td>购买</td>
        </tr>
        <c:forEach items="${products}" var="product" varStatus="st">
        <tr>
            <td>${product.id}</td>
            <td>${product.name}</td>
            <td>${product.price}</td>
            <td>
                <!--
            <form action="addOrderItem" method="post">
                数量<input type="text" value="1" name="num">
                <input type="hidden" name="pid" value="${product.id}">
                <input type="submit" value="购买">
            </form>
                -->

                数量<input pid="${product.id}" class="number" type="text" value="1" name="num">
                <input class="addCartButton" pid="${product.id}" type="submit" value="加入购物车">
        </tr>
        </c:forEach>
            <tr>
                <td colspan="4" align="center"><a href="listOrderItem">查看购物车</a></td>
            </tr>
    </table>
</body>
</html>
