 <!DOCTYPE html>
 <html lang="francais">

 <head>
<?php
   function Somme(array $montanteuro):string{
    $somme = array_sum($montanteuro);
    return number_format($somme);
   }
    
 </head>
 <body>