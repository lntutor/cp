var parse = require('./tweet_parser');

var test1 = '@chris you around?';
var test2 = 'Good morning! (megusta) (coffee)';
var test3 = 'Olympics are starting soon; http://www.nbcolympics.com';
var test4 = "@bob @john_ @_11___john_123_ (success) @congcông @ひらがな such a cool feature; https://twitter.com/jdorfman/status/430511497475670016";

var testCase = [test1, test2, test3, test4];

testCase.forEach(function(item){
	console.log('Input = ', item);
	console.log('Result = ', parse.parse(item), '\n');
});