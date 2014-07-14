<?php

//Sac 
$emailsender = $_POST['emailDuvida'];

if(PATH_SEPARATOR == ";") $quebra_linha = "\n";
else $quebra_linha = "\n";

$nomeremetente     = $_POST['name'];
$emailremetente    = $_POST['emailDuvida'];
$emaildestinatario = " contact@carenet.com.br";
$mensagem          = $_POST['duvida'];

$mensagemHTML = '<P>Nome: '. $nomeremetente .' </P>
<P>Email: '. $emailremetente .'</P>
<p>Dúvida: <b><i>'.$mensagem.'</i></b></p>
<hr>';

$headers = "MIME-Version: 1.1" .$quebra_linha;
$headers .= "Content-type: text/html; charset=utf-8" .$quebra_linha;

$headers .= "From: " . $emailsender.$quebra_linha;
$headers .= "Reply-To: " . $emailremetente . $quebra_linha;

if(!mail($emaildestinatario, "Carenet SAC", $mensagemHTML, $headers ,"-r".$emailsender)){
    $headers .= "Return-Path: " . $emailsender . $quebra_linha;
    mail($emaildestinatario, "Carenet SAC", $mensagemHTML, $headers );
}


?>
