<script src="/assets/js/main.js"></script>

<div id="overlay_layer1" class="layer1"></div>
<div id="overlay_layer2" class="layer2"></div>
<div id="overlay_layer3" class="layer3"></div>
<div id="overlay_dots" class="dotslayer"></div>
<div id="overlay_base-verdeescura-banners" class="base-verdeescura-banners"></div>
<div id="overlay_base-boxes-home" class="base-boxes-home"></div>

<div id="conteudo">
<div id="mediabox">
     <div class="wrapper">
         <ul class="slider">
             <li><img src="/assets/img/media-box/back-home-praia.jpg" class="slider_img"/></li>
             <li><img src="/assets/img/media-box/back-home-academia.jpg" class="slider_img"/></li>
             <li><img src="/assets/img/media-box/back-home-business.jpg" class="slider_img"/></li>
             <li><img src="/assets/img/media-box/back-home-casal.jpg" class="slider_img"/></li>
             <li><img src="/assets/img/media-box/back-home-familia.jpg" class="slider_img"/></li>
         </ul>
    </div>
</div>

<div id="mediabox2">
    <div class="wrapper">
        <ul class="slider_text">
            <li><a href="/carenet#longevidade"><img src="/assets/img/media-box/<?= _("back-home-praia_pt.png") ?>" class="slider_img"/></a></li>
            <li><a href="/carenet#trueage"><img src="/assets/img/media-box/<?= _("back-home-academia_pt.png") ?>" class="slider_img"/></a></li>
            <li><a href="/carenet#four-dimensions"><img src="/assets/img/media-box/<?= _("back-home-business_pt.png") ?>" class="slider_img"/></a></li>
            <li><a href="/carenet#desafios"><img src="/assets/img/media-box/<?= _("back-home-casal_pt.png") ?>"class="slider_img" /></a></li>
            <li><a href="/carenet#comunidade"><img src="/assets/img/media-box/<?= _("back-home-familia_pt.png") ?>" class="slider_img"/></a></li>
        </ul>
    </div>
</div>

<div id="content-boxes" class="row">
     <div class="col-6">
         <div id="box-visao-longevidade">
             <h3>
                 <a href="/assets/img/indicadores/<?= _("indicadores-pt.png") ?>" class="indicadores">
                     <img src="/assets/img/indicadores/<?= _("bloco-indicadores-home_pt.png") ?>">
                 </a>
             </h3>
             <p>
                 <?= _("Uma vida saudável é composta por milhares de pequenas escolhas
                 que fazemos todos os dias, e não somente indo ao médico ou à academia.") ?>
             </p>
             <a class="galeria-indicadores" href="/assets/img/indicadores/<?= _("indicadores-pt.png") ?>" class="arrow-more"><img src="/assets/img/bg/longevidade-bottom.png"></a>
         </div>
         <div class="clear"></div>
         <div id="voce-sabia">
             <p><?= _("Diversas dicas interessantes sobre você e sua saúde") ?><br/><a href="javascript:void(0)" onclick="voceSabia()">[<?= _("saiba mais") ?>]</a></p>
             <a href="javascript:void(0)" onclick="voceSabia()" class="arrow"><?= _("saiba mais") ?></a>
         </div>
     </div>
     <div class="col-6">
         <div id="box-klip">
             <a href="/loja/klip"><?= _("Conheça o Klip") ?></a>
         </div>
         <div id="box-download-app">
             <h3><?= _("O App amigo!") ?></h3>
             <p>
                 <?= _("O APP Carenet será seu maior aliado em sua busca
                 por mais saúde e qualidade de vida. Saiba como este
                 APP pode ajudar você.") ?>
             </p>
             <a href="/instalar" style="float: right; width: 100%; height: 100%; margin-top: 30px;"></a>
         </div>
     </div>
 </div>
 </div>

<div style="display:none">
    <a class="galeria-indicadores" href="/assets/img/indicadores/<?= _("indicadores-pt.png") ?>"></a>
</div>

<div id="content-boxes-height">
</div>

<script type="text/javascript">

    $(function(){
        /*
         Paulino, este bloco dever ser Adicionado naquele javascript que
         está em todas as páginas
         juntamente com o bloco html abaixo que também precisa estar em todas
         as páginas que exibirão o box da newsletter
         <div id="newsletter">
         <h4 class="toggle-newsletter">newsletter carenet</h4>
         <a href="#" id="toggle-newsletter" class="toggle-newsletter">toggle-newsletter</a>
         <div id="newsletter-content">
         <p>
         Digite seu email e receba dicas, treinos e muito mais para sua saúde.
         </p>
         <form>
         <input type="email" name="">
         <input type="submit" value="ok">
         </form>
         <div id="newsletter-content">
         </div>


        $('.toggle-newsletter').on('click', function (e) {
            e.preventDefault();
            console.log('teste');
            $('#newsletter-content').slideToggle();
            $('#toggle-newsletter').toggleClass('open');
        });
         */


        $('.galeria-indicadores').colorbox({
            rel: 'galeria-indicadores',
            onComplete: function() {

                $('#cboxClose').css({
                    'top': '5px',
                    'right': '5px'
                });
            }
        });


        /*
         *  Este bloco abre um lightbox personalizado
         *  para os 30 indicadores. No momento só aparece na home
         *
         */

        $('.indicadores').colorbox({

            onComplete: function() {

                $('#cboxLoadedContent').css({
                    'background': 'transparent',
                    'border': 'none'
                });

                $('#cboxClose').css({
                    'top': '24px',
                    'right': '48.6%'
                });
            },
            onClose: function() {

                $('#cboxLoadedContent').css({
                    'background': '#fff',
                    'border': 'none'
                });

                $('#cboxClose').css({
                    'top': 'inherit',
                    'right': '5px'
                });
            }
        });
    });
</script>