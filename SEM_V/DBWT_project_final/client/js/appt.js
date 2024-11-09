document.getElementById('appointmentForm').addEventListener('submit', function(event) {
    // Prevent the form from submitting
    event.preventDefault();

    // Get form values
    const userId = document.getElementById('userid').value; // Access the hidden input field
    const patientName = document.getElementById('patient_name').value;
    const appointmentDate = document.getElementById('appointment_date').value;
    const appointmentTime = document.getElementById('appointment_time').value;
    const wardNo = document.getElementById('ward_no').value;
    const appointmentId = document.getElementById('id').value;

    // Validation flag
    let isValid = true;

    // Validate Patient Name
    if (!patientName.trim()) {
        alert("Please enter the patient's name.");
        isValid = false;
    }

    // Validate Appointment Date (must not be in the past)
    if (!appointmentDate) {
        alert("Please select an appointment date.");
        isValid = false;
    } else {
        const today = new Date();
        const selectedDate = new Date(appointmentDate);
        if (selectedDate < today.setHours(0, 0, 0, 0)) { // Ensure date is today or later
            alert("The appointment date cannot be in the past.");
            isValid = false;
        }
    }

    // Validate Appointment Time
    if (!appointmentTime) {
        alert("Please select an appointment time.");
        isValid = false;
    }

    // Validate Ward Selection
    if (!wardNo || wardNo <= 0) {
        alert("Please select a valid ward.");
        isValid = false;
    }

    // If form is valid, submit it
    if (isValid) {
        // Automatically set the user ID from session if the input field is not present
        alert("Appointment details are valid. Submitting the form.");
        
        // Optionally, submit the form here
        // this.submit();
    }
});

// Function to display an appointment
function displayAppointment() {
    const appointmentId = document.getElementById('id').value;

    if (!appointmentId) {
        alert("Please enter an appointment ID to display.");
        return;
    }

    // Send a request to fetch the appointment details
    fetch('../server/appointment.php?action=display&id=' + appointmentId)
        .then(response => response.json())
        .then(data => {
            if (data.success) {
                const appointment = data.appointment;
                alert("Appointment Details:\n" +
                    "Patient Name: " + appointment.patient_name + "\n" +
                    "Date: " + appointment.appointment_date + "\n" +
                    "Time: " + appointment.appointment_time + "\n" +
                    "Ward Number: " + appointment.ward_no);
            } else {
                alert(data.message || "Appointment not found.");
            }
        })
        .catch(error => {
            alert("An error occurred while fetching the appointment details.");
            console.error('Error:', error);
        });
}
