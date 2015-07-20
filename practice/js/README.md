The program is written in Javascript in NodeJS Framework

Requirement:
	Machine installed NodeJS

Command Line:
	Install sync-request: npm install sync-request

	Start Program: node main.js 
		(currently has 4 testcase inside main.js, you can add more testcase in this file)


Sample Input/Output: output.txt

	Input =  @chris you around?
	Result =  { mentions: [ 'chris' ] } 

	Input =  Good morning! (megusta) (coffee)
	Result =  { emotions: [ 'megusta', 'coffee' ] } 

	Input =  Olympics are starting soon; http://www.nbcolympics.com
	Result =  { links: 
	   [ { url: 'http://www.nbcolympics.com',
	       title: 'NBC Olympics | Home of the 2016 Olympic Games in Rio' } ] } 

	Input =  @bob @john_ @_11___john_123_ (success) @congcông @ひらがな such a cool feature; https://twitter.com/jdorfman/status/430511497475670016
	Result =  { mentions: [ 'bob', 'john_', '_11___john_123_', 'congcông', 'ひらがな' ],
	  emotions: [ 'success' ],
	  links: 
	   [ { url: 'https://twitter.com/jdorfman/status/430511497475670016',
	       title: 'Justin Dorfman on Twitter: nice @littlebigdetail from ...' } ] } 

