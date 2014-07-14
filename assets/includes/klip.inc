<?php
$CurrOS = '';
$OSList = array
(
// Match user agent string with operating systems
    'Windows 3.11' => '/Win16/',
    'Windows 95' => '/(Windows 95)|(Win95)|(Windows_95)/i',
    'Windows 98' => '/(Windows 98)|(Win98)/',
    'Windows 2000' => '/(Windows NT 5.0)|(Windows 2000)/i',
    'Windows XP' => '/(Windows NT 5.1)|(Windows XP)/i',
    'Windows Server 2003' => '/(Windows NT 5.2)/',
    'Windows Vista' => '/(Windows NT 6.0)/',
    'Windows 7' => '/(Windows NT 7.0)/',
    'Windows NT 4.0' => '/(Windows NT 4.0)|(WinNT4.0)|(WinNT)|(Windows NT)/i',
    'Windows ME' => '/Windows ME/',
    'Open BSD' => '/OpenBSD/',
    'Sun OS' => '/SunOS/',
    'Linux' => '/(Linux)|(X11)/i',
    'Mac OS' => '/(Mac_PowerPC)|(Macintosh)/i',
    'QNX' => '/QNX/',
    'BeOS' => '/BeOS/',
    'OS/2' => '/OS/2/',
    'Search Bot'=>'/(nuhk)|(Googlebot)|(Yammybot)|(Openbot)|(Slurp)|(MSNBot)|(Ask Jeeves/Teoma)|(ia_archiver)/i'
);
// Loop through the array of user agents and matching operating systems
foreach($OSList as $CurrOS=>$Match)
{
// Find a match
    if (preg_match($Match, $_SERVER['HTTP_USER_AGENT']))
    {
// We found the correct match
        break;
    }
}

if($CurrOS == "Mac OS") {
    header("Location: https://itunes.apple.com/us/app/carenet-klip-sync/id877786790?mt=12");
    die();
}

?>

<div class="container">
    <div class="page-title">
        <h2><?= _("Software de Sincronização Klip") ?></h2>
    </div>
    <div class="row content">
        <?php
        if($CurrOS == "Mac OS") {
            echo _("Baixando Carenet Klip para Mac");
        } else {
            echo _("Baixando Carenet Klip para Windows");
        }
        ?>
        <?= _("Se o seu download não tiver iniciado,") ?> <a style="color: #60C4B1" href="https://s3-sa-east-1.amazonaws.com/carenet-public/klip-windows/Carenet+Klip+Sync.exe"><?= _("clique aqui.") ?></a>
            <table style="width: 0; color: #777777">
                <tr>
                    <td><img src="/assets/img/klip-install/seq1.jpg"/></td>
                    <td><img src="/assets/img/klip-install/seta.png"/></td>
                    <td><img src="/assets/img/klip-install/seq2.jpg"/></td>
                    <td><img src="/assets/img/klip-install/seta.png"/></td>
                    <td><img src="/assets/img/klip-install/seq3.jpg"/></td>
                </tr>
                <tr>
                    <td style="vertical-align:top"><p><b><?= _("1. Baixe") ?></b></p>
                        <?= _("Clique no arquivo Klip no canto inferior esquerdo da janela do seu navegador.") ?>
                    </td>
                    <td></td>
                    <td style="vertical-align:top"><p><b><?= _("2. Execute") ?></b></p>
                        <?= _("Execute o instalador, e siga os passos dele. Leva apenas um minuto.") ?></td>
                    <td></td>
                    <td style="vertical-align:top"><p><b><?= _("3. Comece") ?></b></p>
                        <?= _("Comece a usar o seu Klip e sincronize periodicamente para acompanhar o seu progresso!") ?>
                    </td>
                </tr>
            </table>
    </div>
</div>