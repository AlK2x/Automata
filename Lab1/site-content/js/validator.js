var regValidator = {
    isEmailValid: function(email) {
        var reg = /^([a-zA-Z0-9._%+-]+)@(gmail.com|yandex.ru|mail.ru)$/;
        return reg.test(email);
    },

    isNicknameValid: function(nickname) {
        var reg = /^[_a-zA-Z0-9]*$/i;
        return nickname.length >= 3 && reg.test(nickname);
    },

    isPasswordCorrect: function(password) {
        var reg = /^[a-zA-Z0-9]*$/i;
        return password.length >= 6 && reg.test(password);
    }
};

function validateForm() {
    var nickname = document.getElementById('exampleInputNickname');
    var email = document.getElementById('exampleInputEmail');
    var password = document.getElementById('exampleInputPassword1');
    var passwordRepeat = document.getElementById('exampleInputPassword2');

    var errorMessage = '';
    if (!regValidator.isNicknameValid(nickname.value)) {
        errorMessage += "Invalid nickname\n";
    }
    if (!regValidator.isEmailValid(email.value)) {
        errorMessage += "Email is invalid\n";
    }
    if (!regValidator.isPasswordCorrect(password.value)) {
        errorMessage += "Weak password\n";
    }
    if (password.value != passwordRepeat.value) {
        errorMessage += "Password is not the same\n";
    }

    if (errorMessage != '') {
        alert(errorMessage);
        return false;
    }

    return true;
};