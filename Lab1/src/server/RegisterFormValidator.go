package main

import "regexp"

const (
  UserValid = iota
  UserInvalidNickname
  UserInvalidEmail
  UserWeakPassword
  UserPasswordMismatch
)

type RegisterResult struct {
  status int32
  message string
}

type RegisterFormValidator struct {
}

func getPasswordError(password string) string {
	var message = ""
	var passLen = len(password)
	if (passLen < 6) {
		message = "Too small password"
	}
	
	match, _ := regexp.MatchString("^[a-zA-Z0-9]*$", password)
	if (!match) {
		message = "Allowed only letters and digits"
	}
	
	return message;
}

func getNicknameError(nickname string) string {
	var message = ""
	if (len(nickname) < 3) {
		message = "Nickname should at least 3 chars"
	}
	
	match, _ := regexp.MatchString("^[_a-zA-Z0-9]*$", nickname)
	if (!match) {
		message = "Allowed only letters, digits and _"
	}
	
	return message;
}

func getEmailErrors(email string) string {
	var message = ""
	match, _ := regexp.MatchString("^([a-zA-Z0-9._%+-]+)@(gmail.com|yandex.ru|mail.ru)$", email)
	if (!match) {
		message = "Email is invalid"
	}
	
	return message
}

func (self *RegisterFormValidator) Check(user *SiteUser, repeatPass string) RegisterResult {
  result := RegisterResult{
    status: UserValid,
  }
  var passError = getPasswordError(user.password)
  var nickError = getNicknameError(user.nickname)
  var mailError = getEmailErrors(user.email)

  if len(nickError) != 0 {
    result.status = UserInvalidNickname
    result.message = nickError
  } else if len(mailError) != 0 {
    result.status = UserInvalidEmail
    result.message = mailError
  } else if len(passError) != 0 {
	result.status = UserWeakPassword
	result.message = passError
  } else if (user.password != repeatPass) {
	result.status = UserPasswordMismatch
	result.message = "Passwort is not the same"
  }

  return result
}

