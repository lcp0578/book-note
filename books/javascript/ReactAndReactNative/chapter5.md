## 5 Crafting Resable Components
- **Render props** are a nice way to address this challenge. The idea is that you pass a property to your component whose value is a function that returns a component to render. This way, instead of having the feature component directly depend on its child components, you can configure them 
as you like; they pass them in as render prop values. Let’s look at an example. Instead of having MyFeature directly depend on AddArticle and ArticleList, you can pass them as render props.