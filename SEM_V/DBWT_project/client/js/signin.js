document.addEventListener("DOMContentLoaded", function()
{
    document.getElementById("loginForm").addEventListener("submit", function(event)
{
        event.preventDefault();
       
        const username = document.getElementById("username").value;
        const password = document.getElementById("password").value;
       
        if (username === "") {
            alert("Please enter your username.");
            return false;
        }

        if (password.length === "") {
            alert("Please enter your password.");
            return false;
        }

        alert("Form submitted successfully!");
        event.target.submit();
    });
});