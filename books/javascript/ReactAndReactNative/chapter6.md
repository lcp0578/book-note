## 6 Type-Checking and Validation with TypeScript
- Props validation is crucial for a few reasons, as follows:
	- **It helps catch errors early in the development process**: If a component receives a prop of an unexpected type, it might not behave as expected, leading to bugs that can be hard to track down. By validating props, we can catch these errors before they cause problems.
	- **Props validation improves code readability**: By looking at a component’s prop types, you can quickly understand what data the component expects to receive. This makes it easier to use and reuse components throughout your application.
	- **Props validation makes components more predictable**: When a component clearly specifies the types of props it expects to receive, it’s easier to understand how the component will behave based on its props.
- **TypeScript** is a statically typed superset of **JavaScript**, developed and maintained by Microsoft.
- **TypeScript** uses a transpiler (a type of compiler) to convert TypeScript code, which browsers can’t understand directly, into JavaScript code, which can run in any environment where JavaScript runs.
- Why use TypeScript?
	- **Catch errors early**: We’ve already discussed it, but it’s worth putting it in the first place on the list. One of the biggest advantages of TypeScript is its ability to catch errors at compile time, before even running the code. This can help prevent many common errors that might not be caught until runtime in regular JavaScript.
	- **Improve code readability**: TypeScript’s type annotations make it clear what kind of values a function expects as arguments or what type of value a function returns. This can make the code easier to read and understand, especially for other developers who might be working on the same code base.
	- **Easier refactoring**: TypeScript’s static typing also makes it easier to refactor code. If you change the type of a variable or the signature of a function, TypeScript can help you find all the places in your code where you need to make corresponding changes.
	- **Community and tooling support**: TypeScript has gained significant popularity in the JavaScript community and is used by many large companies like Microsoft, Google, and Airbnb. This implies that there’s a large community of developers who can provide support and a wealth of resources for learning TypeScript. Additionally, many code editors have excellent support for TypeScript, providing features like autocompletion, type inference, and error highlighting.
	- **Integration with modern frameworks and libraries**: TypeScript integrates well with modern JavaScript frameworks like React and React Native, which have built-in TypeScript definitions, making it easier to build strongly typed applications. Moreover, a vast majority of popular JavaScript libraries have TypeScript definitions available. These definitions, of￾ten contributed by the community, provide type information about the library’s functions and objects, making it easier and safer to use these libraries in your TypeScript projects. This widespread adoption of TypeScript in the JavaScript ecosystem ensures that you can leverage the benefits of TypeScript almost anywhere in your code base.
	- **Increasing job market demand**: The popularity of TypeScript extends beyond just development practices: it’s also increasingly sought after in the job market. Many companies, from start-ups to large corporations, are adopting TypeScript for their projects, and as a result, there’s a growing demand for developers who are proficient in TypeScript. This is particularly true for roles involving React and React Native, where TypeScript is often used for its benefits in scaling and maintaining large code bases. By learning TypeScript, you’re not only gaining a valuable skill for your projects but also making yourself more marketable as a developer.
