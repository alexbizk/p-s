*This project has been created as part of the 42 curriculum by weitwang, &lt;login2&gt;.*

# push_swap

[English](#english) | [中文](#中文)

---

## English

### Description

`push_swap` is a sorting program with a twist: the numbers live on a **stack `a`**, there is a second empty **stack `b`**, and the only way to move them is a fixed set of 11 operations. The program does not print the sorted numbers. It prints the **list of operations** that sorts stack `a` in ascending order (smallest on top), and the goal is to use as few operations as possible.

| Operation | Effect |
|---|---|
| `sa` / `sb` / `ss` | swap the first two elements of `a` / `b` / both |
| `pa` / `pb` | take the top of `b` and put it on `a` / the other way round |
| `ra` / `rb` / `rr` | rotate up: the first element becomes the last (`a` / `b` / both) |
| `rra` / `rrb` / `rrr` | rotate down: the last element becomes the first (`a` / `b` / both) |

This version of the project asks for **four strategies** in one binary (simple, medium, complex and adaptive), a **disorder** metric, and a `--bench` mode that reports statistics.

### Instructions

**Compile**

```sh
make        # builds libft and push_swap
make clean  # removes object files
make fclean # removes object files and the binary
make re     # fclean + all
```

**Run**

```sh
./push_swap 3 2 1                  # default strategy: --adaptive
./push_swap "3 2 1"                # numbers in one string also work
./push_swap --simple 5 4 3 2 1     # force a strategy
./push_swap --medium  ...
./push_swap --complex ...
./push_swap --adaptive ...
./push_swap --bench 4 67 3 87 23   # print statistics to stderr after sorting
```

Options can be placed anywhere among the numbers. Operations are printed on **stdout**, one per line. The `--bench` report is printed on **stderr**, so it never mixes with the operations:

```sh
ARG="4 67 3 87 23"; ./push_swap --bench $ARG 2> bench.txt | ./checker_linux $ARG
```

```
[bench] disorder:  40.00%
[bench] strategy:  Adaptive / O(n*sqrt(n))
[bench] total_ops:  13
[bench] sa:  0  sb:  0  ss:  0  pa:  5  pb:  5
[bench] ra:  2  rb:  1  rr:  0  rra:  0  rrb:  0  rrr:  0
```

**Errors.** `Error` followed by `\n` is written to stderr when an argument is not an integer, is outside the `int` range, is duplicated, or is an unknown option (for example `--foo`). With no arguments the program prints nothing.

### Algorithms

Before sorting, every number receives an **index**: its rank among all numbers (0 = smallest, n-1 = largest). All algorithms work on these indexes instead of the raw values, so negative or very large numbers need no special handling.

#### Disorder

The disorder is the fraction of pairs `(i, j)` with `i` before `j` where the value of `i` is greater than the value of `j` (the number of inversions divided by `n(n-1)/2`). It is 0 for a sorted stack and 1 for a reversed one. It is computed **before any operation**, with two nested loops (O(n²) time, but it outputs no operations).

#### 1. Simple: selection sort, O(n²)

Repeat until `a` is empty: find the smallest element, bring it to the top with `ra` or `rra` (whichever direction is shorter), then `pb`. Finally `pa` everything back. Each element can need up to n/2 rotations, so the number of operations is O(n²).

#### 2. Medium: chunk sort, O(n√n)

The indexes are split into about √n chunks of size √n (`0..k-1`, `k..2k-1`, ...). Chunks are pushed to `b` in increasing order: rotate `a` until an element of the current chunk is on top, then `pb`. Each chunk needs at most one pass over `a` (≤ n operations), and there are √n chunks, so this phase is O(n√n). Then the largest index is brought to the top of `b` with `rb`/`rrb` and pushed back with `pa`, repeatedly. Because the largest chunk was pushed last, the maximum is always near the top of `b` (within about √n positions), so this phase is also O(n√n).

#### 3. Complex: LSD radix sort, O(n log n)

Indexes are read in binary, starting from the lowest bit. For each bit, every element of `a` is visited once: bit 0 → `pb`, bit 1 → `ra`. Then everything in `b` is pushed back with `pa`. Each pass costs at most 2n operations and there are ⌈log₂ n⌉ passes (9 for 500 numbers), so the total is O(n log n).

#### 4. Adaptive

The adaptive strategy computes the disorder and picks one of the three algorithms:

| Disorder | Algorithm | Reason |
|---|---|---|
| < 0.2 | simple | most elements are already close to their place, so only a few need to be moved |
| 0.2 – 0.5 | medium | balanced cost for partially shuffled input |
| ≥ 0.5 | complex | radix sort costs the same whatever the order, which wins on highly shuffled input |

The choice is made in a single function (`adaptive_choice`) that is also used by `--bench`, so the thresholds only exist in one place.

Measured results (number of operations, same input for every strategy):

| n | disorder | simple | medium | complex | adaptive |
|---|---|---|---|---|---|
| 100 | 5.8% | **264** | 400 | 1084 | 264 |
| 100 | 22.1% | 816 | **679** | 1084 | 679 |
| 100 | 42.0% | 1536 | **771** | 1084 | 771 |
| 500 | 0.8% | **1491** | 1776 | 6784 | 1491 |
| 500 | 5.0% | **4038** | 4648 | 6784 | 4038 |
| 500 | 13.1% | 10038 | **6246** | 6784 | 10038 |

These measurements also show the limits of the default thresholds: with 500 numbers, simple sort becomes expensive even at about 13% disorder. <!-- TODO: update this paragraph if the thresholds are changed. -->

#### Complexity summary

| Strategy | Operations (time) | Extra space |
|---|---|---|
| simple | O(n²) | O(1) (only the two stacks, O(n) in total) |
| medium | O(n√n) | O(1) |
| complex | O(n log n) | O(1) |
| adaptive | the bound of the selected algorithm, plus O(n²) comparisons to compute the disorder (no operations) | O(1) |

#### Operation counting without global variables

The subject forbids global variables. The operation counter is a `static int count[11]` declared **inside** the function `op_counter()`, which returns a pointer to it. Every operation calls `put_op(name, id)`, which prints the operation and increments `count[id]`. The total is the sum of the 11 counters.

### Project structure

```
push_swap.c      main(): parse options, parse numbers, sort, free
parsing/         number validation, duplicates, option parsing
stack/           linked list helpers, index assignment, min/max search
operations/      the 11 operations and the operation counter
sorting/         simple, medium, radix, adaptive, disorder, dispatcher
bench/           --bench report
Libft/           our libft
```

### Contributions

<!-- Fill in who did what. -->
- **weitwang**: ...
- **&lt;login2&gt;**: ...

### Resources

- The push_swap subject (42)
- Wikipedia: [Selection sort](https://en.wikipedia.org/wiki/Selection_sort), [Radix sort](https://en.wikipedia.org/wiki/Radix_sort), [Bucket sort](https://en.wikipedia.org/wiki/Bucket_sort), [Inversion (discrete mathematics)](https://en.wikipedia.org/wiki/Inversion_(discrete_mathematics))

**Use of AI.** <!-- Adjust to match what you actually did. --> We used AI as a tutor during the project:
- to explain the subject, the stack operations, Big-O notation, the disorder metric and the algorithms in plain language;
- to review our code and find bugs (for example the `long` overflow in number validation, missing files in the Makefile, and Norm issues);
- to suggest the design of some parts (the static operation counter, option parsing, the `--bench` output, `adaptive_choice`) and to write a first draft of this README.

Every line of code was typed, tested and understood by us, and both of us can explain any part of it.

---

## 中文

### 项目简介

`push_swap` 是一个特殊的排序程序：数字放在**栈 `a`** 里，另有一个空的**栈 `b`**，只能用 11 种固定的操作来移动数字。程序不输出排好的数字，而是输出一串**操作指令**，按这些指令执行后，栈 `a` 会变成从小到大（最小的在栈顶）。目标是用尽量少的操作。

| 操作 | 作用 |
|---|---|
| `sa` / `sb` / `ss` | 交换 `a` / `b` / 两个栈顶部的两个元素 |
| `pa` / `pb` | 把 `b` 的栈顶放到 `a` 上 / 反过来 |
| `ra` / `rb` / `rr` | 向上旋转：第一个元素变成最后一个（`a` / `b` / 两个都转） |
| `rra` / `rrb` / `rrr` | 向下旋转：最后一个元素变成第一个（`a` / `b` / 两个都转） |

这一版题目要求在同一个程序里实现**四种策略**（简单、中等、复杂、自适应），计算**无序度**，并提供输出统计信息的 `--bench` 模式。

### 使用说明

**编译**

```sh
make        # 编译 libft 和 push_swap
make clean  # 删除 .o 文件
make fclean # 删除 .o 文件和程序
make re     # fclean 后重新编译
```

**运行**

```sh
./push_swap 3 2 1                  # 默认策略：--adaptive
./push_swap "3 2 1"                # 数字写在一个字符串里也可以
./push_swap --simple 5 4 3 2 1     # 强制使用某种策略
./push_swap --bench 4 67 3 87 23   # 排序后向 stderr 输出统计信息
```

选项可以放在数字之间的任何位置。操作指令输出到 **stdout**，每行一条；`--bench` 的统计信息输出到 **stderr**，不会和操作指令混在一起：

```sh
ARG="4 67 3 87 23"; ./push_swap --bench $ARG 2> bench.txt | ./checker_linux $ARG
```

**错误处理**：参数不是整数、超出 `int` 范围、有重复值，或者是不认识的选项（比如 `--foo`）时，向 stderr 输出 `Error` 和换行。没有参数时什么都不输出。

### 算法说明

排序前，每个数字会得到一个 **index**，也就是它在所有数字里的排名（0 = 最小，n-1 = 最大）。所有算法都基于 index，而不是原始数值，所以负数、很大的数都不需要特别处理。

#### 无序度

把所有数两两配对，统计"前面的数比后面的数大"的对数（逆序对），再除以总对数 `n(n-1)/2`。完全排好时为 0，完全倒序时为 1。它在**执行任何操作之前**计算，用两层循环完成（O(n²) 次比较，但不产生任何操作）。

#### 1. 简单算法：选择排序，O(n²)

重复以下步骤直到 `a` 为空：找到最小的元素，用 `ra` 或 `rra`（选较短的方向）把它转到栈顶，然后 `pb`。最后把所有元素 `pa` 回来。每个元素最多需要约 n/2 次旋转，所以操作数是 O(n²)。

#### 2. 中等算法：分块排序，O(n√n)

把 index 分成约 √n 块，每块约 √n 个（`0..k-1`、`k..2k-1`……）。按从小到大的顺序把每一块推到 `b`：旋转 `a`，直到栈顶是当前块的元素，再 `pb`。每一块最多遍历一次 `a`（≤ n 次操作），共 √n 块，所以这一阶段是 O(n√n)。之后反复把 `b` 里最大的 index 用 `rb`/`rrb` 转到栈顶，再 `pa` 回去。因为最大的那一块是最后推进去的，最大值总在 `b` 的顶部附近（约 √n 个位置以内），所以这一阶段也是 O(n√n)。

#### 3. 复杂算法：基数排序（LSD），O(n log n)

把 index 看成二进制，从最低位开始。对每一位，把 `a` 里的每个元素看一遍：这一位是 0 就 `pb`，是 1 就 `ra`，然后把 `b` 里的全部 `pa` 回来。每一轮最多 2n 次操作，共 ⌈log₂ n⌉ 轮（500 个数是 9 轮），所以总共是 O(n log n)。

#### 4. 自适应算法

先计算无序度，再从三种算法中选一种：

| 无序度 | 算法 | 理由 |
|---|---|---|
| < 0.2 | 简单 | 大部分元素已经在正确位置附近，只需要移动少数几个 |
| 0.2 – 0.5 | 中等 | 对中等混乱的数据，代价比较均衡 |
| ≥ 0.5 | 复杂 | 基数排序的代价与顺序无关，数据很乱时最有优势 |

选择逻辑写在同一个函数 `adaptive_choice` 里，`--bench` 也调用它，所以阈值只出现在一个地方。实测数据见英文部分的表格。数据也显示了默认阈值的局限：500 个数时，即使无序度只有约 13%，简单算法的步数也已经很多。

#### 复杂度总结

| 策略 | 操作数（时间） | 额外空间 |
|---|---|---|
| 简单 | O(n²) | O(1)（只用两个栈，总共 O(n)） |
| 中等 | O(n√n) | O(1) |
| 复杂 | O(n log n) | O(1) |
| 自适应 | 所选算法的上界，另加计算无序度的 O(n²) 次比较（不产生操作） | O(1) |

#### 不用全局变量统计操作次数

题目禁止全局变量。操作计数器是一个声明在函数 `op_counter()` **内部**的 `static int count[11]`，函数返回指向它的指针。每个操作都调用 `put_op(name, id)`：打印操作名，并让 `count[id]` 加 1。总步数就是 11 个计数之和。

### 分工

<!-- 填写各自负责的部分。 -->
- **weitwang**：……
- **&lt;login2&gt;**：……

### 参考资料

- 42 push_swap 题目
- Wikipedia：选择排序、基数排序、桶排序、逆序对（链接见英文部分）

**AI 的使用**：<!-- 根据实际情况修改。 --> 我们在项目中把AI当作辅导工具：
- 用通俗的方式解释题目、栈操作、大 O 表示法、无序度和各种算法；
- 检查代码、找出 bug（例如数字校验里的 `long` 溢出、Makefile 漏掉的文件、Norm 问题）；
- 对部分设计提出建议（static 计数器、选项解析、`--bench` 输出、`adaptive_choice`），并写出本 README 的初稿。

所有代码都由我们亲手输入、测试并理解，两个人都能解释其中任何一部分。
