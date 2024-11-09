<?php
// Include database connection file
// require 'db_connection.php'; // Update the path as needed
$conn = mysqli_connect('localhost', 'root', '', 'hospital_mgmt');
if ($conn) {
    echo "<br>Connected Successfully.<br>";
} else {
    echo "<br>Connection Failed.";
    exit();
}

if ($_SERVER["REQUEST_METHOD"] == "POST") {
    // Collect form data
    $id = $_POST['id']; // For update and delete
    $userId = $_POST['userid'];
    $patientName = mysqli_real_escape_string($conn, $_POST['patient_name']);
    $appointmentDate = mysqli_real_escape_string($conn, $_POST['appointment_date']);
    $appointmentTime = mysqli_real_escape_string($conn, $_POST['appointment_time']);
    $wardNo = $_POST['ward_no'];
    $action = $_POST['action']; // Action can be "add", "update", or "delete"

    $redirectToHome = false; // Flag to check if we should redirect to home

    // Output the received form data
    echo "<h3>Form Data Received:</h3>";
    echo "User ID: " . $userId . "<br>";
    echo "Patient Name: " . $patientName . "<br>";
    echo "Appointment Date: " . $appointmentDate . "<br>";
    echo "Appointment Time: " . $appointmentTime . "<br>";
    echo "Ward Number: " . $wardNo . "<br>";
    
    if ($action == 'add') {
        // Insert appointment record
        $sql = "INSERT INTO appointment (user_id, patient_name, appointment_date, appointment_time, ward_no) 
                VALUES ('$userId', '$patientName', '$appointmentDate', '$appointmentTime', '$wardNo')";

        if (mysqli_query($conn, $sql)) {
            // Get the last inserted appointment ID
            $appointmentId = mysqli_insert_id($conn);
            echo "<br><h4>Appointment booked successfully.<\h4><br>Your Appointment ID is: " . $appointmentId;
            $redirectToHome = true; // Set flag to true for redirection
        } else {
            echo "Error: " . $sql . "<br>" . mysqli_error($conn);
        }
    } elseif ($action == 'update') {
        // Update appointment record
        if (!empty($id)) {
            $sql = "UPDATE appointment 
                    SET user_id = '$userId', patient_name = '$patientName', appointment_date = '$appointmentDate', 
                        appointment_time = '$appointmentTime', ward_no = '$wardNo' 
                    WHERE id = '$id'";

            if (mysqli_query($conn, $sql)) {
                echo "<br><h4>Appointment updated successfully.<\h4><br>Your Appointment ID is: " . $id;
                $redirectToHome = true; // Set flag to true for redirection
            } else {
                echo "Error: " . $sql . "<br>" . mysqli_error($conn);
            }
        } else {
            echo "<br>Appointment ID is required for updating.";
        }
    } elseif ($action == 'delete') {
        // Delete appointment record
        if (!empty($id)) {
            $sql = "DELETE FROM appointment WHERE id = '$id'";

            if (mysqli_query($conn, $sql)) {
                echo "<br>Appointment ID " . $id . " has been deleted successfully.";
                $redirectToHome = true; // Set flag to true for redirection
            } else {
                echo "Error: " . $sql . "<br>" . mysqli_error($conn);
            }
        } else {
            echo "<br>Appointment ID is required for deletion.";
        }
    }

    // Close the database connection
    mysqli_close($conn);

    // Redirect to homepage after a successful operation
    if ($redirectToHome) {
        header("Refresh: 5; url=../client/home_page.php");
        exit();
    }
}
?>
