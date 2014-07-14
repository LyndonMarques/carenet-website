<footer>
    <div class="footer-content row">
        <div id="footer-wrapper">
            <div id="footer-logo">
                <img src="/assets/img/logo-rodape.png">
            </div>

            <nav>
                <ul>
                    <li><?= _("Ajuda") ?></li>
                    <li><a href="/perguntas-frequentes"><?= _("FAQ") ?></a></li>
                    <li><a href="/press/Press.pdf" target="_blank"><?= _("Press kit") ?></a></li>
                    <li><a href="/videos"><?= _("Vídeos") ?></a></li>
                </ul>
            </nav>

            <nav>
                <ul>
                    <li><?= _("Serviços") ?></li>
                    <li><a href="/loja"><?= _("Loja") ?></a></li>
                    <li><a href="/klip"><?= _("Software de Sincronização") ?></a></li>
                    <li><a href="/instalar"><?= _("Baixar App") ?></a></li>
                    <li><a href="/termos-de-uso"><?= _("Termos de uso") ?></a></li>
                    <li><a href="/politica-privacidade"><?= _("Política de privacidade") ?></a></li>
                </ul>
            </nav>

            <nav>
                <ul>
                    <li><?= _("Explorar") ?></li>
                    <li><a href="/carenet"><?= _("Carenet") ?></a></li>
                    <li><a href="javascript:void(0)" onclick="voceSabia()"><?= _("Você Sabia?") ?></a></li>
                    <!--<li><a href="http://blogcarenet.com" target="_blank"><?= _("Blog") ?></a></li>!-->
                    <li><a href="/midia"><?= _("Mídia") ?></a></li>
                    <li><a href="/equipe"><?= _("Equipe e Parceiros") ?></a></li>
                </ul>
            </nav>

            <div class="clear"></div>

            <p>
                Carenet Longevity / CNPJ: 18.406.824/0001-21 / Inscrição Estadual: 143.329.032.110 / Endereço: Alameda dos Maracatins, 426 – São Paulo, SP 04089-000 <br /> contato@carenet.com.br / SAC (011) 2338-3291
            </p>
        </div>
    </div>
</footer>

<?php
include("widgets/voce_sabia.inc");
?>
<!--
    Adicionado bloco da newsletter
-->

<div id="newsletter">
    <h4 class="toggle-newsletter">newsletter carenet</h4>
    <a href="javascript:void(0)" id="toggle-newsletter" class="toggle-newsletter">toggle-newsletter</a>
    <div id="newsletter-content" >
        <p>
            Digite seu email e receba dicas, treinos e muito mais para sua saúde.
        </p>

        <input id="email" type="email" name="email">
        <input id="btn_newsletter" type="submit" value="ok">

    </div>
</div>

<script>

    $('.toggle-newsletter').on('click', function (e) {
        e.preventDefault();
        console.log('teste');
        $('#newsletter-content').slideToggle();
        $('#toggle-newsletter').toggleClass('open');
    });

    $(function() {

        $("#btn_newsletter").click(function(event) {

            var email = $("#email").val();
            if(email != "")
            {
                var filtro = /^([\w-]+(?:\.[\w-]+)*)@((?:[\w-]+\.)*\w[\w-]{0,66})\.([a-z]{2,6}(?:\.[a-z]{2})?)$/i;
                if(filtro.test(email))
                {
                    $.ajax({
                        type: "post",
                        url: "/assets/code/newsletter.php",
                        data: "email=" + email,
                        success: function(data) {
                            alert("Email Salvo com sucesso!");
                            $("#email").val("");
                            $('#newsletter-content').slideToggle();
                            $('#toggle-newsletter').toggleClass('open');
                        }
                    })
                    return true;
                } else {
                    alert("Este endereço de email não é válido!");
                    return false;
                }
            } else {
                alert('Digite um email!'); return false;
            }
        })
    })

    (function(i,s,o,g,r,a,m){i['GoogleAnalyticsObject']=r;i[r]=i[r]||function(){
        (i[r].q=i[r].q||[]).push(arguments)},i[r].l=1*new Date();a=s.createElement(o),
        m=s.getElementsByTagName(o)[0];a.async=1;a.src=g;m.parentNode.insertBefore(a,m)
    })(window,document,'script','//www.google-analytics.com/analytics.js','ga');

    ga('create', 'UA-43245167-1', 'carenet.com.br');
    ga('send', 'pageview');

</script>
</body>
</html>