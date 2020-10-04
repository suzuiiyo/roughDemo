<%@ page language="java" contentType="text/html; charset=utf-8" pageEncoding="utf-8" import="java.util.*"%>
<%
    String path = request.getContextPath();
    String basePath = request.getScheme() + "://" + request.getServerName() + ":" + request.getServerPort() + path + "/";
%>

<!DOCTYPE HTML PUBLIC "-//W3C/DTD HTML 4.01 Transitional//EN">
<html>
    <head>
        <base href="<%=basePath%>">

        <title>My JSP 'output.jsp' starting page</title>

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
        <%int row=Integer.parseInt(request.getParameter("row"));
            int col=Integer.parseInt(request.getParameter("col"));
        %>
        <table align="center" border="1" width="180" cellpadding="10" cellspacing="10">
            <%for(int i=0; i<row; i++)
            {
                %>
                <tr>
                    <%for(int j=0; j<col; j++)
                    {   %>
                    <td>
                    </td>
                    <%
                    }
                %>
                </tr>
            <%
            }
            %>
        </table>

    </body>
</html>