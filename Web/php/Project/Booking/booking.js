document.addEventListener('DOMContentLoaded', function(){
    const startInput = document.querySelector('input[name="start_time"]');
    const endInput = document.querySelector('input[name="end_time"]');
    const msg = document.getElementById('availabilityMsg');
    const form = document.querySelector('form');

    function checkDuration(){
        const start = startInput.value;
        const end = endInput.value;
        if (!start || !end){
            return true;
        }
        const [sh, sm] = start.split(':').map(Number);
        const [eh, em] = end.split(':').map(Number);

        const duration = (eh * 60 + em) - (sh * 60 + sm);
        if (duration > 300){
            msg.textContent = 'The booking duration cannot exceed 5 hours.';
            return false;
        }else{
            msg.textContent = "";
            return true;
        }
    }

    startInput.addEventListener("input", checkDuration);
    endInput.addEventListener("input", checkDuration);

    form.addEventListener('submit' , function(e){
        if (!checkDuration()){
            e.preventDefault();
            alert('Please correct the booking duration.');
        }
    });
});