## 2 Rendering with JSX
- JSX, which is the XML/HTML markup syntax that’s embedded 
in your JavaScript code and used to declare your React components.
- The `render()` function takes JSX as an argument and renders it to the DOM node passed to `ReactDOM.createRoot()`.
- You may have noticed the surrounding `<div>` tag, grouping together all of the other tags as its children. This is because React needs a root element to render.
- When you render HTML tags in JSX markup, the expectation is that you’ll use lowercase for the 
tag name.
- React implements event delegation by default to optimize performance. Instead of attaching event handlers to each individual element, React attaches a single event handler to the root of the application (or a parent component). When an event is triggered on a child element, it bubbles up the component tree until it reaches the parent with the event handler. React’s synthetic event system then determines which component should handle the event based on the target property of the event object. This allows React to efficiently manage events without needing to attach handlers to every single element.