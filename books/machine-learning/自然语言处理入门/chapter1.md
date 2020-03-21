## 第1章 新手上路
- 自然语言处理(Natural Language Processing, NLP)是融合了计算机科学、人工智能以及语言学的交叉学科。
- 自然语言处理系统的输入源一共有3种，即语音、图像和文本。
- 开源NLP工具
	- 教学常用的NLTK(Natural Language Toolkit)
	- 斯坦福大学开发的CoreNLP
	- 哈工大开发的LTP(Language Technology Platform)
	- HanLP(Han Language Processing)
- HanLP的Python接口由pyhanlp包提供

		$ pip install pyhanlp
        $ hanlp
        usage: hanlp [-h] [-v] {segment,parse,serve,update} ...

        HanLP: Han Language Processing v1.7.7

        positional arguments:
          {segment,parse,serve,update}
                                which task to perform?
            segment             word segmentation
            parse               dependency parsing
            serve               start http server
            update              update jar and data of HanLP

        optional arguments:
          -h, --help            show this help message and exit
          -v, --version         show installed versions of HanLP
- 分词测试

        $ hanlp segment <<< '我是一名程序员，主要开发语言为PHP、Go、Python'
        我/rr 是/vshi 一/m 名/q 程序员/nnt ，/w 主要/b 开发/vn 语言/n 为/p PHP/nx 、/w Go/nx 、/w Python/nx