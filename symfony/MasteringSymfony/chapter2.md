## 2 The Request and Response Life Cycle
-  four steps that Symfony takes to process a request and send a response

	web/app.php
	
		$kernel = new AppKernel('prod', false);
		$kernel->loadClassCache();
		//$kernel = new AppCache($kernel);
		
		// When using the HttpCache, you need to call the method in your front controller instead of relying on the configuration parameter
		//Request::enableHttpMethodParameterOverride();
		$request = Request::createFromGlobals(); // setp1 receive it
		$response = $kernel->handle($request); // setp2 handle it
		$response->send(); // setp3 send it
		$kernel->terminate($request, $response); // setp4 terminate it
- 