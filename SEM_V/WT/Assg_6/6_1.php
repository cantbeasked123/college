<?php
$integer = 42;
$float = 3.14;
$string = "Hello, PHP!";
$array = array(1, 2, 3);
$boolean = true;
$nullValue = null;

echo "Value: $integer, Data Type: " . gettype($integer) . "<br>";
echo "Value: $float, Data Type: " . gettype($float) . "<br>";
echo "Value: $string, Data Type: " . gettype($string) . "<br>";
echo "Value: " . implode(", ", $array) . ", Data Type: " . gettype($array) . "<br>";
echo "Value: $boolean, Data Type: " . gettype($boolean) . "<br>";
echo "Value: " . var_export($nullValue, true) . ", Data Type: " . gettype($nullValue) . "<br>";
?>
