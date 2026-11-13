 <!DOCTYPE html>
 <html lang="francais">

 <head>

 </head>
 <body>
   <?php
    include "conversion.php";
    include "Somme.php";
    include "Affichage.php";
    $MontantDirham =[100,250,50,300];
    const TAUX_euro = 1/11;
    $MontantDirham = convertir($MontantDirham,$TAUX_euro);
    ?>
 </body>

 </html>