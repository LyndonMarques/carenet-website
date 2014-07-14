<?php
include "assets/code/open_db.php";

// Detect Language
//define('LOCALE', 'en_US');
//putenv("LC_ALL=" . LOCALE);
setlocale(LC_ALL, LOCALE);

// Set the text domain as 'messages'
$domain = 'messages';
bindtextdomain($domain, "/var/www/carenet.com.br/locale");
textdomain($domain);

$desconto       = null;
$valor          = null;
$submeter_bcash = 0;

if (isset($_REQUEST['cupom']) && !isset($_SESSION['cupom'])) {
    $_SESSION['cupom'] = $_REQUEST['cupom'];
    $submeter_bcash    = 1;
}

if(isset($_SESSION['cupom'])){
    $cupom = $_SESSION['cupom'];
    $cupom = strtoupper($cupom);
    $sql = mysql_query("SELECT * FROM cn_promocode WHERE cupom = '$cupom' AND ativo = 1");
    while($row = mysql_fetch_array($sql)){
        $desconto = $row['desconto'];
        $valor    = $row['vl_produto'];
    }
}else{
    $valor = '199,00';
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
        <input name="nome_prod" type="hidden" value="KLIP-Green - usando cupom <?= $cupom ?> - 1 un somente">
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
    <?php if ($desconto) { ?>
    function ajustaQuant() {
        $("#quant_prod").val($("#quant_prod_sel").val()-1);
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
    <a href="/" class="aux-nav"><?= _("HOME") ?></a>
    <div class="clear"></div>

    <div class="row">
        <form class="row">
            <label><?= _("Produto") ?></label>
            <input type="hidden" name=""/>
            <!--<input type="submit" />

                        <label><?= _("Categorias") ?></label>
                        <select>
                            <option><?= _("Biossensores") ?></option>
                        </select>!-->
        </form>
        <div class="itens-cart row">
            <div class="cart-details">
                <!-- <span class="itens-count">2 itens</span>
                 <span class="total">R$ 9.359,90</span>!-->
            </div>
            <!--                        <a href="#" class="go-cart"><?= _("Ir para o carrinho de compras") ?></a>-->
        </div>
    </div>

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

            <script type="text/javascript">
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

            <div class="advanced-slider" id="responsive-slider" >
                <ul class="slides" style="padding: 0; margin: 0">
                    <li class="slide">
                        <img class="image" src="/assets/img/slider/user_clip1.jpg" width="500" alt=""/>
                        <img class="thumbnail" src="/assets/img/slider/tumb_user_clip1.jpg" />
                    </li>

                    <li class="slide rounded-caption">
                        <img class="image" src="/assets/img/slider/user_clip2.jpg" width="500" alt=""/>
                        <img class="thumbnail" src="/assets/img/slider/tumb_user_clip2.jpg" />
                    </li>

                    <li class="slide">
                        <img class="image" src="/assets/img/slider/user_clip3.jpg" width="500" alt=""/>
                        <img class="thumbnail" src="/assets/img/slider/tumb_user_clip3.jpg" alt="Slide 3"/>
                    </li>

                    <li class="slide">
                        <img class="image" src="/assets/img/slider/user_clip4.jpg" width="500" alt=""/>
                        <img class="thumbnail" src="/assets/img/slider/tumb_user_clip4.jpg" alt="Slide 4" />
                    </li>

                    <li class="slide">
                        <img class="image" src="/assets/img/slider/user_clip5.jpg" width="500" alt=""/>
                        <img class="thumbnail" src="/assets/img/slider/tumb_user_clip5.jpg" alt="Slide 5" />
                    </li>

                    <li class="slide">
                        <img class="image" src="/assets/img/slider/user_clip6.jpg" width="400" height="300" alt="Claudia Cepakua"/>
                        <img class="thumbnail" src="/assets/img/slider/tumb_user_clip6.jpg" alt="Slide 6" />
                        <div class="detalhes-imagem1" >Cláudia Cepakua <br/>Email: claudia@carenet.com.br<br>Twitter: @ccepukas</div>
                    </li>

                    <li class="slide">
                        <img class="image" src="/assets/img/slider/user_clip7.jpg" width="400" alt=""/>
                        <img class="thumbnail" src="/assets/img/slider/tumb_user_clip7.jpg" alt="Slide 7" />
                        <div class="detalhes-imagem2" style="">Dr. Micheal Kronenberg <br/>Email: michael@carenet.com.br</div>
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
                <span class="price" ><?php echo "R$ ". str_replace('.', ',', $valor) ?></span>
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
        </div>
        <form method="post" action="/loja/klip/index.php">
            <div class="promocode">
                <?php
                if(isset($desconto)){
                    ?>
                    <i></i> <?= _("Promocode") ?> "<?= $_SESSION['cupom'] ?>":
                    <?= _("Desconto de") ?> <?= $desconto ?>% <?= _("na primeira unidade") ?>
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
                <span><input id="quant_prod_sel" name="quant_prod_sel" type="number" value="1" min="1" max="" step="1"></span>
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
            <input id="comprar" type="submit" class="comprar" value="Comprar" style="border: none">
        </form>
    </div>
</div>

<div class="topic">
    <h4><i></i><?= _("Descrição") ?></h4>
    <p>
        <?= _("O biossensor KLIP Carenet será seu maior aliado na busca de seus objetivos para melhorar sua saúde e bem-estar. Você poderá saber diariamente o número de passos dados, calorias queimadas, tempo de atividade física e distância percorrida e visualizar todas essas informações através do visor do dispositivo. Poderá também utilizar o aplicativo gratuito Carenet Longevity para sincronizar e consolidar todas essas informações em seu telefone celular e verificar seu desempenho, incluindo dados sobre a qualidade do seu sono e em gráficos completos e fáceis de entender. Começe a cuidar de você HOJE.") ?><br />
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

<!--                    <div class="topic">
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
    <img src="/assets/img/loja/produtos/user_clip1.jpg" id="source_image1" width="358" height="323"/>
    <img src="/assets/img/loja/produtos/user_clip2.jpg" id="source_image2" width="358" height="323"/>
    <img src="/assets/img/loja/produtos/user_clip3.jpg" id="source_image3" width="358" height="323"/>
    <img src="/assets/img/loja/produtos/user_clip4.jpg" id="source_image4" width="358" height="323"/>
</div>

<script>

    $('#comprar').on('click', function() {
        ga('send', 'event', 'comprar', 'click', 'nav-buttons');
    });

    function changeImage(id) {
        $("#target_image").attr("src",$("#source_image"+id).attr("src"));
        return false;
    }
</script>
