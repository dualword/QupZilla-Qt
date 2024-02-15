// ==UserScript==
// @name          youtube-hide-recommended
// @description   Hides recommended video sidebar
// @match         https://www.youtube.com/watch*
// @author        https://github.com/dualword/QupZillKa/
// @namespace     https://github.com/dualword/QupZillKa/
// @version       0.1
// @license       MIT
// ==/UserScript==

var id = "secondary";
new MutationObserver(function(m) {
    if (document.getElementById(id)) {
        var o = document.getElementById(id);
            document.getElementById(id).style.display = "none";
            this.disconnect();
    }
}).observe(document, {childList: true, subtree: true});

