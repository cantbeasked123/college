<?php
// Database connection
$conn = new mysqli("localhost","root","","test_db");

// Create table if it doesn't exist
$sql = "CREATE TABLE IF NOT EXISTS users (
    id INT(6) AUTO_INCREMENT PRIMARY KEY,
    username VARCHAR(30) NOT NULL,
    email VARCHAR(50) NOT NULL)";
$conn->query($sql);
?>
