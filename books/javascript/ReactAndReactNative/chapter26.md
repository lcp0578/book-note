## 26 Using Animations
- The **Animated API** is the most common tool used to animate components in React Native. It has a set of methods that help you to create an animation object, control its state, and process it. The main benefit is that it can be used with any component, and not just animated components such as `View` or `Text`.
	- But, at the same time, this API has been implemented in the old architecture of React Native. Asynchronous communications between JavaScript and UI Native threads are used with the Animated API, delaying updates by at least one frame and lasting approximately 16 ms. Sometimes, the delay may last even longer if the JavaScript thread is running React’s diff algorithm and comparing or processing network requests simultaneously. The problem of dropped or delayed frames can be solved with the React Native Reanimated library, which is based on the new architecture and processes all business logic from the JavaScript thread in the UI thread.
- **React Native Reanimated** can be utilized to provide a more exhaustive abstraction of the Animated API to use with React Native. It provides an imperative API with multistage animations and custom transitions, while at the same time providing a declarative API that can be used to describe 
simple animations and transitions in a similar way to how CSS transitions work. It’s built on top of React Native Animated and reimplements it on the Native thread. This allows you to use the familiar JavaScript language while taking advantage of the most high performance and simple API.
	- Furthermore, React Native Reanimated defines worklets, which are JavaScript functions that can be synchronously executed within the UI thread. This allows instant animations without having to wait for a new frame.
	- React Native Reanimated provides a variety of hooks and methods that help us handle animations:
		- `useSharedValue`: This hook returns a SharedValue instance, which is the main stateful data object that lives in the UI thread context and has a similar concept to Animated.Value in the core Animated API. A Reanimated animation is triggered when SharedValueis changed. The key benefit is that updates to shared values can be synchronized across the React Native and UI threads without triggering a re-render. This enables complex animations to run smoothly at 60 FPS without blocking the JS thread.
		- `useDerivedValue`: This hook creates a new shared value that automatically updates whenever the shared values used in its calculation change. It allows you to create shared values that depend on other shared values, while keeping them all reactive. useDerivedValue is used to create a derived state in a worklet that runs on the UI thread based on updates to the source shared values. This derived state can then drive animations or other side effects without triggering a re-render on the JS thread.
		- `useAnimatedStyle`: The hook allows you to create a style object with the ability to animate its properties based on shared values. It maps shared value updates to the corresponding view properties. useAnimatedStyle is the main way to connect shared values to views and enable smooth animations running on the UI thread.
		- `withTiming`, `withSpring`, `withDecay`: These are animation utility methods that update a shared value in a smooth, animated way using various curves and physics. They allow you to define animations declaratively by specifying the target value and animation configuration.
	- To install the React Native Reanimated library, run this command inside your Expo project:

			expo install react-native-reanimated