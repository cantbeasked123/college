<?php
// Callback function
function greet($name) {
    return "Hello, $name!";
}

// Variable function
$functionName = 'greet';
echo $functionName("John"); // Calls the greet function
?>
