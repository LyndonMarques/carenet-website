
<?php
include "open_db.php";

// Detect Language
define('LOCALE', 'en_US');
putenv("LC_ALL=" . LOCALE);
setlocale(LC_ALL, LOCALE);

// Set the text domain as 'messages'
$domain = 'messages';
bindtextdomain($domain, "/var/www/carenet.com.br/locale");
textdomain($domain);

$desconto = null;
$valor = "199,00";
$submeter_bcash = 0;

$sql = mysql_query("SELECT *, count(1) as total FROM cn_promocode WHERE cupom = '$_REQUEST[cupom]' AND ativo = 1");

while($row = mysql_fetch_array($sql)){
    if($_GET['cupom'] && $row['total'] == 1 ) {
        unset($_SESSION['cupom']);
    }
}

if (isset($_REQUEST['cupom']) && !isset($_SESSION['cupom'])) {

    $sql = mysql_query("SELECT *, count(1) as total FROM cn_promocode WHERE cupom = '$_REQUEST[cupom]' AND ativo = 1");

    while($row = mysql_fetch_array($sql)){

        if($row['total'] > 0) {
            $_SESSION['desconto'] = $row['desconto'];
            $valor = $row['vl_produto'];
            $_SESSION['cupom'] = $row['cupom'];
            $_SESSION['valor'] = $valor;
            $submeter_bcash = 1;
        }
    }
}

if(isset($_SESSION['cupom'])){
    $cupom = $_SESSION['cupom'];
    $cupom = strtoupper($cupom);
}

if ($submeter_bcash) {
    ?>
    <iframe id="bcash_promocode" name="bcash_promocode" src="about:blank" width="0" height="0" tabindex="-1" title="empty" style="display: none">
    </iframe>
    <form action="https://www.bcash.com.br/checkout/car/" method="post" target="bcash_promocode">
        <input type="hidden" name="quant_prod" value="1">
        <input name="email_loja" type="hidden" value="contact@carenet.com.br">
        <input name="acao" type="hidden" value="add">
        <input name="cod_prod" type="hidden" value="<?= $cupom ?>">
        <input name="nome_prod" type="hidden" value="KLIP-Green - usando cupom <?= $cupom ?> - 1 um somente">
        <input name="peso_prod" type="hidden" value="90">
        <input name="valor_prod" type="hidden" value="<?= $valor ?>" >
        <input id="bcash_promocode_submit" type="submit" class="comprar" value="Comprar" style="border: none; display: none">
    </form>
    <script>
        $(function(){
            $("#bcash_promocode_submit").click();
        });
    </script>
<?php } ?>
<script>
    <?php if ($_SESSION['desconto']) { ?>
    function ajustaQuant() {
        $("#quant_prod").val($("#quant_prod_sel").val());
        return true;
    }
    <?php } else { ?>
    function ajustaQuant() {
        $("#quant_prod").val($("#quant_prod_sel").val());
        return true;
    }
    <?php } ?>
</script>

<div class="container-loja" id="no-mediabox">
<div id="content-top">
    <a href="/loja" class="aux-nav"><?= _("Produtos") ?></a>

    <div class="row pagamento">
        <div class="col main-title">
            <a href="/loja" class="back"><i></i> <?= _("Voltar") ?></a>
        </div>
        <div class="col2 formas-pagamento2">
            <h2>
                <small><?= _("Todos os produtos em até") ?> </small>
                <?= _("10x no cartão") ?>
            </h2>
        </div>
    </div>
</div>

<div class="clear"></div>

