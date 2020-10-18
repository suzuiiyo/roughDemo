<%--
  Created by IntelliJ IDEA.
  User: yangw
  Date: 2020/10/15
  Time: 13:29
  To change this template use File | Settings | File Templates.
--%>
<%@ page contentType="text/html;charset=UTF-8" language="java" pageEncoding="UTF-8" import="java.util.*"%>
<script src="webjars/jquery/3.5.1/jquery.min.js"></script>
<script src="webjars/bootstrap/4.5.2/js/bootstrap.min.js"></script>
<link rel="stylesheet" href="webjars/bootstrap/4.5.2/css/bootstrap.min.css" />
<html>
<head>
    <title>登陆页面</title>
</head>
<body>
<!--
<script type="text/javascript">
    $(document).ready(function(){
        $("#submit").click(function(){
            location.href="/login";
        });
    });
</script>

<div>
    <div class="form-group">
        <label class="custom-control-label">用户名</label>
        <input class="form-control" type="text" placeholder="请输入用户名" name="name" />
    </div>
    <div class="form-group">
        <label class="control-label">密码</label>
        <input class="form-control" type="password" placeholder="请输入密码" name="password" />
    </div>
    <div class="form">
        <button id="submit" class="btn btn-default btn-lg btn-block" >登录</button>
    </div>
</div>
-->
<div align="center">
    <form action="login" method="post">
        <p>
            账户:<input type="text" name="name" placeholder="请输入账户名">
        </p>
        <p>
            密码:<input type="text" name="password" placeholder="请输入密码">
        </p>
        <input type="submit" value="登陆">
    </form>
</div>
</body>
</html>
