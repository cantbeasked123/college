<?php
// Database connection
$conn = mysqli_connect('localhost', 'root', '', 'hospital_mgmt');

// Check connection
if (!$conn) {
    die("Connection Failed: " . mysqli_connect_error());
}

// SQL query to get the count of doctors per ward
$sql = "SELECT ward.WardId, ward.WardName, COUNT(doctor.DoctorId) AS doctor_count 
        FROM ward 
        LEFT JOIN doctor ON ward.WardId = doctor.WardId 
        GROUP BY ward.WardId, ward.WardName";

// Execute the query
$result = mysqli_query($conn, $sql);

// Check if query was successful
if ($result && mysqli_num_rows($result) > 0) {
    // Start the HTML output for the table
    echo "<table border='1'>
            <tr>
                <th>Ward ID</th>
                <th>Ward Name</th>
                <th>Doctor Count</th>
            </tr>";
    
    // Fetch and display each row
    while ($row = mysqli_fetch_assoc($result)) {
        echo "<tr>
                <td>{$row['WardId']}</td>
                <td>{$row['WardName']}</td>
                <td>{$row['doctor_count']}</td>
              </tr>";
    }
    
    // End of the table
    echo "</table>";
} else {
    // Display an error message if the query fails or no data is returned
    echo "No data available or error retrieving data.";
}

// Close the connection
mysqli_close($conn);
?>
