document.addEventListener("DOMContentLoaded", () => {
    const startInput = document.querySelector('input[name="start_time"]');
    const endInput = document.querySelector('input[name="end_time"]');
    const msg = document.getElementById("availabilityMsg");
    const form = document.querySelector("form");

    window.checkAvailabilityAndDuration = function (){
        checkDuration();
        checkAvailability();
    };

    const searchInput = document.getElementById("facilitySearch");
    const dropdown = document.getElementById("facilityDropdown");

    searchInput.addEventListener("input", () => {
        const filter = searchInput.value.toLowerCase();
        const options = dropdown.options;

        for (let i = 0; i < options.length; i++) {
            const text = options[i].textContent.toLowerCase();
            if (options[i].disabled) {
                options[i].style.display = "block";
                continue;
            }
            options[i].style.display = text.includes(filter) ? "block" : "none";
        }
    });

    function checkDuration() {
        const start = startInput.value;
        const end = endInput.value;

        if (!start || !end) return true;

        const startTime = new Date(`1970-01-01T${start}`);
        const endTime = new Date(`1970-01-01T${end}`);

        const diffMinutes = (endTime - startTime) / (1000 * 60);
        if (diffMinutes > 300) {
            msg.textContent = "Booking cannot exceed 5 hours.";
            return false;
        } else {
            msg.textContent = "";
            return true;
        }
    }

    function checkAvailability() {
        const facilityId = dropdown.value;
        const bookingDate = document.querySelector('input[name="booking_date"]').value;
        const start = startInput.value;
        const end = endInput.value;

        if (!facilityId || !bookingDate || !start || !end) return;

        fetch("checkAvailability.php", {
            method: "POST",
            headers: { "Content-Type": "application/x-www-form-urlencoded" },
            body: `facility_id=${facilityId}&booking_date=${bookingDate}&start_time=${start}&end_time=${end}`
        })
        .then(res => res.text())
        .then(data => {
            if (data.trim() === "unavailable") {
                msg.textContent = "This time slot is already booked.";
            } else {
                if (checkDuration()) msg.textContent = "";
            }
        })
        .catch(err => {
            console.error("Error checking availability:", err);
            msg.textContent = "Error checking availability.";
        });
    }

    startInput.addEventListener("input", () => {
        checkDuration();
        checkAvailability();
    });

    endInput.addEventListener("input", () => {
        checkDuration();
        checkAvailability();
    });

    form.addEventListener("submit", (e) => {
        if (!checkDuration() || msg.textContent !== "") {
            e.preventDefault();
        }
    });
});
