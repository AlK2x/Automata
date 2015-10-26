package main

import "github.com/gin-gonic/gin"
import "net/http"

func RenderRegisterForm(ctx *gin.Context, result *RegisterResult, user *SiteUser) {
	tplData := gin.H{
		"title":                "Automata Theory - Lab 1, form validation",
		"alertMessage":         "",
		"showAlertName":        false,
		"showAlertEmail":       false,
		"showAlertPassword":    false,
		"showPasswordMismatch": false,
		"userNickname":         user.nickname,
		"userEmail":            user.email,
	}
	if result != nil && result.status != UserValid {
		tplData["alertMessage"] = result.message
		switch result.status {
		case UserInvalidNickname:
			tplData["showAlertName"] = true
		case UserInvalidEmail:
			tplData["showAlertEmail"] = true
		case UserWeakPassword:
			tplData["showAlertPassword"] = true
		case UserPasswordMismatch:
			tplData["showPasswordMismatch"] = true
		}
	}
	ctx.HTML(http.StatusOK, "reg-form.tpl", tplData)
}

func RenderUserPage(ctx *gin.Context, user *SiteUser) {
	ctx.HTML(http.StatusOK, "reg-results.tpl", gin.H{
		"title":        "Automata Theory - Lab 1, form validation",
		"userNickname": user.nickname,
		"userEmail":    user.email,
	})
}

func main() {
	cache := NewSiteUsersCache()
	validator := new(RegisterFormValidator)
	user := &SiteUser{
		nickname: "",
		email:    "",
		password: "",
	}
	router := gin.Default()
	router.Static("/css", "../site-content/css")
	router.Static("/js", "../site-content/js")
	router.LoadHTMLGlob("../site-content/tpl/*.tpl")
	router.GET("/form", func(ctx *gin.Context) {
		RenderRegisterForm(ctx, nil, user)
	})
	router.POST("/form", func(ctx *gin.Context) {
		user.email = ctx.PostForm("userEmail")
		user.nickname = ctx.PostForm("userNickname")
		user.password = ctx.PostForm("userPassword")

		// Commented out while unused.
		passwordRepeat := ctx.PostForm("userPasswordRepeat")
		checkResult := validator.Check(user, passwordRepeat)
		if checkResult.status == UserValid {
			cache.AddUser(user)
			RenderUserPage(ctx, user)
		} else {
			RenderRegisterForm(ctx, &checkResult, user)
		}
	})
	router.Run(":8080")
}
