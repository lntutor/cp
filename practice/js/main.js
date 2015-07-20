var parse = require('./tweet_parser');

var test1 = "@bob @john_ @_11___john___ (success) @congcông @ひらがな such a cool feature; https://twitter.com/jdorfman/status/430511497475670016";
var test2 = '@chris you around?';
var test3 = 'Good morning! (megusta) (coffee)';
var test4 = 'Olympics are starting soon; http://www.nbcolympics.com';
var testCase = [test1, test2, test3, test4];

testCase.forEach(function(item){
	console.log('Input = ', item);
	console.log('Result = ', parse.parse(item), '\n');
});