<?php
session_start();

$conn = mysqli_connect('localhost', 'root', '', 'hospital_mgmt');

if (!$conn) {
    die("Connection Failed: " . mysqli_connect_error());
}

if ($_SERVER["REQUEST_METHOD"] == "POST") {
    $username = mysqli_real_escape_string($conn, $_POST['username']);
    $password = mysqli_real_escape_string($conn, $_POST['password']);

    $sql = "SELECT id, password FROM users WHERE username = '$username'";
    $result = mysqli_query($conn, $sql);

    // Check if the query returned any results
    if (mysqli_num_rows($result) > 0) {
        // Fetch the user data
        $row = mysqli_fetch_assoc($result);

        // Verify the password using password_verify()
        if (password_verify($password, $row['password'])) {
            // Start a session and store user data
            $_SESSION['user_id'] = $row['id']; // Store user ID in the session
            $_SESSION['username'] = $username; // Store username in the session

            // Redirect to the home page
            header("Location: ../client/home_page.html");
            exit(); 
        } else {
            // If the password is incorrect
            echo "Invalid password.";
        }
    } else {
        // If the username doesn't exist in the database
        echo "Invalid username.";
    }

    mysqli_close($conn);
}
?>
