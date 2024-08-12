## 10 High-Performance State Updates
- **State** represents the dynamic aspect of your React application.When the state changes, your components react to those changes.
- **Automatic batching** is applied everywhere that state updates are made, even in common asynchronous scenarios such as this one.
- The `startTransition()` API is used to mark certain state updates as transitional, meaning that the updates are treated as a lower priority.
- By using `startTransition()`, you tell React that any state updates within can wait if there are more important updates.
- A good rule of thumb for `startTransition()` is to use it for the following:
	- Anything that has the potential to perform a lot of rendering work
	- Anything that doesn’t require immediate feedback from the user in response to their interactions