## 第3章 WebGL编程
- 在Three.js中，有3个重要的组件
	- 场景(scene)
	- 相机(camera)
	- 渲染器(renderer)
- 在Three.js中相机的表示是Three.Camera,它是相机的抽象类，其子类有两种相机，分别是
	- 平行投影相机`Three.OrthographicCamera`
	- 透视投影相机`Three.PerspectiveCamera`
- 在Three.js中采用的是右手坐标系，正对屏幕，
	- 水平从左到右是x轴，
	- 从下向上是y轴，
	- z轴是由里向外。
- Three推荐通过`requestAnimationFrame()`方法制作动画
	- 虽然没有指定动画的间隔，但是这个方法默认以每秒60次（60帧）的频率执行。
	- 这个方法的调用方式与`setInterval()`方法类似。
	- `requestAnimationFrame()`方法与`setInterval()`方法的区别主要在于CPU占用率、浏览器兼容性和卡顿处理等。
		- `requestAnimationFrame()`方法对CPU更友好