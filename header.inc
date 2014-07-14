<?php
global $template;
?>
<!DOCTYPE html>
<html class="no-js">
<head>
    <meta charset="utf-8">
    <meta http-equiv="X-UA-Compatible" content="IE=edge,chrome=1">
    <title><?= $template['title'] ?></title>
    <meta name="description" content="<?= $template['description'] ?>">
    <meta name="keywords" content="<?= $template['keywords'] ?>">
    <meta name="robots" content="index, follow">
    <meta name="revisit-after" content="7 day">
    <meta name="language" content="Portuguese">
    <meta name="generator" content="N/A">
    <meta http-equiv="Content-Type" content="text/html; charset=utf-8">
    <meta name="viewport" content="width=device-width">
<?php if (in_array("meta-refresh",$template)) { ?>
    <meta http-equiv="refresh" content="5;URL=<?= $template['meta-refresh'] ?>">
<?php } ?>
    <?php foreach($template['css'] as $css): ?>
        <link rel="stylesheet" href="/assets/css/<?= $css ?>.css">
    <?php endforeach; ?>
    <script src="/assets/js/jquery-1.7.2.min.js"></script>
<?php if (in_array("modernizr",$template['features'])) { ?>
        <script src="/assets/js/vendor/modernizr-2.6.2.min.js"></script>
<?php } ?>
<?php if (in_array("mCustomScrollbar",$template['features'])) { ?>
    <link rel="stylesheet" href="/assets/js/jquery.mCustomScrollbar.css">
    <script src="/assets/js/jquery.mCustomScrollbar.concat.min.js"></script>
<?php } ?>
    <link rel="stylesheet" href="/assets/css/colorbox.css">
    <script src="/assets/js/jquery.colorbox-min.js"></script>

    <link rel="stylesheet" type="text/css" href="/assets/css/base/advanced-slider-base.css" media="screen"/>
    <link rel="stylesheet" type="text/css" href="/assets/css/glossy-square/gray/glossy-square-gray.css" media="screen"/>
    <link rel="stylesheet" type="text/css" href="/assets/css/responsive-slider.css" media="screen"/>

    <!--[if IE]><script type="text/javascript" src="/assets/js/excanvas.compiled.js"></script><![endif]-->
    <script type="text/javascript" src="/assets/js/jquery.transition.min.js"></script>
    <script type="text/javascript" src="/assets/js/jquery.touchSwipe.min.js"></script>
    <script type="text/javascript" src="/assets/js/jquery.advancedSlider.min.js"></script>

    <!--Start of Zopim Live Chat Script-->
    <script type="text/javascript">
        window.$zopim||(function(d,s){var z=$zopim=function(c){z._.push(c)},$=z.s=
            d.createElement(s),e=d.getElementsByTagName(s)[0];z.set=function(o){z.set.
            _.push(o)};z._=[];z.set._=[];$.async=!0;$.setAttribute('charset','utf-8');
            $.src='//v2.zopim.com/?2EiGB9zGhYoWy0el6ZcGWBugOZixsJ1h';z.t=+new Date;$.
                type='text/javascript';e.parentNode.insertBefore($,e)})(document,'script');
    </script>
    <!--End of Zopim Live Chat Script-->

</head>
<body class="home">

<div id="nav-bar-top">
    <nav class="primary-container row">
        <a href="/" id="main-logo" ><img src="/assets/img/logo.png"></a>
        <ul class="unstyled f-left" id="menu-top">
            <li><a href="/carenet"><?= _("Carenet") ?></a></li>
            <li><a href="javascript:void(0)" onclick="voceSabia()"><?= _("Você Sabia?") ?></a></li>
            <li><a href="/loja"><?= _("Loja") ?></a></li>
            <li><a href="/instalar"><?= _("Baixar App") ?></a></li>
            <!--<li><a href="#">Blog</a></li>!-->
        </ul>
        <ul id="social-top" class="unstyled f-right">
            <li><a href="https://twitter.com/Carenet_TrueAge" target="_blank"  class="twitter">Twitter</a></li>
            <li><a href="https://www.facebook.com/CarenetLongevity" target="_blank" class="facebook">Facebook</a></li>
            <li><a href="https://plus.google.com/118233382157644661637" target="_blank" class="google">Google+</a></li>
            <!--<li><a href="#" class="youtube">YouTube</a></li>!-->
        </ul>
    </nav>
</div>