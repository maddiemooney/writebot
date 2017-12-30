<?php

$comPort = "/dev/ttyUSB0"; /*change to correct com port */
$PHP_SELF = "connecttest.php";

if (isset($_POST["rcmd"])) {
$rcmd = $_POST["rcmd"];
switch ($rcmd) {
  case A:
    $fp =fopen($comPort, "w");
    fwrite($fp, 1); /* this is the number that it will write */
    fclose($fp);
    break;
  case B:
    $fp = fopen($comPort, "w");
    fwrite($fp, 2); /* this is the number that it will write */
    fclose($fp);
    break;
  case C:
    $fp = fopen($comPort, "w");
    fwrite($fp, 3); /* this is the number that it will write */
    fclose($fp);
    break;
  case D:
    $fp = fopen($comPort, "w");
    fwrite($fp, 4); /* this is the number that it will write */
    fclose($fp);
    break;
  case E:
    $fp = fopen($comPort, "w");
    fwrite($fp, 5); /* this is the number that it will write */
    fclose($fp);
    break;
  case F:
    $fp = fopen($comPort, "w");
    fwrite($fp, 6); /* this is the number that it will write */
    fclose($fp);
    break;
  case G:
    $fp = fopen($comPort, "w");
    fwrite($fp, 7);
    fclose($fp);
    break;
  case H:
    $fp = fopen($comPort, "w");
    fwrite($fp, 8);
    fclose($fp);
    break;
  case I:
    $fp = fopen($comPort, "w");
    fwrite($fp, 9);
    fclose($fp);
    break;
  case J:
    $fp = fopen($comPort, "w");
    fwrite($fp, 10);
    fclose($fp);
    break;
  case K:
    $fp = fopen($comPort, "w");
    fwrite($fp, 11);
    fclose($fp);
    break;
  case L:
    $fp = fopen($comPort, "w");
    fwrite($fp, 12);
    fclose($fp);
    break;
  case M:
    $fp = fopen($comPort, "w");
    fwrite($fp, 13);
    fclose($fp);
    break;
  case N:
    $fp = fopen($comPort, "w");
    fwrite($fp, 14);
    fclose($fp);
    break;
  case O:
    $fp = fopen($comPort, "w");
    fwrite($fp, 15);
    fclose($fp);
    break;
  case P:
    $fp = fopen($comPort, "w");
    fwrite($fp, 16);
    fclose($fp);
    break;
  case Q:
    $fp = fopen($comPort, "w");
    fwrite($fp, 17);
    fclose($fp);
    break;
  case R:
    $fp = fopen($comPort, "w");
    fwrite($fp, 18);
    fclose($fp);
    break;
  case S:
    $fp = fopen($comPort, "w");
    fwrite($fp, 19);
    fclose($fp);
    break;
  case T:
    $fp = fopen($comPort, "w");
    fwrite($fp, 20);
    fclose($fp);
    break;
  case U:
    $fp = fopen($comPort, "w");
    fwrite($fp, 21);
    fclose($fp);
    break;
  case V:
    $fp = fopen($comPort, "w");
    fwrite($fp, 22);
    fclose($fp);
    break;
  case W:
    $fp = fopen($comPort, "w");
    fwrite($fp, 23);
    fclose($fp);
    break;
  case X:
    $fp = fopen($comPort, "w");
    fwrite($fp, 24);
    fclose($fp);
    break;
  case Y:
    $fp = fopen($comPort, "w");
    fwrite($fp, 25);
    fclose($fp);
    break;
  case Z:
    $fp = fopen($comPort, "w");
    fwrite($fp, 26);
    fclose($fp);
    break;
  case space:
    $fp = fopen($comPort, "w");
    fwrite($fp, 27);
    fclose($fp);
    break;
  default:
    die('Crap, something went wrong. The page just puked.');
}

}
?>
<html>
<body>

<center><h1>Arduino from PHP Example</h1></center>

<form method="post" action="<?php echo $PHP_SELF;?>">
&nbsp&nbsp&nbsp&nbsp
<input type="submit" value="A" name="rcmd">
<input type="submit" value="B" name="rcmd">
<input type="submit" value="C" name="rcmd">
<input type="submit" value="D" name="rcmd">
<input type="submit" value="E" name="rcmd">
<input type="submit" value="F" name="rcmd">
<input type="submit" value="G" name="rcmd">
<input type="submit" value="H" name="rcmd">
<input type="submit" value="I" name="rcmd">
<input type="submit" value="J" name="rcmd">
<input type="submit" value="K" name="rcmd">
<input type="submit" value="L" name="rcmd">
<input type="submit" value="M" name="rcmd">
<input type="submit" value="N" name="rcmd">
<input type="submit" value="O" name="rcmd">
<input type="submit" value="P" name="rcmd">
<input type="submit" value="Q" name="rcmd">
<input type="submit" value="R" name="rcmd">
<input type="submit" value="S" name="rcmd">
<input type="submit" value="T" name="rcmd">
<input type="submit" value="U" name="rcmd">
<input type="submit" value="V" name="rcmd">
<input type="submit" value="W" name="rcmd">
<input type="submit" value="X" name="rcmd">
<input type="submit" value="Y" name="rcmd">
<input type="submit" value="Z" name="rcmd">
<input type="submit" value="space" name="rcmd">

<br />
<br />
<br />
<br />
<br />
<br />

</form>
</body>
</html>