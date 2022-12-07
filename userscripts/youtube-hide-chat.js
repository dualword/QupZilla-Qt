// ==UserScript==
// @name          youtube-hide-chat
// @description   Hides chat
// @match         https://www.youtube.com/watch*
// @author        https://github.com/dualword/Qupzilla-Qt/
// @namespace     https://github.com/dualword/Qupzilla-Qt/
// @version       0.1
// @license       MIT
// ==/UserScript==

var id = 'button.yt-spec-button-shape-next[aria-pressed="false"] div span[role="text"]';
t = window.setInterval(test, 3000);
var i = 0, m = 10;

function test(){
	if (i++ >= m) window.clearInterval(t);
	var o = document.querySelectorAll(id);
	if (o) {
		for (let i = 0; i < o.length; i++) { 
			if(o[i].innerHTML == 'Hide chat' || o[i].innerHTML == 'Hide chat replay'){
				o[i].click();
				window.clearInterval(t);
			}
		}
	}
}

