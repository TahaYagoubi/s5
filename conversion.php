 <!DOCTYPE html>
 <html lang="francais">

 <head>

 </head>
 <body>
    <?php
   function convertir(array $MontantDirham ,float $TAUX_euro): array{
        $montanteuro = [];

   foreach($montanteuro as $value){
    $montanteuro = $value * $TAUX_euro;
   }
   return $MontantDirham;
   }
    ?>
   
 </body>

 </html>