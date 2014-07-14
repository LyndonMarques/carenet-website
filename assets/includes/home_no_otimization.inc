<div id="conteudo">
<div id="mediabox">
     <div class="wrapper">
         <ul class="slider">
             <li><a href="/carenet#longevidade"><img src="/assets/img/media-box/volei_pt.png" /></a></li>
             <li><a href="/carenet#trueage"><img src="/assets/img/media-box/academia_ptBK.png" /></a></li>
             <li><a href="/carenet#four-dimensions"><img src="/assets/img/media-box/casal-business_ptBK.png" /></a></li>
             <li><a href="/carenet#desafios"><img src="/assets/img/media-box/casal-correndo_ptBK.png" /></a></li>
             <li><a href="/carenet#comunidade"><img src="/assets/img/media-box/soccer-family_ptBK.png" /></a></li>
         </ul>
    </div>
     <script src="/assets/js/main.js"></script>
</div>

 <div class="row pull-up-180">
     <div class="col-6">
         <div id="box-visao-longevidade">
             <h3>
                 <a href="/assets/img/indicadores/indicadores-pt.png" class="indicadores">
                     <img src="/assets/img/indicadores/bloco-indicadores-home_pt.png">
                 </a>
             </h3>
             <p>
                 Uma vida saudável é composta por milhares de pequenas escolhas
                 que fazemos todos os dias, e não apenas durante algumas visitas
                 ao médico ou à academia. Através de tecnologia inovadora a Carenet
                 ajuda seus usuários a tomar essas decisões e viver mais e melhor.
             </p>
             <a class="galeria-indicadores" href="/assets/img/indicadores/indicadores-pt.png" class="arrow-more"><img src="/assets/img/bg/longevidade-bottom.png"></a>
         </div>
         <div class="clear"></div>
         <div id="voce-sabia">
             <p>Diversas dicas interessantes sobre você e sua saúde <a href="javascript:void(0)" onclick="voceSabia()">[saiba mais]</a></p>
             <a href="javascript:void(0)" onclick="voceSabia()" class="arrow">saiba mais</a>
         </div>
     </div>
     <div class="col-6">
         <div id="box-klip">
             <a href="/loja/klip">Conheça o Klip</a>
         </div>

         <div id="box-download-app">
             <h3>O App amigo!</h3>
             <p>
                 O APP Carenet será seu maior aliado em sua busca
                 por mais saúde e qualidade de vida. Saiba como este
                 APP pode ajudar você.
             </p>
             <strong><small>Disponível para iOS e </br> Android em breve</small></strong></br>
             <a href="/instalar" class="ios">iOS</a>
             <a href="/instalar" class="android">Android</a></br>
             <a href="/instalar" class="link">link</a>
         </div>

     </div>
 </div>
 </div>

<div style="display:none">
    <a class="galeria-indicadores" href="/assets/img/indicadores/indicadores-pt.png"></a>
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

         */
        $('.toggle-newsletter').on('click', function (e) {
            e.preventDefault();
            console.log('teste');
            $('#newsletter-content').slideToggle();
            $('#toggle-newsletter').toggleClass('open');
        });


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