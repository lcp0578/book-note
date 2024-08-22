## 15 Why React Native?
- React Native uses a technique that makes asynchronous calls to the underlying mobile OS, which calls the native widget APIs. There’s a JavaScript engine, and the React API is mostly the same as React for the web. The difference is with the target; instead of a DOM, there are asynchronous API calls.
- This oversimplifies everything that’s happening under the hood but the basic ideas are as follows:
	- The same React library that’s used on the web is used by React Native and runs in JavaScriptCore.
	- Messages that are sent to native platform APIs are asynchronous and batched for performance purposes.
	- React Native ships with components implemented for mobile platforms, instead of components that are HTML elements.
	- React Native is just a way to render components via iOS and Android APIs. It can be replaced using the same concept with tvOS, Android TV, Windows, macOS, and even Web again. This is reachable by forks and add-ons for React Native. In this part of the book, we will learn how to write mobile apps for iOS and Android.
- It’s important to remember that React Native’s goal is to “learn once, write 
anywhere” rather than “write once, run anywhere.”