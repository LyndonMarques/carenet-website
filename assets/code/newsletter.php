<?php

$email = strip_tags($_REQUEST['email']);

filter_var($email, FILTER_SANITIZE_STRING);

$sql = mysql_query("INSERT INTO newsletter(news_mail) VALUES('$email')");
