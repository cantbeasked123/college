<!DOCTYPE html>
<html>
<head>
    <title>Galaxy Hospital Home Page</title>
    <link rel="stylesheet" href="../client/css/home_page.css">
</head>
<body>
    <header>
        <nav>
            <a href="#about-us">About Us</a> 
            <a href="#gallery">Gallery</a> 
            <a href="#departments">Departments</a> 
            <a href="#services">Services</a> 
            <a href="#contact">Contact</a>
        </nav>
        <br>
        <div class="image">
            <a href="https://galaxyhospitalgoa.com" target="_blank">
                <img src="../client/pics/hospital_logo.jpg" alt="Galaxy Hospital Logo" style="width: 300px; height: auto;">
            </a>
        </div>
    </header>

    <main>
        <section id="about-us">
            <h2>About us</h2>
            <p>Welcome to Galaxy Hospital. We are committed to providing top-notch healthcare services.</p>
            <p>Galaxy Hospital Mapusa is a leading private multispeciality hospital in Goa dedicated to delivering compassionate and patient-centric care. Our team of highly experienced doctors in Goa offer a wide range of specialized treatments. Experience world-class healthcare at our state-of-the-art facility. Choose Galaxy for your journey to a healthier you.</p>
        </section>

        <section id="gallery">
            <h2>Gallery</h2>
            <div class="image">
                <img src="../client/pics/galaxy_hospital.jpg" alt="Hospital Building">
                <figcaption>Hospital Building</figcaption>
                <img src="../client/pics/galaxy_hospital1.jpg" alt="Hospital Entrance">
                <figcaption>Hospital Entrance</figcaption>
            </div>
        </section>

        <section>
            <h2>Links</h2>
            <div class="content">
                <a href="https://galaxyhospitalgoa.com" class="appointment-link" target="_blank">Visit our website</a>
            </div>
            <div class="content">
                <a href="appointment.html" class="appointment-link">Book an Appointment</a>
            </div>
        </section>

        <section id="departments">
            <h2>Departments</h2>
            <table>
                <tr>
                    <th>Department</th>
                    <th>Head</th>
                    <th>Staff</th>
                </tr>
                <tr>
                    <td rowspan="2">Cardiology</td>
                    <td rowspan="2">Dr. Alice Smith</td>
                    <td>Dr. Alan James</td>
                </tr>
                <tr>
                    <td>Dr. John Blake</td>
                </tr>
                <tr>
                    <td>Neurology</td>
                    <td colspan="2">Dr. Bob Johnson</td>
                </tr>
                <tr>
                    <td rowspan="3">Pediatrics</td>
                    <td rowspan="3">Dr. Carol Lee</td>
                    <td>Dr. Josh Brown</td>
                </tr>
                <tr>
                    <td>Dr. Jacob Dsouza</td>
                </tr>
                <tr>
                    <td>Dr. Clyde Fernandes</td>
                </tr>
                <tr>
                    <td rowspan="2">Orthopedics</td>
                    <td rowspan="2">Dr. David Kim</td>
                    <td>Dr. Christian Bale</td>
                </tr>
                <tr>
                    <td>Dr. Gareth Luis</td>
                </tr>
            </table>
        </section>

        <section>
            <h2>Doctors and Wards</h2>
            <form action="home_page.php" method="POST">
                <button type="submit" name="join_button" class="display-button">Display doctors and wards</button>
            </form>

            <div style="padding: 20px;">
                <?php
                // Include database connection file
                $conn = mysqli_connect('localhost', 'root', '', 'hospital_mgmt');

                // Check connection
                if (!$conn) {
                    die("Connection Failed: " . mysqli_connect_error());
                }

                // Fetch data when the button is clicked
                if (isset($_POST['join_button'])) {
                    // SQL query to join the 'doctors' and 'wards' tables
                    $sql = "SELECT doctor.DoctorId AS doctor_id, doctor.NAME AS doctor_name, ward.WardId, ward.WardName 
                            FROM doctor
                            INNER JOIN ward
                            ON doctor.WardId = ward.wardid";

                    // Execute the query
                    $result = mysqli_query($conn, $sql);

                    // Check if query was successful and there are results
                    if ($result) {
                        $doctors_wards = mysqli_fetch_all($result, MYSQLI_ASSOC); // Fetch all results as an associative array
                        if (!empty($doctors_wards)) {
                            echo "<table border='1' style='width: 100%; text-align: center;'>
                                    <thead>
                                        <tr>
                                            <th>Doctor ID</th>
                                            <th>Doctor Name</th>
                                            <th>Ward ID</th>
                                            <th>Ward Name</th>
                                        </tr>
                                    </thead>
                                    <tbody>";
                            foreach ($doctors_wards as $row) {
                                echo "<tr>
                                        <td>" . $row['doctor_id'] . "</td>
                                        <td>" . $row['doctor_name'] . "</td>
                                        <td>" . $row['WardId'] . "</td>
                                        <td>" . $row['WardName'] . "</td>
                                    </tr>";
                            }
                            echo "</tbody>
                                </table>";
                        } 
                }
            }

                // Close the connection
                mysqli_close($conn);
                ?>
            </div>
        </section>

        <section>
            <h2>Doctors per Ward</h2>
            <form action="home_page.php" method="POST">
                <button type="submit" name="display_doctor_count" class="display-button">Display Doctor Count per Ward</button><br>
            </form>

            <?php
            // Check if the button was clicked
            if (isset($_POST['display_doctor_count'])) {
                // Include database connection
                $conn = mysqli_connect('localhost', 'root', '', 'hospital_mgmt');

                // Check connection
                if (!$conn) {
                    die("Connection failed: " . mysqli_connect_error());
                }

                // SQL query to count the number of doctors per ward
                $sql = "SELECT ward.WardId, ward.WardName, COUNT(doctor.DoctorId) AS doctor_count
                        FROM ward
                        LEFT JOIN doctor ON ward.WardId = doctor.WardId
                        GROUP BY ward.WardId";

                // Execute the query
                $result = mysqli_query($conn, $sql);

                // Check if there are results
                if ($result && mysqli_num_rows($result) > 0) {
                    echo "<table>";
                    echo "<tr><th>Ward ID</th><th>Ward Name</th><th>Doctor Count</th></tr>";
                    while ($row = mysqli_fetch_assoc($result)) {
                        echo "<tr>";
                        echo "<td>" . $row['WardId'] . "</td>";
                        echo "<td>" . $row['WardName'] . "</td>";
                        echo "<td>" . $row['doctor_count'] . "</td>";
                        echo "</tr>";
                    }
                    echo "</table>";
                } else {
                    echo "<p>No data found or no doctors assigned to wards.</p>";
                }

                // Close the connection
                mysqli_close($conn);
            }
            ?>
        </section>


        <section id="services">
            <h2>Services</h2>
            <h3>Our Services</h3>
            <ul>
                <li>Emergency Care</li>
                <li>Outpatient Services</li>
                <li>Surgical Services</li>
            </ul>

            <h3>Special Clinics</h3>
            <ul>
                <li>Heart Clinic</li>
                <li>Brain Clinic</li>
                <li>Chemotherapy Clinic</li>
                <li>Orthopedic Clinic</li>
            </ul>

            <h3 id="contact">Patient Information</h3>
            <dl>
                <dt>Visiting Hours</dt>
                <dd>9 AM - 8 PM</dd>
                <dt>Emergency Unit</dt>
                <dd>Open 24/7</dd>
                <dt>Contact Information</dt>
                <dd>Phone: (+91) 456-7890</dd>
            </dl>
        </section>

        <section>
            <h2>Notice</h2>
            <div class="div">
                Important: Please follow COVID-19 safety protocols.
            </div><br><br><br>
        </section>
    </main>
    <footer>
        <p>&copy; 2024 Galaxy Hospital</p>
    </footer>
</body>
</html>
