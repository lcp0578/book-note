## 8 Code Splitting Using Lazy Components and Suspense
- Using the lazy API
	- There are two pieces involved with using the `lazy()` API in React.
	- First, there’s bundling components into their own separate files so that they can be downloaded by the browser separately from other parts of the application. 
	- Second, once you have created the bundles, you can build React components that are lazy: they don’t download anything until they are needed.