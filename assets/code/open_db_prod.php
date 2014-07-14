<?php

$database = 'carenet';

global $db_connection;
global $log;
global $rest_debug;
global $log_path;

$rest_debug = 0;

$db_connection = mysql_connect('localhost', 'root', '@1@HZpw^$6kY');

if (!$db_connection) {
    die('Could not connect to host: ' . mysql_error());
}
if (!mysql_select_db($database)) {
    die('Could not connect to DB: ' . mysql_error());
}

$log_path = '/var/log/zend/prod/';
$log      = KLogger::instance($log_path, KLogger::DEBUG);

?>