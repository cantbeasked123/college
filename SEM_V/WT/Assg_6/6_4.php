<?php
// Function to print Fibonacci sequence
function fibonacci($n) {
    if ($n <= 0) {
        return 0; // Base case for n = 0
    } elseif ($n == 1) {
        return 1; // Base case for n = 1
    } else {
        return fibonacci($n - 1) + fibonacci($n - 2); // Recursive call
    }
}

$count = 10; // Number of Fibonacci numbers to generate
echo "Fibonacci Sequence:<br>";
for ($i = 0; $i < $count; $i++) {
    echo fibonacci($i) . " ";
}
?>
