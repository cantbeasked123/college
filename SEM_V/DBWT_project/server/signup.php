<?php
// Include database connection file
$conn = mysqli_connect('localhost','root','','hospital_mgmt');
if($conn){
    echo "<br>Connected Successfully<br>";
}else{
    echo "<br>Connection Failed<br>";
    exit();
} 

if ($_SERVER["REQUEST_METHOD"] == "POST") {
    // Collect and sanitize input data
    $name = mysqli_real_escape_string($conn, $_POST['name']);
    $gender = mysqli_real_escape_string($conn, $_POST['gender']);
    $blood_type = mysqli_real_escape_string($conn, $_POST['blood-type']);
    $contact = mysqli_real_escape_string($conn, $_POST['contact']);
    $age = (int)$_POST['age']; 
    $username = mysqli_real_escape_string($conn, $_POST['username']);
    $pwd = mysqli_real_escape_string($conn, $_POST['pwd']);

    // Output the form data to confirm it's being received correctly
    echo "<h3>Form Data Received:</h3>";
    echo "Name: " . $name . "<br>";
    echo "Gender: " . $gender . "<br>";
    echo "Blood Type: " . $blood_type . "<br>";
    echo "Contact: " . $contact . "<br>";
    echo "Age: " . $age . "<br>";
    echo "Username: " . $username . "<br>";

    // Hash the password
    $hashedPwd = password_hash($pwd, PASSWORD_DEFAULT);
    
    // Prepare SQL query
    $sql = "INSERT INTO users (name, gender, blood_type, contact, age, username, password)
            VALUES ('$name', '$gender', '$blood_type', '$contact', $age, '$username', '$hashedPwd')";

    // Execute query and check for success
    if (mysqli_query($conn, $sql)) {
    // Get the last inserted user ID
    $userId = mysqli_insert_id($conn);
    
    echo "<br><h4>User signed up successfully!</h4><br>Your User ID is: " . $userId . "<br>";
    
    mysqli_close($conn);
    
    // Redirect to the Sign-In page after a 5-second delay
    header("Refresh: 5; url=../client/signin.html");
    exit();  // Ensure no further code executes after redirection
    } else {
        echo "Error: " . $sql . "<br>" . mysqli_error($conn);
    }

mysqli_close($conn);
}
?>