<?php
include "open_db.php";

$cupom = $_GET['cupom'];

$sql = mysql_query("SELECT * FROM cn_promocode WHERE cupom = '$cupom'");

while($row = mysql_fetch_array($sql)){
   $desconto = $row['desconto'];
}
?>
