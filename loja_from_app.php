<?php
include "assets/code/open_db.php";

$cupom                    = "";
$quantidade               = $_REQUEST['quantity'];
$desconto                 = null;
$valor                    = null;
$submeter_bcash_promocode = 0;

if(isset($_REQUEST['promocode'])) {
    $submeter_bcash_promocode = 1;
    $cupom = $_REQUEST['promocode'];
    $cupom = explode(' ',$cupom)[0];
    $cupom = strtoupper($cupom);
    $sql = mysql_query("SELECT * FROM cn_promocode WHERE cupom = '$cupom' AND ativo = 1");
    while($row = mysql_fetch_array($sql)){
        $desconto = $row['desconto'];
        $valor    = $row['vl_produto'];
    }
}

if ($submeter_bcash_promocode == 1) {
    $quantidade -= 1;
}
?>
<html>
<head>
    <style>
        .loader {
            position: fixed;
            left: 0px;
            top: 0px;
            width: 100%;
            height: 100%;
            z-index: 9999;
            background: url('/assets/img/page-loader.gif') 50% 50% no-repeat rgb(249,249,249);
        }
    </style>
    <script src="/assets/js/jquery-1.9.1.min.js"></script>
    <script>
        var last;
        var steps = undefined;
        <?php if ($submeter_bcash_promocode == 1 && $quantidade >0) { ?>
        steps = ['bcash_prod_submit','bcash_promocode_submit'];
        last  = 'bcash_prod_submit_f';
        <?php } elseif ($submeter_bcash_promocode == 1 && $quantidade ==0) { ?>
        steps = ['bcash_promocode_submit'];
        last  = 'bcash_promocode_submit_f';
        <?php } else {  ?>
        steps = ['bcash_prod_submit'];
        last  = 'bcash_prod_submit_f';
        <?php } ?>
        function loadSuccess() {
           if (steps == undefined || steps.length == 0) return;
            var step = steps.pop();
            btn = $('#'+step);
            if (steps.length == 0) {
                document.getElementById(step+'_f').target = "_self";
            }
            btn.click();
        }
        $(function(){
            $('#bcash_frame').load(function() {
                loadSuccess();
            });
            loadSuccess();
        });
    </script>
</head>
<body>

<form id="bcash_promocode_submit_remove_f" action="https://www.bcash.com.br/checkout/car/" method="post" target="bcash_frame">
    <input type="hidden" name="quant_prod" value="-1000"/>
    <input name="email_loja" type="hidden" value="contact@carenet.com.br"/>
    <input name="acao" type="hidden" value="add"/>
    <input name="cod_prod" type="hidden" value="<?= $cupom ?>"/>
    <input name="nome_prod" type="hidden" value="KLIP-Green - usando cupom <?= $cupom ?> - 1 un somente"/>
    <input name="peso_prod" type="hidden" value="90"/>
    <input name="valor_prod" type="hidden" value="<?= $valor ?>"/>
    <input id="bcash_promocode_submit_remove" type="submit" class="comprar" value="Comprar" style="border: none; display: none"/>
</form>

<form id="bcash_prod_submit_remove_f" action="https://www.bcash.com.br/checkout/car/" method="post" target="bcash_frame">
    <input type="hidden" name="quant_prod" value="-1000"/>
    <input name="email_loja" type="hidden" value="contact@carenet.com.br"/>
    <input name="acao" type="hidden" value="rem"/>
    <input name="cod_prod" type="hidden" value="11"/>
    <input name="nome_prod" type="hidden" value="KLIP-Green"/>
    <input name="peso_prod" type="hidden" value="90"/>
    <input name="valor_prod" type="hidden" value="199"/>
    <input id="bcash_prod_submit_remove" type="submit" class="comprar" value="Comprar" style="border: none; display: none"/>
</form>

<form id="bcash_promocode_submit_f" name="bcash_promocode_submit_f" action="https://www.bcash.com.br/checkout/car/" method="post" target="bcash_frame">
    <input type="hidden" name="quant_prod" value="1"/>
    <input name="email_loja" type="hidden" value="contact@carenet.com.br"/>
    <input name="acao" type="hidden" value="add"/>
    <input name="cod_prod" type="hidden" value="<?= $cupom ?>"/>
    <input name="nome_prod" type="hidden" value="KLIP-Green - usando cupom <?= $cupom ?> - 1 un somente"/>
    <input name="peso_prod" type="hidden" value="90"/>
    <input name="valor_prod" type="hidden" value="<?= $valor ?>" />
    <input id="bcash_promocode_submit" type="submit" class="comprar" value="Comprar" style="border: none; display: none"/>
</form>

<form id="bcash_prod_submit_f" name="bcash_prod_submit_f" action="https://www.bcash.com.br/checkout/car/" method="post" target="bcash_frame">
    <input type="hidden" name="quant_prod" value="<?= $quantidade ?>"/>
    <input name="email_loja" type="hidden" value="contact@carenet.com.br"/>
    <input name="acao" type="hidden" value="add"/>
    <input name="cod_prod" type="hidden" value="11"/>
    <input name="nome_prod" type="hidden" value="KLIP-Green"/>
    <input name="peso_prod" type="hidden" value="90" />
    <input name="valor_prod" type="hidden" value="199" />
    <input id="bcash_prod_submit" type="submit" class="comprar" value="Comprar" style="border: none; display: none"/>
</form>

<iframe id="bcash_frame" name="bcash_frame" src="about:blank" width="0" height="0" tabindex="-1" title="empty" style="display: none">
</iframe>

<div class="loader"></div>

</body>
</html>