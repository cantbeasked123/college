function validateForm(event) {
    event.preventDefault(); // Prevent the form from submitting immediately

    // Get form elements
    const name = document.getElementById('name').value.trim();
    const gender = document.querySelector('input[name="gender"]:checked');
    const bloodType = document.getElementById('blood-type').value;
    const contact = document.getElementById('contact').value.trim();
    const age = document.getElementById('age').value.trim();
    const username = document.getElementById('username').value.trim();
    const pwd = document.getElementById('pwd').value;

    // Validation checks
    if (name === "") {
        alert("Name is required.");
        return false;
    }

    if (!gender) {
        alert("Please select a gender.");
        return false;
    }

    if (bloodType === "") {
        alert("Please select a blood type.");
        return false;
    }

    if (contact === "" || !/^\d{10}$/.test(contact)) {
        alert("Please enter a valid contact number (10 digits).");
        return false;
    }

    if (age === "" || isNaN(age) || age < 0 || age > 120) {
        alert("Please enter a valid age (0-120).");
        return false;
    }

    if (username === "") {
        alert("Username is required.");
        return false;
    }

    if (pwd === "") {
        alert("Password is required.");
        return false;
    }

    if (pwd.length < 6) {
        alert("Password must be at least 6 characters long.");
        return false;
    }

    // If everything is valid, submit the form
    document.querySelector('form').submit();
}
