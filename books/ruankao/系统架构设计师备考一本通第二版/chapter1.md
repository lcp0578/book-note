## 第1章 计算机组成与结构
- 运算器由
	- 算术逻辑单元(Arithmetic and Logic Unit, ALU)，实现对数据的算术和逻辑运算。
	- 累加寄存器(Accumulator, AC)，运算结果或源操作数的存放区
	- 数据缓冲寄存器(Data Register, DR)，暂时存放内存的指令或数据
	- 状态条件寄存器(Program Status Word, PSW)，保存指令运行结果的条件码内容，如溢出标志等。
- 控制器由
	- 指令寄存器(Instruction Register, IR)，暂存CPU执行指令
	- 程序计数器(Program Counter, PC)，存放指令执行地址
	- 地址寄存器(Address Register, AR)，保存当前CPU所访问的内存地址
	- 指令译码器(Instruction Decoder, ID)，分析指令操作码

- CISC和RISC的区别
<table>
	<tr>
		<th>指令系统类型</th>
		<th>指令</th>
		<th>寻址方式</th>
		<th>实现方式</th>
		<th>其他</th>
	</tr>
	<tr>
		<td>CISC(复杂)</td>
		<td>数量多，使用频率差别大，可变长格式</td>
		<td>支持多种</td>
		<td>微程序控制技术（微码）</td>
		<td>研制周期长</td>
	</tr>
	<tr>
		<td>RISC(精简)</td>
		<td>数量少，使用频率接近，定长格式，大部分为单周期指令，操作寄存器，只有LOAD/Store操作内存</td>
		<td>支持方式少</td>
		<td>增加了通用寄存器；硬布线逻辑控制为主；适合采用流水线</td>
		<td>优化编译，有效支持高级语言</td>
	</tr>
</table>

- 可靠性指标
	- 平均无故障时间(Mean Time To Filure, MTTF)

			MTTF = 1/失效率
	- 平均故障修复时间(Mean Time To Repair, MTTR)

			MTTR = 1/修复率
	- 平均故障间隔时间(Mean Time Between Failure, MTBF)

			MTBF = MTTF + MTTR
	- 系统可用性

			系统可用性= MTTF/(MTTF + MTTR) * 100%