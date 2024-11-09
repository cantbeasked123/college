<?php
// Function to calculate factorial
function factorial($n) {
    if ($n <= 1) {
        return 1; // Base case
    }
    return $n * factorial($n - 1); // Recursive call
}

$num = 5;
echo "Factorial of $num is " . factorial($num);
?>
