#include<iostream>

// Dependency Inversion Principle

/* 
	Note:
	
		1. High level modules should not depend on Low-Level modules. Both should depend on abstractions.
			e.g: Reporting Component should depend on a ConsoleLogger, but can depend on a ILogger. 
		2. Abstractions should not depend upon details. Details should depend upon abstractions.
			Dependencies on Interfaces and Supertypes is better than dependency on concrete types.

		I)  Inversion of Control (Ioc) - It is the actual process of creating abstractions and getting
			 them to replace dependencies.
		II) Dependency Injection - Use of Software frameworks( e.g. boostDI ) to ensure that a component's dependencies
			 are satisfied.

*/
