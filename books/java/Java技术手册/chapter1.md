## 第1章 Java环境介绍
- JVM，Java Virtual Machine
- Java开源版本叫OpenJDK
- Java ME，Java移动版；Java SE，Java标准版；Java EE,Java企业版。
- JLS, Java Language Specification
- JVM是一个程序，提供了运行Java程序所需的运行时环境。它运行的是Java字节码。
	- 提供给JVM运行的程序不是Java语言源码，源码必须转换（或编译）成一种称为Java字节码格式。提供给JVM的Java字节码必须是类文件格式，其扩展名为`.class`。
	- JVM是字节码格式程序的解释器，一次只执行字节码中的一个指令。
- Java类文件可从一个运行平台迁移到另一个平台，只要有可用的JVM，就能正常运行。
- JVM会收集运行时信息，从而对如何执行代码做出更好的决定，也就是说，JVM能监控有优化运行在其中的程序。