<div class="main-content">
<div class="product-box">
<div class="row product-top-box">
    <div class="gallery col">
        <div class="" style="height: 423px; width: 472px; margin-left: -60px;  ">

            <div class="advanced-slider" id="responsive-slider" >
                <ul class="slides" style="padding: 0; margin: 0">
                    <li class="slide">
                        <img class="image" src="/assets/img/slider/clip1.jpg" width="200" alt=""/>
                        <img class="thumbnail" src="/assets/img/slider/thumb1.jpg" />
                    </li>

                    <li class="slide rounded-caption">
                        <img class="image" src="/assets/img/slider/clip2.jpg" width="500" alt=""/>
                        <img class="thumbnail" src="/assets/img/slider/thumb2.jpg" />
                    </li>

                    <li class="slide">
                        <img class="image" src="/assets/img/slider/clip3.jpg" width="500" alt=""/>
                        <img class="thumbnail" src="/assets/img/slider/thumb3.jpg" alt=""/>
                    </li>

                    <li class="slide">
                        <img class="image" src="/assets/img/slider/clip4.jpg" width="500" alt=""/>
                        <img class="thumbnail" src="/assets/img/slider/thumb4.jpg" alt="" />
                    </li>

                    <li class="slide">
                        <img class="image" src="/assets/img/slider/clip5.jpg" width="500" alt=""/>
                        <img class="thumbnail" src="/assets/img/slider/thumb5.jpg" alt="" />
                    </li>

                    <li class="slide">
                        <img class="image" src="/assets/img/slider/clip6.jpg" width="400"  alt="Claudia Cepakua"/>
                        <img class="thumbnail" src="/assets/img/slider/thumb6.jpg" alt="" />
                    </li>

                    <li class="slide">
                        <img class="image" src="/assets/img/slider/clip7.jpg"  alt=""/>
                        <img class="thumbnail" src="/assets/img/slider/thumb7.jpg" alt="" />
                    </li>

                    <li class="slide">
                        <img class="image" src="/assets/img/slider/clip8.jpg"  alt=""/>
                        <img class="thumbnail" src="/assets/img/slider/thumb8.jpg" height="40" alt="" />
                    </li>

                    </li>
                </ul>
            </div>
        </div>
    </div>

    <div class="primary-info col">
        <h1><?= _("Biossensor Klip Carenet Green") ?></h1>
        <small><?= _("Biossensores") ?></small>
        <hr>
        <div class="row">
            <div class="classificacoes">
                <img src="/assets/img/loja/star-white32.png" style="float: left;"/>
                <img src="/assets/img/loja/star-white32.png" style="float: left;"/>
                <img src="/assets/img/loja/star-white32.png" style="float: left;"/>
                <img src="/assets/img/loja/star-white32.png" style="float: left;"/>
                <img src="/assets/img/loja/star-white32.png" />
                (0) <?= _("Sem classificações") ?>
            </div>
            <div class="price-info">
                <span class="price" ><?php if(isset($_SESSION['cupom']))echo "R$ ". str_replace(".", ",", $_SESSION['valor']); else echo "R$ ". str_replace(".", ",", $valor); ?></span>
                <span class="payment-option"><?= _("parcele em até 10x") ?></span>
            </div>
        </div>

        <div class="availability">
                                <span class="em-estoque">
                                    <?= _("Disponível em estoque") ?>
                                </span>
            <?= _("compra direta na") ?>
            <span class="store carenet-store">
                                    Carenet Longevity
                                </span>
            <div>
                <img src="/assets/img/interrogacao.png" style="margin-left: 2px"> &nbsp; Dúvidas sobre o KLIP? <a id="create-user" title="Fale conosco" href="javascript:void(0)" style="color: #00D6BC; text-decoration: none">Fale conosco </a>
            </div>
        </div>
        <form method="post" action="<?php echo $_SERVER['PHP_SELF'];?>">
            <div class="promocode">
                <?php
                if(isset($_SESSION['desconto'])){
                    ?>
                    <i></i> <?= _("Promocode") ?> "<?= $_SESSION['cupom'] ?>":
                    <?= _("Desconto de") ?> <?= $_SESSION['desconto'] ?>% <?= _("na primeira unidade") ?>
                <?php
                } else {
                    ?>
                    <i></i> <?= _("Tem um Promocode?") ?>
                    <label for="cupom"></label>
                    <input name="cupom" id="cupom" type="text" />
                    <input type="submit" value="OK">
                <?php
                }
                ?>
            </div>
        </form>

        <form action="https://www.bcash.com.br/checkout/car/" method="post" target="carrinho" onsubmit="return ajustaQuant();">
            <div class="quantidade">
                <i></i><label for="quant_prod"><?= _("Quantidade") ?></label>
                    <span>

                    <span id="menos" style="background: none; width: 2px; margin: 0; padding: 0; border: none; cursor: pointer; margin-left: 30px; font-size: 28px; position: relative;top: 2px; color: #000">-</span>
                        <input readonly="true" id="quant_prod_sel" name="quant_prod_sel" type="text" value="1" style="width: 60px;text-align: center;font-size: 20px;font-weight: bolder;background: none; border: none; outline: 0; padding-left: 0px"; >
                    <span id="mais" style="background: none; width: 2px; margin: 0; padding: 0; border: none; cursor: pointer;  margin-right: 30px; font-size: 28px; position: relative;top: 2px; color: #000">+</span>

                    </span>
            </div>

            <span class="arrow-buy"></span>

            <hr />
            <input type="hidden" id="quant_prod" name="quant_prod" value="">
            <input name="email_loja" type="hidden" value="contact@carenet.com.br">
            <input name="acao" type="hidden" value="add">
            <input name="cod_prod" type="hidden" value="11">
            <input name="nome_prod" type="hidden" value="KLIP-Green">
            <input name="peso_prod" type="hidden" value="90">
            <input name="valor_prod" type="hidden" value="199" >
            <input type="submit" id="comprar" class="comprar" value="Comprar" style="border: none">
        </form>
    </div>
