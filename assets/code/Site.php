<?php
/**
 * Created by PhpStorm.
 * User: Vitor
 * Date: 22/04/14
 * Time: 14:39
 */

namespace code;

ini_set('display_errors', true);

session_start();
require_once '51degrees/51Degrees.php';
require_once '51degrees/51Degrees_usage.php';
include_once('routes.php');
set_include_path(get_include_path() . PATH_SEPARATOR .$_SERVER['DOCUMENT_ROOT'].'/assets/code');

class Site {

    function __construct() {
        global $template;
        global $_51d;
        global $routes;

        //Check is is mobile
        if ($_51d['IsMobile'] == TRUE) {
            header("Location: http://m.carenet.com.br");
            die();
        }

        set_include_path(get_include_path() . PATH_SEPARATOR .$_SERVER['DOCUMENT_ROOT'].'/assets/includes');

        // Validate Route and find templete
        $id = dirname($_SERVER['PHP_SELF']);
        $id = str_replace($_SERVER['DOCUMENT_ROOT'], "", $id);
        $id = preg_replace('/^\W+/','',$id);
        $id = preg_replace('/\W+$/','',$id);
        if ($id == '') $id = 'home';
        $id = preg_replace('/[\/]+/','.',$id);
        if (!array_key_exists($id,$routes)) {
            die("Route not valid");
        }

        // Find template
        $template = $routes[$id];

        // Detect Language
        define('LOCALE', 'en_US');
        putenv("LC_ALL=" . LOCALE);
        setlocale(LC_ALL, LOCALE);

        // Set the text domain as 'messages'
        $domain = 'messages';
        bindtextdomain($domain, "/var/www/carenet.com.br/locale");
        textdomain($domain);

        $languages = explode(',',getenv("HTTP_ACCEPT_LANGUAGE"));
        if (in_array('pt',$languages) || in_array('pt-br',$languages) || in_array('pt-pt',$languages)) {
            //setlocale(LC_MESSAGES, "en");
        } else {
            //setlocale(LC_MESSAGES, "en");
        }

        $this->handle($id);
    }

    public function handle($id) {
        include("header.inc");
        include($id.".inc");
        include("footer.inc");
   }
}
