<?php

$database = 'dev_carenet';

global $db_connection;

$db_connection = mysql_connect('173.230.151.149', 'careext', 'u4x3dDlW7@DQ');

if (!$db_connection) {
    die('Could not connect to host: ' . mysql_error());
}
if (!mysql_select_db($database)) {
    die('Could not connect to DB: ' . mysql_error());
}

mysql_query("SET NAMES 'utf8'");
mysql_query("SET CHARACTER SET utf8");
mysql_query("SET SESSION collation_connection = 'utf8_unicode_ci'");

?>