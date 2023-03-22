<?php

    namespace Controller\auth;
    use Model\user;

    class LoginController{
        public $sv; //sesion validada
        public $name;
        public $id;
        public function __construct(){
            $this->sv = false;
        }
        public function userAuth($datos){
            $user = new user;
        }
    }
    