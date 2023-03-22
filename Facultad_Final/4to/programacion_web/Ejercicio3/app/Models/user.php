<?php

    namespace Models;

    class user extends DB {
        public $table;
        function __construc(){
            parent:: __construc();
            $this->table= $this->db_connect();
        }

        protected $campos = ['name', 'username', 'password'];
        
        public $valores = [];

    }