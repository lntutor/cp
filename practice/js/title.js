var request = require('sync-request');
var url = 'https://twitter.com/jdorfman/status/430511497475670016';

function getPageTitle(url) {
	try{
		var res = request('GET', url);
		var html = res.getBody();
		var re = /(<\s*title[^>]*>(.+?)<\s*\/\s*title)>/gi;
		var match = re.exec(html);
		if (match && match[2]) {
	   		var title = match[2].replace(/&quot;/g,'');
	   		return title;
		}
	} catch (err) {
		return '';
	}
	return '';
}

console.log(getPageTitle(url));