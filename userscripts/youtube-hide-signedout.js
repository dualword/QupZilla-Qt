// ==UserScript==
// @name          youtube-hide-signedout
// @description   Hides "you are signed out" messagebox
// @match         https://www.youtube.com/watch*
// @author        https://github.com/dualword/QupZillKa/
// @namespace     https://github.com/dualword/QupZillKa/
// @version       0.1
// @license       MIT
// ==/UserScript==

var id = 'button[aria-label="Got it"]';
t = window.setInterval(test, 3000);
var i = 0, m = 10;

function test(){
	if (i++ >= m) window.clearInterval(t);
	var o = document.querySelector(id);
	if (o) {
		o.click();
		window.clearInterval(t);
	}
}

