<?php


$verz="1.0";
$comPort = "/dev/ttyUSB0"; /*change to correct com port */
$PHP_SELF = "connecttest.php"

if (isset($_POST["rcmd"])) {
$rcmd = $_POST["rcmd"];
switch ($rcmd) {
     case Stop:
        $fp =fopen($comPort, "w");
  fwrite($fp, 1); /* this is the number that it will write */
  fclose($fp);
  break;
     case Slow:
        $fp =fopen($comPort, "w");
  fwrite($fp, 2); /* this is the number that it will write */
  fclose($fp);
  break;
  case Medium:
        $fp =fopen($comPort, "w");
  fwrite($fp, 3); /* this is the number that it will write */
  fclose($fp);
  break;
  case Fast:
        $fp =fopen($comPort, "w");
  fwrite($fp, 4); /* this is the number that it will write */
  fclose($fp);
  break;
case Strobe:
        $fp =fopen($comPort, "w");
  fwrite($fp, 5); /* this is the number that it will write */
  fclose($fp);
  break;
case SortaStrobe:
        $fp =fopen($comPort, "w");
  fwrite($fp, 6); /* this is the number that it will write */
  fclose($fp);
  break;
default:
  die('Crap, something went wrong. The page just puked.');
}

}
?>