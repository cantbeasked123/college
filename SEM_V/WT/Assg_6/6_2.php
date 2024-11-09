<?php
// Numeric array
$numericArray = array(1, 2, 3, 4, 5);

// Associative array
$associativeArray = array("first" => "Alice", "second" => "Bob", "third" => "Charlie");

// Using foreach on numeric array
echo "Numeric Array:<br>";
foreach ($numericArray as $value) {
    echo $value . "<br>";
}

// Using foreach on associative array
echo "Associative Array:<br>";
foreach ($associativeArray as $key => $value) {
    echo "$key: $value<br>";
}
?>