</div>

<div class="topic">
    <h4><i></i><?= _("Descrição") ?></h4>
    <p>
        <?= _("O biossensor KLIP Carenet será seu maior aliado na busca de seus objetivos para melhorar sua saúde e bem-estar.  Você poderá saber diariamente o número de passos dados, calorias queimadas, tempo de atividade física e distância percorrida e visualizar todas essas informações através do visor do dispositivo. Poderá também utilizar o aplicativo gratuito Carenet Longevity para sincronizar e consolidar todas essas informações em seu telefone celular e verificar seu desempenho, incluindo dados sobre a qualidade do seu sono e em gráficos completos e fáceis de entender. Comece a cuidar de você HOJE.") ?><br />
        <small>
            <?= _("Atenção: o KLIP Carenet não é à
                                prova d'água.") ?>
        </small>
    </p>
</div>

<div class="row">
    <div class="col features">
        <ul>
            <li class="atividades">
                <h3><i></i><?= _("Atividades diárias") ?></h3>
                <p>
                    <?= _("Monitora seus passos, distância
                                      percorrida, calorias queimadas e o
                                      alcance da sua meta diária através de
                                      um visor integrado.") ?>
                </p>
            </li>
            <li class="monitoramento">
                <h3><i></i><?= _("Monitoramento do sono") ?></h3>
                <p>
                    <?= _("Controla sua qualidade do sono.") ?>
                </p>
            </li>
            <li class="compartilhamento">
                <h3>
                    <i></i>
                    <?= _("Compartilhamento e sincronização online de dados") ?>
                </h3>
                <p>
                    <?= _("Transferência de dados das suas atividades através de cabo USB.") ?>
                </p>
            </li>
            <li class="gerenciamento">
                <h3><i></i><?= _("Gerenciamento online") ?></h3>
                <p>
                    <?= _("Monitoramento online e mobile de seus objetivos de saúde e metas alcançadas.") ?>
                </p>
            </li>
        </ul>
    </div>
    <div class="col video-help">
        <h3><?= _("Como usar") ?></h3>
        <object width="350" height="196.875">
            <param name="movie" value="https://www.youtube.com/v/sDEbOScR-Jg?version=3"/>
            <param name="allowFullScreen" value="true"/>
            <param name="allowScriptAccess" value="always"/>
            <embed src="https://www.youtube.com/v/sDEbOScR-Jg?version=3" type="application/x-shockwave-flash" allowfullscreen="true" allowScriptAccess="always" width="350" height="196.875"></embed>
        </object>
        <p>
            <?= _("Para dormir, para se exercitar, para trabalhar, não importa, o KLIP Carenet irá colher dados a respeito de suas atividades diárias.") ?>
        </p>
    </div>
</div>

<table>
    <tr>
        <td><?= _("Nome do Produto") ?></td>
        <td><?= _("JP1301 Activity Tracker Sleep Monitor") ?></td>
    </tr>
    <tr>
        <td><?= _("Dimensões") ?></td>
        <td>58 x 21.5 x 15mm </td>
    </tr>
    <tr>
        <td><?= _("Peso") ?></td>
        <td>11.5g</td>
    </tr>
    <tr>
        <td><?= _("Bateria") ?></td>
        <td><?= _("Bateria de polímero de lítio recarregável") ?></td>
    </tr>
    <tr>
        <td><?= _("Memória") ?></td>
        <td><?= _("Tela Oled") ?></td>
    </tr>
</table>

<div class="topic">
    <h4><i></i></h4>
    <ul class="products-list">
    </ul>
    <div class="clear"></div>
</div>

<div style="text-align: center">
    <div class="paywith row pagination-bottom">
        <p>
            <?= _("Pague com") ?>
        </p>
    </div>
    <img style="margin-left: 40px" src="/assets/img/loja/pagamentos-bcash.png">
</div>

<!-- <div class="topic">
                        <h4><i></i><?= _("Produtos Relacionados") ?></h4>
                        <ul class="products-list">
                            <li>
                                <small class="cod">COD 1209</small>
                                <div class="photo-box">
                                    <a href="#">
                                        <img src="/assets/img/loja/produtos/klip-green.png">
                                    </a>
                                </div>
                                <div class="details">
                                    <a href="#" class="name">
                                        <?= _("Carenet Klip Green") ?>
                                    </a>
                                    <span class="price">R$ 199</span>
                                    <a href="#" class="action buy-yours">
                                        <?= _("Compre o Seu") ?>
                                    </a>
                                </div>
                            </li>
                            <li>
                                <small class="cod">COD 1209</small>
                                <div class="photo-box">
                                    <a href="#">
                                        <img src="/assets/img/loja/produtos/klip-blue.png">
                                    </a>
                                </div>
                                <div class="details">
                                    <a href="#" class="name">
                                        <?= _("Carenet Klip Blue") ?>
                                    </a>
                                    <span class="price">R$ 199</span>
                                    <a href="#" class="action coming-soon">
                                        <?= _("Em Breve") ?>
                                    </a>
                                </div>
                            </li>
                            <li>
                                <small class="cod">COD 1209</small>
                                <div class="photo-box">
                                    <a href="#">
                                        <img src="/assets/img/loja/produtos/klip-red.png">
                                    </a>
                                </div>
                                <div class="details">
                                    <a href="#" class="name">
                                        <?= _("Carenet Klip Red") ?>
                                    </a>
                                    <span class="price">R$ 199</span>
                                    <a href="#" class="action coming-soon">
                                        <?= _("Em Breve") ?>
                                    </a>
                                </div>
                            </li>
                        </ul>
                        <div class="clear"></div>
                    </div>-->

</div>
</div> <!-- .main-content -->
</div>

<div style="display: none">
    <img src="/assets/img/loja/produtos/produto-foco01.jpg" id="source_image1" />
    <img src="/assets/img/loja/produtos/produto-foco02.jpg" id="source_image2" />
    <img src="/assets/img/loja/produtos/produto-foco03.jpg" id="source_image3" />
    <img src="/assets/img/loja/produtos/produto-foco04.jpg" id="source_image4" />
</div>

<script>
    $('#comprar').on('click', function() {
        ga('send', 'event', 'comprar', 'click', 'nav-buttons');
    });

    function changeImage(id) {
        $("#target_image").attr("src",$("#source_image"+id).attr("src"));
        return false;
    }

    $("#mais").click(function(){
        var qtd = $("#quant_prod_sel").val();
        $("#quant_prod_sel").val(parseInt(qtd) + 1 )
    })

    $("#menos").click(function(){
        var qtd = $("#quant_prod_sel").val();
        if(qtd >= 1) {
            $("#quant_prod_sel").val(parseInt(qtd) - 1 )
        }
    })

    jQuery(document).ready(function($){
        $('#responsive-slider').advancedSlider({width: '400px',
            height: '450px',
            scaleType: 'outsideFit',
            skin: 'glossy-square-gray',
            effectType: 'swipe',
            pauseSlideshowOnHover: true,
            swipeThreshold: 2,
            slideButtons: false,
            thumbnailType: 'scroller',
            thumbnailButtons: true,
            thumbnailScrollerResponsive: true,
            minimumVisibleThumbnails: 4,
            slideProperties:{
                0:{captionSize: 35, captionHideEffect: 'slide'},
                1:{captionPosition: 'custom', captionShowEffect: 'fade', captionHeight: 160, captionLeft: 70, slideshowDelay: 10000},
                3:{captionSize: 10},
                5:{captionPosition: 'left', captionSize: 150, captionHideEffect: 'slide'},
                7:{captionPosition: 'right', captionSize: 150, captionHideEffect: 'slide'}
            }
        });
    });
</script>

<style>

    fieldset,input.text { margin-bottom:12px; width:95%; padding: .4em; }
    fieldset { padding:0; border:0; margin-top:25px; }
    h1 { font-size: 1.2em; margin: .6em 0; }
    div#users-contain { width: 350px; margin: 20px 0; }
    div#users-contain table { margin: 1em 0; border-collapse: collapse; width: 100%; }
    div#users-contain table td, div#users-contain table th { border: 1px solid #eee; padding: .6em 10px; text-align: left; }
    .ui-dialog .ui-state-error { padding: .3em; }
    .validateTips { border: 1px solid transparent; padding: 0.3em; }
</style>
<script>

    $(function() {
        var dialog, form,
// From http://www.whatwg.org/specs/web-apps/current-work/multipage/states-of-the-type-attribute.html#e-mail-state-%28type=email%29
            emailRegex = /^[a-zA-Z0-9.!#$%&'*+\/=?^_`{|}~-]+@[a-zA-Z0-9](?:[a-zA-Z0-9-]{0,61}[a-zA-Z0-9])?(?:\.[a-zA-Z0-9](?:[a-zA-Z0-9-]{0,61}[a-zA-Z0-9])?)*$/,
            name = $( "#name" ),
            email = $( "#emailDuvida" ),
            password = $( "#password" ),
            allFields = $( [] ).add( name ).add( email ).add( password ),
            tips = $( ".validateTips" );

        dialog = $( "#dialog-form" ).dialog({
            autoOpen: false,
            height: 320,
            width: 310,
            modal: true,
            buttons: {
                "Enviar": duvida,
                "Cancelar": function() {
                    dialog.dialog( "close" );
                }
            },
            close: function() {
                form[ 0 ].reset();
                allFields.removeClass( "ui-state-error" );
            }
        });

        function duvida() {

            var email = $("#emailDuvida").val();
            var nome = $("#name").val();
            var duvida = $("#duvida").val();

            if(nome == "" && email == "" && duvida == "") {
                alert("Preencha o campo nome!\nPreencha o campo email!\nPreencha o campo dúvida!")
            }
            else if(email == "" && duvida == "") {
                alert("Preencha o campo nome!\nPreencha o campo email!")
            }
            else if(nome == "") {
                alert('Preencha o campo nome!');
            }
            else if(email == "") {
                alert('Preencha o campo email!');
            }
            else if(duvida == "") {
                alert('Preencha o campo dúvida!');
            }
            else if(email != "")
            {
                var filtro = /^([\w-]+(?:\.[\w-]+)*)@((?:[\w-]+\.)*\w[\w-]{0,66})\.([a-z]{2,6}(?:\.[a-z]{2})?)$/i;
                if(!filtro.test(email))
                {
                    alert("Este endereço de email não é válido!");
                }else{
                    $.ajax({
                        type: 'post',
                        url: '/assets/code/duvida.php',
                        data: $('#formDuvidas').serialize(),
                        success: function(data) {
                            alert("Dúvida enviada com sucesso!");
                            dialog.dialog( "close" );
                        }
                    })
                }
            }
        }

        form = dialog.find( "form" ).on( "submit", function( event ) {
            event.preventDefault();
        });
        $( "#create-user" ).on( "click", function() {
            dialog.dialog( "open" );
        });
    });
</script>

<?php
$useragent = $_SERVER['HTTP_USER_AGENT'];

if (preg_match('|MSIE ([0-9].[0-9]{1,2})|',$useragent,$matched)) {
    $browser_version=$matched[1];
    echo "<style>
        textarea{
            margin-top: 17px;
            margin-left: -50px;
            width: 260px;
        }
    </style>";
} elseif(preg_match('|Firefox/([0-9\.]+)|',$useragent,$matched)) {
    $browser_version=$matched[1];
    echo "<style>
        textarea{
            margin-top: 19px;
            margin-left: -49px;
            width: 245px;
        }
    </style>";
} elseif(preg_match('|Chrome/([0-9\.]+)|',$useragent,$matched)) {
    $browser_version=$matched[1];
    echo "<style>
        textarea{
            margin-top: 17px;
            margin-left: -50px;
            width: 260px;
        }
    </style>";
} else {
    // browser not recognized!
    $browser_version = 0;
    echo "<style>
        textarea{
            margin-top: 17px;
            margin-left: -50px;
            width: 260px;
        }
    </style>";
}
?>

<div id="dialog-form" title="Fale conosco">

    <form id="formDuvidas">
        <fieldset>
            <label for="name">Nome</label>
            <input type="text" name="name" id="name" class="text ui-widget-content ui-corner-all">
            <label for="emailDuvida">Email</label>
            <input type="text" name="emailDuvida" id="emailDuvida" class="text ui-widget-content ui-corner-all">
            <label for="duvida">Dúvida</label>
            <textarea name="duvida" id="duvida" class="text ui-widget-content ui-corner-all"  style=""></textarea>
        </fieldset>
    </form>
</div>


