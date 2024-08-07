## 9 User Interface Framework Components
- Material UI stands out due to its comprehensive suite of customizable components, adherence to Google’s Material Design principles, and extensive documentation, making it an optimal choice for developers seeking efficiency and aesthetic coherence in their UI design.
- **Material UI** excels in simplifying the complex process of designing application layouts. By offering a robust set of components, specifically **containers** and **grids**, it empowers developers to efficiently structure and organize UI elements. 
	- **Containers** serve as the foundation, providing a flexible way to encapsulate and align content within the overall layout. 
	- **Grids**, on the other hand, allow more granular control, enabling precise placement and alignment of components across different screen sizes, ensuring responsiveness and consistency
- The `Drawer` component, just like a physical drawer, slides open to reveal content that is easily accessed.
- Material UI comes with a `styled()` function that can be used to create styled components based on JavaScript objects.
- Material UI comes with a default theme. We can use this as the starting point to create our own theme. There are two main steps to creating a new theme in Material UI:
	- 1. Use the `createTheme()` function to customize the default theme settings and return a new theme object.
	- 2. Use the `ThemeProvider` component to wrap our application so that the appropriate theme 
is applied.