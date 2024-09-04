## 17 Kick-Starting React Native Projects
- Exploring React Native CLI tools
	- The **React Native CLI** is a tool created by Meta. The project is based on the original CLI tool and has three parts: native iOS and Android projects and a React Native JavaScript app. To get started, you will need either Xcode or Android Studio. One of the main advantages of the React Native CLI is its flexibility. You can connect any library with a Native module or directly write code to the native parts. However, all of this requires at least a basic understanding of mobile development.
	- The **Expo CLI** is just one part of the big ecosystem for developing React Native apps. Expo is a framework and a platform for universal React applications. Built around React Native and native platforms, it allows you to build, deploy, test, and rapidly iterate on iOS, Android, and web apps from a single JavaScript/TypeScript code base.
		- The Expo framework provides the following:
			- The **Expo CLI**: A command-line tool that can create blank projects, then run, build, and update them.
			- **Expo Go**: An Android and iOS app for running your projects directly on your device (without having to compile and sign native apps) and sharing them with your entire team.
			- **Expo Snack**: The online playground that allows you to develop React Native apps in the browser.
			- **Expo Application Services (EAS)**: A set of deeply integrated cloud services for Expo and React Native applications. Apps can be compiled, signed, and uploaded to stores using EAS in the cloud.
- Installing and using the Expo command-line tool
	- Before we can use Expo, we need to install Node.js, Git, and Watchman. Watchman is a tool for watching files in our project to trigger actions like rebuilds when they change. All of the required tools and details can be found here: https://docs.expo.dev/getstarted/installation/#requirements
	- Once this installation is complete, we can start a new project by running the command:

			npx create-expo-app --template

			√ Choose a template: » Blank (TypeScript)
			√ What is your app named? ... my_native_app
			✔ Downloaded and extracted project files.
			> npm install
			npm WARN deprecated osenv@0.1.5: This package is no longer supported.
			npm WARN deprecated inflight@1.0.6: This module is not supported, and leaks memory. Do not use it. Check out lru-cache if you want a good and tested way to coalesce async requests by a key value, which is much more comprehensive and powerful.
			npm WARN deprecated @babel/plugin-proposal-numeric-separator@7.18.6: This proposal has been merged to the ECMAScript standard and thus this plugin is no longer maintained. Please use @babel/plugin-transform-numeric-separator instead.
			npm WARN deprecated @babel/plugin-proposal-nullish-coalescing-operator@7.18.6: This proposal has been merged to the ECMAScript standard and thus this plugin is no longer maintained. Please use @babel/plugin-transform-nullish-coalescing-operator instead.
			npm WARN deprecated @babel/plugin-proposal-optional-catch-binding@7.18.6: This proposal has been merged to the ECMAScript standard and thus this plugin is no longer maintained. Please use @babel/plugin-transform-optional-catch-binding instead.
			npm WARN deprecated @babel/plugin-proposal-class-properties@7.18.6: This proposal has been merged to the ECMAScript standard and thus this 
			plugin is no longer maintained. Please use @babel/plugin-transform-class-properties instead.
			npm WARN deprecated @babel/plugin-proposal-logical-assignment-operators@7.20.7: This proposal has been merged to the ECMAScript standard and thus this plugin is no longer maintained. Please use @babel/plugin-transform-logical-assignment-operators instead.
			npm WARN deprecated rimraf@2.6.3: Rimraf versions prior to v4 are no longer supported
			npm WARN deprecated @babel/plugin-proposal-optional-chaining@7.21.0: This proposal has been merged to the ECMAScript standard and thus this plugin is no longer maintained. Please use @babel/plugin-transform-optional-chaining instead.
			npm WARN deprecated @babel/plugin-proposal-object-rest-spread@7.20.7: This proposal has been merged to the ECMAScript standard and thus this plugin is no longer maintained. Please use @babel/plugin-transform-object-rest-spread instead.
			npm WARN deprecated rimraf@3.0.2: Rimraf versions prior to v4 are no longer supported
			npm WARN deprecated glob@7.2.3: Glob versions prior to v9 are no longer supported
			npm WARN deprecated @babel/plugin-proposal-async-generator-functions@7.20.7: This proposal has been merged to the ECMAScript standard and thus this plugin is no longer maintained. Please use @babel/plugin-transform-async-generator-functions instead.
			npm WARN deprecated glob@7.1.6: Glob versions prior to v9 are no longer supported
			npm WARN deprecated glob@7.1.6: Glob versions prior to v9 are no longer supported
			npm WARN deprecated glob@7.1.6: Glob versions prior to v9 are no longer supported
			npm WARN deprecated querystring@0.2.1: The querystring API is considered Legacy. new code should use the URLSearchParams API instead.
			
			added 1195 packages in 40s
			
			130 packages are looking for funding
			  run `npm fund` for details
			
			✅ Your project is ready!
			
			To run your project, navigate to the directory and run one of the following npm commands.
			
			- cd my_native_app
			- npm run android
			- npm run ios # you need to use macOS to build the iOS project - use the Expo app if you need to do iOS development without a Mac
			- npm run web