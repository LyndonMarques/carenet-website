<?php
//teste

$produtos = array(
    '0' => array( 'cod'=>'9192','name'=> 'Fitbit','price'=>'USD $$', 'descricao'=>'', 'imagem'=>'/assets/img/loja/fitbit.jpg','link'=>'http://www.amazon.com/gp/search/ref=as_li_qf_sp_sr_tl?ie=UTF8&camp=1789&creative=9325&index=aps&keywords=fitbit&linkCode=ur2&tag=carenlonge-20'),
    '1' => array( 'cod'=>'9192','name'=> 'UP Jawbone','price'=>'USD $$', 'descricao'=>'', 'imagem'=>'http://ws-na.amazon-adsystem.com/widgets/q?_encoding=UTF8&ASIN=B00A17IAO0&Format=_SL160_&ID=AsinImage&MarketPlace=US&ServiceVersion=20070822&WS=1&tag=carenlonge-20' ,'link'=>'http://www.amazon.com/gp/search/ref=as_li_qf_sp_sr_tl?ie=UTF8&camp=1789&creative=9325&index=aps&keywords=UP%20Jawbone&linkCode=ur2&tag=carenlonge-20'),
    '2' => array( 'cod'=>'9192','name'=> 'Misfit Wearables','price'=>'US $$', 'descricao'=>'', 'imagem'=>'http://ws-na.amazon-adsystem.com/widgets/q?_encoding=UTF8&ASIN=B00FDWN8RM&Format=_SL160_&ID=AsinImage&MarketPlace=US&ServiceVersion=20070822&WS=1&tag=carenlonge-20' ,'link'=>'http://www.amazon.com/gp/search/ref=as_li_qf_sp_sr_tl?ie=UTF8&camp=1789&creative=9325&index=aps&keywords=Misfit%20Wearables&linkCode=ur2&tag=carenlonge-20'),
    '3' => array( 'cod'=>'9192','name'=> 'Basis','price'=>'US $$$$', 'descricao'=>'', 'imagem'=>'http://ws-na.amazon-adsystem.com/widgets/q?_encoding=UTF8&ASIN=B00GJG5ZEA&Format=_SL160_&ID=AsinImage&MarketPlace=US&ServiceVersion=20070822&WS=1&tag=carenlonge-20','link'=>'http://www.amazon.com/gp/search/ref=as_li_qf_sp_sr_tl?ie=UTF8&camp=1789&creative=9325&index=aps&keywords=basis%20health%20tracker&linkCode=ur2&tag=carenlonge-20'),
    '4' => array( 'cod'=>'9192','name'=> 'Nike FuelBand','price'=>'US $$$', 'descricao'=>'', 'imagem'=>'http://ws-na.amazon-adsystem.com/widgets/q?_encoding=UTF8&ASIN=B008RRLJUS&Format=_SL160_&ID=AsinImage&MarketPlace=US&ServiceVersion=20070822&WS=1&tag=carenlonge-20' ,'link'=>'http://www.amazon.com/gp/search/ref=as_li_qf_sp_sr_tl?ie=UTF8&camp=1789&creative=9325&index=aps&keywords=nike%20fuel%20band&linkCode=ur2&tag=carenlonge-20')
);

