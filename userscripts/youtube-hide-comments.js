// ==UserScript==
// @name          youtube-hide-comments
// @description   Hides comments
// @match         https://www.youtube.com/watch*
// @author        https://github.com/dualword/Qupzilla-Qt/
// @namespace     https://github.com/dualword/Qupzilla-Qt/
// @version       0.1
// @license       MIT
// ==/UserScript==

var id = "comments";
new MutationObserver(function(m) {
    if (document.getElementById(id)) {
        var o = document.getElementById(id);
            document.getElementById(id).style.display = "none";
            this.disconnect();
    }
}).observe(document, {childList: true, subtree: true});

