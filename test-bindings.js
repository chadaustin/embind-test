var b = require('./bindings.js');
console.log(b.addTwo(3, 4));

var c = new b.MyClass();
c.setString("Hello world!");
c.printString();
c.delete();

