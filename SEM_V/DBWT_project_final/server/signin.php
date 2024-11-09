<?php
session_start();

// Database connection
$conn = mysqli_connect('localhost', 'root', '', 'hospital_mgmt');
if (!$conn) {
    die("Connection Failed: " . mysqli_connect_error());
}

if ($_SERVER["REQUEST_METHOD"] == "POST") {
    // Sanitize input to prevent SQL injection
    $username = mysqli_real_escape_string($conn, $_POST['username']);
    $password = mysqli_real_escape_string($conn, $_POST['password']);

    // Query to check for user
    $sql = "SELECT id, password FROM users WHERE username = '$username'";
    $result = mysqli_query($conn, $sql);

    // Check if the query returned a result
    if (mysqli_num_rows($result) > 0) {
        // Fetch the user's data
        $row = mysqli_fetch_assoc($result);

        // Verify the password
        if (password_verify($password, $row['password'])) {
            // Store user data in session variables
            $_SESSION['user_id'] = $row['id']; // Store user ID in session
            $_SESSION['username'] = $username; // Store username in session

            // Redirect to the appointment booking page
            header("Location: ../client/appointment_page.php");
            exit(); 
        } else {
            // If the password is incorrect
            echo "Invalid password. Please try again.";
        }
    } else {
        // If the username does not exist
        echo "Invalid username. Please check your credentials.";
    }

    // Close database connection
    mysqli_close($conn);
}
?>
