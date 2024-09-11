## 24 Showing Progress
- Indicating progress
	- `ActivityIndicator` component
- Exploring navigation indicators
	- Have the Navigator component automatically fetch API data for the scene that’s about to be rendered.
	- Use the promise that’s returned by the API call as a means to display the spinner and hide it once the promise has been resolved.
- The `ProgressBar` component accepts the progress property and renders the label and progress bar. The `<Progress.Bar />` component accepts a set of props, but we need only width, progress, and useNativeDriver (for better animation).