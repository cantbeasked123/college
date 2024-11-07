document.getElementById('appointmentForm').addEventListener('submit', function(event) {
    // Prevent the form from submitting
    event.preventDefault();

    // Get form values
    const userId = document.getElementById('userid').value;
    const patientName = document.getElementById('patient_name').value;
    const appointmentDate = document.getElementById('appointment_date').value;
    const appointmentTime = document.getElementById('appointment_time').value;
    const wardNo = document.getElementById('ward_no').value;

    // Validation flag
    let isValid = true;

    // Validate User ID
    if (!userId || isNaN(userId) || userId <= 0) {
        alert("Please enter a valid User ID.");
        isValid = false;
    }

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
        alert("Appointment details are valid. Submitting the form.");
        // Optionally, you can submit the form here if it's valid
        // this.submit();
    }
});