?>
<div class="container-loja" id="no-mediabox">
    <div id="content-top">
        <a href="/" class="aux-nav"><?= _("HOME") ?></a>
        <div class="clear"></div>

        <!--<div class="row">

            <form class="row" action="/loja/">
                              <label><?= _("Produto") ?></label>
                <label for="txtSearch"></label>
                <input type="text" name="txtSearch" id="txtSearch"/>
                <input type="submit" />

                <label><?= _("Categorias") ?></label>
                <label for="cmbCategory"></label>
                <select name="cmbCategory" id="cmbCategory">
                    <option><?= _("Biossensores") ?></option>
                </select>
            </form>
            <div class="itens-cart row">
                              <div class="cart-details">
                    <span class="itens-count"></span>
                    <span class="total"></span>
                </div>
                <a href="#" class="go-cart"><?= _("Ir para o carrinho de compras") ?></a>
            </div>#E76710
        </div>-->

        <div class="row pagamento">
            <div class="col formas-pagamento">
                <h2>
                    <small>&nbsp;</small>
                    &nbsp;<?= _("Compre o seu Carenet Klip em até 10X no cartão") ?>
                </h2>
            </div>
        </div>
    </div>

    <div class="clear"></div>

    <div class="main-content pull-up-30">
        <div class="row row-biossensores">
            <div class="col sensores-destaque">
                <ul class="products-list">
                    <li>
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
                            <a href="/loja/klip" class="action buy-yours">
                                <?= _("Compre o Seu") ?>
                            </a>
                        </div>
                    </li>
                    <li>
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
                            <span class="action coming-soon">
                                <?= _("Em Breve") ?>
                            </span>
                        </div>
                    </li>
                    <li>
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
                            <span class="action coming-soon">
                                <?= _("Em Breve") ?>
                            </span>
                        </div>
                    </li>
                </ul>
            </div>
            <div class="col como-usar">
                <h3><?= _("Como usar") ?></h3>
                <object width="350" height="196.875">
                    <param name="movie" value="https://www.youtube.com/v/sDEbOScR-Jg?version=3"/>
                    <param name="allowFullScreen" value="true"/>
                    <param name="allowScriptAccess" value="always"/>
                    <embed src="https://www.youtube.com/v/sDEbOScR-Jg?version=3" type="application/x-shockwave-flash" allowfullscreen="true" allowScriptAccess="always" width="350" height="196.875"></embed>
                </object>
                <p>
                    <?= _("O Biossensor Carenet KLIP
                    age em conjunto com o APP
                    Carenet Logevity, e juntos geram resultados claros de
                    como andam seus esforços em obter mais
                    saúde e qualidade de vida.") ?>
                </p>
            </div>
        </div>

        <div style="text-align: center">
            <div class="paywith row pagination-bottom">
                <p>
                    <?= _("Pague com") ?>
                </p>
            </div>
            <img style="margin-left: 40px" src="/assets/img/loja/pagamentos-bcash.png">
        </div>
        <br/>
        <div class="row recomendamos">
            <h3><?= _("Recomendamos") ?></h3>
            <a href="#"><?= _("Compre direto da") ?>: <span class="amazon">Amazon</span></a>
        </div>

        <div class="products-nav">
            <ul class="products-list">
                <?php
                foreach($produtos as $produto){
                    ?>
                    <li>
                        <!--<small class="cod"><?php echo $produto['cod'] ?></small>!-->
                        <div class="photo-box">
                            <a href="<?php echo $produto['link']?>" target="_blank">
                                <img style="max-height: 150px" src="<?php echo $produto['imagem']?>">
                            </a>
                        </div>
                        <div class="details">
                            <a href="<?php echo $produto['link']?>" class="name">
                                <?php echo $produto['name']?>
                            </a>
                            <span class="price"><?php echo $produto['price']?></span>
                            <a href="<?php echo $produto['link']?>" class="action coming-soon">
                                <?php echo $produto['descricao']?>
                            </a>
                        </div>
                    </li>
                <?php
                }
                ?>

            </ul>

            <div style="margin-left: 30px; margin-right: 30px">
                <?= _("Faixa de preço (sem incluir frete e impostos)") ?> :<br/>
                <b>$</b> <?= _("Entre US$ 50 e US$ 79") ?> |
                <b>$$</b> <?= _("Entre US$ 80 e US$ 119") ?> |
                <b>$$$</b> <?= _("Entre US$ 120 e US$ 179") ?> |
                <b>$$$$</b> <?= _("Maior que US$ 180") ?>
            </div>
            <div class="clear"></div>
        </div> <!-- / .products-nav -->


    </div> <!-- .main-content -->
</div>

