<?php
    function head(){;
    
?>
<!DOCTYPE html>
<html lang="en">
<head>
    <meta charset="UTF-8">
    <meta http-equiv="X-UA-Compatible" content="IE=edge">
    <link rel="icon" type="image/x-icon" href="./images/icon.png">
    <meta name="viewport" content="width=device-width, initial-scale=1.0">
    <link rel="stylesheet" href="./css/boostrap.css">
    <link rel="stylesheet" href="https://cdn.jsdelivr.net/npm/bootstrap-icons@1.10.3/font/bootstrap-icons.css">
    <!--
        <link href="https://cdn.jsdelivr.net/npm/bootstrap@5.3.0-alpha1/dist/css/bootstrap.min.css" rel="stylesheet" integrity="sha384-GLhlTQ8iRABdZLl6O3oVMWSktQOp6b7In1Zl3/Jr59b6EGGoI1aFkw7cmDA6j6gD" crossorigin="anonymous">
    -->
    
    <link rel="preconnect" href="https://fonts.googleapis.com">
<link rel="preconnect" href="https://fonts.gstatic.com" crossorigin>
<link href="https://fonts.googleapis.com/css2?family=Roboto:wght@100&display=swap" rel="stylesheet">
<style>
    body{
        font-family:'Roboto',serif;
    }
</style>
    <title>Blog X</title>
</head>

<body>
    <div id="app" class="container-fluid p-0">
    <header class="row m-8 bg-light">
        <div class="col-9">
            <h1 class="ml-3 mt-2">BLOG X</h1>
            <div class="col-3">
                
            </div>
        </div>
    </header>
    <nav class="navbar navbar-expand-lg bg-body-tertiary">
        <div class="container-fluid">
            <a class="navbar-brand" href="#">owo</a>
            <button class="navbar-toggler" type="button" data-bs-toggle="collapse" data-bs-target="#navbarSupportedContent" aria-controls="navbarSupportedContent" aria-expanded="false" aria-label="Toggle navigation">
                <span class="navbar-toggler-icon"></span>
            </button>
            <div class="collapse navbar-collapse" id="navbarSupportedContent">
            <ul class="navbar-nav me-auto mb-2 mb-lg-0">
                <li class="nav-item">
                <a class="nav-link active" aria-current="page" href="#">Inicio</a>
                </li>
                <li class="nav-item">
                <a class="nav-link" href="#">Seccion 1</a>
                </li>

                <li class="nav-item">
                <a class="nav-link ">seccion 2</a>
                </li>
            </ul>
            <form class="d-flex" role="search">
                <input class="form-control me-2" id="buscar-palabra" type="search" placeholder="Buscar" aria-label="Buscar">
                <button class="btn btn-outline-success" oneclick="app.buscarPalabra()" type="button"><i class="bi bi-search"></i></button>
            </form>
            </div>
        </div>
        </nav>
    </div>

<?php
    }
    function foot(){
?>
<script src="./js/jquery.js"></script>
<script src="./js/bootstrap.js"></script>
<script src="./js/app.js"></script>
</body>
</html>

<?php
    }
?>