- Basic types in TypeScript
	- **boolean**: The most basic datatype is the simple true/false value, which JavaScript and TypeScript call a Boolean:

			let isDone: boolean = false;
	- **number**: As in JavaScript, all numbers in TypeScript are floating point values. These floating point numbers get the type number:

			let age: number = 32;
	- **string**: Another fundamental part of creating programs in JavaScript for web pages and servers alike is working with textual data. As in other languages, we use the type string to refer to these textual datatypes:

			let color: string = "blue";
	- **array**: TypeScript, like JavaScript, allows you to work with arrays of values. Array types can be written in one of two ways. In the first, you use the type of the elements followed by [] to denote an array of that element type:

			let list: number[] = [1, 2, 3];
		- The second way uses a generic array type, Array<elemType>:

				let list: Array<number> = [1, 2, 3];
	- **tuple**: Tuple types allow you to express an array where the type of a fixed number of ele￾ments is known but does not need to be the same. For example, you may want to represent a value as a pair of a string and a number:

			let x: [string, number];
			x = ["hello", 10]; // OK
	- **enum**: A helpful addition to the standard set of datatypes from JavaScript is the enum. As in languages like C#, an enum is a way of giving more friendly names to sets of numeric values:

			enum Color {
			 Red,
			 Green,
			 Blue,
			}
			let c: Color = Color.Green;
	- **any**: We may need to describe the type of variables that we do not know when we are writing an application. These values may come from dynamic content, for example, from the user or a third-party library. In these cases, we want to opt out of type-checking and let the values pass through compile-time checks. To do so, we label these with the any type:

			let notSure: any = 4;
			notSure = "maybe a string instead";
			notSure = false; // okay, definitely a Boolean
	- **unknown**: The unknown type is a type-safe counterpart of any. Anything is assignable to unknown, but unknown isn’t assignable to anything but itself and any without a type assertion or a control flow-based narrowing. Likewise, no operations are permitted on an unknown without first asserting or narrowing to a more specific type:

			let notSure: unknown = 4;
			notSure = "maybe a string instead";
			// OK, because of structural typing
			notSure = false; 
			Chapter 6 95
			let surelyNotAString: string = notSure; // Error, 'unknown' is not 
			assignable to 'string'
		- In this example, we can’t assign notSure to surelyNotAString without a type-check, because notSure is of the unknown type. This helps prevent errors because we can’t in￾advertently perform operations on variables of the unknown type without first checking their types.
		- A common use case for unknown is in a catch clause, where the type of the error object is not known:

				try {
				 // some operation that might throw
				} catch (error: unknown) {
				 if (error instanceof Error) {
				 console.log(error.message);
				 }
				}
		- In this example, we don’t know what the error type might be, so we give it the unknown type. This forces us to check its type before we can interact with it.
	- **void**: void is a little like the opposite of any: the absence of having any type at all. You may commonly see this as the return type of functions that do not return a value:

			function warnUser(): void {
			 console.log("This is my warning message");
			}
	- **null** and **undefined**: In TypeScript, both undefined and null actually have their owntypes named undefined and null respectively. Much like void, they’re not extremely useful on their own:

			let u: undefined = undefined;
			let n: null = null;
		- However, undefined plays a crucial role in optional types. In TypeScript, you can make a type optional by adding ? after the type name. This means the value can be of the specified type or undefined. For example:

				function greet(name?: string) {
				Type-Checking and Validation with TypeScript 96
				 return 'Hello ${name}';
				}
				greet("Mike");
				greet(undefined); // OK
				greet(); // Also OK
	- **never**: The never type in TypeScript represents a type of value that never occurs. It’s used in situations where a function never returns a value or reaches the end of its execution path. For example, a function that throws an error or one that has an infinite loop can be annotated with the never type:

			function throwError(errorMsg: string): never {
			 throw new Error(errorMsg);
			}
			function infiniteLoop(): never {
			 while (true) {
			 }
			}
- Interfaces
	- An interface in TypeScript is a way of defining a contract for complex types. It describes the shape an object should have. Here’s an example:

			interface User {
			 name: string;
			Chapter 6 97
			 email: string;
			}
	- In this example, we’ve defined a User interface with two properties: name and email, both of which are strings. We can use this interface to type-check objects:

			const user: User = {
			 name: "Alice",
			 email: "alice@example.com",
			};
	- If we try to assign an object that doesn’t match the User interface to the user variable, TypeScript will give us an error.
- Type aliases
	- Type aliases are very similar to interfaces, but can be used for other types as well, not just objects. 
	- Here’s an example of a type alias:

			type Point = {
			 x: number;
			 y: number;
			};
			type ID = number | string;
	- In this example, we’ve defined a Point type that represents a point in a two-dimensional space and ID that can be a string or number. We can use these type aliases in the same way we use interfaces:

			const point: Point = {
			 x: 10,
			 y: 20,
			};
			const id: ID = 100;