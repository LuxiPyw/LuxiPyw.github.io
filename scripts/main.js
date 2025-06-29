var element = document.body;
if(localStorage.getItem("theme_status")){
	if("light" == localStorage.getItem("theme_status")){
		element.classList.toggle("white_theme");
	}
		
}
function changeTheme(){
	
	if(localStorage.getItem("theme_status")){
		if("light" == localStorage.getItem("theme_status")){
			localStorage.setItem("theme_status","dark");
			element.classList.toggle("white_theme");
		}
		else{
			localStorage.setItem("theme_status","light");
			element.classList.toggle("white_theme");
	
		}
	}
	else{
		localStorage.setItem("theme_status", "light");
		element.classList.toggle("white_theme");		
	}	
}
