## 基础议题(Basics)
#### 条款1：仔细区别pointers和reference (Distinguish between pointers and reference)
- pointers使用`*`和`->`操作符，reference则使用`.`。
- 由于reference一定得代表某个对象，C++因此要求references必须有初值。
- pointers可以被重新赋值，指向另一个对象，reference却总指向（代表）它最初获得的那个对象。
- 当你知道你需要指向某个东西，而且绝不会改变指向其他东西，或是当你实现一个操作符而其他语法需求无法由pointers达成，你就应该选择reference。任何其他时候，请采用pointers。
#### 条款2：最好使用C++转型操作符 (Prefer C++-style casets.)
- `dynamic_cast`用来执行继承体系中“安全的向下转型或跨系转型动作”。
- 如果你想为一个不涉及继承机制的类型执行转型动作，可使用`static_cast`，要改变常量性(constness)，则必须使用`const_cast`。
- `reinterpret_cast`的最常用用途是转换“函数指针”类型。
#### 条款3：绝对不要以多态（polymorphically）方式处理数组 (Never treat arrays polmorphically.)
#### 条款4：非必要不提供default constructors. (Avoid gratuitous default constructors.)