<?php
    define('ROOT', dirnmae(__FILE__));
    define('DS',DIRECTORY_SEPARATOR);

    spl_autoloader_register('autoload');

    function autoload($class){
        $class =  ROOT . DS . str_replace("\\",DS,$class) . '.php';
        if(!file_exists($class)){
            throw new Exception("Error, clase no encontrada" .$class, 1);
        }
        require_once $class;
    }