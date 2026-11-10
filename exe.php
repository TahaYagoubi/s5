<html>
<body> 
    <php
$dateNaissance = "2007-05-15";
$dateInscription = "2026-10-30";
$nom = trim($nom);
$prenom = trim($prenom);

$nomcomplet = "$nom $prenom";
echo strlen($nomcomplet) . "<br>";
echo ucwords($nomcomplet) . "<br>";
//echo explode("@", $email)[1] . "<br>";
echo substr($email, strpos($email, "@") + 1, strlen($email));
if (strpos($email, "@")) {
    echo "Email valide";
} else {
    echo "Email invalide";
}
$date = new DateTime($dateInscription);
echo $date->format("d/m/Y");

$currentdate = new DateTime();
$age = $currentdate->diff(new DateTime($dateNaissance))->y;
echo "<br>Votre age est $age ans";
?>
</body>   
</html>