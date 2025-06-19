function validateForm() {
    const form = document.forms[0];

    const firstName = form['first_name'].value.trim();
    const lastName = form['last_name'].value.trim(); // optional
    const email = form['email'].value.trim();
    const contact = form['contact_number'].value.trim();
    const username = form['username'].value.trim();
    const password = form['password'].value;
    const role = form['role_id'].value;

    if (!firstName || !email || !contact || !username || !password || !role) {
        alert("Please fill in all required fields.");
        return false;
    }

    // Optional: validate email format
    const emailPattern = /^[^@\s]+@[^@\s]+\.[^@\s]+$/;
    if (!emailPattern.test(email)) {
        alert("Please enter a valid email address.");
        return false;
    }

    return true;
}

function togglePassword() {
    var pwd = document.getElementById("password");
    pwd.type = (pwd.type === "password") ? "text" : "password";
}