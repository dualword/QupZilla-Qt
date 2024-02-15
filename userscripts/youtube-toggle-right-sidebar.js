// ==UserScript==
// @name          youtube-toggle-right-sidebar
// @description   Toggles right sidebar (chat, recommended videos)
// @match         https://www.youtube.com/watch*
// @author        https://github.com/dualword/QupZillKa/
// @namespace     https://github.com/dualword/QupZillKa/
// @version       0.1
// @license       MIT
// ==/UserScript==

var o;
var id = "secondary";
new MutationObserver(function(m) {
    if (document.getElementById(id)) {
        o = document.getElementById(id);
		var link = document.createElement('a');
		link.innerHTML = '<div style="position: fixed;"><a style="font-size:1.5em;text-decoration:none;color:green;" id="toggle-sidebar" href="#toggle-sidebar" title="Toggle sidebar">Toggle sidebar</a></div>';
		o.parentNode.insertBefore(link.firstChild, o);
		document.getElementById("toggle-sidebar").addEventListener("click", toggle, true);
		o.style.visibility = "hidden";
		this.disconnect();
    }
}).observe(document, {childList: true, subtree: true});

function toggle(event){
	if(event) {
		event.stopPropagation();
		event.preventDefault();
	  }
	if(o.classList.contains("inline-block")) {
		if (window.scrollY > 50) window.scroll(window.scrollX,0);
		o.style.visibility = "hidden";
	}else{
		o.style.visibility = "visible";
	}
	o.classList.toggle("inline-block");
	return false;
}


