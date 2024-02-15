// ==UserScript==
// @name          youtube-expand-description
// @description   Expands the description of the video
// @match         https://www.youtube.com/watch*
// @author        https://github.com/dualword/QupZillKa/
// @namespace     https://github.com/dualword/QupZillKa/
// @version       0.1
// @license       MIT
// ==/UserScript==

var id = "expand";
new MutationObserver(function(m) {
    if (document.getElementById(id)) {
		var o = document.getElementById(id);
		o.click();
		this.disconnect();
    }
}).observe(document, {childList: true, subtree: true});

