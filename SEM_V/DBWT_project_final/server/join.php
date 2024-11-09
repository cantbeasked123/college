<?php
// Include database connection file
$conn = mysqli_connect('localhost', 'root', '', 'hospital_mgmt');

// Check connection
if (!$conn) {
    die("Connection Failed: " . mysqli_connect_error());
}

$doctors_wards = []; // Initialize array to hold results
$error_message = "";

// Fetch data when the button is clicked
if (isset($_POST['join_button'])) {
    // SQL query to join the 'doctors' and 'wards' tables
    $sql = "SELECT doctor.DoctorId AS doctor_id, doctor.NAME AS doctor_name, ward.wardid, ward.wardname 
            FROM doctor
            INNER JOIN ward
            ON doctor.WardId = ward.wardid";

    // Execute the query
    $result = mysqli_query($conn, $sql);

    // Check if query was successful and there are results
    if ($result && mysqli_num_rows($result) > 0) {
        $doctors_wards = mysqli_fetch_all($result, MYSQLI_ASSOC); // Fetch all results as an associative array
    } else {
        $error_message = "No results found or error: " . mysqli_error($conn);
    }
}

// Close the connection
mysqli_close($conn);
?>
