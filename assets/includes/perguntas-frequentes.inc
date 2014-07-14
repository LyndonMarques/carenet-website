<?php
include "open_db.php";
mb_internal_encoding("UTF-8");
mb_http_output( "UTF-8" );
ob_start("mb_output_handler");
//header("Content-Type: text/html; charset=ISO-8859-1",true);
const GET_TOPICS =  "";

$sql = mysql_query("SELECT * FROM cn_faq_main_topics");
$c=0;
while($row = mysql_fetch_array($sql)){
    $faq_categorias[$c]['id'] = $row['main_topic_id_pk'];
    $faq_categorias[$c]['topic'] = $row['main_topic_pt'];
    $c++;
}

$sql = mysql_query("SELECT * FROM cn_faq");
$c=0;
while($row = mysql_fetch_array($sql)){
    $facs[$c]['id'] = $row['faq_topic_id_fk'];
    $facs[$c]['titulo'] = $row['faq_pt'];
    $facs[$c]['conteudo'] = $row['ans_pt'];
    $c++;
}

?>
<div class="container">
    <div class="page-title">
        <h2><? _("FAQ") ?></h2>
    </div>
    <div class="row content">
        <div class="questions col">
                <h2><? _("TÓPICOS") ?></h2>
<!--
            <form>
                <input type="text" placeholder="<? _("Procurar...") ?>"/>
                <input type="submit" />
            </form>
            -->
            <ul>
                <?php
                foreach($faq_categorias as $cat){
                ?>
                <li>
                     <a href="#" class="plus"> <?php echo $cat['topic'];?> </a>
                    <ol>
                    <?php

                    foreach($facs as $fac){
                        if($cat['id'] == $fac['id']){
                        ?>

                                <li>
                                    <a href="javascript:alteraconteudo(<?php echo "' <h3>". $fac['titulo'] ."</h3>".$fac['conteudo']."'" ?>);"><?php echo $fac['titulo'] ?></a>
                                </li>

                        <?php
                        }
                    }
                    ?>
                    </ol>
                </li>
                    <?php
                    }
                    ?>
            </ul>

        </div>
        <div id="testemudar" class="answers col">
            <h3><? _("Como minha privacidade é protegida?") ?></h3>
            <p>
                <? _("Levamos a privacidade de dados muito a sério e tratamos como informações pessoais todas as informações recebidas e/ou armazenadas. As nossas políticas de privacidade de dados baseiam-se em enquadramentos locais e internacionais: Diretriz 95/46/EC do Parlamento e do Conselho Europeus de 24 de outubro de 1995 quanto à proteção de indivíduos com relação ao processamento de dados pessoais e à livre movimentação de tais dados. A Regra de Privacidade HIPAA (EUA) proporciona proteção para informações pessoais de saúde detidas por entidades abrangidas e dá aos pacientes uma gama de direitos com respeito a tais informações.") ?>
            </p>
        </div>
    </div>
</div>

<script type="text/javascript">
    $(function () {
        $(document).on('click', '.plus', function (e) {
            e.preventDefault();
            $(this).removeClass('plus')
                   .addClass('minus')
                   .next('ol')
                   .slideDown();
        });

         $(document).on('click', '.minus', function (e) {
            e.preventDefault();
            $(this).removeClass('minus')
                   .addClass('plus')
                   .next('ol')
                   .slideUp();
        });
    });

    function alteraconteudo(conteudo){
        document.getElementById("testemudar").innerHTML = conteudo;
    }
</script>
