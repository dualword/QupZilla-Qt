// ==UserScript==
// @name          youtube-toggle-comments
// @description   Toggles comments
// @match         https://www.youtube.com/watch*
// @author        https://github.com/dualword/Qupzilla-Qt/
// @namespace     https://github.com/dualword/Qupzilla-Qt/
// @version       0.1
// @license       MIT
// ==/UserScript==

var o;
var id = "comments";
new MutationObserver(function(m) {
    if (document.getElementById(id)) {
        o = document.getElementById(id);
		var link = document.createElement('a');
		link.innerHTML = '<center><a style="font-size:1.5em;text-decoration:none;color:green;" id="toggle-comments" href="#toggle-comments" title="Toggle comments">Toggle comments</a></center>';
		o.parentNode.insertBefore(link.firstChild, o);
		document.getElementById("toggle-comments").addEventListener("click", toggle, true);
		o.style.display = "none";
		this.disconnect();
    }
}).observe(document, {childList: true, subtree: true});

function toggle(event){
	if(event) {
		event.stopPropagation();
		event.preventDefault();
	  }
	if(o.classList.contains("inline-block")) {
		o.style.display = "none";
	}else{
		o.style.display = "inline-block";
	}
	o.classList.toggle("inline-block");
	return false;
}


